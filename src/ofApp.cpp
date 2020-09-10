#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//  ofDisableArbTex();
  
  windowWidthF = (float)ofGetWidth();
  windowHeightF = (float)ofGetHeight();
  
  // setup drawing surface
  rect.x = 0;
  rect.y = 0;
  rect.width = windowWidthF;
  rect.height = windowHeightF;
  
  // load our shader
  shader.load(shaderPath+shaderName);
  
  rand.set( ofRandom(1.0), ofRandom(1.0), ofRandom(1.0) );
  
  ofResetElapsedTimeCounter();
}


//--------------------------------------------------------------
void ofApp::update(){

  // update time
  nowf = ofGetElapsedTimef();
  nowMillis = ofGetElapsedTimeMillis();
  
  // update randomness
  rand.set( ofRandom(1.0), ofRandom(1.0), ofRandom(1.0) );
  
}


//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(255);
  
  shader.begin();
  shader.setUniform1f("nowf", nowf);
  shader.setUniform1i("nowMillis", nowMillis);
  shader.setUniform3f("rand", rand );
  shader.setUniform2f("window", windowWidthF, windowHeightF);
  ofDrawRectangle(rect);  // magic!
  shader.end();
  
  if(showFPS == true) drawFPS();
}


//--------------------------------------------------------------
// pressing the 1 key will show the current Frames Per Second
void ofApp::drawFPS() {
  // FPS
  stringstream ss;
  ss << "FPS: " << ofToString(ofGetFrameRate(), 0) << endl;
  ofDrawBitmapStringHighlight(ss.str().c_str(), 20, 20);
  
  ofSetWindowTitle( "FPS: " + ofToString( ofGetFrameRate(), 0));
}


//--------------------------------------------------------------
// pressing Enter key will save a jpeg of the app window
void ofApp::windowScreenShot() {
  img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
  ofPixels & pixels = img.getPixels();
  pixels.swapRgb();   // fix inverted R and B channels
  string pic = imgPath+ofGetTimestampString()+".jpg";
  ofSaveImage(pixels, pic, OF_IMAGE_QUALITY_BEST);
  img.clear();
  pixels.clear();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  // SHOW OUR FRAMES PER SECOND
  if (key == '1') {
    showFPS = !showFPS;
  }
  
  // CREATE JPG IMAGE FROM CURRENT SCREEN
  if (key == OF_KEY_RETURN) {
    windowScreenShot();
  }
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
void ofApp::mouseEntered(int x, int y){
  
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
  
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  windowWidthF = (float)w;
  windowHeightF = (float)h;
  // std::cout << "windowResized w=" << w << " h=" << h << endl;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
  
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
  
}
