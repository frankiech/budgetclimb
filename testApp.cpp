#include "testApp.h"

const int multiplier = 3;

//--------------------------------------------------------------
void testApp::setup(){
	//ofBackground(250,250,250);
	ofSetVerticalSync(true);
	// glEnable(GL_DEPTH_TEST); //lights look weird if depth test is not enabled
	//but  this also prevents nice transperency 
	centerX = ofGetWidth()/2;
	centerY = ofGetHeight()/2;
	centerZ = 0;

	boxIndexI = 7;
	boxIndexJ = 0;
	bSmoothLight = true;
	
	cheatmode=-1;
	ontop=-1;
    headOffsetX = 0;
	
	//reflexions!!
	ofxMaterialSpecular(120, 120, 120); //how much specular light will be reflect by the surface
	ofxMaterialShininess(50); //how concentrated the reflexion will be (between 0 and 128

	//each light will emit white reflexions
	light1.specular(100, 100, 100);
	//light2.specular(255, 255, 255);
	//light3.specular(255, 255, 255);

    camera.setOrigin(OF_ORIGIN);    
	//camera.setOrigin(OF_ORIGIN_ZERO);

	camera.position(centerX, 10000, -20000); //initialize the camera 
	
	int boxSpacingX = -200;
	int boxSpacingZ= 200;
    

	//building my array of boxes
    //initialize categories
    string categories[] = {"National Defense", "International Affairs", "General Science, Space, and Technology", "Energy", "Natural Resources and Environment", "Agriculture", "Commerce and Housing Credit", "Transportation", "Community and Regional Development", "Education, Training, Employment, and Social Services", "Health", "Medicare", "Income Security", "Social Security", "Veterans Benefits and Services", "Administration of Justice", "General Government", "Net Interest"};
    
    int dollars[] = {556488456,597122311,575270243,551711701,538241380,526785955,505938202,462483382,458595477,424152174,387438540,381148724,369932212,367316350,362582981,382495877,384958746,412108602,564700281,438787095,540410317,566259918,601684213,658173822,705146615,709208242,722138000,
        51516082,53593996,33130760,35934175,31664623,30334079,31374027,36318036,32963937,48746115,26033214,36658876,22774274,19796224,19683901,49567819,28671451,24824647,36674272,30433296,37554220,52101416,35382181,71913405,48522607,64415541,67388000,
        18501050,18537957,18447467,24036055,19985829,22741654,24402755,26416602,26894021,25973748,25866486,23858817,23196766,22607176,24010239,24627501,24373646,25842898,27163770,26639437,27271221,26973608,27067715,27588539,27977217,35610687,31023000,
        16477140,17592628,11941335,6502804,9855244,7141662,8217546,8622749,9473655,12470228,6952803,7192700,3669011,2302834,395978,1281373,1,144057,1433609,483626,649427,3671975,325569,679380,4275985,43501021,8810000,
        25762762,27018739,23304108,27967025,28331081,29847871,30255290,30777283,33074314,32635225,33240246,29946929,29871865,31154156,32573285,31949261,31670038,35727447,36856265,37709506,37659693,37928353,41173212,35487656,37634138,58334403,39520000,
        24551581,55501049,59300484,48570455,33714130,37023847,24074518,27398520,34594091,28676965,24911971,12060328,13195931,15363098,16831782,31324935,42456338,35566152,32641408,28554548,29196987,37780597,27715609,23961319,17672113,24531897,25419000,
        27924943,24758246,22141091,21377835,42515629,109775337,105089237,139834588,73972998,16265679,40217823,12058897,11204381,10946275,19160834,18775590,19537665,15191275,15884704,13623954,17594986,16316683,15468347,10552487,221023464,459077620,1,
        61511310,59903454,57416574,51819950,51871039,51599055,51619559,50272990,57396202,61006673,63923803,56230976,50883902,55800598,60650336,67517519,70121085,82930230,85117763,83451570,81451026,82027842,81869428,82747741,82531982,127045263,93669000,
        18677033,16539865,13696041,12759717,16276295,13858619,16378745,12413303,19101124,15316304,22939619,18593423,17425023,18429468,14212435,14774406,14257215,17884039,94340203,27903653,19789767,20935222,33638599,18552564,42041785,24148713,19884000,
        64967147,64039200,58764575,61781649,63105771,65414112,65891219,70683153,71574375,75210868,71601284,74439510,66260394,72841572,75820612,72629924,62652478,78196038,111627254,96824621,103875241,106218321,136070837,98474460,92511982,170303365,91920000,
        66380706,68091210,72879358,79308610,84102199,90886845,101605055,120694338,143831385,163884449,171372598,167357980,152675334,176853605,180720264,186084487,204468654,223690241,281078985,249728058,274527763,290203792,319258428,256848013,288911565,379744335,386437000,
        121379483,132899084,141661638,144163678,145259587,150169239,176651099,165235350,207640388,188262607,239356235,223979568,249676204,258133470,259081296,249501350,254003582,267301441,338762780,284149149,296208929,313585075,395195132,404902549,411759545,444154795,462087000,
        247817495,266549009,240704370,235095732,236757030,235897915,245418672,289772516,316049323,328747596,325025777,313441191,314765017,315303541,315789234,318894465,316271106,336756772,389709504,375638125,390699467,385976435,379752744,387043037,431621304,620586052,664559000,
        375234183,391478666,391232283,400010360,407610005,410616491,418162654,434275986,449994256,462275182,472510515,476871588,489383539,497317126,508972134,511892349,521754063,542209603,593604704,559903324,564778075,572609976,597301461,619395481,627590453,701115643,723504000,
        55580686,55214435,53470271,52150276,54120693,52515036,50884315,53186351,52961689,54594633,54415855,54558355,53831619,54216465,57192209,57720705,57515119,58500817,77264174,63077455,69959238,69776765,76764148,83663748,89440200,98538215,125002000,
        13022782,13987346,13820446,17193565,17732876,17990077,20982809,21394948,23346343,23267290,23587108,27298493,29775970,32952948,35355840,36729216,34726874,39289480,45301608,44915414,46934183,52724763,46151941,48556797,49730861,57531445,53462000,
        26021268,24840361,25135159,16403978,18744130,18425814,21587280,21712029,20362171,19882762,17622806,18722196,15867083,16974402,21247751,21857954,16493492,19829429,18833428,21726813,29873672,27463050,21266949,19583204,21807321,30715691,29010000,
        233170684,262394497,270639444,266056108,279803363,297412740,308376313,310619057,309879148,299881856,298594686,332160526,335011287,331480443,322565023,300719642,282321737,253841316,205410315,207204108,181496067,184899713,245099919,249391651,255960552,189969742,187775000
    };
    
	for (int i=0; i < 18; i++) //categories 0-17
	{
		for (int j=0; j< 27; j++) //years 1984-2010
		{
			// height = (int) ofRandom(10, 1000);
            height = dollars[i * 27 + j] / 1000000 * multiplier; 
			myBoxes[i][j].height = height;
			myBoxes[i][j].location= ofxVec3f(i*boxSpacingX, -height/2, boxSpacingZ*j);
			myBoxes[i][j].category = categories[i];
            myBoxes[i][j].year = j + 1984;
            ofColor c;
			c.r=ofRandom(10, 250);
			c.g=ofRandom(10, 250);
			c.b=ofRandom(10, 250);
			//c.a=ofRandom(100, 250);
			c.a=50;
			myBoxes[i][j].color= c;

		}
	}


	
	groundSize= 8000;
	g1.x= -groundSize; g1.y=0; g1.z= -groundSize;
	g2.x= -groundSize; g2.y=0; g2.z= groundSize;
	g3.x= groundSize; g3.y=0; g3.z= groundSize;
	g4.x= groundSize; g4.y=0; g4.z= -groundSize;
	
	
	s1.x= -groundSize*2; s1.y=0; s1.z= groundSize;
	s2.x= groundSize*2; s2.y=0; s2.z= groundSize;
	s3.x= groundSize*2; s3.y=-groundSize*2; s3.z= groundSize;
	s4.x= -groundSize*2; s4.y=-groundSize*2; s4.z= groundSize;
	
	
	
	youPos.y= 0;
	
// Kinect setup	
#ifdef KINECT    
    miniWidth = 640;
	miniHeight = 480;
	
	context.setup();
	context.setupUsingXMLFile();
	depth.setup(&context);
	rgb.setup(&context);
	user.setup(&context, &depth, &rgb);
	
	depth.toggleRegisterViewport(&rgb);
	context.toggleMirror();	
    
	handHistoryDepth = 10; // store the last 10 hand positions, newest first
	playDelay = 60; // frames between cues
	lastPlay = 0;
    
	jump = false;
    debug = false;
    pressed = false;
    released = true;
#endif	
	
    
	/*
    boxImage.loadImage("squirrel.jpg");
	boxTextureData = new unsigned char [100*100*3];
	boxTextureData = boxImage.getPixels();
	boxTexture.loadData(boxTextureData, 100, 100, GL_RGB); //add A for transparent
	*/
	
	verdana.loadFont("verdana.ttf",8, false, true);
	verdana.setLineHeight(20.0f);
	
	
} //end setup

//--------------------------------------------------------------
void testApp::update(){


	//light1
	float L1DirectionX = -100;
	float L1DirectionY = 3500;
	float L1DirectionZ = -500;

	light1.directionalLight(255, 255, 255, L1DirectionX, L1DirectionY, L1DirectionZ);
	light2.globalAmbientLight(200, 200, 200);

 
    current = myBoxes[boxIndexI][boxIndexJ];
    category = current.category;
    year = current.year;
    height = current.height;

	youPos.x=current.location.x;
	
    // don't follow user
	if (cheatmode==1)
	{
		//cheatmode
	}
	// for following the user
	else
	{
		//headOffsetX = ofMap(mouseX, 0, ofGetWidth(), 50, -50);

        
        if (ontop == 1)
            camera.lerpPosition(current.location.x + headOffsetX, ofGetHeight()-youPos.y*1.2+5, current.location.z-150, 0.05); //interpolate the camera into a closer position
        else
            camera.lerpPosition(current.location.x + headOffsetX, ofGetHeight()-youPos.y*1.2+5, current.location.z-150, 0.05);
            
        camera.lerpEye(current.location.x, ofGetHeight()+current.height/25-youPos.y, current.location.z, 0.05);

        
		//win condition for getting on top of a box
		//confusingly less than, as we're going negative from 0...
		if (youPos.y <=-current.height)
		{
			info="You're at the top!";
			camera.lerpPosition(current.location.x, ofGetHeight()-youPos.y+100, current.location.z-150, 0.05); //interpolate the camera into a closer position
			youPos.y = -current.height;
			youPos.z=ofLerp(youPos.z, current.location.z, .05);
			ontop=1;

		}
		
		else
		{
			youPos.z= current.location.z -25;	
            ontop =-1;
		}
	} //end this isn't cheatmode
	
	/*cout << "box currentX: " << current.location.x << " currentY: " << current.location.y << " currentZ: " << current.location.z <<endl;
	cout << "boxIndexI " << boxIndexI << " boxIndexJ "<<boxIndexJ<<endl;
	cout << "youPosX: " << youPos.x << " youPosY: " << youPos.y << " youPosZ: " << youPos.z <<endl;*/
	
	
// Kinect update
#ifdef KINECT
    context.update();
	user.update();
    nouserfound = true;

	// find the hands
	for (int i = 0; i < user.getTrackedUsers().size(); i++) {
		ofxTrackedUser* tracked = user.getTrackedUser(i);
		if (tracked != NULL && tracked->left_lower_arm.found && tracked->right_lower_arm.found && tracked->neck.found) {
			leftHand = tracked->left_lower_arm.end;
			rightHand = tracked->right_lower_arm.end;
			theHead = tracked->neck.begin;
			theThroat = tracked->neck.end;
            nouserfound = false;
			break;
		}
	}
    
    if (nouserfound)
        headOffsetX=0;
    else if(ontop == 1) 
        headOffsetX=ofMap(theHead.x, 250, 450, -200, 200);
    else
        headOffsetX=ofMap(theHead.x, 250, 450, -180, 180);
    // cout << "theHeadX: " << theHead.x << endl;
    
	// add hand positions to history
	if (leftHandHistory.size() <= handHistoryDepth) {
		leftHandHistory.insert(leftHandHistory.begin(), leftHand);
	}
	
	if (rightHandHistory.size() <= handHistoryDepth) {
		rightHandHistory.insert(rightHandHistory.begin(), rightHand);
	}
	
	if (theHeadHistory.size() <= handHistoryDepth) {
		theHeadHistory.insert(theHeadHistory.begin(), theHead);
	}
	
	// remove hand positions from history
	if (leftHandHistory.size() > handHistoryDepth) {
		leftHandHistory.pop_back();
	}
	
	if (rightHandHistory.size() > handHistoryDepth) {
		rightHandHistory.pop_back();
	}
	
	if (theHeadHistory.size() > handHistoryDepth) {
		theHeadHistory.pop_back();
	}
	
	
	leftHandDist = leftHand.y - leftHandHistory[1].y;
	rightHandDist = rightHand.y - rightHandHistory[1].y;
    // cout << "leftHandDist = " << leftHandDist << ", rightHandDist = " << rightHandDist  << endl;

    
    // climbing interaction
    if (leftHandDist > 0)
        youPos.y = youPos.y - leftHandDist/8;
    if (rightHandDist > 0)
        youPos.y = youPos.y - rightHandDist/8;   
    
	
    headDist = theHead.y - theHeadHistory[1].y;
	theNeck = theThroat.y - theHead.y;
	//cout << "theNeck = " << theNeck << endl;
	//cout << "headDist = " << headDist << endl;
    
    
	if (headDist > theNeck/10) {
        if ((ofGetFrameNum() - lastPlay) > playDelay && ontop == 1) {
            lastPlay = ofGetFrameNum();
            // cout << "JUMP!" << endl;
            boxIndexJ++; // move forward
            youPos.y = 0; // set to zero
        }
	}
    
	
    // cout << "pressed = " << pressed << ", released = " << released << endl;    
	if ((leftHand.x > 0 && leftHand.x < miniWidth/3) && (rightHand.x > 0 && rightHand.x < miniWidth/3) && (theHead.x > 0 && theHead.x < miniWidth/3)) {
        // cout << "move right attempt" << endl;
        if (released == true && pressed == false) {
            cout << "MOVE RIGHT" << endl;
            if (boxIndexI < 27) {boxIndexI++;} else {boxIndexI = 26;}
            pressed = true;
            released = false;
        }
	}
	else if ((leftHand.x > miniWidth*2/3 && leftHand.x < miniWidth) && (rightHand.x > miniWidth*2/3 && rightHand.x < miniWidth) && (theHead.x > miniWidth*2/3 && theHead.x < miniWidth)) {
        // cout << "move left attempt" << endl;
        if (released == true && pressed == false) {
            cout << "MOVE LEFT" << endl;
            if (boxIndexI > 0) {boxIndexI--;} else {boxIndexI = 0;}
            pressed = true;
            released = false;
        }
	}
    else { 
        released = true;
        pressed = false;
    }

#endif	
	
	hat.loadImage("unclesam.png");
	//hat.setImageType(OF_IMAGE_COLORALPHA);

}

//--------------------------------------------------------------
void testApp::draw(){


	

    // kinect draw
    if (debug == true) {
#ifdef KINECT
        ofSetLineWidth(1);
        ofSetColor(255, 255, 255);
        
        // rgb.draw(0, 0, miniWidth, miniHeight);
        
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_DST_COLOR, GL_ZERO);
        
        // user.drawUserMasks(0, 0);
        glDisable(GL_BLEND);
        user.draw();
        
        ofSetColor(255, 0, 0, 255);
        ofCircle(leftHand.x, leftHand.y, 10);
        ofCircle(rightHand.x, rightHand.y, 10);
        ofCircle(theHead.x, theHead.y, 10);
        
        ofSetColor(0, leftHandDist * 4, rightHandDist * 4);
        
#endif  
    }  
    
    else {
        ofSetColor(255, 0, 0);
//        ofDrawBitmapString("keypressed: " + info, 20, 30);
//		ofCircle(current.location.x, current.location.y-20, current.location.z-300);
//        ofDrawBitmapString("category: " + category, youPos.x, youPos.y);
//        ofDrawBitmapString("year: " + ofToString(year), 20, 50);
//        ofDrawBitmapString("height: " + ofToString(height/multiplier) + " million", 20, 70);
//        ofDrawBitmapString("boxIndexI: " + ofToString(boxIndexI) + "; boxIndexJ: " + ofToString(boxIndexJ), 20, 110);
//        ofDrawBitmapString("youPosZ: " + ofToString(youPos.z), 20, 130);
//        ofDrawBitmapString("youPosY: " + ofToString(youPos.y), 20, 150);
//        ofDrawBitmapString("youPosX: " + ofToString(youPos.z), 20, 170);
                           
        camera.place();//this MUST be inside the draw function, and actually places the camera in position

		
		
        ofxLightsOn(); //turn lights on
		

        
        //draw the ground
        ofSetColor(10, 10, 10);
        ofxQuad(g1, g2, g3, g4);
		
		//draw the sky
		ofSetColor(100, 100, 200, 50);
		//ofxQuad(s1, s2, s3, s4);
        
		ofxSphere(centerX, centerY, 0, 4000);
		
        //ofSetColor(255, 255, 255);
        
        // draw budgetBoxes
        for (int i=0; i<18; i++)
        {
            for (int j=0; j<27; j++)
            {
                if (i==boxIndexI && j==boxIndexJ)
                    myBoxes[i][j].draw(240);
                else
                    myBoxes[i][j].draw();
            }
        }
        
        ofSetColor(0, 0, 0);
        

		

        ofxLightsOff(); //turn lights off to draw text

        
#ifdef KINECT
        // draw skeleton
        ofPushMatrix();
			if (ontop==1)
				ofTranslate(youPos.x-25 , youPos.y-45, youPos.z+20);
			if (ontop==-1)
				ofTranslate(youPos.x-25 , youPos.y, youPos.z+20);
					
        ofScale(.08, .08, .08);
		if (!nouserfound)
		{	user.draw();
			ofSetColor(255, 255, 255);
			
			ofxSphere(theHead.x, 130, 0, 100);
			
			ofSetRectMode(OF_RECTMODE_CENTER);
			hat.draw(theHead.x, -40);
			
			//ofxSphere(leftHand.x/10, leftHand.y/10, 0,30);
				//ofxSphere(rightHand.x/10, rightHand.y/10, 0,30);
				//ofxSphere(theHead.x/10, theHead.y/10, 0, 30);
		}
        ofPopMatrix();
#else        
        // draw sphere
        ofxSphere(youPos.x, youPos.y, youPos.z, 10);
		ofSetColor(255, 255, 255);

		hat.draw(youPos.x-30, youPos.y-50, 50, 50);
#endif
	
    }
	
	
	ofPushMatrix();
		ofTranslate(0,0,youPos.z);
		ofSetColor(255,255,255);
		ofRotateY(180);
		string curHeightString = "$" + ofToString((int) abs(youPos.y/multiplier)) + ",000,000";
		if (abs(youPos.y) < 10*multiplier)
			curHeightString = "";
        if (ontop == 1)
            verdana.drawString(curHeightString, -youPos.x-verdana.stringWidth(curHeightString)/2, youPos.y-65);
        else
            verdana.drawString(curHeightString, -youPos.x-verdana.stringWidth(curHeightString)/2, youPos.y-20);

		
//		verdana.drawString(curHeightString, -youPos.x-verdana.stringWidth(curHeightString)/2, youPos.y-20);
//		string yearString = ofToString(year);
//		string heightString = ofToString(height/multiplier)  + " million";
//		verdana.drawString(yearString, -youPos.x-verdana.stringWidth(yearString)/2, youPos.y);
//		verdana.drawString(category, -youPos.x-verdana.stringWidth(category)/2, youPos.y+10);
//		verdana.drawString(heightString, -youPos.x-verdana.stringWidth(heightString)/2, youPos.y+20);
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(0,0,youPos.z);
        ofRotateY(180);
		string yearString = ofToString(year);
		string heightString = "$" + ofToString(height/multiplier)  + " million";
		verdana.drawString(heightString, -youPos.x-verdana.stringWidth(heightString)/2, -40);
		verdana.drawString(yearString, -youPos.x-verdana.stringWidth(yearString)/2, -30);
		if (category == "Education, Training, Employment, and Social Services") {
				verdana.drawString("Education, Training, Employment", -youPos.x-verdana.stringWidth("Education, Training, Employment")/2, -20);
				verdana.drawString(" and Social Services", -youPos.x-verdana.stringWidth(" and Social Services")/2, -10);
		}
		else 
			verdana.drawString(category, -youPos.x-verdana.stringWidth(category)/2, -20);
	ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	
	info = ofToString(key);
	if (key==100 && boxIndexI < 17) // right (d)
		boxIndexI++;  
    
	if (key==119 && boxIndexJ < 26) // forward (w) 
		boxIndexJ++;
	
    if (key==115 && boxIndexJ > 0) // backward (s)
		boxIndexJ--; 
    
	if (key==97 && boxIndexI > 0) // left (a)
		boxIndexI--;
    
	if (key==357) //climbing up (up arrow)
		youPos.y-=10;
	if (key==359) //climbing down (down arrow)
		youPos.y+=10;
    
	if (key==99) //c
		cheatmode*=-1;
    
    if (key==101) // toggle debug (e)
        debug = !debug;
    
    if (key==106 && ontop == 1) {// toggle jump (j)
        boxIndexJ++; // move forward
        youPos.y = 0; // set to zero
    }
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}
