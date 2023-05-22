#pragma once
#include <windows.h>
#include <iostream>
using namespace std;
class Character
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
		Character();
		Character(string pName, int pHp, int pDamage, int pSpeed, int pRow, int pCol);

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
		
		//METHODS

		void printStats();
};

