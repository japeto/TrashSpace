
#include "Camara.h"
#include <cmath>		//libreria calculos matematicos
#include <GL/glut.h>	//libreria grafica

#include "defConstantes.h"     //Definiciones globales y constantes
#define Sqr(x)  x*x		//particular definicion

//Constructor de clase que inicia la posicion de la vista
Camara::Camara(void) {
	
	cx = GAME_WIDTH/2, cy = GAME_HEIGHT/2, cz = 20.0;
	dx = 0.0, dy = 0.0, dz = -1.0;
	ux = 0.0, uy = 1.0, uz = 0.0;
	rx = 1.0, ry = 0.0, rz = 0.0;
	camYaw = 0.0, camPitch = 0.0, camRoll = 0.0;

    fov = FOV; zNear = 3; zFar = -(GAME_DEPTH)+50;

}
//Destructor de la clase
Camara::~Camara(void) {}

// Establece la vista de la Camara
void Camara::view() {
	glLoadIdentity();		//matrix identidad
	gluLookAt(cx, cy, cz, cx+dx, cy+dy, cz+dz, ux, uy, uz); //ubicacion de la Camara segun 
}

// Yaws the Camara, a positive value yaws to the right
void Camara::yaw(float angle) {
	
	camYaw += angle;
	float x = dx*cos(angle*M_PI/180.0) + rx*sin(angle*M_PI/180.0);
	float y = dy*cos(angle*M_PI/180.0) + ry*sin(angle*M_PI/180.0);
	float z = dz*cos(angle*M_PI/180.0) + rz*sin(angle*M_PI/180.0);
	normalizeVector(x, y, z);
	dx = x, dy = y, dz = z;
	crossProduct(dx, dy, dz, ux, uy, uz, rx, ry, rz);
	
}

// Pitches the Camara, a positive value pitches upwards
void Camara::pitch(float angle) {
	camPitch += angle;
	float x = dx*cos(angle*M_PI/180.0) + ux*sin(angle*M_PI/180.0);
	float y = dy*cos(angle*M_PI/180.0) + uy*sin(angle*M_PI/180.0);
	float z = dz*cos(angle*M_PI/180.0) + uz*sin(angle*M_PI/180.0);
	normalizeVector(x, y, z);
	dx = x, dy = y, dz = z;
	crossProduct(rx, ry, rz, dx, dy, dz, ux, uy, uz);
}

// Rolls the Camara, a positive value rolls clockwise
void Camara::roll(float angle) {
	camRoll += angle;
	float x = rx*cos(angle*M_PI/180.0) - ux*sin(angle*M_PI/180.0);
	float y = ry*cos(angle*M_PI/180.0) - uy*sin(angle*M_PI/180.0);
	float z = rz*cos(angle*M_PI/180.0) - uz*sin(angle*M_PI/180.0);
	normalizeVector(x, y, z);
	rx = x, ry = y, rz = z;
	crossProduct(rx, ry, rz, dx, dy, dz, ux, uy, uz);
}

// Translates the Camara from its current location by the vector (stepX, stepY, stepZ)
void Camara::translate(float stepX, float stepY, float stepZ) {
	cx += stepX;
	cy += stepY;
	cz += stepZ;
}

// Strafes the Camara, a positive value strafes to the right
void Camara::strafe(float step) {
	cx += rx*step;
	cy += ry*step;
	cz += rz*step;
}

// Moves the Camara, a positive value moves forward
void Camara::move(float step) {
	cx += dx*step;
	cy += dy*step;
	cz += dz*step;
}

// Raises the Camara, a negative value lowers it
void Camara::rise(float step) {
	cx += ux*step;
	cy += uy*step;
	cz += uz*step;
}

// computo producto cruz
void Camara::crossProduct(float x1, float y1, float z1, float x2, float y2, float z2, float &xr, float &yr, float &zr) {
	xr = y1*z2-z1*y2;
	yr = z1*x2-x1*z2;
	zr = x1*y2-y1*x2;
}

// Computo de la magnitud del vector
float Camara::magnitude(float x, float y, float z) {
	return (sqrt(Sqr(x)+Sqr(y)+Sqr(z)));
}

//Computo para normalizacion del vector
void Camara::normalizeVector(float &x, float &y, float &z) {
	float m = magnitude(x, y, z);
	if (m!=0) {
		x = x/m;
		y = y/m;
		z = z/m;
	}
}
