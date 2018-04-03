//
//  Loadout.hpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-03-29.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#ifndef Loadout_hpp
#define Loadout_hpp

#include <stdio.h>
#include "gear.hpp"
using namespace std;

class Loadout
{
private:
    int job;
    gear Head;
    gear Body;
    gear Hands;
    gear Waist;
    gear Legs;
    gear Feet;
    gear Ear;
    gear Neck;
    gear Brace;
    gear Ring1;
    gear Ring2;
    gear Arm;
    gear Sheild;
    
    int MainStat=0;
    int WeaponDamage=0;
    int gearstats[5]={0,0,0,0,0};
    
    int melds[2][5]={{0,0,0,0,0},{0,0,0,0,0}};
    
    
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
    
    int V_melds=0;
    int VI_melds=0;
    
public:
    void Addgear(int job,gear ring1, gear ring2,gear head,gear body,gear hands,gear waist,gear legs,gear feet,gear ear,gear neck,gear brace,gear arm,gear sheild);
    int unmelded_damage(int brd,int sch, int drg);
    void meld();
    //extra ring1, sheidl2,head3,body4,hands5,waist6,legs7,feet8,ear9,neck10,brace11,ring12,arm13
    
};



#endif /* Loadout_hpp */
