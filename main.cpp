#include <iostream>
using namespace std;

#include "LifeSimulation.h"
#include "test_worlds.h"
#include "constants.h"

int main(void) {
	cout << "       *      *   * *                             * *   *      *       \n";
	cout << "* * * *   * *    *    *                         *    *    * *   * * * *\n";
	cout << " * *    *  * * *   *     Conway's Game of Life     *   * * *  *    * * \n";
	cout << "     *   *      *                                     *      *   *     \n";

	cout << "                             instructions                            \n\n";
	cout << "  The Game of Life, also known simply as Life, is a cellular automaton \n";
	cout << "devised by the British mathematician John Horton Conway in 1970.\n\n";
	cout << "  The game is a zero-player game, meaning that its evolution is determined\n";
	cout << "by its initial state, requiring no further input. One interacts with the\n";
	cout << "Game of Life by creating an initial configuration and observing how it evolves.\n\n";
	cout << "                                rules                                  \n\n";
	cout << "  The universe of the Game of Life is an infinite, two-dimensional orthogonal grid\n";
    cout << "of square cells, each of which is in one of two possible states, alive or dead,\n";
    cout << "(or populated and unpopulated, respectively). Every cell interacts with its eight\n";
	cout << "neighbours, which are the cells that are horizontally, vertically, or diagonally \n";
	cout << "adjacent. At each step in time, the following transitions occur:\n\n";
	cout << "1) Any live cell with fewer than two live neighbours dies, as if by underpopulation.\n";
	cout << "2) Any live cell with two or three live neighbours lives on to the next generation.\n";
	cout << "3) Any live cell with more than three live neighbours dies, as if by overpopulation.\n";
	cout << "4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.\n\n";
	cout << "  The initial pattern constitutes the seed of the system. The first generation is created \n";
	cout << "by applying the above rules simultaneously to every cell in the seed; births and deaths \n";
	cout << "occur simultaneously, and the discrete moment at which this happens is sometimes called\n";
	cout << "a tick. Each generation is a pure function of the preceding one. The rules continue to \n";
	cout << "be applied repeatedly to create further generations.\n\n";

	while (true) {
	    cout << "choose test-case:\n" << endl;

		cout << "[1] - TEST1;" << endl;
		cout << "[2] - TEST2;" << endl;
		cout << "[3] - TEST3;" << endl;
		cout << "[4] - Still lives representatives;" << endl;
		cout << "[5] - Oscillators;" << endl;
		cout << "[6] - PULSAR;" << endl;
		cout << "[7] - PENTA-DECATHLON;" << endl;
		cout << "[8] - Spaceships;" << endl;
		cout << "[9] - DIAMOND;" << endl;
		cout << "[10] - GUN;" << endl;
		cout << "[11] - BELUCHENKO`S p37;" << endl;
		cout << "[12] - randomly generate the world of size N;" << endl;
		
		int answer = 0;
		cout << "enter: ";
		cin >> answer;

		unsigned** test_world = 0;

		switch (answer) {
		case 1: {
			test_world = new unsigned* [TEST1_N];
			init2DWorld<TEST1_N>(test_world, TEST1);
			simulateLife(50, test_world, TEST1_N);
			break;
		}
		case 2: {
			test_world = new unsigned* [TEST2_N];
			init2DWorld<TEST2_N>(test_world, TEST2);
			simulateLife(10, test_world, TEST2_N);
			break;
		}
		case 3: {
			test_world = new unsigned* [TEST3_N];
			init2DWorld<TEST3_N>(test_world, TEST3);
			simulateLife(50, test_world, TEST3_N);
			break;
		}
		case 4: {
			test_world = new unsigned* [STILL_LIVES_N];
			init2DWorld<STILL_LIVES_N>(test_world, STILL_LIVES);
			simulateLife(10, test_world, STILL_LIVES_N);
			break;
		}
		case 5: {
			test_world = new unsigned* [OSCILLATORS_N];
			init2DWorld<OSCILLATORS_N>(test_world, OSCILLATORS);
			simulateLife(10, test_world, OSCILLATORS_N);
			break;
		}
		case 6: {
			test_world = new unsigned* [PULSAR_N];
			init2DWorld<PULSAR_N>(test_world, PULSAR);
			simulateLife(15, test_world, PULSAR_N);
			break;
		}
		case 7: {
			test_world = new unsigned* [PENTA_DECATHLON_N];
			init2DWorld<PENTA_DECATHLON_N>(test_world, PENTA_DECATHLON);
			simulateLife(15, test_world, PENTA_DECATHLON_N);
			break;
		}
		case 8: {
			test_world = new unsigned* [SPACESHIPS_N];
			init2DWorld<SPACESHIPS_N>(test_world, SPACESHIPS);
			simulateLife(20, test_world, SPACESHIPS_N);
			break;
		}
		case 9: {
			test_world = new unsigned* [DIAMOND_N];
			init2DWorld<DIAMOND_N>(test_world, DIAMOND);
			simulateLife(30, test_world, DIAMOND_N);
			break;
		}
		case 10: {
			test_world = new unsigned* [GUN_N];
			init2DWorld<GUN_N>(test_world, GUN);
			simulateLife(100, test_world, GUN_N);
			break;
		}
		case 11: {
			test_world = new unsigned* [BELUCHENKO_37_N];
			init2DWorld<BELUCHENKO_37_N>(test_world, BELUCHENKO_37);
			simulateLife(50, test_world, BELUCHENKO_37_N);
			break;
		}
		case 12: {
			int N;
			cout << "enter N-size: ";
			cin >> N;
			test_world = generateWorld(N);
			simulateLife(GENS_LIMIT, test_world, N);
			break;
		}
		}
		delete[] test_world;
		test_world = 0;
	}
	return 0;
}