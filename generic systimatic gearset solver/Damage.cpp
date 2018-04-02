//
//  Damage.cpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-04-01.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#include "Damage.hpp"

int Damage::finddamage(int brd,int sch, int drg,int wd, int Mainstat, int det, int dh, int crit, int ten, int ss)
{
    WD=wd;
    AP_tier=(100+(Mainstat-292)*1000/(2336));
    Det_tier=130*(det)/2170;
    DH_tier=550*(dh)/2170;
    Crit_tier=200*(crit)/2170;
    Ten_tier=100*(ten)/2170;
    Ss_tier=130*(ss)/2170;
    
    //damage with crit/dh buff uptime
    return
    damageformula(1000,brd*150,brd*20+drg*150+sch*150)*15/360+//bl+bv+ch
    damageformula(1000,brd*150,brd*20+drg*150)*5/360+//bl+bv
    damageformula(1000,brd*150,brd*20+sch*150)*30/360+//bv+ch
    damageformula(1000,0,brd*20+drg*150)*20/360+//bl
    damageformula(1000,0,brd*20)*290/360;
};

int Damage::damageformula(int potency,int DH_rate_buff,int Crit_rate_buff)
{
    int damage=potency*WD*AP_tier;
    damage=damage*(1000+Det_tier)/1000;
    damage=damage*(1000+Ten_tier)/1000;
    damage=damage*(1000+Ss_tier)/1000;
    damage=damage/100;//div potcey by 100
    
    int CritDamage=damage*(1400+Crit_tier)/1000;
    int DHDamage=damage*1250/1000;
    int CritDHDamage=CritDamage*1250/1000;
    
    float CritRate=float(Crit_tier+50+Crit_rate_buff)/1000;
    float DHRate=float(DH_tier+DH_rate_buff)/1000;
    float CritDHRate=CritRate*DHRate;
    float BaseRate=1-CritRate-DHRate+CritDHRate;
    
    return damage*BaseRate+CritDamage*(CritRate-CritDHRate)+DHDamage*(DHRate-CritDHRate)+CritDHDamage*CritDHRate;//include crit and dh damage buffs
}