#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofx3DUtils.h"
#include "budgetBox.h"

//#define KINECT

#ifdef KINECT
#include "ofxOpenNI.h"
#endif

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
    budgetBox current;
    
	float groundSize;
	ofxVec3f g1, g2, g3, g4;
	ofxVec3f s1, s2, s3, s4;

	string info;
    string category;
    int year;
    int height;
	
	ofxVec3f youPos;

	int cheatmode;
	int ontop;
	
    int headOffsetX; // for head tracking
    
#ifdef KINECT
	ofxOpenNIContext	context;
	ofxDepthGenerator	depth;
	ofxImageGenerator	rgb;
	ofxUserGenerator	user;
#endif
	
    int handHistoryDepth;
    vector<ofPoint> leftHandHistory;
    vector<ofPoint> rightHandHistory;
    vector<ofPoint> theHeadHistory;
	
    ofPoint leftHand;
    ofPoint rightHand;
    ofPoint theHead;
    ofPoint theThroat;
    
    int playDelay;
    int lastPlay;
	
    float leftHandDist, rightHandDist, headDist, theNeck;
	
    int miniWidth;
    int miniHeight;
	
    boolean_t jump;
    boolean_t debug;
    boolean_t pressed;
    boolean_t released;
	
	//ofTexture boxTexture;
	ofImage hat;
	//unsigned char *boxTextureData;
	ofTexture boxTexture;
	ofImage boxImage;
	unsigned char *boxTextureData;
	
	ofTrueTypeFont  verdana;
	
	bool nouserfound;
	
};

#endif
	
