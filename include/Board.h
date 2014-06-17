#ifndef BOARD_H
#define BOARD_H
#include "../include/State.h"

class Board
{
	public:
		Board(int height = 21, int width = 51);
		Board(const Board &board);
		Board& operator=(Board &board);
		Board& operator++();
		virtual ~Board();
		int getWidth();
		int getHeight();
		State* getTab(int i, int j);
		void setWidth(int width);
		void setHeight(int height);
		void display();
		void display_file();
	protected:
	private:
		int height;
		int width;
		State **tab;
};

#endif // BOARD_H
