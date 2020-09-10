#pragma once

#include "ofMain.h"

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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void drawFPS();
    void windowScreenShot();
    
    ofShader shader;
    
    float nowf;
    int nowMillis;
    
    float windowWidthF;
    float windowHeightF;
    ofRectangle rect;
    
    ofVec3f rand;
    
    bool showFPS = false;
    ofImage img;
    std::string shaderPath = "shaders/000/";
    std::string shaderName = "shader";
    std::string imgPath = shaderPath+"imgs/";
};
