#include "ofApp.h"

template <typename T>
string NumberToString(T pNumber)
{
    ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
	action_url = "http://filikatasarim.com/TwitterWall/broadcasting.php";
	ofAddListener(httpUtils.newResponseEvent,this,&ofApp::newResponse);
	httpUtils.start();
    
    ofxHttpForm form;
	form.action = action_url;
	//form.method = OFX_HTTP_POST;
	httpUtils.addForm(form);
	requestStr = "message sent: " + ofToString(counter);
	counter++;
    
    
	ofBackground(255,255,255);
	ofSetColor(0,0,0);
    
    templateImg.loadImage("sablon.png");
    templateVis = false;
    
    h1.setup();
    h2.setup();
    h3.setup();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    templateImg.update();
    
    h1.update();
    h2.update();
    h3.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0);
    
    if(templateVis){
        ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));
        
    }else{
        ofSetColor(255,255,255,255);
        templateImg.draw(0,0, ofGetWidth(), ofGetHeight());
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.8, 0);
    ofRotateY(ofGetElapsedTimef() * 40.0 - 90);
    h1.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.2, ofGetHeight()*0.3, 0);
    ofRotateZ(90);
    ofRotateY(ofGetElapsedTimef() * 40.0);
    h2.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.8, ofGetHeight()*0.3, 0);
    ofRotateZ(-90);
    ofRotateY(ofGetElapsedTimef() * 40.0 - 180);
    h3.draw();
    ofPopMatrix();
    
    ofSetColor(255,255,255,255);
    
    if(tweets.size() > 0 && !TweetsDownloaded) {
        /*for (int i = 0; i < 3; i++) {
            
        }*/
        h1.newText(tweets[0]);
        h2.newText(tweets[0]);
        h3.newText(tweets[0]);
        TweetsDownloaded = true;
    }
}

void ofApp::newResponse(ofxHttpResponse & response){
    ofRemoveListener(httpUtils.newResponseEvent,this,&ofApp::newResponse);
    
	responseStr = ofToString(response.status) + ": " + (string)response.responseBody;
    
    XML.loadFromBuffer((string)response.responseBody);
    XML.setTo("tweets");
        int num = XML.getNumChildren("tweet");
        //cout << "xml" << num << endl;
        
        //tweets.resize(num);
    
    for (int i = 0; i < num; i++) {
            
        string n = NumberToString(i);
        string s;
            
        s = XML.getValue("tweet["+n+"]/tweet_text");
        //XML.setToParent();
        
        for(int i = 40; i < s.length(); i = i + 50){
            //cout << "i " << i << endl;
            int pos = s.find(' ', i);
            if(pos != string::npos){
                //cout << "true!!!" << endl;
                s.replace(pos, 1, "\n");
            }
        }
        
        tweets.push_back(s);
        //cout << tweets[i] << endl;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == '1'){
		mtxt = tweets[1];
        h1.newText(mtxt);
        h2.newText(mtxt);
        h3.newText(mtxt);
	}
    
    if( key == '2'){
		mtxt = tweets[2];
        h1.newText(mtxt);
        h2.newText(mtxt);
        h3.newText(mtxt);
	}
    
    if( key == 't'){
        templateVis = !templateVis;
    }
    
    if( key == 'f'){
        ofToggleFullscreen();
    }


}
void ofApp::exit() {
    httpUtils.clearQueue();
    httpUtils.stop();
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
