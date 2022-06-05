#include "CellsCalc.h"

CellsCalc::CellsCalc()
{
}

CellsCalc::~CellsCalc()
{
}

std::vector<int_vec> CellsCalc::old_state_triplets(int_vec state)
{
    int first = state[0], last = state[state.size() - 1];
    state.push_back(first);
    state.insert(state.begin(), last);
    std::vector<int_vec> triplets;
    for (int i = 0; i < state.size() - 2; i++) {
        int_vec triplet{ state[i], state[i + 1], state[i + 2] };
        triplets.push_back(triplet);
    }
    return triplets;
}

int CellsCalc::new_cell_state(int_vec triplet, int_vec rule)
{
    return rule[9 * triplet[0] + 3 * triplet[1] + triplet[2]];;
}

int_vec CellsCalc::new_state(int_vec old_state, int_vec rule)
{
    std::vector<int_vec> triplets = old_state_triplets(old_state);
    int_vec new_state;
    for (int_vec triplet : triplets) {
        new_state.push_back(new_cell_state(triplet, rule));
    }
    return new_state;
}

int_vec CellsCalc::decimal_to_ternary(long long int dec)
{
    int_vec rule;
    while (dec > 0) {
        int n = dec % 3;
        rule.insert(rule.begin(), n);
        dec = dec / 3;
    }
    while (rule.size() < 27) {
        rule.insert(rule.begin(), 0);
    }
    return rule;
}

std::vector<int_vec> CellsCalc::evolution(int_vec first_state, long long int rule, int steps)
{
    int_vec rule_vec = decimal_to_ternary(rule);
    std::vector<int_vec> states;
    states.push_back(first_state);
    int_vec current_state = first_state;
    for (int i = 1; i <= steps; i++) {
        current_state = new_state(current_state, rule_vec);
        states.push_back(current_state);
    }
    return states;
}

int_vec CellsCalc::random_state(int len)
{   
    int_vec state;
    for (int i = 0; i < len; i++) {
        state.push_back(rand() % 3);
    }
    return state;
}
