#pragma once
#include "Character.h"
#include <iostream>
class FinalBoss : public Character
{
private:
	string name;
	int hp;
	int damage;
	int speed;
	int row;
	int col;
public:
	//CONSTRUCTOR
	FinalBoss();
	FinalBoss(string pName, int pHp, int pDamage,int ultraAttack, int megaAttack, int pSpeed, int pRow, int pCol);

	//GETTERS
	string getName();
	int getHp();
	int getDamage();
	int getSpeed();
	int getRow();
	int getCol();

	//SETTERS
	void setName(string pNombre);
	void setHp(int pHp);
	void setDamage(int pDamage);
	void setSpeed(int pSpeed);
	void setRow(int pRow);
	void setCol(int pCol);

};
