#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_MOVERS 10

class Demo : public AppBasic 
{
private:
  Mover * movers[NB_MOVERS];
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  gl::enableAlphaBlending();
  for (int i = 0; i < NB_MOVERS; i++) {
    movers[i] = new Mover();
  }
}

void Demo::update() {
  for (int i = 0; i < NB_MOVERS; i++) {
    movers[i]->update(getMousePos());
  }
}

void Demo::draw()
{
  gl::clear( Color(1.0f, 1.0f, 1.0f) );
  for (int i = 0; i < NB_MOVERS; i++) {
    movers[i]->draw();
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
