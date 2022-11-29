#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	cout << "Made with openFrameworks version :" << ofGetVersionInfo();
    cout << "with OpenCV " << CV_VERSION << endl;
    // For this example I added OpenCV library that comes on with official theo ofxOpenCV
    // so the CV_VERSION should be 2.3.1
	
	ofSetVerticalSync(true);
    extractPalette("lena.jpg");
}

void ofApp::extractPalette(string filename) {
    ready = false;
    ready = source.loadImage(filename);
    if(ready) {
        average = ofxPosterize::average(source, 9);
        averageHistogram = ofxPosterize::getHistogram(average);
        averagePalette = drawPalette(averageHistogram, 200, 10);
        
        clustered = ofxPosterize::clusterize(source, 9);
        clusteredHistogram = ofxPosterize::getHistogram(clustered);
        clusteredPalette = drawPalette(clusteredHistogram, 200, 10);
        
        writeWebInterface();
    }
}

void ofApp::writeWebInterface() {
    ofBuffer dataBuffer;
    stringstream ss;
    
    int num_histograms = 2;
    map<int, int> histograms[] = {averageHistogram, clusteredHistogram};
    
    for (int i=0; i<num_histograms; i++) {
        map<int, int> hist = histograms[i];
        ss << "var palette" << i << "= [";
        for(std::map<int,int>::iterator iter = hist.begin(); iter != hist.end(); ++iter)
        {
            int k =  iter->first;
            ofColor c = ofColor::fromHex(k);
            ss << "{ ";
            ss << "r:" << (int)c.r << "," << "g:" << (int)c.g << "," << "b:" << (int)c.b;
            ss << "}, ";
        }
        ss << "];" << endl;
    }
    
    dataBuffer.set(ss);
    bool fileWritten = ofBufferToFile("webinterface/palette.js", dataBuffer);
    
    source.saveImage("webinterface/original.jpg");
    average.saveImage("webinterface/average.jpg");
    clustered.saveImage("webinterface/cluster.jpg");
    
    ss.clear();
    ss.str("");
    ss << "open " +ofToDataPath("webinterface/index.html", true);
    cout << "calling: " << ss.str() << endl;
    std::system(ss.str().c_str());
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------

cv::Scalar ofColor2cvScalar(ofColor c) {
    cv::Scalar s;
    s[0] = c.r;
    s[1] = c.g;
    s[2] = c.b;
    return s;
}

ofImage ofApp::drawPalette(map<int, int> histogram, int width, int height) {
    
    cv::Mat palette = cv::Mat::zeros(height, width, CV_8UC3);
    vector<int> colors;
    
    for(map<int,int>::iterator it = histogram.begin(); it != histogram.end(); ++it) {
        colors.push_back(it->first);
    }
    
    int length = colors.size();
    int w = width/length;
    
    for(int i=0; i<length; i++) {
        cv::Rect rec;
        rec.x = i*w;
        rec.y = 0;
        rec.width = w;
        rec.height = height;
        
        cv::Scalar color = ofColor2cvScalar(ofColor::fromHex(colors[i]));
        cv::rectangle(palette, rec, color, CV_FILLED);
    }
    
    ofImage ofPalette;
    ofxCv::toOf(palette, ofPalette);
    ofPalette.update();
    return ofPalette;
}

void ofApp::draw(){
    int w=200, h=200;
    
    ofBackground(0);
    ofNoFill();
    
    ofSetColor(255);
    ofDrawBitmapString("Drag an image in this window for extracting colors", 15, 15);
    
    ofTranslate(0, 25);
    if(ready) {
        ofSetColor(255);  // reset opengl state machine color because it could be dirty
        source.draw(0, 0, w, h);
        
        ofSetColor(255);  // reset opengl state machine color because it could be dirty
        average.draw(200, 0, w, h);
        averagePalette.draw(200, h-10, w, 10);
        ofSetColor(0);
        ofRect(200, h-10, w, 10);
        
        ofSetColor(255);  // reset opengl state machine color because it could be dirty
        clustered.draw(400, 0, w, h);
        clusteredPalette.draw(400, h-10, w, 10);
        ofSetColor(0);
        ofRect(400, h-10, w, 10);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
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
void ofApp::mouseReleased(){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo info) {
    if( info.files.size() > 0 ){
		for(int k = 0; k < info.files.size(); k++){
			extractPalette( info.files[k] );
		}
	}
}
