#pragma once
#include "ofMain.h"


class pixelParticle{
    
public:
    
    pixelParticle(int x, int y, ofColor cl);
    
    
    void draw();
    void update();
    ofPoint pos;
    ofPoint vel;
    ofPoint init;
    ofPoint frc;
};