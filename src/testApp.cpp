#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    myfont.loadFont("Menlo-Regular.ttf", 10, 0);
    ofBackground(0, 0, 0);
    sniff.setup();
    
    sound.setup();
    sound.soundStream.setup(this, 2, 0, sound.sampleRate, 512, 4);
}

//-------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    myfont.drawString("Sonifier v0.1", 20, 20);
    myfont.drawString("LOM instruments", 20, 40);
    
    count++;
    if (count == 400) {
        sniff.get_packet();
        count = 0;
    }
    
    if (sniff.header.len > 0) {
        for (int i = 0; i < sniff.elems.size(); i++) {
            myfont.drawString(sniff.elems[i], 20, 80+i*15);
        }
    }
}

void testApp::exit() {
    pcap_close(sniff.descr);
}

void testApp::audioOut(float * output, int bufferSize, int nChannels){
	//pan = 0.5f;
	float leftScale = 1 - sound.pan;
	float rightScale = sound.pan;
    sound.volume = 0.0;
    for (int i = 0; i < bufferSize; i++){
        sound.lAudio[i] = output[i*nChannels    ] = getwifi() * sound.volume * leftScale;
        sound.rAudio[i] = output[i*nChannels + 1] = ofRandom(0, 1) * sound.volume * rightScale;
    }
}

float testApp::getwifi() {
    if (n == 100) n = 0;
    return ofMap((float)sniff.content[n++], 0.0, 255.0, 0.0, 1.0);

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if( key == 's' ){
		sound.soundStream.start();
	}
	
	if( key == 'e' ){
		sound.soundStream.stop();
	}
     

}
//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    ofToggleFullscreen();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}