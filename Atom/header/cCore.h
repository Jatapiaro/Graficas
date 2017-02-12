//
//  cCore.h
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

#include "cProtoElectron.h"

class Core{
    public:
        Core();
        ~Core();
        void draw(int type);
        ProtoElectron *neutrons[5],*protons[4];
        float angle;
};
