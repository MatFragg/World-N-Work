#pragma once
#include "mapa.h"
#include "personaje.h"

struct enemigo {
	int x;
	int y;
	int dir;
	bool dir2;
	char c = 'M';
};

enemigo** spawnEnemigos(enemigo** arr, int n) {
	enemigo** newArr = new enemigo*[n + 1];
	for (int i = 0; i < n; i++) {
		newArr[i] = arr[i];
	}
	enemigo* e = new enemigo();
	do {
		e->x = rand() % 54 + 5;
		e->y = rand() % 28 + 1;
		e->dir = 1;
		e->dir2 = rand() % 2;

	} while (mapa[e->y][e->x] == 1);
	newArr[n] = e;
	delete[]arr;
	return newArr;
}

enemigo** deleteEnemigo(enemigo** arr, int &n, int j) {
	enemigo** newArr = new enemigo * [n - 1];
	enemigo* temp = NULL;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		if (i == j) {
			asignarPosicion(arr[i]->x, arr[i]->y);
			cout << " ";
			temp = arr[i];
			ok = true;
		}
		else newArr[i - ok] = arr[i];
	}
	delete temp;
	delete[]arr;
	n--;
	return newArr;
}

void moverEnemigos(enemigo** &arr, int n) {
	for (int i = 0; i < n; i++) {
		asignarPosicion(arr[i]->x, arr[i]->y);
		cout << " ";
		if (arr[i]->dir2) {
			if (mapa[arr[i]->y][arr[i]->x + arr[i]->dir] == 1) {
				arr[i]->dir *= -1;
			}
			arr[i]->x += arr[i]->dir;
		}
		else {
			if (mapa[arr[i]->y + arr[i]->dir][arr[i]->x] == 1) {
				arr[i]->dir *= -1;
			}
			arr[i]->y += arr[i]->dir;
		}
		asignarColor(12);
		asignarPosicion(arr[i]->x, arr[i]->y);
		cout << arr[i]->c;
	}
}

bool tocarEnemigo(Personaje* &p1, enemigo** &arr, int &n) {
	for (int i = 0; i < n; i++) {
		int y = arr[i]->y, x = arr[i]->x;
		if (y >= p1->y && y < p1->y + 1 && x >= p1->x && x < p1->x + 2) {
			p1->vidas--;
			arr = deleteEnemigo(arr, n, i);
			return true;
		}
	}
	return false;
}
