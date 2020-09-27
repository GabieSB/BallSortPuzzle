#pragma once
class Movimiento
{
private:
	int x;
	int y;
	Movimiento* sig;
	Movimiento* ant;
	
	
public: 
	Movimiento(int,int, Movimiento* , Movimiento*);
	void setX(int );
	void setY(int);
	int getX();
	int getY();
	Movimiento *getSig();
	Movimiento* getAnt();
	void setSig(Movimiento *);
	void setAnt(Movimiento*);


};

