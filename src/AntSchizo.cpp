#include "../include/AntSchizo.h"

AntSchizo::AntSchizo(Board &board, int state, int c11, int d11, int e11, int c12, int d12, int e12, int c21, int d21, int e21, int c22, int d22, int e22) : Ant(board, c11, d11, c22, d22)
{
	this->state = state;

	this->rules[0][0].setColor(c11);
	this->rules[0][0].setDirection(d11);
	this->rules[0][0].setState(e11);

	this->rules[0][1].setColor(c12);
	this->rules[0][1].setDirection(d12);
	this->rules[0][1].setState(e12);

	this->rules[1][0].setColor(c21);
	this->rules[1][0].setDirection(d21);
	this->rules[1][0].setState(e21);

	this->rules[1][1].setColor(c22);
	this->rules[1][1].setDirection(d22);
	this->rules[1][1].setState(e22);
}

AntSchizo::~AntSchizo()
{
	//dtor
}

int AntSchizo::getState()
{
	return this->state;
}

void AntSchizo::setState(int state)
{
	this->state = state;
}

void AntSchizo::moving(Board &board)
{
	State *state(0);
	state = board.getTab(this->i, this->j);

	if (state->getColor() == 1)
	{
		if (this->state == 1)
		{
			this->changeDirection(this->rules[0][0].getDirection());
			this->setState(this->rules[0][0].getState());
			state->setColor(this->rules[0][0].getColor());
		}
		else if (this->state == 2)
		{
			this->changeDirection(this->rules[0][1].getDirection());
			this->setState(this->rules[0][1].getState());
			state->setColor(this->rules[0][1].getColor());
		}
	}
	else if (state->getColor() == 2)
	{
		if (this->state == 1)
		{
			this->changeDirection(this->rules[1][0].getDirection());
			this->setState(this->rules[1][0].getState());
			state->setColor(this->rules[1][0].getColor());
		}
		else if (this->state == 2)
		{
			this->changeDirection(this->rules[1][1].getDirection());
			this->setState(this->rules[1][1].getState());
			state->setColor(this->rules[1][1].getColor());
		}
	}

	switch (this->getDirection())
	{
		case 1: // Nord
			this->j-- ;
			break;
		case 2: // Ouest
			this->i-- ;
			break;
		case 3: // Sud
			this->j++ ;
			break;
		case 4: // Est
			this->i++ ;
			break;
		default:
			break;
	}

	state->inverseFree();
	state = board.getTab(this->i, this->j);
	state->inverseFree();

	if((this->j == 0) || (this->j == board.getHeight() - 1) || (this->i == 0) || (this->i == board.getWidth() - 1))
	{
		++board;
		this->j++;
		this->i++;
	}
}
