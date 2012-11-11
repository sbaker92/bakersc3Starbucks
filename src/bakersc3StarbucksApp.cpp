#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "bakersc3Starbucks.h"
#include "Resources.h"
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

	void prepareSettings(Settings* settings);

  private:
	bool clicked;
	Vec2i mousePos;
	Surface* mySurface;
	uint8_t* dataArray;
	gl::Texture* texture;
	gl::Texture* image;
	bakersc3Starbucks* panda;

	static const int appWidth = 800;
	static const int appHeight = 600;
	static const int textureSize = 1024;
};

//The lovely prepareSettings method.
void bakersc3Starbucks::prepareSettings(Settings* settings){
	(*settings).setWindowSize(appWidth, appHeight);
	(*settings).setResizable(false);
}

void bakersc3Starbucks::setup(){
	//The surface!
	mySurface = new Surface(textureSize, textureSize, false);
	texture = new gl::Texture(*mySurface);
	image = new gl::Texture(loadImage(loadResource(RES_IMAGE)));

	//Array initialization.
	count = 0;
    Entry* arr = createArray();
    int n = count;
	panda = new bakersc3Starbucks;
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

void bakersc3Starbucks::mouseDown( MouseEvent event ){
	clicked = true;
	if(event.isLeft()){
		double x = mousePos.x;
		double y = mousePos.y;
		//panda->getNearest(x, y);
		console() << "clicked!" <<endl;
	}
}

void bakersc3Starbucks::update(){
	(*texture).update(*mySurface, mySurface->getBounds());
	
}

void bakersc3Starbucks::draw(){
	//gl::color(Color(.1f, .8f, .6f));
	gl::draw(*texture);
	int xoffset = (getWindowWidth()-320)/2;
	int yoffset = (getWindowHeight()-240)/2;
	gl::draw(*image, getWindowBounds());
}

CINDER_APP_BASIC( bakersc3Starbucks, RendererGl )