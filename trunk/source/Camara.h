/*!
 *  \file  Camara.h
 *  \brief  LA CÁMARA ES EL PUNTO DE VISTA DEL OBSERVADOR,
 * 			ESTE PUNTO DE VISTA PUEDE SER CAMBIADO CON FACILIDAD POR EL JUGADOR PARA OBSERVAR OTRAS 
 * 			PARTES DE LAS ESCENA MODELADA. EN LA REALIZACIÓN DE ESTA ANIMACIÓN, 
 * 			LA CÁMARA PUEDE SER MÓVIL SIGUIENDO LOS MOVIMIENTOS DEL MOUSE
 *  \author    Jefferson Amado Pe&ntilde;a Torres <jeffersonamado@gmail.com>
 *  \version   1.0
 *  \date      2011 - Last Modified: 18/01/012
 */

#ifndef CAMARA_H
#define CAMARA_H
/**
 * Crea el punto de vista del observador
 */
class Camara {
public:
	/// Contructor de la clase
	Camara(void);
	/// Destructor \"virtual\" de la clase (Para que exista mas de un destructor hereditario)
	virtual ~Camara(void);
	/// Metodo vista que permite ubicar y sincronizar la camara con el jugador
	void view();
	/// 
	void yaw(float angle);
	/// 
	void pitch(float angle);
	/// 
	void roll(float angle);
	/// Permite hacer las trasnlaciones 
	void translate(float stepX, float stepY, float stepZ);
	/// 
	void strafe(float step);
	/// 
	void move(float step);
	/// 
	void rise(float step);
	/// Computo del producto cruz
	void crossProduct(float x1, float y1, float z1, float x2, float y2, float z2, float &xr, float &yr, float &zr);
	/// Obtine la magnitud del vector posicion del objetivo
	float magnitude(float x, float y, float z);
	/// Computo la normalizacion del vector
	void normalizeVector(float &x, float &y, float &z);
    float zNear, zFar, fov;	
	float cx,cy, cz;	// Camera posicion
	float dx, dy, dz;

private:
	float ux, uy, uz;	
	float rx, ry, rz;	
	float camYaw, camPitch, camRoll;
};

#endif //CAMARA_H
//Jefferson Amado Pena Torres $(JAPeTo)
