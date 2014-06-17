#include "../include/ModifSchizo.h"

ModifSchizo::ModifSchizo(int color, int direction, int state) : Modif(color, direction)
{
	this->state = state;
}

ModifSchizo::~ModifSchizo()
{
	//dtor
}

int ModifSchizo::getState()
{
	return this->state;
}

void ModifSchizo::setState(int state)
{
	this->state = state;
}
