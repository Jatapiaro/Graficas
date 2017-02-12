//
//  cProtoElectron.cpp
//  Atoms
//
//  Created by Jacobo Tapia on 11/02/17.
//  Copyright © 2017 Jacobo Tapia. All rights reserved.
//

#include "cProtoElectron.h"

ProtoElectron::ProtoElectron(int protonOrElectron)
{
    this->protonOrElectron = protonOrElectron;
    if(protonOrElectron==0){
        /*
         *Defines purple for protons
         */
        this->r = 1;
        this->g = 1;
        this->b = 0;
    }else if(protonOrElectron==1){
        /*
         *Defines green for neutrons
         */
        this->r = 0;
        this->g = 1;
        this->b = 0;
    }else{
        /*
         *Defines blue for electron
         */
        this->r = 0;
        this->g = 1;
        this->b = 1;
    }
}

ProtoElectron::~ProtoElectron(){}


void ProtoElectron::draw(int type)
{
    glPushMatrix();
    {
        if(this->protonOrElectron != 2){
            glScalef(0.25, 0.25, 0.25);
        }else{
            glScalef(0.125, 0.125, 0.125);
        }
        
        glColor3d(r,g,b);
        
        if(type == 1){
            glutSolidSphere(1, 20, 20);
        }else{
            glutWireSphere(1, 20, 20);
        }
    }
    glPopMatrix();
}

