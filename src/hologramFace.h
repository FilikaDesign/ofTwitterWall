//
//  hologramFace.h
//  Twitter3DFx
//
//  Created by Selçuk ARTUT on 7/15/14.
//
//


#pragma once
#include "ofMain.h"
#include "pixelParticle.h"
#include "ofxFontStash.h"

#define TEXT_RECT_W 300
#define TEXT_RECT_H 200
#define TEXT_LAYOUT_WIDTH 256

class hologramFace{
    
public:
    void setup();
    void update();
    void draw();

    // font
    ofxFontStash myFont;
    ofFbo textFbo;
    ofPixels fboPixels;
    ofImage fboImage;

    ofImage templateImg;
    bool templateVis;

    unsigned char 	* colorPixels;

    vector <pixelParticle> p;
    vector <ofVec2f> initXY;

    void newText(string);
    string mtxt;
    
    float lineH = 1.4;

};
