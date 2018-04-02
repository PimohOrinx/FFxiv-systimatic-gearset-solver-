//
//  Damage.hpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-04-01.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#ifndef Damage_hpp
#define Damage_hpp

#include <stdio.h>

class Damage
{
    int WD;
    int AP_tier;
    int Det_tier;
    int DH_tier;
    int Crit_tier;
    int Ten_tier;
    int Ss_tier;
    
    int damageformula(int potency,int DH_rate_buff,int Crit_rate_buff);
    
    
public:
    int finddamage(int brd,int sch, int drg,int wd, int Mainstat, int det, int dh, int crit, int ten, int ss);
};

#endif /* Damage_hpp */
