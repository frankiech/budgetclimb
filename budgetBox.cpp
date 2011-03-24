#include "budgetBox.h"

budgetBox::budgetBox()
{

}

budgetBox::budgetBox(ofxVec3f templocation, float tempheight, ofColor tempcolor)
{
	location=templocation;
	height= tempheight;
	color= tempcolor;
	
	
}


void budgetBox::update(){
		
}


void budgetBox::draw(int currentbox){
	//ofEnableAlphaBlending();
	ofSetColor(color.r, color.g, color.b, color.a);
	
	if (currentbox)
		ofSetColor(color.r, color.g, color.b, currentbox);
	
	
	ofxBox(location.x , location.y, location.z, 100, height , 50, 0, 0, 0);
	
} 