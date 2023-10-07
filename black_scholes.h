#pragma once
#include <cmath>


double black_scholes(double rate, double spot, double strike, double time_maturity, double sigma, char type='c');

