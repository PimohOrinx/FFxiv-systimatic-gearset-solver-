//
//  gear.cpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-03-28.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#include "gear.hpp"
#include <iostream>
#include <string>
using namespace std;


void gear::gearimport(string input)
{
    //read file
    //name,jp name,id number,job,slot,Unique,VI melds,V melds,ilvl,pWD,mWD,main stat,Meld cap,Determination,Critical Hit,Skill Speed,Spell Speed,Piety,Tenacity,Direct Hit Rate
    
    //parse gear file line
    size_t comma1=input.find(",");
    size_t comma2=0;
    name=input.substr(0,comma1);
    //getline(input, name, ',');
    comma2=input.find(",",comma1+1);
    
    jp_name=input.substr(comma1+1,comma2-comma1-1);
    //jp_name=getline(input,",");
    comma1=comma2;
    comma2=input.find(",",comma1+1);//???
    
    ID=stoi(input.substr(comma1+1,comma2-comma1));
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    string jobs=input.substr(comma1+1,comma2-comma1);
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    slot=stoi(input.substr(comma1+1,comma2-comma1));
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    unique=stoi(input.substr(comma1+1,comma2-comma1));
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    VI_melds=stoi(input.substr(comma1+1,comma2-comma1));
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    V_melds=stoi(input.substr(comma1+1,comma2-comma1));
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    ilvl=stoi(input.substr(comma1+1,comma2-comma1));//det
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    int pWD=stoi(input.substr(comma1+1,comma2-comma1));//crit
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    int mWD=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    Mainstat=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    int meldcap=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    SubStats[0]=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    SubStats[1]=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    SubStats[2]=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    SubStats[2]+=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    SubStats[3]=stoi(input.substr(comma1+1,comma2-comma1));//ss
    comma1=comma2;
    comma2=input.find(",",comma1+1);
    
    SubStats[3]+=stoi(input.substr(comma1+1,comma2-comma1));//pie
    SubStats[4]=stoi(input.substr(comma2+1));//dh
    
    //find allowed melds
    //string jobs
    //0PLD,1MNK,2WAR,3DRG,4BRD,5WHM,6BLM,7SMN,8SCH,9NIN,10MCH,11DRK,12AST,13SAM,14RDM
    if(jobs.find("PLD")!=string::npos)
        job[0]=true;
    if(jobs.find("MNk")!=string::npos)
        job[1]=true;
    if(jobs.find("WAR")!=string::npos)
        job[2]=true;
    if(jobs.find("DRG")!=string::npos)
        job[3]=true;
    if(jobs.find("BRD")!=string::npos)
        job[4]=true;
    if(jobs.find("WHM")!=string::npos)
        job[5]=true;
    if(jobs.find("BLM")!=string::npos)
        job[6]=true;
    if(jobs.find("SMN")!=string::npos)
        job[7]=true;
    if(jobs.find("SCH")!=string::npos)
        job[8]=true;
    if(jobs.find("NIN")!=string::npos)
        job[9]=true;
    if(jobs.find("MCH")!=string::npos)
        job[10]=true;
    if(jobs.find("DRK")!=string::npos)
        job[11]=true;
    if(jobs.find("AST")!=string::npos)
        job[12]=true;
    if(jobs.find("SAM")!=string::npos)
        job[13]=true;
    if(jobs.find("RDM")!=string::npos)
        job[14]=true;
    
    

    //sees if the job is physical or magic based and stores the relivent wd

    if(job[5]||job[6]||job[7]||job[8]||job[12]||job[14])
        WD=mWD;
    else
        WD=pWD;
        
    //if tank accesore removed one VI meld slot as it will have a str meld

    if((slot==9||slot==10||slot==11||slot==12) && job[1]==0)
        VI_melds--;
   //bugged
    for(int i=0;i<5;i++)// finds the most melds of each type the item can use
    {
        int stats=meldcap-SubStats[i];
        bool no_escape=true;
        for(int j=V_melds;j>=0&&no_escape;j--)
        {
            for(int k=VI_melds;k>=0&&no_escape;k--)
            {
                if(stats>=j*12+k*40-3||(stats>=j*12+k*40-5&&k>0))
                {
                    if(stats>=j*12+k*40)
                        VI_type[i]=k,V_type[i]=j,no_escape=false;
                    else if (k==0&&stats==j*12+k*40-1)
                        VI_type[i]=k,V_type[i]=max(j-1,0),V_type_11[i]=1,no_escape=false;
                    else if (k==0&&stats==j*12+k*40-2)
                        VI_type[i]=k,V_type[i]=max(j-1,0),V_type_10[i]=1,no_escape=false;
                    else if (k==0&&stats==j*12+k*40-3)
                        VI_type[i]=k,V_type[i]=max(j-1,0),V_type_9[i]=1,no_escape=false;
                    else if (stats==j*12+k*40-1)
                        VI_type[i]=max(k-1,0),VI_type_39[i]=1,V_type[i]=j,no_escape=false;
                    else if (stats==j*12+k*40-2)
                        VI_type[i]=max(k-1,0),VI_type_38[i]=1,V_type[i]=j,no_escape=false;
                    else if (stats==j*12+k*40-3)
                        VI_type[i]=max(k-1,0),VI_type_37[i]=1,V_type[i]=j,no_escape=false;
                    else if (stats==j*12+k*40-4)
                        VI_type[i]=max(k-1,0),VI_type_36[i]=1,V_type[i]=j,no_escape=false;
                    else if (stats==j*12+k*40-5)
                        VI_type[i]=max(k-1,0),VI_type_35[i]=1,V_type[i]=j,no_escape=false;
                    
                }
            }
        }
    }
    //no piety V mleds and no piety/ten melds on dps
    if(0==job[0]||0==job[1]||0==job[11])//if not tank no piety/ten melds
    {
        V_type[3]=0;
        V_type_11[3]=0;
        V_type_10[3]=0;
        V_type_9[3]=0;
    }
    //if not tank/healer
    if(0==job[0]||0==job[1]||0==job[11]||0==job[5]||0==job[8]||0==job[14])//if not tank or healer no ten/piety melds
    {
        VI_type[3]=0;
        VI_type_39[3]=0;
        VI_type_38[3]=0;
        VI_type_37[3]=0;
        VI_type_36[3]=0;
        VI_type_35[3]=0;
    }
    
    for(int j=0;j<5;j++)//needs fixing
    {
        for(int k=0;k<5;k++)
        {
            if (VI_melds>VI_type[j]+VI_type_39[j]+VI_type_38[j]+VI_type_36[j]+VI_type_35[j]&&VI_melds>VI_type[k]+VI_type_39[k]+VI_type_38[k]+VI_type_36[k]+VI_type_35[k])
                VI_meld_limits[j][k]=min(VI_melds-(VI_type[j]+VI_type_39[j]+VI_type_38[j]+VI_type_36[j]+VI_type_35[j]),VI_melds-(VI_type[k]+VI_type_39[k]+VI_type_38[k]+VI_type_36[k]+VI_type_35[k]));
            
            if (V_melds>V_type[j]+V_type_11[j]+V_type_10[j]+V_type_9[j]&&V_melds>V_type[k]+V_type_11[k]+V_type_10[k]+V_type_9[k])
                V_meld_limits[j][k]=min(V_melds-(V_type[j]+V_type_11[j]+V_type_10[j]+V_type_9[j]),V_melds-(V_type[k]+V_type_11[k]+V_type_10[k]+V_type_9[k]));
        }
    }
    //int VI_meld_limits[5][5]={0};
    //int V_meld_limits[5][5]={0};
    
    
};

int gear::gearslot(void)
{
    return slot;
};

bool gear::gearjob(int job_number)
{
    return job[job_number];
};


int gear::gear_ID(void)
{
    return ID;
};
bool gear::gear_unique(void)
{
    return unique;
};

int gear::gear_mainstat(void)
{
    return Mainstat;
};
int gear::gear_sub_stat(int stat)
{
    return SubStats[stat];
};

