#ifndef _BUDGET_BOX // if this class hasn't been defined, the program can define it
#define _BUDGET_BOX // by using this if statement you prevent the class to be called more 
// than once which would confuse the compiler

#include "ofMain.h"
#include "ofx3DUtils.h"


class budgetBox {
	
	
public: // place public functions or variables declarations here
	
	// methods, equivalent to specific functions of your class objects
	void update(); // update method, used to refresh your objects properties
	//void draw(); // draw method, this where you'll do the object's drawing 
	void draw(int currentbox=0);
	ofxVec3f location;
	float height;
	ofColor color;
	string category;
    int year;
	
	
	
	budgetBox(ofxVec3f location, float height, ofColor color); // constructor - used to initialize an object, if no properties are passed
	//               the program sets them to the default value
	budgetBox();
	
    
private: // place private functions or variables declarations here
	
	
	
	
	
}; // dont't forget the semicolon!!


#endif 
