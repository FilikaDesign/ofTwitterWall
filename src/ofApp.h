#pragma once

#include "ofMain.h"
#include "ofxHttpUtils.h"
#include "ofxFX.h"
#include "pixelParticle.h"
#include "hologramFace.h"
#include <string>
#include <sstream>

#define TEXT_RECT_W 300
#define TEXT_RECT_H 200
#define TEXT_LAYOUT_WIDTH 256


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void exit();
    
    
    void newResponse(ofxHttpResponse & response);
    
    ofxHttpUtils httpUtils;
    int counter;
    string responseStr;
    string requestStr;
    string action_url;

    ofXml XML;
    vector<string> tweets;
    
    
    
    ofFbo textFbo;
    ofPixels fboPixels;
    ofImage fboImage;
    
    ofImage templateImg;
    bool templateVis;
    
    unsigned char 	* colorPixels;
    
    vector <pixelParticle> p;
    vector <ofVec2f> initXY;
    
    void newText();
    string mtxt;
    
    hologramFace h1,h2,h3;
    bool TweetsDownloaded = false;

};
