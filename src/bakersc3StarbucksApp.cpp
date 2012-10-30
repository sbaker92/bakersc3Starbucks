#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "bakersc3Starbucks.h"
#include <iostream>
#include <fstream>

using namespace ci;
using namespace ci::app;
using namespace std;

class bakersc3Starbucks : public AppBasic {
  public:
    int count;
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    Entry* createArray();
};

void bakersc3Starbucks::setup()
{
	count = 0;
    Entry* arr = createArray();
    int n = count;
    // call build 
	// call getNearest
}

Entry* bakersc3Starbucks::createArray(){
    string storeName;
    double xVal, yVal;
    ifstream in("Starbucks_2006.csv");
    while(in.good()){
        getline(in, storeName, ',');
        in >> xVal;
        in.get();
        in >> yVal;
        in.get();

        count++;
    }
    in.clear();
    in.seekg(0);
    
    Entry* stores  = new Entry[count];
    int i = 0;
    
    while(in.good()){
        getline(in, storeName, ',');
        in >> xVal;
        in.get();
        in >> yVal;
        in.get();

        (stores+i)->identifier = storeName;
        (stores+i)->x = xVal;
        (stores+i)->y = yVal;

        i++;
    }
    in.close();
    
    return stores;
}

void bakersc3Starbucks::mouseDown( MouseEvent event )
{
}

void bakersc3Starbucks::update()
{
}

void bakersc3Starbucks::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( bakersc3Starbucks, RendererGl )