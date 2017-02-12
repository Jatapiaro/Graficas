//
//  cBerylliumAtom.h
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

#include "cCore.h"
#include "cPoint.h"

class BerylliumAtom
{
    public:
        BerylliumAtom();
        ~BerylliumAtom();
        void draw(int type);
        ProtoElectron *electrons[4];
        Core *core;
        Point *pointsR1[360],*pointsR2[360];
        float angle;
        int i,j;
};

