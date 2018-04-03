//
//  gear.hpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-03-28.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#ifndef gear_hpp
#define gear_hpp

#include <stdio.h>
#include <string>
using namespace std;

class gear
{
private:
    ////name,jp name,id number,job,slot,Unique,VI melds,V melds,ilvl,pWD,mWD,main stat,Meld cap,Determination,Critical Hit,Skill Speed,Spell Speed,Piety,Tenacity,Direct Hit Rate
    string name="";
    string jp_name="";
    int ID=0;
    bool job[15]={0};//find job numbers from
    //0PLD,1MNK,2WAR,3DRG,4BRD,5WHM,6BLM,7SMN,8SCH,9NIN,10MCH,11DRK,12AST,13SAM,14RDM
    int slot=0;
    bool unique=0;
    
    int ilvl=0;
    int WD=0;
    int Mainstat=0;
    
    int SubStats[5]={0,0,0,0,0};
    //det,crit,sps/sks,pie/ten,dh
    

    
    int melds[2][5]={{0,0,0,0,0},{0,0,0,0,0}};//VI,V
    
    
public:
    int V_melds=0;
    int VI_melds=0;
    int V_type[5]={0,0,0,0,0};
    int V_type_11[5]={0,0,0,0,0};
    int V_type_10[5]={0,0,0,0,0};
    int V_type_9[5]={0,0,0,0,0};
    int VI_type[5]={0,0,0,0,0};
    int VI_type_39[5]={0,0,0,0,0};
    int VI_type_38[5]={0,0,0,0,0};
    int VI_type_37[5]={0,0,0,0,0};
    int VI_type_36[5]={0,0,0,0,0};
    int VI_type_35[5]={0,0,0,0,0};
    
    int VI_meld_limits[5][5]={0};
    int V_meld_limits[5][5]={0};
    
    void gearimport(string input);
    
    
    int gearslot(void);
    bool gearjob(int job_number);
    int gear_ID(void);
    bool gear_unique(void);
    int gear_mainstat(void);
    int gear_sub_stat(int stat);
};

#endif /* gear_hpp */
