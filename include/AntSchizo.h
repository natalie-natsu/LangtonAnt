#ifndef ANTSCHIZO_H
#define ANTSCHIZO_H
#include "../include/Ant.h"
#include "../include/ModifSchizo.h"


class AntSchizo : public Ant
{
	public:
		AntSchizo(Board &board, int state = 1, int c11 = 2, int d11 = 1, int e11 = 2, int c12 = 2, int d12 = 2, int e12 = 2, int c21 = 1, int d21 = 1, int e21 = 2, int c22 = 1, int d22 = 1, int e22 = 1);
		virtual ~AntSchizo();
		int getState();
		void setState(int state);
		void moving(Board &board);
	protected:
	private:
		int state;
		ModifSchizo rules[2][2];
};

#endif // ANTSCHIZO_H
