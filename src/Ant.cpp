#include "../include/Ant.h"

#include <iostream>
using namespace std;

Ant::Ant(Board &board, int color1, int direction1, int color2, int direction2, int speed)
{
	State *state(0);
	int k = 0;
	do
	{
		this->i = ((board.getWidth() - 1) / 2) + k;
		this->j = ((board.getHeight() - 1) / 2) + k;
		state = board.getTab(this->i, this->j);
		k++;
	}
	while(state->getFree() == false);
	state->inverseFree();


	this->direction = 1;
	this->speed = speed;

	this->rules[0].setColor(color1);
	this->rules[0].setDirection(direction1);
	this->rules[1].setColor(color2);
	this->rules[1].setDirection(direction2);
}

Ant::Ant(const Ant&ant)
{
	this->i = ant.i;
	this->j = ant.j;
	this->direction = ant.direction;
	this->rules[0] = Modif(ant.rules[0]);
	this->rules[1] = Modif(ant.rules[1]);
}

Ant::~Ant()
{
	//dtor
}

int Ant::getI()
{
	return this->i;
}

void Ant::setI(int i)
{
	this->i = i;
}

int Ant::getJ()
{
	return this->j;
}

void Ant::setJ(int j)
{
	this->j = j;
}

int Ant::getDirection()
{
	return this->direction;
}

void Ant::setDirection(int direction)
{
	this->direction = direction;
}

void Ant::changeDirection(int d)
{
	if (d == 1) // Si la fourmi se déplace à 90° vers la gauche
	{
		this->direction == 4 ? this->direction = 1 : this->direction++;
	}
	else if (d == 2) // Si la fourmi se déplace à 90° vers la droite
	{
		this->direction == 1 ? this->direction = 4 : this->direction--;
	}
}

void Ant::moving(Board &board)
{
	int colision = 1;
	State *state(0);
	state = board.getTab(this->i, this->j);

	while(colision == 1)
	{
		if (state->getColor() == 1) // Si la case est blanche
		{
			this->changeDirection(this->rules[0].getDirection()); // On change la direction selon les règles
			state->setColor(this->rules[0].getColor()); // On redéfinit la couleur selon les règles
		}
		else if (state->getColor() == 2) // Si la case est noire
		{
			this->changeDirection(this->rules[1].getDirection()); // On change la direction selon les règles
			state->setColor(this->rules[1].getColor()); // On redéfinit la couleur selon les règles
		}

		switch (this->getDirection()) // Selon la direction, on bouge la forumi et on inverse la disponibilité de la case sur laquelle elle se trouve
		{
			case 1: // Nord
				if(board.getTab(this->i, this->j - 1)->getFree()){
					colision = 0;
					this->j--;
				}
				break;
			case 2: // Ouest
				if(board.getTab(this->i - 1, this->j)->getFree()){
					colision = 0;
					this->i--;
				}

				break;
			case 3: // Sud
				if(board.getTab(this->i, this->j + 1)->getFree()){
					colision = 0;
					this->j++;
				}
				break;
			case 4: // Est
				if(board.getTab(this->i + 1, this->j)->getFree()){
					colision = 0;
					this->i++;
				}
				break;
			default:
				break;
		}
		state->inverseFree(); // On libère la case sur laquelle la fourmi se tenait
		state = board.getTab(this->i, this->j); // On récupère la nouvelle carse sur laquelle elle se tient
		state->inverseFree();
	}

	if((this->j == 0) || (this->j == board.getHeight() - 1) || (this->i == 0) || (this->i == board.getWidth() - 1))
	{
		++board;
		this->j++;
		this->i++;
	}
}
