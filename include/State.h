#ifndef STATE_H
#define STATE_H


class State
{
	public:
		State(int color = 1, bool free = true);
		virtual ~State();
		int getColor();
		bool getFree();
		void setColor(int color);
		void setFree(bool free);
		void inverseFree();
	protected:
	private:
		int color;
		bool free;
};

#endif // STATE_H
