//
//  cCore.cpp
//  Atoms
//
//  Created by Jacobo Tapia on 11/02/17.
//  Copyright © 2017 Jacobo Tapia. All rights reserved.
//

#include "cCore.h"

Core::Core(){
    for(int i=0;i<5;i++){
        this->neutrons[i] = new ProtoElectron(1);
    }
    for(int i=0;i<4;i++){
        this->protons[i] = new ProtoElectron(0);
    }
    this->angle = 0.0f;
}

Core::~Core(){}

void Core::draw(int type){
    glPushMatrix();
    {
        for(int i=0;i<5;i++){
            glPushMatrix();
            {
                switch(i){
                    case 0:
                        glTranslatef(0.23f, 0.0f, 0.23f);
                        break;
                    case 1:
                        glTranslatef(-0.23f, 0.0f, 0.23f);
                        break;
                    case 2:
                        glTranslatef(0.0f, -0.40f, 0.30f);
                        break;
                    case 3:
                        glTranslatef(0.23f, 0.0f, -0.23f);
                        break;
                    case 4:
                        glTranslatef(-0.23f, 0.0f, -0.23f);
                        break;
                }
                this->neutrons[i]->draw(type);
            }
            glPopMatrix();
        }
        
        for(int i=0;i<4;i++){
            glPushMatrix();
            {
                switch(i){
                    case 0:
                        glTranslatef(0.0f, -0.40f, -0.15f);
                        break;
                    case 1:
                        glTranslatef(0.0f, 0.25f, 0.0f);
                        break;
                    case 2:
                        glTranslatef(0.40f, -0.25f, 0.0f);
                        break;
                    case 3:
                        glTranslatef(-0.40f, -0.07f, 0.0f);
                        break;
                }
                this->protons[i]->draw(type);
            
            }
            glPopMatrix();
        }
    }
    glPopMatrix();
}



