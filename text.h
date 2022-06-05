#pragma once
#include <string>

std::string text_source1 = "Welcome to Cellular Automaton!\n\nA cellular automaton is a grid of celss, each of which"
" is in one of finite number of states.In this example, the cells' states include 0, 1 and 2. The cells are "
"represented as a line of squares, with colors corresponding to states. We define a function (rule) for stransitioning"
" the set of cells from one state to another, which appears as a new line of cells under the previous one. "
"After some number of transitions, we obtain a pixelized image. \n\nThe transition rule acting on a cell "
"takes its current state, as well as the states of its two neighbours as arguments.This set of 3 arguments "
"corresponds to a 3 - digit ternary number(0 to 26 decimal).Therefore, we set the rule to be a 27 - digit ternary "
"number (0 to 7625597484986 decimal).The function works as following : if the argumnets form a decimal number N,"
"then the next state of the cell is the ternary digit, that correspons to the N - th power of 3 ((N + 1)th position "
"in the rule number)).";