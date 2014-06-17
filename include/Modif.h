#ifndef MODIF_H
#define MODIF_H


class Modif
{
	public:
		Modif(int color = 2, int direction = 1);
		Modif(const Modif&modif);
		virtual ~Modif();
		int getColor();
		int getDirection();
		void setColor(int color);
		void setDirection(int direction);
	protected:
		int color;
		int direction;
	private:
};

#endif // MODIF_H
