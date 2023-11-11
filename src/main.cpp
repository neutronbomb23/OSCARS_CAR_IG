#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
    ofGLFWWindowSettings settings;
    settings.setGLVersion(1, 0);
    settings.setSize(1920, 1080);
    ofCreateWindow(settings);  
    ofRunApp(new ofApp());
}