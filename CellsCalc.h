#pragma once
#include <vector>
#include <random>
typedef std::vector<int> int_vec;

class CellsCalc
{
public:
	CellsCalc();
	~CellsCalc();
	std::vector<int_vec> old_state_triplets(int_vec);
	int new_cell_state(int_vec, int_vec);
	int_vec new_state(int_vec, int_vec);
	int_vec decimal_to_ternary(long long int);
	std::vector<int_vec> evolution(int_vec, long long int, int);
	int_vec random_state(int);
};

