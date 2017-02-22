/*
* WRITE YOUR NAME/ID HERE
*/

#include "cDroid.h"
#include "cCylinder.h"
#include "cCube.h"
#include <math.h>

Droid::Droid()
{

    head = new Sphere(0.25f,25,20,0.0f,0.0f,1.0f);
    body = new Cylinder(0.25f,0.25f,0.65f,25,25,1.0f,1.0f,1.0f);
    trompa = new Cube(1.0f,1.0f,0.0f,0.0f);
    
    leftArm = new Cube(1.0f,0.8f,0.8f,0.8f);
    leftLittleArm = new Cube(1.0f,1.0f,1.0f,1.0f);
    
    rightArm = new Cube(1.0f,0.8f,0.8f,0.8f);
    rightLittleArm = new Cube(1.0f,1.0f,1.0f,1.0f);
    
    centerArm = new Cube(1.0f,0.8f,0.8f,0.8f);
    centerLittleArm = new Cube(1.0f,0.8f,0.8f,0.8f);
    
    headRotation = shoulderRotation = movementFloat = 0.0f;
    left = shoulder = movement = true;
}

Droid::~Droid(){}

void Droid::draw(){
    
    //glRotatef(headRotation, 0.0f, 1.0f, 0.0f);
    glPushMatrix();
    {
        
        glPushMatrix();
        {
            
            
            glTranslatef(movementFloat, 0.0, 0.0);
            
            glRotatef(shoulderRotation,0.0, 0.0, 1.0f);
            
            
            glRotatef(headRotation, 0.0f, 1.0f, 0.0f);
            /*
             *Tras 1
             */
            glTranslatef(0.0f, 0.75f, 0.0f);
            
            

            
            head -> draw();
            /*
             * Ahora la siguiente traslación toma
             * a Tras1 como el origen
             */
            glTranslatef(0.0f, 0.0f, 0.25f);
            glScalef(0.10, 0.05, 0.10);
            
            
            
            trompa -> draw();
            
            

        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glRotatef(90, -1.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.0f, 0.10f);
            
            glTranslatef(movementFloat/1.2, 0.0, 0.0);
            
            glRotatef(shoulderRotation,0.0, -1.0, 0.0f);
            
            body -> draw();
        }
        glPopMatrix();
        
        
        /*
         * Left Arm
         */
        
        glPushMatrix();
        {
            glRotatef(shoulderRotation,0.0, 0.0, -1.0f);
            glTranslatef(0.0f, 0.35f, 0.30f);
            glScalef(0.10, 0.60, 0.10);
            leftArm -> draw();
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(0.0f, 0.0f, 0.30f);
            glScalef(0.20f, 0.10f, 0.15f);
            leftLittleArm -> draw();
        }
        glPopMatrix();
        
        /*
         * Left Arm
         */
        
        /*
         * Right Arm
         */
        
        glPushMatrix();
        {
            glRotatef(shoulderRotation,0.0, 0.0, -1.0f);
            glTranslatef(0.0f, 0.35f, -0.30f);
            glScalef(0.10, 0.60, 0.10);
            rightArm -> draw();
            
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(0.0f, 0.0f, -0.30f);
            glScalef(0.20f, 0.10f, 0.15f);
            rightLittleArm -> draw();
        }
        glPopMatrix();
        
        /*
         * Right Arm
         */
        
        
        
        
        /*
         * Center Arm
         */
        
        glPushMatrix();
        {
            
            glTranslatef(movementFloat/1.2, 0.1, 0.0);
            
            glRotatef(shoulderRotation,0.0, 0.0, 1.0f);
            
            glScalef(0.10, 0.10, 0.10);
            
            centerArm -> draw();
            
        }
        glPopMatrix();
        
        glPushMatrix();
        {
            glTranslatef(movementFloat/1.2, 0.0, 0.0);
            glScalef(0.20f, 0.10f, 0.15f);
            centerLittleArm -> draw();
        }
        glPopMatrix();
        
        /*
         * Center Arm
         */
        
    }
    glPopMatrix();
    
}

void Droid::update(){
    if(left){
        if(this->headRotation<180.0f){
            headRotation++;
        }else{
            left = false;
        }
    }else{
        if(this->headRotation>0){
            headRotation--;
        }else{
            left = true;
        }
    }
    
    if(shoulder){
        if(this->shoulderRotation<45.0f){
            shoulderRotation+=0.40;
        }else{
            shoulder = false;
        }
    }else{
        if(this->shoulderRotation>0){
            shoulderRotation-=0.40;
        }else{
            shoulder = true;
        }
    }
    
    if(movement){
        if(movementFloat>0){
            movementFloat-=0.0045;
        }else{
            movement = false;
            shoulderRotation = 0;
        }
    }else{
        if(movementFloat<=0.5f){
            movementFloat+=0.0045;
        }else{
            movement = true;
        }
    }
}
