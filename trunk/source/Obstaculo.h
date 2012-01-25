/**
 *\file  Obstaculo.h
 *\brief EN ESTA CLASE SE REALIZA LA ABSTRACCION DE \"OBSTACULOS \" QUE SE POSEE LA APLICACION
 *\author Jefferson Amado Pe\a Torres <jeffersonaamado@gmail.com>
 *\date   2011
 * Last Modified: 18/01/012
*/


#include "defConstantes.h"     //Definiciones globales y constantes

#ifndef OBSTACULO_H
#define OBSTACULO_H
/**
 * Crea un objeto que sera un obstaculo
 */
class Obstaculo{
	private:
		/// Coordenadas del Objeto cargado
		float xPos, yPos, zPos;                 
		/// Ejes asociados al objeto
		int xAxis, yAxis, zAxis;				
		/// Angulo de rotacion ///Generador de color
		float spinAngle, colorGen;
		///Puntero al siguiente nodo
		Obstaculo* next;                         
		/// tipo de Objeto \@see defConstantes
		objType objtype;						
		///identificacion booleana sobre alguna colision
		bool crash;                             
		/// Tamanio del objeto para detectar la colision
		int objSize;
		/// radio del Objeto
		float objRad;
		/// tamanio de escala
		float objScaler;
		/// nivel en que va el juego para la velocidad
		int level;
		/// tamanio del sol
		int sunNum;

	public:
		///Cosntructor sin parametros
		Obstaculo();                                     
		///Contructor con las posiciones y el nodo
		Obstaculo(float,float,float,Obstaculo*);          
		///Contructor con las posiciones , el nodo y el tipo de objeto
		Obstaculo(float,float,float,Obstaculo*,objType);  
		//~Obstaculo();                                  // Destructor
		///
		void putOut();
		//void setSunNum(int);///< Establece tamanio del sol
		//int getSunNum();///< Obtiene tamanio del sol
		
		void setXPos(float);///< Establece la posion X del objeto
		float getXPos();///< Obtiene la posion X del objeto
		
		void setYPos(float);///< Establece la posion Y del objeto
		float getYPos();///< Obtiene la posion Y del objeto
		
		void setZPos(float);///< Establece la posion Z del objeto
		float getZPos();///< Obtiene la posion Z del objeto

		void setNext(Obstaculo*); // Changes next
		Obstaculo* getNext();     // Returns next

		void setObjType(objType);///< Establece el tipo del objeto
		objType getObjType();	///< Obtiene el tipo objeto

		void setObjSize(int size);///< Establece tamanio del objeto
		int getObjSize();///< Obtiene el tamanio del objeto

			void setObjRad(float rad);///< Establece el radio del objeto
		float getObjRad();///< Obtiene radio del objeto

		void setCrash(bool);///< Establece si hay una colision
		bool getCrash();///< Obtiene si existe colision

		void setLevel(int);	///<Establece el nivel en que va el juego

		void setSunPos(float,float,float,float); ///<Posicion del sol

//----------------------------------------------------------------------------------------
        void draw(int level, bool testMode);
        void move(int level);

        bool collide(int xDiff, int yDiff);
        void explode();
};
#endif //OBSTACULO_H
//Jefferson Amado Pena Torres $(JAPeTo)

