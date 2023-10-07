#pragma once
#include <cmath>

double delta_calculation(double rate, double spot, double strike, double time_maturity, double sigma, char type='c');
double vega_calculation(double rate, double spot, double strike, double time_maturity, double sigma, char type='c');
double theta_calculation(double rate, double spot, double strike, double time_maturity, double sigma, char type='c');
double rho_calculation(double rate, double spot, double strike, double time_maturity, double sigma, char type='c');
double gamma_calculation(double rate, double spot, double strike, double time_maturity, double sigma, char type='c');

