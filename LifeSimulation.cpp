#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

#include "constants.h"
#include "LifeSimulation.h"

Life curr_life;
Life prev_life;

//initializes curr_life and prev_life
void init(const size_t size) {
#ifndef INIT
#define INIT
#endif INIT
	//init curr_life
	curr_life = {size,new bool*[size],0};
	for (size_t i = 0; i < size; ++i) {
		curr_life._world[i] = new bool[size];
	}
	//initialize all cells as dead
	for (size_t i = 0; i < size;++i) {
		for (size_t j = 0; j < size;++j) {
			curr_life._world[i][j] = {0};
		}
	}
	//prev_life equals to curr_life at the begining
	prev_life = { size,new bool* [size],0 };
	for (size_t i = 0; i < size; ++i) {
		prev_life._world[i] = new bool[size];
	}
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			prev_life._world[i][j] = { 0 };
		}
	}
}

//shows the current generation of the life in the console
void showLife(const Life& life) {
	cout << '+';
	for (size_t i = 0; i < life._N; ++i) {
		cout << "--";
	}
	cout << '+' << endl;
	for (size_t i = 0; i < life._N; ++i) {
		cout << '|';
		for (size_t j = 0; j < life._N; ++j) {
			if (life._world[i][j])
				cout << " *";
			else cout << "  ";
		}
		cout << '|' << endl;
	}
	cout << '+';
	for (size_t i = 0; i < life._N; ++i) {
		cout << "--";
	}
	cout << '+' << endl;
	cout << "\nGEN : " <<life._gen<< endl;
}

//counts all the living neighbors of the specified cell
const int countLives(const Life& life, int x, int y) {
	int lives_counter = 0;
	for (size_t i = -1; i <= 1; ++i) {
		for (size_t j = -1; j <= 1; ++j) {
			if (y + i >= 0 && y + i < life._N && x + j >= 0 && x + j < life._N) {
				if (life._world[y + i][x + j]) {
					++lives_counter;
				}
			}
		}
	}
	return lives_counter;
}

//calculates the next generation of the given life
void nextGen(Life& life) {
	for (size_t i = 0; i < life._N; ++i) {
		for (size_t j = 0; j < life._N; ++j) {
			int p = prev_life._world[i][j];
			int counter = countLives(prev_life,j, i);
			if (p) {
				if (counter <= 2)life._world[i][j] = 0;
				else if (counter == 3 || counter == 4)life._world[i][j] = 1;
				else if (counter > 4)life._world[i][j] = 0;
			}
			else  if (counter == 3)life._world[i][j] = 1;
		}
	}
	life._gen = prev_life._gen+1;
}

//copies one life into another
void copyLife(const Life& from, Life& to) {
	for (size_t i = 0; i < from._N; ++i) {
		for (size_t j = 0; j < from._N; ++j) {
			to._world[i][j] = from._world[i][j];
		}
	}
	to._gen = from._gen;
}

//compares one life to another
bool compareLives(const Life& life1, const Life& life2) {
	for (size_t i = 0; i < life1._N; ++i) {
		for (size_t j = 0; j < life1._N; ++j) {
			if (life1._world[i][j] != life2._world[i][j])return false;
		}
	}
	return true;
}

//method of simulation
//it continues to simulate untill the life`s gen`s counter reaches gens_limit
void simulateLife(const unsigned int gens_limit, Life& life) {
#ifndef INIT
	init(life._N);
#endif 
	size_t gens_counter = 0;
	copyLife(life, prev_life);
	while (gens_counter < gens_limit) {
		showLife(life);
		nextGen(life);
		copyLife(life, prev_life);
		gens_counter++;
		Sleep((DWORD)DELAY);
		system("cls");
	}
}

//method being called from the outside to simulate the world
//it translates the world into the life and starts it`s simulation
void simulateLife(const unsigned int gens_limit, unsigned** test_world,const size_t size) {
	init(size);
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			curr_life._world[i][j] =  test_world[i][j];
		}
	}
	simulateLife(gens_limit, curr_life);
}

//creates the new world NxN with random cells alive
unsigned** generateWorld(const size_t size) {
	srand((int)time(NULL));
	unsigned** world = new unsigned* [size];
	for (size_t i = 0; i < size; ++i) {
		world[i] = new unsigned[size];
	}
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			int rand = std::rand();
			if (rand % RANDOM_CHANCE)world[i][j] = {0};
			else world[i][j] = { 1 };
		}
	}
	return world;
}