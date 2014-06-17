#include "../include/State.h"
#include <iostream>

using namespace std;

State::State(int color, bool free)
{
	this->color = color;
	this->free = free;
}

State::~State()
{
	//dtor
}

int State::getColor()
{
	return this->color;
}

void State::setColor(int color)
{
	this->color = color;
}

bool State::getFree()
{
	return this->free;
}

void State::setFree(bool free)
{
	this->free = free;
}

void State::inverseFree()
{
	bool free = this->free;
	this->free = !free;
}
