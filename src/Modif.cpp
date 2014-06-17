#include "../include/Modif.h"

Modif::Modif(int color, int direction)
{
	this->color = color;
	this->direction = direction;
}

Modif::Modif(const Modif&modif)
{
	this->color = modif.color;
	this->direction = modif.direction;

}

Modif::~Modif()
{
	//dtor
}

int Modif::getColor()
{
	return this->color;
}

void Modif::setColor(int color)
{
	this->color = color;
}

int Modif::getDirection()
{
	return this->direction;
}

void Modif::setDirection(int direction)
{
	this->direction = direction;
}
