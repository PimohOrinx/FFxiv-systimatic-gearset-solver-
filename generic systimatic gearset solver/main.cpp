//
//  main.cpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-03-27.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "math.h"
#include "Gearset.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    //user modifiyable variables read from config file//
    //0PLD,1MNK,2WAR,3DRG,4BRD,5WHM,6BLM,7SMN,8SCH,9NIN,10MCH,11DRK,12AST,13SAM,14RDM
    int job=8;
    bool brd_in_party=0;
    bool sch_in_party=0;
    bool drg_in_party=0;
    
    bool Savage_gear=0;
    bool Tome_gear=1;
    bool Eureka_gear=0;
    bool Crafted_accesories=0;
    
    bool food=1;
    
    bool DH_on_healer=0;
    
    int min_Ss=364;
    int max_SS=3000;
    
    int min_piety=292;
    int max_piety=3000;
    
    //end of user custimization//
    //grab gear from file
    Gearset gear;
    if(Savage_gear==1)
        gear.importgear(job, "SavageGear.csv");
    if(Tome_gear==1)
        gear.importgear(job, "TomeGear.csv");
    if(Eureka_gear==1)
        gear.importgear(job, "EurekaGear.csv");
    if(Crafted_accesories==1)
        gear.importgear(job, "CraftedGear.csv");
    
    //make gearsets
    gear.solve(brd_in_party,sch_in_party,drg_in_party);
    //
    
    //read setup stuff eve
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
