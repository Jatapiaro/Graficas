//
//  cBerylliumAtom.cpp
//  Atoms
//
//  Created by Jacobo Tapia on 11/02/17.
//  Copyright © 2017 Jacobo Tapia. All rights reserved.
//

#include "cBerylliumAtom.h"
#include <math.h>

BerylliumAtom::BerylliumAtom(){
    for(int i=0;i<4;i++){
        this->electrons[i] = new ProtoElectron(2);
    }
    
    for(int i = 0; i < 360; i ++){
        float angle;
        angle = 0.0174533f * (float)i;
        float cos = cosf(angle);
        float sin = -sinf(angle);
        float x = 1.0 * cos;
        float y = 1.0 * sin;
        float x2 = 1.2 * cos;
        float y2 = 1.2 * sin;
        this->pointsR1[i] = new Point(x,y);
        this->pointsR2[i] = new Point(x2,y2);
    }
    
    this->core = new Core();

    this->angle = 0.0f;
    
    this->i = 0;
    this->j =180;
}
BerylliumAtom::~BerylliumAtom(){}

void BerylliumAtom::draw(int type){
    glPushMatrix();
    {
        
        glPushMatrix();
        {
            glRotatef(angle*0.0174533f, 5.0f, 1.0f, 5.0f);
            this->core->draw(type);
        }
        glPopMatrix();
        
        this->angle+=60.0f;
        
        glPushMatrix();
        {
            if(this->i==360){
                i=0;
            }
            
            glTranslatef(0.0f, this->pointsR1[i]->x, this->pointsR1[i]->y);
            this->electrons[0]->draw(type);
            glTranslatef(this->pointsR2[i]->y,0.0f,this->pointsR2[i]->x);
            this->electrons[2]->draw(type);
        }
        glPopMatrix();
        
        
        i++;
        
        glPushMatrix();
        {
            if(this->j==360){
                j=0;
            }
            glTranslatef(0.0f, this->pointsR1[j]->x, this->pointsR1[j]->y);
            this->electrons[1]->draw(type);
            glTranslatef(this->pointsR2[j]->y,0.0f,this->pointsR2[j]->x);
            this->electrons[3]->draw(type);
            j++;
        }
        glPopMatrix();
        
        
    }
    glPopMatrix();
    

}

