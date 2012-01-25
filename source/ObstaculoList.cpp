#include "ObstaculoList.h"
#include "Obstaculo.h"

#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

ObstaculoList::ObstaculoList(){
	first = 0;
	last = 0;
    current = 0;
}

/*
//Destructor
ObstaculoList::~ObstaculoList(){

}
*/

Obstaculo* ObstaculoList::getFirst(){
    return first;
}

Obstaculo* ObstaculoList::getCurrent(){
    return current;
}

void ObstaculoList::setCurrent(Obstaculo* Obstaculo){
    current = Obstaculo;
}

bool ObstaculoList::isEmpty(){
	if(first == 0)
		return true;
	else
		return false;
}

int ObstaculoList::size(){
	Obstaculo* temp;
	int i = 1;
	if(isEmpty())
		return 0;
	else{
		for(temp = first; temp != last ; temp = temp->getNext() )
			i++;
		return i;
	}

}

void ObstaculoList::insert(float xPos, float yPos, float zPos, int level){
	
	int randObj;
	if(level==1)randObj = rand() % 3;
	if(level==2)randObj= rand() % 8;
	if(level>=3)randObj= rand() % 10;
	
	Obstaculo* MyNode = new Obstaculo(xPos, yPos, zPos, NULL);
	if (randObj==0)
		MyNode->setObjType(PLANETA);
	if (randObj==1)
		MyNode->setObjType(MODULO);
	if (randObj==2)
		MyNode->setObjType(VEHICULO1);
	if (randObj==3)
		MyNode->setObjType(VEHICULO2);
	if (randObj==4)
		MyNode->setObjType(SATELITE);
	if (randObj==5)
		MyNode->setObjType(TELESCOPIOE);
	if(randObj==7)
		MyNode->setObjType(SATELITE1);
	if(randObj==8)
		MyNode->setObjType(ANTENA);
	if(randObj==9)
		MyNode->setObjType(VEHICULO3);
	if(randObj==10)
		MyNode->setObjType(BUSCADOR);		
		
	if(last != 0){
		last->setNext(MyNode);
		last = MyNode;
	}else{
		last = MyNode;
		first = last;
        current = first;
	}
}

void ObstaculoList::remove(){
    if (isEmpty()){
        return;
    }else if (first == last){
		first = 0;
		last = 0;
        current = 0;
	}else{
        first = first->getNext();
    }
}

void ObstaculoList::moveAll(int level){
	float zparameter = 0;

    if (isEmpty()) return;
	if (first!=0){			//lsta no vacia
		if(first ==last){	//hay un solo elemento en la lista
            first->move(level);
		}else{						//Mientras hallan elementos circules y verifique no se choquen	
			Obstaculo * temp = first;
			do{
                temp->move(level);
       			temp = temp->getNext();
			}while(temp!= last);
            last->move(level); //para el ultimo miembro a la lista
		}
	}
}

float ObstaculoList::distance(float x, float y, float z, float x2, float y2, float z2){
	return sqrtf((x2-x)*(x2-x)+(y2-y)*(y2-y)+(z2-z)*(z2-z));
}

bool ObstaculoList::CollidesAll(Player* player){
    if (isEmpty()) return false;
	if (first!=0){ //la lista no esta vacia
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
		}else{
			Obstaculo * temp = first;

			 do{
				 if((player->getHittable()) && (!temp->getCrash()) &&
                     distance(player->getXPos(),
                              player->getYPos(),
                              player->getZPos(),
                              temp->getXPos(),
                              temp->getYPos(),
                              temp->getZPos()) <
                     player->getRad() + temp->getObjRad() )
					{
						temp->explode();
						player->explode();
						return true;
					}
       				temp = temp->getNext();

				}while(temp!= last);

				if((player->getHittable()) && (!last->getCrash()) &&
                    distance(player->getXPos(),
                             player->getYPos(),
                             player->getZPos(),
                             last->getXPos(),
                             last->getYPos(),
                             last->getZPos()) <
                    player->getRad()+last->getObjRad())
				{
					last->explode();
					player->explode();
					return true;
				}
		}

	}
	return false;
}

void ObstaculoList::drawAll(int level, bool testMode){
    
    if (isEmpty()) return;
	if (first!=0){

		if(first ==last){
            first->draw(level,testMode);
		}else{
			Obstaculo * temp = first;
			do{			
				temp->draw(level,testMode);
				temp = temp->getNext();
			}while(temp!= last);
            last->draw(level,testMode);
		}
	}
}

void ObstaculoList::removeAll(){

	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
    first = 0;
    current = 0;
    last = 0;
}
