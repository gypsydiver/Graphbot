//
//  movement.h
//  Graphbot
//
//  Created by Fernando Mendoza on 5/3/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//
//Here we define functions that are required for the correct mapping of the move, rightturn and leftturn commands

#ifndef Graphbot_movement_h
#define Graphbot_movement_h

#include <cmath>
float degreestoRadians(float degrees){
    return PI * degrees/180;
}

void newPosition(float length){
    pointerx = pointerx+length * cos(degreestoRadians(direccionEnGrados));
    pointery = pointery+length * sin(degreestoRadians(direccionEnGrados));
}

int updateAngle(int newToBeAngle){
    return newToBeAngle % 360;
}

#endif
