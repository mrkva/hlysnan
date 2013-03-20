//
//  sound.h
//  wifisonifi
//
//  Created by Jonas Gruska on 19.3.2013.
//
//

#ifndef wifisonifi_sound_h
#define wifisonifi_sound_h

#include "ofMain.h"

class sound {
public:
    ofSoundStream soundStream;
    
    float 	pan;
    int		sampleRate;
    bool 	bNoise;
    float 	volume;
    
    vector <float> lAudio;
    vector <float> rAudio;
    
    //------------------- for the simple sine wave synthesis
    float 	targetFrequency;
    float 	phase;
    float 	phaseAdder;
    float 	phaseAdderTarget;
    
    
    
    void setup() {
        int bufferSize		= 128;
        sampleRate 			= 44100;
        phase 				= 0;
        phaseAdder 			= 0.0f;
        phaseAdderTarget 	= 0.0f;
        volume				= 0.1f;
        bNoise 				= false;
        
        lAudio.assign(bufferSize, 0.0);
        rAudio.assign(bufferSize, 0.0);
        
    }
		
};

#endif
