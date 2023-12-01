#pragma once
#include <iostream>
#include "utilidades.h"
using namespace System;
using namespace std;

const int ARRIBA = 72;
const int ABAJO = 80;
const int DERECHA = 77;
const int IZQUIERDA = 75;

struct Personaje {
    int x;
    int y;
    int vidas = 5;
    int dir = 1;
    char cabeza = '$';
};

void dibujarPersonaje(Personaje* personaje, int posX, int posY) {
    personaje->x = posX;
    personaje->y = posY;
    asignarColor(15);
    asignarPosicion(personaje->x, personaje->y);
    cout << personaje->cabeza;
}

void borrarPersonaje(Personaje* personaje, int posX, int posY) {
    personaje->x = posX;
    personaje->y = posY;
    asignarColor(8);
    asignarPosicion(personaje->x, personaje->y);
    cout << char(' ');
}

