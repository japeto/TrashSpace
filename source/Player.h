/**
 *\file  Player.h
 *\brief UN PLAYER ES UN PARTICIPANTE DE EL JUEGO TRASHSPACE 
 * QUE DEBE ENFRENTARE A UN SIN FIN DE OBSTÁCULOS QUE SE SEGÚN 
 * EL NIVEL AUMENTAN SU VELOCIDAD DE DESPLAZAMIENTO
 *\author Jefferson Amado Pe&ntilde;a Torres <jeffersonaamado@gmail.com>
 *\date   2011 - Last Modified: 18/01/012
*/
#ifndef PLAYER_H
#define PLAYER_H
#include "defConstantes.h"     //Definiciones globales y constantes
/**
 * Clase que abstrae y crea un jugador
 */
class Player{
	
    private:
        int lives;///<Numero de vidas
        int health;///<Salud del jugador
        int points;///<Puntos obtenido por el jugador
        float xPos;///<Posicion en X del jugador
        float yPos;///<Posicion en Y del jugador
		float zPos;///<Posicion en Z del jugador

		float xLean;
		float zLean;

		float rad;

		int flashcount;
		bool flash;
		bool spinout;
		bool hittable;
		int spintime;
		float ySpin;

    public:
		///Contructor de la clase
        Player();
        // ~Player(); // Using default
        ///Establece las vidas del jugador
        void setLives(int lives)   { this->lives   = lives; }
        ///Establece la salud del jugador
        void setHealth(int health) { this->health  = health; }
        ///Establece el puntaje del jugador
        void setPoints(int points) { this->points  = points; }
        ///Adiciona puntos al jugador
        void addPoints(int points) { this->points += points; }
        ///Establece la posicion de la coordenada X del jugador
        void setXPos(float xPos)   { this->xPos    = xPos; }
        ///Establece la posicion de la coordenada Y del jugador
        void setYPos(float yPos)   { this->yPos    = yPos; }
        ///Establece la posicion de la coordenada Z del jugador
	void setZPos(float zPos)   { this->zPos    = zPos; }
	///inclinacion en X
	void setXLean(float xLean) { this->xLean   = xLean; }
	///inclinacion en Z
	void setZLean(float zLean) { this->zLean   = zLean; }
	void setRad(float rad)	   { this->rad	= rad; }
	void setSpinout(bool spinout2) {this->spinout = spinout2; }
	void setYspin(float spin)	{this->ySpin = spin; }
	void setSpinTime(int spintime) {this->spintime = spintime; }

		///Obtiene las vidas del jugador
        int getLives()  { return this->lives; }
        ///Obtiene la salud del del jugador
        int getHealth() { return this->health; }
        ///Obtiene el puntaje del jugador
        int getPoints() { return this->points; }
        ///Obtiene el valor de la coordenada X del jugador
        float getXPos() { return this->xPos; }
        ///Obtiene el valor de la coordenada Y del jugador
        float getYPos() { return this->yPos; }
        ///Obtiene el valor de la coordenada Z del jugador
		float getZPos() { return this->zPos; }
	    float getXLean() { return this->xLean; }
        float getZLean() { return this->zLean; }
		float getRad()	{return this->rad;	}
		bool getSpinout() {return this->spinout; }
		int getSpinTime() {return this->spintime; }
		float getYSpin() {return this->ySpin; }
		bool getHittable() {return this->hittable; }
		int getFlashCount() {return this->flashcount; }


		void explode();
        void draw(bool testMode);
		void Move(float stepX, float stepY);
		void Lean();

};
#endif //PLAYER_H
//Jefferson Amado Pena Torres $(JAPeTo)
