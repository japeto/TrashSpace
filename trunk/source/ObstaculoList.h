//!
/**
 *\file  ObstaculoList.h
 *\brief ES UNA DE LAS ESTRUCTURAS DE DATOS FUNDAMENTALES QUE CONSISTE 
 * 			EN UNA SECUENCIA DE NODOS, EN LOS QUE SE GUARDAN CAMPOS DE DATOS 
 * 			ARBITRARIOS Y UNA O DOS REFERENCIAS (PUNTEROS) AL NODO ANTERIOR O POSTERIOR
 *\author Jefferson Amado Pe&ntilde;a Torres <jeffersonaamado@gmail.com>
 *\date   2011
 * Last Modified: 18/01/012
*/
#ifndef OBSTACULO_LIST_H
#define OBSTACULO_LIST_H

#include "Obstaculo.h"
#include "Player.h"
/**
 * Estructura de almacena la lista de objetos de tipo Obstaculo
 */
class ObstaculoList{
	
	private:
		///Puntero al primer Obstaculo creado en la lista
		Obstaculo* first;
		///Puntero al siguiente Obstaculo creado en la lista
		Obstaculo* last;
		///Puntero al actual Obstaculo creado en la lista
        Obstaculo* current;

	public:
		///Constructor de la clase
		ObstaculoList();       
		//~ObstaculoList();
		///Obtiene el primer Obstaculo de la lista
        Obstaculo* getFirst();
		///Obtiene el actual Obstaculo de la lista
        void setCurrent(Obstaculo* Obstaculo);
        ///Obtiene el actual Obstaculo de la lista
        Obstaculo* getCurrent();
        
		///Retorna \c true si no hay obstaculos en esta lista		
		bool isEmpty(); 
		///Retorna el numero de Obstaculos en la lista
		int size();
		///inserta un nuevo obstaculo al principio de la lista
		void insert(float xPos, float yPos, float zPos,int level);
		///elimina un obstaculo al principio de la lista
		void remove();
		
		///Calcula la distancia entre dos obstaculos segun sus coordenadas
		float distance(float,float,float,float,float,float); 
		/**
		 * Verifica que no halla una colision y mientras circula el timer para pasar al siguiente nivel
		 * @code
		 if(first ==last){	//hay un solo elemento en la lista
		     if((player->getHittable()) && (!first->getCrash()) &&
					distance(player->getXPos(),
					player->getYPos(),
					player->getZPos(),
					first->getXPos(),
					first->getYPos(),
					first->getZPos()) <
					player->getRad() + first->getObjRad() ) //deteccion de la colision
			{
				first->explode(); //choque
				player->explode(); //choque
				return true;
			}
		 * @endcode
		 */
		bool CollidesAll(Player* player);
		
		///Permite mover todos los elementos segun el nivel del juego
		void moveAll(int level); 
		///grafica los obstaculos del lista en pantalla
        void drawAll(int level, bool testMode); 
        ///Elimina todos los obstaculos de la lista
        void removeAll(); 
};

#endif //OBSTACULO_LIST_H
//Jefferson Amado Pena Torres $(JAPeTo)
