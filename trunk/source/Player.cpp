#include "Player.h" 			//cabecera

#include <cstdlib>
#include <iostream>
#include <GL/glut.h>			//libreria grafica

#include "objLoader/glm.c"		//lector de archivos obj
#include "imageloader.h"		//cargador de imagenes
#include "defConstantes.h"     	//Definiciones globales y constantes


//model
GLMmodel* pmodel;
//Contructor de la clase
Player::Player(){
	
    setLives(3);
    setPoints(0);
    setXPos( GAME_WIDTH  /2 );
    setYPos( GAME_HEIGHT /2 );
	setZPos( -5);
	setSpinout(false);
	ySpin=0;
	setRad(.2);
	hittable=true;
}

// Player::~Player(); // Using default

void drawmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("obj/0TrashShip/StarCruiser.obj");
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 0.0);
	 }  
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
}

GLuint LoadTextureRAW( const char * filename, int width, int height)
{
    GLuint texture;
    unsigned char * data;
    FILE * file;
    file = fopen( filename, "rb" );
    if ( file == NULL ) return 0;
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );
    glGenTextures(1, &texture );
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);
    return texture;
}

void Player::explode(){

}

void Player::draw(bool testMode){
    glPushMatrix();
	glTranslated(xPos, yPos,zPos);

    glPushMatrix();
	glRotatef(90,0,1,0);
	glRotatef(270,1,0,0);
	glRotatef(xLean,0,1,0); //arriba y abajo
	glRotatef(zLean,0,0,1); //arriba y abajo
	if(spinout){
		setYspin(getYSpin()+25);
		if(getYSpin()>=360){
			ySpin=0;
			spinout=false;
		}
	}
	glRotatef(ySpin,0,1,0);
	if(flash){
		flashcount=flashcount-1;
		if(flashcount==0){
			flash=false;
			hittable=true;
		}
	}
	if(flashcount%2==0)
		drawmodel();
	if(testMode)
		glutWireSphere(.8,10,10);

    glPopMatrix();
    glPopMatrix();
}

void Player::Move(float stepX, float stepY) {
	xPos += stepX;
	yPos += stepY;	
}

void Player::Lean() {
	xLean=xLean*.9;
	zLean=zLean*.9;
}

