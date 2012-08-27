#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
private:
    float* posX;
    float* posY;
    float* velocityX;
    int coorLen;
    
};

void CatPictureApp::setup()
{
    coorLen = 3;
    posX = new float[coorLen];
    posY = new float[coorLen];
    velocityX = new float[coorLen];
    
    for(int i = 0; i<coorLen; i++){
        posX[i] = 100;
        posY[i] = 100*(i+1);
        velocityX[i] = (i+1)*2;
    }
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
    for(int i = 0; i<coorLen; i++){
        posX[i] += velocityX[i];
        if(posX[i] > 255 || posX[i] < 0)
            velocityX[i] *=-1;
    }
}

void CatPictureApp::draw()
{
	gl::clear( Color( posX[0]/255.0, posX[1]/255.0, posX[2]/255.0 ) );
    for(int i = 0; i<coorLen; i++){
        gl::drawSolidCircle(Vec2f(posX[i]*2+50, posY[i]), 20.0f);
        
    }
    
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
