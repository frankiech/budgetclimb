#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofx3DUtils.h"
#include "budgetBox.h"
#include "ofxOpenNI.h"



class testApp : public ofSimpleApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	ofxCamera camera;
	
	ofxLight light1; //this will be a directional light
	ofxLight light2; //this one a spot light
	ofxLight light3; //and this one a point light
	
	
	float centerX, centerY, centerZ;
	
	bool bSmoothLight;

	budgetBox myBoxes[18][27];
	int boxIndexI, boxIndexJ; //what box are we on?
    string categories[18];

	float groundSize;
	ofxVec3f g1, g2, g3, g4;
	string info;
    string category;
    int year;
    int height;
	
	ofxVec3f youPos;

	int cheatmode;
	int ontop;

//FRED's Below
	
	ofxOpenNIContext	context;
	ofxDepthGenerator	depth;
	ofxImageGenerator	rgb;
	ofxUserGenerator	user;
	
	int handHistoryDepth;
	vector<ofPoint> leftHandHistory;
	vector<ofPoint> theNeckHistory;	
	
	ofPoint leftHand;
	ofPoint rightHand;
	ofPoint theNeck;
	
	int playDelay;
	int lastPlay;
	
	
	float velocity;

};

#endif
	
