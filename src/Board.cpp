#include "../include/Board.h"
#include <iostream>
#include <fstream>

using namespace std;

Board::Board(int height, int width)
{
	if (height < 1 || width < 1 || height % 2 == 0 || width % 2 == 0)
	{
		this->height = 21;
		this->width = 51;
	}
	else
	{
		this->height = height;
		this->width = width;
	}

	this->tab = new State*[this->width];
	for(int i = 0 ; i < this->width ; i++)
      this->tab[i] = new State[this->height];
}

Board::Board(const Board &board)
{
	this->height = board.height;
	this->width = board.width;

	this->tab = new State*[this->width];
	for(int i = 0 ; i < this->width ; i++)
      this->tab[i] = new State[this->height];

	for(int i = 0 ; i < this->width ; i++) {
		for(int j = 0 ; j < this->height ; j++) {
			this->tab[i][j] = board.tab[i][j];
		}
	}
}

Board& Board::operator=(Board &board)
{
	for(int i = 0 ; i < this->width ; i++)
		delete[] this->tab[i];
	delete[] this->tab;

	this->height = board.height;
	this->width = board.width;

	this->tab = new State*[this->width];
	for(int i = 0 ; i < this->width ; i++)
      this->tab[i] = new State[this->height];

	for(int i = 0 ; i < this->width ; i++) {
		for(int j = 0 ; j < this->height ; j++) {
			State *state(0);
			state = board.getTab(i, j);
			this->tab[i][j] = State(state->getColor(), state->getFree());
		}
	}

	return *this;
}

Board::~Board()
{
	for(int i = 0 ; i < this->width ; i++)
		delete[] this->tab[i];

	delete[] this->tab;
}

Board& Board::operator++()
{
	Board oldBoard(*this);

	for(int i = 0 ; i < this->width ; i++)
		delete[] this->tab[i];
	delete[] this->tab;

	this->setHeight(this->height + 2);
	this->setWidth(this->width + 2);

	this->tab = new State*[this->width];
	for(int i = 0 ; i < this->width ; i++)
      this->tab[i] = new State[this->height];

	for(int i = 0; i < oldBoard.width; i++){
		for(int j = 0; j < oldBoard.height; j++){
			this->tab[i+1][j+1] = State(oldBoard.tab[i][j]);
		}
	}
	return *this;
}

int Board::getWidth()
{
	return this->width;
}

void Board::setWidth(int width)
{
	this->width = width;
}

int Board::getHeight()
{
	return this->height;
}

void Board::setHeight(int height)
{
	this->height = height;
}

State* Board::getTab(int i, int j)
{
	return &this->tab[i][j];
}

void Board::display()
{
	for(int y = 0 ; y < this->height ; y++)
	{
		for(int x = 0 ; x < this->width ; x++)
		{
			cout << (this->tab[x][y].getFree() == false ? "o" : (this->tab[x][y].getColor() == 1 ? " " : "."));
		}
		cout << endl;
	}
	cout << endl;
}

void Board::display_file()
{
	ofstream board;
	board.open ("2ADS_board.txt");

	board << "// 2ADS - SUPINFO LYON - AUTOMATE CELLULAIRE - 158390 //" << endl << endl;
	for(int y= 0 ; y < this->height ; y++)
	{
		for(int x = 0 ; x < this->width ; x++)
		{
			board << (this->tab[x][y].getFree() == false ? "o" : (this->tab[x][y].getColor() == 1 ? " " : "."));
		}
		board << endl;
	}
	board << endl;
	board.close();
}
