#ifndef MODIFSCHIZO_H
#define MODIFSCHIZO_H
#include "../include/Modif.h"


class ModifSchizo : public Modif
{
	public:
		ModifSchizo(int color = 2, int direction = 1, int state = 1);
		virtual ~ModifSchizo();
		int getState();
		void setState(int state);
	protected:
	private:
		int state;
};

#endif // MODIFSCHIZO_H
