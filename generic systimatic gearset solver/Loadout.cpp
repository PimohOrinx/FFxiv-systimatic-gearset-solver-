//
//  Loadout.cpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-03-29.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#include <iostream>
#include "Loadout.hpp"
#include "gear.hpp"
#include "Damage.hpp"
using namespace std;
void Loadout::Addgear(int job, gear ring1, gear ring2, gear head, gear body, gear hands, gear waist, gear legs, gear feet, gear ear, gear neck, gear brace, gear arm, gear sheild)
{
    //find main stat
    int jobmod;
    int trait=0;
    //0PLD,1MNK,2WAR,3DRG,4BRD,5WHM,6BLM,7SMN,8SCH,9NIN,10MCH,11DRK,12AST,13SAM,14RDM
    if(job==0)
        jobmod=100;
    else if(job==1||job==9)
        jobmod=110,trait=48;
    else if(job==2||job==11)
        jobmod=105;
    else if((job>=3&&job<=7)||job==10||job==12||job==14)
        jobmod=115,trait=48;
    else if(job==13)
        jobmod=112,trait=48;
    
    MainStat=trait+292*jobmod/100+ring1.gear_mainstat()+ring2.gear_mainstat()+head.gear_mainstat()+waist.gear_mainstat()+legs.gear_mainstat()+feet.gear_mainstat()+ear.gear_mainstat()+neck.gear_mainstat()+brace.gear_mainstat()+arm.gear_mainstat()+sheild.gear_mainstat();
    WeaponDamage=292*jobmod/1000;
    
    for(int i=0;i<5;i++)
    {
        gearstats[i]=ring1.gear_sub_stat(i)+ring2.gear_sub_stat(i)+head.gear_sub_stat(i)+waist.gear_sub_stat(i)+legs.gear_sub_stat(i)+feet.gear_sub_stat(i)+ear.gear_sub_stat(i)+neck.gear_sub_stat(i)+brace.gear_sub_stat(i)+arm.gear_sub_stat(i)+sheild.gear_sub_stat(i);
        //melds
        V_melds=ring1.V_melds+ring2.V_melds+head.V_melds+waist.V_melds+legs.V_melds+feet.V_melds+ear.V_melds+neck.V_melds+brace.V_melds+arm.V_melds+sheild.V_melds;
        VI_melds=ring1.VI_melds+ring2.VI_melds+head.VI_melds+waist.VI_melds+legs.VI_melds+feet.VI_melds+ear.VI_melds+neck.VI_melds+brace.VI_melds+arm.VI_melds+sheild.VI_melds;
        
        V_type[i]=ring1.V_type[i]+ring2.V_type[i]+head.V_type[i]+waist.V_type[i]+legs.V_type[i]+feet.V_type[i]+ear.V_type[i]+neck.V_type[i]+brace.V_type[i]+arm.V_type[i]+sheild.V_type[i];
        V_type_11[i]=ring1.V_type_11[i]+ring2.V_type_11[i]+head.V_type_11[i]+waist.V_type_11[i]+legs.V_type_11[i]+feet.V_type_11[i]+ear.V_type_11[i]+neck.V_type_11[i]+brace.V_type_11[i]+arm.V_type_11[i]+sheild.V_type_11[i];
        V_type_10[i]=ring1.V_type_10[i]+ring2.V_type_10[i]+head.V_type_10[i]+waist.V_type_10[i]+legs.V_type_10[i]+feet.V_type_10[i]+ear.V_type_10[i]+neck.V_type_10[i]+brace.V_type_10[i]+arm.V_type_10[i]+sheild.V_type_10[i];
        V_type_9[i]=ring1.V_type_9[i]+ring2.V_type_9[i]+head.V_type_9[i]+waist.V_type_9[i]+legs.V_type_9[i]+feet.V_type_9[i]+ear.V_type_9[i]+neck.V_type_9[i]+brace.V_type_9[i]+arm.V_type_9[i]+sheild.V_type_9[i];
        
        VI_type[i]=ring1.VI_type[i]+ring2.VI_type[i]+head.VI_type[i]+waist.VI_type[i]+legs.VI_type[i]+feet.VI_type[i]+ear.VI_type[i]+neck.VI_type[i]+brace.VI_type[i]+arm.VI_type[i]+sheild.VI_type[i];
        VI_type_39[i]=ring1.VI_type_39[i]+ring2.VI_type_39[i]+head.VI_type_39[i]+waist.VI_type_39[i]+legs.VI_type_39[i]+feet.VI_type_39[i]+ear.VI_type_39[i]+neck.VI_type_39[i]+brace.VI_type_39[i]+arm.VI_type_39[i]+sheild.VI_type_39[i];
        VI_type_38[i]=ring1.VI_type_38[i]+ring2.VI_type_38[i]+head.VI_type_38[i]+waist.VI_type_38[i]+legs.VI_type_38[i]+feet.VI_type_38[i]+ear.VI_type_38[i]+neck.VI_type_38[i]+brace.VI_type_38[i]+arm.VI_type_38[i]+sheild.VI_type_38[i];
        VI_type_37[i]=ring1.VI_type_37[i]+ring2.VI_type_37[i]+head.VI_type_37[i]+waist.VI_type_37[i]+legs.VI_type_37[i]+feet.VI_type_37[i]+ear.VI_type_37[i]+neck.VI_type_37[i]+brace.VI_type_37[i]+arm.VI_type_37[i]+sheild.VI_type_37[i];
        VI_type_36[i]=ring1.VI_type_36[i]+ring2.VI_type_36[i]+head.VI_type_36[i]+waist.VI_type_36[i]+legs.VI_type_36[i]+feet.VI_type_36[i]+ear.VI_type_36[i]+neck.VI_type_36[i]+brace.VI_type_36[i]+arm.VI_type_36[i]+sheild.VI_type_36[i];
        VI_type_35[i]=ring1.VI_type_35[i]+ring2.VI_type_35[i]+head.VI_type_35[i]+waist.VI_type_35[i]+legs.VI_type_35[i]+feet.VI_type_35[i]+ear.VI_type_35[i]+neck.VI_type_35[i]+brace.VI_type_35[i]+arm.VI_type_35[i]+sheild.VI_type_35[i];

        for(int j=0;j<5;j++)
        {
            VI_meld_limits[i][j]=ring1.VI_meld_limits[i][j]+ring2.VI_meld_limits[i][j]+head.VI_meld_limits[i][j]+waist.VI_meld_limits[i][j]+legs.VI_meld_limits[i][j]+feet.VI_meld_limits[i][j]+ear.VI_meld_limits[i][j]+neck.VI_meld_limits[i][j]+brace.VI_meld_limits[i][j]+arm.VI_meld_limits[i][j]+sheild.VI_meld_limits[i][j];
            V_meld_limits[i][j]=ring1.V_meld_limits[i][j]+ring2.V_meld_limits[i][j]+head.V_meld_limits[i][j]+waist.V_meld_limits[i][j]+legs.V_meld_limits[i][j]+feet.V_meld_limits[i][j]+ear.V_meld_limits[i][j]+neck.V_meld_limits[i][j]+brace.V_meld_limits[i][j]+arm.V_meld_limits[i][j]+sheild.V_meld_limits[i][j];
        }
    }
};

int Loadout::unmelded_damage(int brd,int sch, int drg)
{
    Damage unmelded;
    return unmelded.finddamage(brd, sch, drg,WeaponDamage,MainStat, gearstats[0], gearstats[1], gearstats[2], gearstats[3], 0);
};

void Loadout::meld()// need checks for stat totals
{
    int VI_Melded_Stats[5];
    int V_Melded_Stats[5];
    for(int SsVI=0;SsVI<=VI_type[4]+VI_type_39[4]+VI_type_38[4]+VI_type_36[4]+VI_type_35[4];SsVI++)
    {
        VI_Melded_Stats[4]=0;
        if(VI_type[4]>=SsVI)
            VI_Melded_Stats[4]+=SsVI*40;
        else if(VI_type[4]+VI_type_39[4]>=SsVI)
            VI_Melded_Stats[4]+=VI_type[4]*40+(SsVI-VI_type[4])*39;
        else if(VI_type[4]+VI_type_39[4]+VI_type_38[4]>=SsVI)
            VI_Melded_Stats[4]+=VI_type[4]*40+VI_type_39[4]*39+(SsVI-VI_type[4]-VI_type_39[4])*38;
        else if(VI_type[4]+VI_type_39[4]+VI_type_38[4]+VI_type_37[4]>=SsVI)
            VI_Melded_Stats[4]+=VI_type[4]*40+VI_type_39[4]*39+VI_type_38[4]*38+(SsVI-VI_type[4]-VI_type_39[4]+VI_type_38[4])*37;
        else if(VI_type[4]+VI_type_39[4]+VI_type_38[4]+VI_type_37[4]+VI_type_36[4]>=SsVI)
            VI_Melded_Stats[4]+=VI_type[4]*40+VI_type_39[4]*39+VI_type_38[4]*38+VI_type_37[4]*37+(SsVI-VI_type[4]-VI_type_39[4]+VI_type_38[4]-VI_type_37[4])*36;
        else if(VI_type[4]+VI_type_39[4]+VI_type_38[4]+VI_type_37[4]+VI_type_36[4]+VI_type_35[4]>=SsVI)
            VI_Melded_Stats[4]+=VI_type[4]*40+VI_type_39[4]*39+VI_type_38[4]*38+VI_type_37[4]*37+VI_type_36[4]*36+(SsVI-VI_type[4]-VI_type_39[4]+VI_type_38[4]-VI_type_37[4]-VI_type_36[4])*35;
        else
            cout<<"Ss meld error\n";
        
        //is ss too >
        for(int TenVI=0;TenVI<=VI_type[3]+VI_type_39[3]+VI_type_38[3]+VI_type_36[3]+VI_type_35[3]-SsVI;TenVI++)
        {
            VI_Melded_Stats[3]=0;
            if(VI_type[3]>=TenVI)
                VI_Melded_Stats[3]+=TenVI*40;
            else if(VI_type[3]+VI_type_39[3]>=TenVI)
                VI_Melded_Stats[3]+=VI_type[3]*40+(TenVI-VI_type[3])*39;
            else if(VI_type[3]+VI_type_39[3]+VI_type_38[3]>=TenVI)
                VI_Melded_Stats[3]+=VI_type[3]*40+VI_type_39[3]*39+(TenVI-VI_type[3]-VI_type_39[3])*38;
            else if(VI_type[3]+VI_type_39[3]+VI_type_38[3]+VI_type_37[3]>=TenVI)
                VI_Melded_Stats[3]+=VI_type[3]*40+VI_type_39[3]*39+VI_type_38[3]*38+(TenVI-VI_type[3]-VI_type_39[3]+VI_type_38[3])*37;
            else if(VI_type[3]+VI_type_39[3]+VI_type_38[3]+VI_type_37[3]+VI_type_36[3]>=TenVI)
                VI_Melded_Stats[3]+=VI_type[3]*40+VI_type_39[3]*39+VI_type_38[3]*38+VI_type_37[3]*37+(TenVI-VI_type[3]-VI_type_39[3]+VI_type_38[3]-VI_type_37[3])*36;
            else if(VI_type[3]+VI_type_39[3]+VI_type_38[3]+VI_type_37[3]+VI_type_36[3]+VI_type_35[3]>=TenVI)
                VI_Melded_Stats[3]+=VI_type[3]*40+VI_type_39[3]*39+VI_type_38[3]*38+VI_type_37[3]*37+VI_type_36[3]*36+(TenVI-VI_type[3]-VI_type_39[3]+VI_type_38[3]-VI_type_37[3]-VI_type_36[3])*35;
            else
                cout<<"Ten/piety meld error\n";
            int CritVI_min=max(VI_meld_limits[0][1]-(SsVI+TenVI),0);//deals with some issues where a gear set need 3 types of materia to acualy meld
            for(int CritVI=CritVI_min;CritVI<=VI_type[2]+VI_type_39[2]+VI_type_38[2]+VI_type_36[2]+VI_type_35[2]-SsVI-TenVI;CritVI++)
            {
                VI_Melded_Stats[2]=0;
                if(VI_type[2]>=CritVI)
                    VI_Melded_Stats[2]+=CritVI*40;
                else if(VI_type[2]+VI_type_39[2]>=CritVI)
                    VI_Melded_Stats[2]+=VI_type[2]*40+(CritVI-VI_type[2])*39;
                else if(VI_type[2]+VI_type_39[2]+VI_type_38[2]>=CritVI)
                    VI_Melded_Stats[2]+=VI_type[2]*40+VI_type_39[2]*39+(CritVI-VI_type[2]-VI_type_39[2])*38;
                else if(VI_type[2]+VI_type_39[2]+VI_type_38[2]+VI_type_37[2]>=CritVI)
                    VI_Melded_Stats[2]+=VI_type[2]*40+VI_type_39[2]*39+VI_type_38[2]*38+(CritVI-VI_type[2]-VI_type_39[2]+VI_type_38[2])*37;
                else if(VI_type[2]+VI_type_39[2]+VI_type_38[2]+VI_type_37[2]+VI_type_36[2]>=CritVI)
                    VI_Melded_Stats[2]+=VI_type[2]*40+VI_type_39[2]*39+VI_type_38[2]*38+VI_type_37[2]*37+(CritVI-VI_type[2]-VI_type_39[2]+VI_type_38[2]-VI_type_37[2])*36;
                else if(VI_type[2]+VI_type_39[2]+VI_type_38[2]+VI_type_37[2]+VI_type_36[2]+VI_type_35[2]>=CritVI)
                    VI_Melded_Stats[2]+=VI_type[2]*40+VI_type_39[2]*39+VI_type_38[2]*38+VI_type_37[2]*37+VI_type_36[2]*36+(CritVI-VI_type[2]-VI_type_39[2]+VI_type_38[2]-VI_type_37[2]-VI_type_36[2])*35;
                else
                    cout<<"crit meld error\n";
                
                int DetVI_Min=max((VI_meld_limits[1][1]-SsVI-TenVI-CritVI),0);//deals with issues when items ban 2 meld types in 1 slot
                for(int DetVI=DetVI_Min;DetVI<=VI_type[0]+VI_type_39[0]+VI_type_38[0]+VI_type_36[0]+VI_type_35[0]-SsVI-TenVI-CritVI;DetVI++)
                {
                    int DHVI=VI_melds-DetVI-TenVI-CritVI-SsVI;
                    if(DHVI>=0 &&DHVI<=VI_type[1]+VI_type_39[1]+VI_type_38[1]+VI_type_36[1]+VI_type_35[1])
                    {
                        VI_Melded_Stats[0]=0;
                        if(VI_type[0]>=DetVI)
                            VI_Melded_Stats[0]+=DetVI*40;
                        else if(VI_type[0]+VI_type_39[0]>=DetVI)
                            VI_Melded_Stats[0]+=VI_type[0]*40+(DetVI-VI_type[0])*39;
                        else if(VI_type[0]+VI_type_39[0]+VI_type_38[0]>=DetVI)
                            VI_Melded_Stats[0]+=VI_type[0]*40+VI_type_39[0]*39+(DetVI-VI_type[0]-VI_type_39[0])*38;
                        else if(VI_type[0]+VI_type_39[0]+VI_type_38[0]+VI_type_37[0]>=DetVI)
                            VI_Melded_Stats[0]+=VI_type[0]*40+VI_type_39[0]*39+VI_type_38[0]*38+(DetVI-VI_type[0]-VI_type_39[0]+VI_type_38[0])*37;
                        else if(VI_type[0]+VI_type_39[0]+VI_type_38[0]+VI_type_37[0]+VI_type_36[0]>=DetVI)
                            VI_Melded_Stats[0]+=VI_type[0]*40+VI_type_39[0]*39+VI_type_38[0]*38+VI_type_37[0]*37+(DetVI-VI_type[0]-VI_type_39[0]+VI_type_38[0]-VI_type_37[0])*36;
                        else if(VI_type[0]+VI_type_39[0]+VI_type_38[0]+VI_type_37[0]+VI_type_36[0]+VI_type_35[0]>=DetVI)
                            VI_Melded_Stats[0]+=VI_type[0]*40+VI_type_39[0]*39+VI_type_38[0]*38+VI_type_37[0]*37+VI_type_36[0]*36+(DetVI-VI_type[0]-VI_type_39[0]+VI_type_38[0]-VI_type_37[0]-VI_type_36[0])*35;
                        else
                            cout<<"Det meld error\n";
                        
                        VI_Melded_Stats[1]=0;
                        if(VI_type[1]>=DHVI)
                            VI_Melded_Stats[1]+=DHVI*40;
                        else if(VI_type[1]+VI_type_39[1]>=DHVI)
                            VI_Melded_Stats[1]+=VI_type[1]*40+(DHVI-VI_type[1])*39;
                        else if(VI_type[1]+VI_type_39[1]+VI_type_38[1]>=DHVI)
                            VI_Melded_Stats[1]+=VI_type[1]*40+VI_type_39[1]*39+(DHVI-VI_type[1]-VI_type_39[1])*38;
                        else if(VI_type[1]+VI_type_39[1]+VI_type_38[1]+VI_type_37[1]>=DHVI)
                            VI_Melded_Stats[1]+=VI_type[1]*40+VI_type_39[1]*39+VI_type_38[1]*38+(DHVI-VI_type[1]-VI_type_39[1]+VI_type_38[1])*37;
                        else if(VI_type[1]+VI_type_39[1]+VI_type_38[1]+VI_type_37[1]+VI_type_36[1]>=DHVI)
                            VI_Melded_Stats[1]+=VI_type[1]*40+VI_type_39[1]*39+VI_type_38[1]*38+VI_type_37[1]*37+(DHVI-VI_type[1]-VI_type_39[1]+VI_type_38[1]-VI_type_37[1])*36;
                        else if(VI_type[1]+VI_type_39[1]+VI_type_38[1]+VI_type_37[1]+VI_type_36[1]+VI_type_35[1]>=DHVI)
                            VI_Melded_Stats[1]+=VI_type[1]*40+VI_type_39[1]*39+VI_type_38[1]*38+VI_type_37[1]*37+VI_type_36[1]*36+(DHVI-VI_type[1]-VI_type_39[1]+VI_type_38[1]-VI_type_37[1]-VI_type_36[1])*35;
                        else
                            cout<<"DH meld error\n";
                        
                        
                        
                        if(DHVI<=(VI_type[1]+VI_type_39[1]+VI_type_38[1]+VI_type_36[1]+VI_type_35[1])&&VI_melds==DHVI+DetVI+TenVI+CritVI+SsVI)
                        {
                            for(int SsV=0;SsV<=V_type[4]+V_type_11[4]+V_type_10[4]+V_type_9[4];SsV++)
                            {
                                V_Melded_Stats[4]=0;
                                if(V_type[4]>=SsV)
                                    V_Melded_Stats[4]+=SsV*12;
                                else if(V_type[4]+V_type_11[4]>=SsV)
                                    V_Melded_Stats[4]+=V_type[4]*12+(SsV-V_type[4])*11;
                                else if(V_type[4]+V_type_11[4]+V_type_10[4]>=SsV)
                                    V_Melded_Stats[4]+=V_type[4]*12+V_type_11[4]*11+(SsV-V_type[4]-V_type_11[4])*10;
                                else if(V_type[4]+V_type_11[4]+V_type_10[4]+V_type_9[4]>=SsV)
                                    V_Melded_Stats[4]+=V_type[4]*12+V_type_11[4]*11+V_type_10[4]*10+(SsV-V_type[4]-V_type_11[4]+V_type_10[4])*9;
                                else
                                    cout<<"SsV meld error\n";
                                //check ss
                                for(int TenV=0;TenV<=V_type[3]+V_type_11[3]+V_type_10[3]+V_type_9[3]-SsV;TenV++)
                                {
                                    V_Melded_Stats[3]=0;
                                    if(V_type[3]>=TenV)
                                        V_Melded_Stats[3]+=TenV*12;
                                    else if(V_type[3]+V_type_11[3]>=TenV)
                                        V_Melded_Stats[3]+=V_type[3]*12+(TenV-V_type[3])*11;
                                    else if(V_type[3]+V_type_11[3]+V_type_10[3]>=TenV)
                                        V_Melded_Stats[3]+=V_type[3]*12+V_type_11[3]*11+(TenV-V_type[3]-V_type_11[3])*10;
                                    else if(V_type[3]+V_type_11[3]+V_type_10[3]+V_type_9[3]>=TenV)
                                        V_Melded_Stats[3]+=V_type[3]*12+V_type_11[3]*11+V_type_10[3]*10+(TenV-V_type[3]-V_type_11[3]+V_type_10[3])*9;
                                    else
                                        cout<<"TenV meld error\n";
                                    //check pie
                                    int CritV_min=max(V_meld_limits[0][1]-(SsV+TenV),0);//to avoid issues with lack of meld options
                                    for(int CritV=CritV_min;CritV<=V_type[2]+V_type_11[2]+V_type_10[2]+V_type_9[2]-SsV-TenV;CritV++)
                                    {
                                        V_Melded_Stats[2]=0;
                                        if(V_type[2]>=CritV)
                                            V_Melded_Stats[2]+=CritV*12;
                                        else if(V_type[2]+V_type_11[2]>=CritV)
                                            V_Melded_Stats[2]+=V_type[2]*12+(CritV-V_type[2])*11;
                                        else if(V_type[2]+V_type_11[2]+V_type_10[2]>=CritV)
                                            V_Melded_Stats[2]+=V_type[2]*12+V_type_11[2]*11+(CritV-V_type[2]-V_type_11[2])*10;
                                        else if(V_type[2]+V_type_11[2]+V_type_10[2]+V_type_9[2]>=CritV)
                                            V_Melded_Stats[2]+=V_type[2]*12+V_type_11[2]*11+V_type_10[2]*10+(CritV-V_type[2]-V_type_11[2]+V_type_10[2])*9;
                                        else
                                            cout<<"CritV meld error\n";
                                        
                                        int DetV_Min=max((V_meld_limits[1][1]-SsV-TenV-CritV),0);//wierd meld fix
                                        for(int DetV=DetV_Min;DetV<=V_type[0]+V_type_11[0]+V_type_10[0]+V_type_9[0]-SsV-TenV-CritV;DetV++)
                                        {
                                            int DHV=V_melds-DetV-TenV-CritV-SsV;
                                            if(DHV<=(V_type[1]+V_type_11[1]+V_type_10[1]+V_type_9[1])&&V_melds==DHV+DetV+TenV+CritV+SsV)
                                            {//find stat total
                                                
                                                V_Melded_Stats[0]=0;
                                                if(V_type[0]>=DetV)
                                                    V_Melded_Stats[0]+=DetV*12;
                                                else if(V_type[0]+V_type_11[0]>=DetV)
                                                    V_Melded_Stats[0]+=V_type[0]*12+(DetV-V_type[0])*11;
                                                else if(V_type[0]+V_type_11[0]+V_type_10[0]>=DetV)
                                                    V_Melded_Stats[0]+=V_type[0]*12+V_type_11[0]*11+(DetV-V_type[0]-V_type_11[0])*10;
                                                else if(V_type[0]+V_type_11[0]+V_type_10[0]+V_type_9[0]>=DetV)
                                                    V_Melded_Stats[0]+=V_type[0]*12+V_type_11[0]*11+V_type_10[0]*10+(DetV-V_type[0]-V_type_11[0]+V_type_10[0])*9;
                                                else
                                                    cout<<"DetV meld error\n";
                                                
                                                V_Melded_Stats[1]=0;
                                                if(V_type[1]>=DHV)
                                                    V_Melded_Stats[1]+=DHV*12;
                                                else if(V_type[1]+V_type_11[1]>=DHV)
                                                    V_Melded_Stats[1]+=V_type[1]*12+(DHV-V_type[1])*11;
                                                else if(V_type[1]+V_type_11[1]+V_type_10[1]>=DHV)
                                                    V_Melded_Stats[1]+=V_type[1]*12+V_type_11[1]*11+(DHV-V_type[1]-V_type_11[1])*10;
                                                else if(V_type[1]+V_type_11[1]+V_type_10[1]+V_type_9[1]>=DHV)
                                                    V_Melded_Stats[1]+=V_type[1]*12+V_type_11[1]*11+V_type_10[1]*10+(DHV-V_type[1]-V_type_11[1]+V_type_10[1])*9;
                                                else
                                                    cout<<"DHV meld error\n";
                                               
                                                cout<<"at endmeld\n";
                                                
                                                //food
                                                //rank damage and save;
                                                
                                            }
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    /*int V_type[5]={0,0,0,0,0};
    int V_type_11[5]={0,0,0,0,0};
    int V_type_10[5]={0,0,0,0,0};
    int V_type_9[5]={0,0,0,0,0};
    int VI_type[5]={0,0,0,0,0};
    int VI_type_39[5]={0,0,0,0,0};
    int VI_type_38[5]={0,0,0,0,0};
    int VI_type_37[5]={0,0,0,0,0};
    int VI_type_36[5]={0,0,0,0,0};
    int VI_type_35[5]={0,0,0,0,0};
    
    int V_melds=0;
    int VI_melds=0;*/
};

