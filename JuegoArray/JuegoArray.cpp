#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Character.h"
using namespace std;


    const int ROWS = 10;
    const int COLUMNS = 10;
    const char PLAYER = '@';
    const char ENEMY = 'X';
    const char EXIT = '0';
    const char EMPTY = '#';

void printMap(char map[ROWS][COLUMNS], Character hero, int exitRow, int exitCol, Character enemy1, Character enemy2, Character enemy3, Character enemy4) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i == hero.getRow() && j == hero.getCol()) {
                cout << "\033[34m" << PLAYER << "\033[0m" << " ";
            }
            else if (i == exitRow && j == exitCol){
                cout << "\033[1;31m" << EXIT << "\033[0m" << " ";
            }
            else {
                cout << "\033[32m" << EMPTY << "\033[0m" << " ";
            }
        }
        cout << endl;
    }
}

void fight(Character enemy, Character hero) {
    enemy.printStats();
    cout << endl;
    if (hero.getSpeed() >= enemy.getSpeed()) {
        cout << "Tienes mas velocidad que el enemigo por lo que atacaras antes." << endl;
        Sleep(2000);
        while (enemy.getHp() > 0 && hero.getHp() > 0) {
            enemy.setHp(enemy.getHp() - hero.getDamage());
            cout << "Al enemigo le quedan " << enemy.getHp() << " de vida." << endl;
            Sleep(2000);
            if (enemy.getHp() <= 0) {
                cout << "El enemigo " << enemy.getName() << " ha muerto." << endl;
                return;
            }
            cout << "Le toca atacar el enemigo." << endl;
            hero.setHp(hero.getHp() - enemy.getDamage());
            Sleep(2000);
            cout << "Te quedan " << hero.getHp() << endl;
            Sleep(2000);
            if (hero.getHp() <= 0) {
                cout << "El enemigo te ha derrotado." << endl;
                return;
            }
        }

    }
    else {
        cout << "Tienes menos velocidad que el enemigo por lo que el enemigo atacara primero." << endl;
        Sleep(2000);
        while (enemy.getHp() > 0 && hero.getHp() > 0) {
            hero.setHp(enemy.getHp() - enemy.getDamage());
            cout << "Te quedan " << hero.getHp() << " de vida." << endl;
            Sleep(2000);
            if (hero.getHp() <= 0) {
                cout << "El enemigo te ha derrotado." << endl;
                return;
            }
            cout << "Te toca atacar." << endl;
            enemy.setHp(enemy.getHp() - hero.getDamage());
            Sleep(2000);
            cout << "Al enemigo le quedan " << enemy.getHp() << " de vida." << endl;
            Sleep(2000);
            if (enemy.getHp() <= 0) {
                cout << "El enemigo " << enemy.getName() << " ha muerto." << endl;
                Sleep(2000);
                return;
            }
        }
    }
}

void checkPos(char map[ROWS][COLUMNS], Character hero, int exitRow, int exitCol, Character enemy1, Character enemy2, Character enemy3, Character enemy4, Character finalBoss) {
    if (map[hero.getRow()][hero.getCol()] == map[exitRow][exitCol]) {
        cout << "Enhorabuena has llegado al final" << endl;
        Sleep(2000);
        cout << "Pero para ganar la partida tienes que derrotar al jefe que aguarda la puerta" << endl;
        Sleep(2000);
        fight(finalBoss, hero);
    }
    else if (map[hero.getRow()][hero.getCol()] == map[enemy1.getRow()][enemy1.getCol()]) {
        cout << "Oh no!!!" << endl;
        Sleep(2000);
        cout << "Te has encontrado al enemigo " << enemy1.getName() << endl;
        Sleep(2000);
        cout << "Para avanzar deberas derrotarlo primero" << endl;
        Sleep(2000);
        fight(enemy1, hero);
    }

    else if (map[hero.getRow()][hero.getCol()] == map[enemy2.getRow()][enemy2.getCol()]) {
        cout << "Oh no!!!" << endl;
        Sleep(2000);
        cout << "Te has encontrado al enemigo " << enemy2.getName() << endl;
        Sleep(2000);
        cout << "Para avanzar deberas derrotarlo primero" << endl;
        Sleep(2000);
        fight(enemy2, hero);
    }

    else if (map[hero.getRow()][hero.getCol()] == map[enemy3.getRow()][enemy3.getCol()]) {
        cout << "Oh no!!!" << endl;
        Sleep(2000);
        cout << "Te has encontrado al enemigo " << enemy3.getName() << endl;
        Sleep(2000);
        cout << "Para avanzar deberas derrotarlo primero" << endl;
        Sleep(2000);
        fight(enemy3, hero);
    }
    else if (map[hero.getRow()][hero.getCol()] == map[enemy4.getRow()][enemy4.getCol()]) {
        cout << "Oh no!!!" << endl;
        Sleep(2000);
        cout << "Te has encontrado al enemigo " << enemy4.getName() << endl;
        Sleep(2000);
        cout << "Para avanzar deberas derrotarlo primero" << endl;
        Sleep(2000);
        fight(enemy4, hero);
    }
    else {
        return;
    }
}

int main() {
    srand(time(NULL));
    int exitCol = rand() % COLUMNS;
    int exitRow = ROWS - 1;
    //PERSONAJES
    Character hero("Manolo",5000,50,50,0, int(COLUMNS / 2));
    Character finalBoss("Jorge", 200, 50, 50,exitRow,exitCol);
    Character enemy1("Marcos", rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, rand() % ROWS, rand() % COLUMNS);
    Character enemy2("Leo", rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, rand() % ROWS, rand() % COLUMNS);
    Character enemy3("Xavi", rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, rand() % ROWS, rand() % COLUMNS);
    Character enemy4("Arnau", rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, rand() % ROWS, rand() % COLUMNS);
    //MAPA
    char map[ROWS][COLUMNS];

    // Se crea la array con los huecos vacios
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            map[i][j] = EMPTY;
        }
    }
    // Se coloca la salida (0) en una posición aleatoria de la última fila
    //Se setea la posicion de la array con el caracter de la salida
    map[exitRow][exitCol] = EXIT;

    // Se coloca al jugador (@) en la posición (1, 5)
    //Se setea la posicion del jugador con el caracter del jugador
    map[hero.getRow()][hero.getCol()] = PLAYER;
    

    // Se imprime la matriz inicial
    printMap(map, hero, exitRow, exitCol, enemy1, enemy2, enemy3, enemy4);

    // Bucle de juego
    while (hero.getHp() > 0 && finalBoss.getHp() > 0) {
        // Se guarda la tecla
        char key = _getch();
        // Se cambia la posicion dependiendo de la tecla
        switch (key) {
        case 'w':
            if (hero.getRow() > 0) {
                map[hero.getRow()][hero.getCol()] = EMPTY;
                hero.setRow(hero.getRow() - 1);
                map[hero.getRow()][hero.getCol()] = PLAYER;
            }
            break;
        case 'a':
            if (hero.getCol() > 0) {
                map[hero.getRow()][hero.getCol()] = EMPTY;
                hero.setCol(hero.getCol() - 1);
                map[hero.getRow()][hero.getCol()] = PLAYER;
            }
            break;
        case 's':
            if (hero.getRow() < ROWS - 1) {
                map[hero.getRow()][hero.getCol()] = EMPTY;
                hero.setRow(hero.getRow() + 1);
                map[hero.getRow()][hero.getCol()] = PLAYER;
            }
            break;
        case 'd':
            if (hero.getCol() < COLUMNS - 1) {
                map[hero.getRow()][hero.getCol()] = EMPTY;
                hero.setCol(hero.getCol() + 1);
                map[hero.getRow()][hero.getCol()] = PLAYER;
            }
            break;
        default:
            break;
        }

        // Se vuelve a imprimir el mapa
        system("cls");
        printMap(map, hero, exitRow, exitCol, enemy1, enemy2, enemy3, enemy4);
        checkPos(map, hero, exitRow, exitCol, enemy1, enemy2, enemy3, enemy4,finalBoss);

    }

    return 0;
}
