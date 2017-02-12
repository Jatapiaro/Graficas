//
//  cProtoElectron.h
//  Atoms
//
//  Created by Jacobo Tapia on 11/02/17.
//  Copyright © 2017 Jacobo Tapia. All rights reserved.
//

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else
    #include "freeglut.h"
#endif

class ProtoElectron{
    public:
        ProtoElectron(int protonOrElecton);
        ~ProtoElectron();
        void draw(int type);
    
        /*
         * If var == 0 will draw a electron
         * else it will draw a proton;
         * basically it only chages the color.
         */
        float r,g,b;
        int protonOrElectron;
};
