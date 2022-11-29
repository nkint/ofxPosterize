#pragma once

#include "ofMain.h"

#include <iostream>
#include <vector>
//#include <GLUT/GLUT.h>

#include "ofxPosterize.h"


class ofApp : public ofBaseApp{
    
public:
    
	void setup();
	void update();
	void draw();
    
	void keyPressed  (int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
    
  	void dragEvent(ofDragInfo info);
    
private:
    void extractPalette(string filename);
    void writeWebInterface();
    
    ofImage source;
    bool ready;
    
    ofImage drawPalette(map<int, int> histogram, int width, int height);
    
    ofImage average;
    ofImage averagePalette;
    map<int, int> averageHistogram;
    
    ofImage clustered;
    ofImage clusteredPalette;
	map<int, int> clusteredHistogram;
    
};