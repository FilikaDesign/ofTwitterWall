//
//  hologramFace.cpp
//  Twitter3DFx
//
//  Created by Selçuk ARTUT on 7/15/14.
//
//

#include "hologramFace.h"

//--------------------------------------------------------------
void hologramFace::setup(){
    
    ofTrueTypeFont::setGlobalDpi(72);
    
	myFont.setup("verdana.ttf");
    
    
    textFbo.allocate(TEXT_RECT_W, TEXT_RECT_H, GL_RGBA);
    fboImage.allocate(TEXT_RECT_W, TEXT_RECT_H, OF_IMAGE_COLOR);
    
    textFbo.begin();
    ofBackground(255, 30, 30, 0);
    ofSetColor(255,255,255,255);
    mtxt = "Germany's victory was a fitting end to \n a hugely successful World Cup in Brazil\n http://econ.st/1oyLet3 #EconBrazil ";
    myFont.drawMultiLine(mtxt, 14,(TEXT_RECT_W - TEXT_LAYOUT_WIDTH) / 2.0 ,80);
    myFont.setLineHeight(lineH);
    textFbo.end();
    textFbo.readToPixels(fboPixels);
    fboImage.setFromPixels(fboPixels);
    fboPixels.clear();
    
    int num = TEXT_RECT_W * TEXT_RECT_H;
    
    int i = 0;
    for(int y = 0; y < fboImage.getHeight(); y++){
		for(int x = 0; x < fboImage.getWidth(); x++){
			
			ofColor color = fboImage.getColor(x, y);
            
            if(color.b > 150){
                
                pixelParticle *mp = new pixelParticle(x, y, color);
                p.push_back(*mp);
                
                ofVec2f *xy = new ofVec2f(x, y);
                initXY.push_back(*xy);
                
            }
            
            i++;
		}
        
	}
}

//--------------------------------------------------------------
void hologramFace::update(){
    
    for(unsigned int i = 0; i < p.size(); i++){
		p[i].update();
	}
    
    templateImg.update();
}

//--------------------------------------------------------------
void hologramFace::draw(){
    
    
    
    if(templateVis){
        ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));
        
    }else{
        ofSetColor(255,255,255,255);
        templateImg.draw(0,0, ofGetWidth(), ofGetHeight());
    }
    
    for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
	}
    
   
    
}

void hologramFace::newText(string mtxt){
    
    p.clear();
    initXY.clear();
    
    textFbo.begin();
    ofBackground(255, 30, 30, 0);
    ofSetColor(255,255,255,255);
    
    myFont.drawMultiLine(mtxt, 14,(TEXT_RECT_W - TEXT_LAYOUT_WIDTH) / 2.0 ,80);
    myFont.setLineHeight(lineH);
    textFbo.end();
    textFbo.readToPixels(fboPixels);
    fboImage.setFromPixels(fboPixels);
    fboPixels.clear();
    
    int num = TEXT_RECT_W * TEXT_RECT_H;
    
    int i = 0;
    for(int y = 0; y < fboImage.getHeight(); y++){
		for(int x = 0; x < fboImage.getWidth(); x++){
			
			ofColor color = fboImage.getColor(x, y);
            
            if(color.b > 150){
                
                pixelParticle *mp = new pixelParticle(x, y, color);
                p.push_back(*mp);
                
            }
            
            i++;
		}
        
	}
    
}