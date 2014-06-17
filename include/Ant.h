#ifndef ANT_H
#define ANT_H
#include "../include/Modif.h"
#include "../include/Board.h"


class Ant
{
	public:
		Ant(Board &board, int color1 = 2, int direction1 = 1, int color2 = 1, int direction2 = 2, int speed = 1);
		Ant(const Ant&ant);
		virtual ~Ant();
		int getI();
		void setI(int i);
		int getJ();
		void setJ(int j);
		int getDirection();
		void setDirection(int direction);
		void changeDirection(int d);
		void moving(Board &board);
	protected:
		int i;
		int j;
		int direction;
		int speed;
		Modif rules[2];
	private:
};

#endif // ANT_H
