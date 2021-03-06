#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "GameOfLife.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Demo : public AppBasic {
private:
  GameOfLife * goa;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
};


void Demo::mouseDown(MouseEvent e) {
}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 840, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();
  goa = new GameOfLife(getWindowSize(), 3);
}

void Demo::update() {
  goa->generate();
}

void Demo::draw() {
  goa->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
