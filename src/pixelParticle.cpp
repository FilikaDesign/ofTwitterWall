#include "pixelParticle.h"

//------------------------------------------------------------------
pixelParticle::pixelParticle(int x, int y, ofColor clr){
	
    pos.x = x - 100;
	pos.y = y - 100;
    
    
    init.x = x - 100;
    init.y = y - 100;
    
    vel.x = ofRandom(-1, 1);
	vel.y = ofRandom(-1, 1);
    
    
}


void pixelParticle::draw(){
    
    ofSetColor(160,160,160, 180);
    
    ofCircle(pos.x,pos.y,pos.z,1);
    
    ofSetColor(ofColor(150,255,150,240));
    
    ofCircle(init.x,init.y,1);
    
}

void pixelParticle::update(){
    
    
    pos += vel;
    
    
    if( pos.x > ofGetWidth() *0.2 ){
		pos.x = ofGetWidth() *0.2;
		vel.x *= -1.0;
        pos.z = ofRandom(-50, 50);
	}else if( pos.x < -1 * ofGetWidth() * 0.2 ){
		pos.x = -1 * ofGetWidth() * 0.2;
		vel.x *= -1.0;
	}
	if( pos.y > ofGetHeight() *0.1){
		pos.y = ofGetHeight() *0.1;
		vel.y *= -1.0;
        pos.z = ofRandom(-50, 50);
	}
	else if( pos.y < -1 * ofGetHeight() * 0.1){
		pos.y = -1 * ofGetHeight() * 0.1;
		vel.y *= -1.0;
	}
    
   
    
}
