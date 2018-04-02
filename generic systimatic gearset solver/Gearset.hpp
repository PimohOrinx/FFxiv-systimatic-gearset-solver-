//
//  Gearset.hpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-03-28.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#ifndef Gearset_hpp
#define Gearset_hpp

#include <stdio.h>
#include <vector>
#include "gear.hpp"
using namespace std;

class Gearset
{
private:
    vector<gear> head;
    vector<gear> body;
    vector<gear> hands;
    vector<gear> waist;
    vector<gear> legs;
    vector<gear> feet;
    vector<gear> ear;
    vector<gear> neck;
    vector<gear> brace;
    vector<gear> ring;
    vector<gear> arm;
    vector<gear> sheild;
    void Meld();
    void stat_totals();
public:
    void importgear(int job, string file);
    void solve();
    
    
};

#endif /* Gearset_hpp */
