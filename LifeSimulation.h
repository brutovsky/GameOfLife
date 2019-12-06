#pragma once

// 0 - cell is dead
// 1 - cell is alive
struct Life {
	size_t _N;
	bool** _world;
	unsigned int _gen = 0;
};

void simulateLife(const unsigned int gens_limit, unsigned** test_world, const size_t size);

unsigned** generateWorld(const size_t size);

template <size_t N>
void init2DWorld(unsigned** array, const unsigned world[N][N]) {
	for (int i = 0; i < N; ++i) {
		array[i] = new unsigned[N];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int num = world[i][j];
			array[i][j] = num;
		}
	}
}
