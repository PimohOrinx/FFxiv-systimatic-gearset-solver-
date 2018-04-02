//
//  Gearset.cpp
//  generic systimatic gearset solver
//
//  Created by Pimoh Orinx on 2018-03-28.
//  Copyright © 2018 Pimoh Orinx. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "math.h"
#include "Gearset.hpp"
#include "loadout.hpp"
#include "gear.hpp"
using namespace std;

void Gearset::importgear(int job, string file)
{
    Job=job;
    string line;
    ifstream ImportGear (file);
    if (ImportGear.is_open())
    {
        getline (ImportGear,line);
        while ( getline (ImportGear,line) )//sort gear into types and find important info
        {
            gear tempgear;//det,crit,ss,pie,dh
            tempgear.gearimport(line);
            if(tempgear.gearjob(Job))//checks to see if the gear is for the correct job
            {
                if (tempgear.gearslot()==3)
                    head.push_back(tempgear);
                else if (tempgear.gearslot()==4)
                    body.push_back(tempgear);
                else if (tempgear.gearslot()==5)
                    hands.push_back(tempgear);
                else if (tempgear.gearslot()==6)
                    waist.push_back(tempgear);
                else if (tempgear.gearslot()==7)
                    legs.push_back(tempgear);
                else if (tempgear.gearslot()==8)
                    feet.push_back(tempgear);
                else if (tempgear.gearslot()==9)
                    ear.push_back(tempgear);
                else if (tempgear.gearslot()==10)
                    neck.push_back(tempgear);
                else if (tempgear.gearslot()==11)
                    brace.push_back(tempgear);
                else if (tempgear.gearslot()==12)
                    ring.push_back(tempgear);
                else if (tempgear.gearslot()==13)
                    arm.push_back(tempgear);
                else if (tempgear.gearslot()==2)
                    sheild.push_back(tempgear);
            }
        }
        ImportGear.close();
    }
};

void Gearset::solve(int brd,int sch, int drg)
{
    if(Job!=0)
    {
        gear tempgear;//gives non pld a none sheild
        tempgear.gearimport("no shield,n/a,-1,MNK WAR DRG BRD WHM BLM SMN SCH NIN MCH DRK AST SAM RDM,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
        sheild.push_back(tempgear);
    }
    
    //ugly nested for loops to itterate though all gear combos
    for(vector<gear>::iterator it_ring1=ring.begin();it_ring1!=ring.end();it_ring1++)
    {
        for(vector<gear>::iterator it_ring2=ring.begin();it_ring2!=ring.end();it_ring2++)
        {
            if(it_ring1->gear_ID()!=it_ring1->gear_ID()||it_ring1->gear_unique()!=true)//makes sure that the 2 unique rings of the same type aren't used
            {
                for(vector<gear>::iterator it_head=head.begin();it_head!=head.end();it_head++)
                {
                    for(vector<gear>::iterator it_body=body.begin();it_body!=ring.end();it_body++)
                    {
                        for(vector<gear>::iterator it_hands=hands.begin();it_hands!=hands.end();it_hands++)
                        {
                            for(vector<gear>::iterator it_waist=waist.begin();it_waist!=waist.end();it_waist++)
                            {
                                for(vector<gear>::iterator it_legs=legs.begin();it_legs!=ring.end();it_legs++)
                                {
                                    for(vector<gear>::iterator it_feet=feet.begin();it_feet!=feet.end();it_feet++)
                                    {
                                        for(vector<gear>::iterator it_ear=ear.begin();it_ear!=ear.end();it_ear++)
                                        {
                                            for(vector<gear>::iterator it_neck=neck.begin();it_neck!=neck.end();it_neck++)
                                            {
                                                for(vector<gear>::iterator it_brace=brace.begin();it_brace!=brace.end();it_brace++)
                                                {
                                                    for(vector<gear>::iterator it_arm=arm.begin();it_arm!=arm.end();it_arm++)
                                                    {
                                                        //meld this shit
                                                        
                                                        //some progress stuff
                                                        //if pld
                                                        for(vector<gear>::iterator it_sheild=sheild.begin();it_sheild!=sheild.end();it_sheild++)
                                                        {
                                                            Loadout tempload;
                                                            tempload.Addgear(Job, *it_ring1, *it_ring2, *it_head, *it_body, *it_hands, *it_waist, *it_legs, *it_feet, *it_ear, *it_neck, *it_brace, *it_arm, *it_sheild);
                                                            //some way of saving good results
                                                            int damage=tempload.unmelded_damage(brd,sch,drg);
                                                            //if new damage is close to old damage, 10% atm
                                                            tempload.meld();
                                                            
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
            }
        }
    }
};

void Gearset::stat_totals()
{
    
};


