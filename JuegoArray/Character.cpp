#include "Character.h"
#include <windows.h>
#include <iostream>
using namespace std;

//CONSTRUCTOR
Character::Character() {
}

Character::Character(string pName, int pHp, int pDamage, int pSpeed, int pRow, int pCol) {
	name = pName;
	hp = pHp;
	damage = pDamage;
	speed = pSpeed;
	row = pRow;
	col = pCol;
}

//GETTERS
string Character::getName() {
	return name;
}
int Character::getHp() {
	return hp;
}
int Character::getDamage() {
	return damage;
}
int Character::getSpeed() {
	return speed;
}
int Character::getRow() {
	return row;
}
int Character::getCol() {
	return col;
}

//SETTERS
void Character::setName(string pName) {
	name = pName;
}
void Character::setHp(int pHp) {
	hp = pHp;
}
void Character::setDamage(int pDamage) {
	damage = pDamage;
}
void Character::setSpeed(int pSpeed) {
	speed = pSpeed;
}
void Character::setRow(int pRow) {
	row = pRow;
}
void Character::setCol(int pCol) {
	col = pCol;
}


//METHODS

void Character::printStats() {
	cout << name << " cuenta con " << hp << " de vida, " << damage << " de ataque y " << speed << " de velocidad de ataque.";
}