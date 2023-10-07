#include "greeks.h"
#include <stdexcept>
#include "utils.h"

// Ref:
// https://www.macroption.com/black-scholes-formula/
// assumption: dividend yield is zero
// hence prefactor exp(-yield * time) = 1

double delta_calculation(double rate, 
    double spot, 
    double strike, 
    double time_maturity, 
    double sigma, 
    char type) 
{
  double d1 = (std::log(spot/strike) + (rate + std::pow(sigma, 2) / 2.0) * time_maturity) / (sigma * std::sqrt(time_maturity));
  
  if(type == 'c') {
    return norm_cdf(d1);
  } else if(type == 'p') {
    return -norm_cdf(-d1);
  } else {
    throw std::invalid_argument("Incorrect option type, it should be either 'c' or 'p'");
  }
}

// "Vega is the first derivative of option price 
//  with respect to volatility \sigma. It is the same 
//  for calls and puts."
double vega_calculation(double rate, 
    double spot, 
    double strike, 
    double time_maturity, 
    double sigma, 
    char type) 
{
  double d1 = (std::log(spot/strike) + (rate + std::pow(sigma, 2) / 2.0) * time_maturity) / (sigma * std::sqrt(time_maturity));
  
  return spot * norm_pdf(d1) * std::sqrt(time_maturity) * 0.01;
}

// "Theta is the first derivative of option price 
//  with respect to time to expiration t."
double theta_calculation(double rate, 
    double spot, 
    double strike, 
    double time_maturity, 
    double sigma, 
    char type) 
{
  double d1 = (std::log(spot/strike) + (rate + std::pow(sigma, 2) / 2.0) * time_maturity) / (sigma * std::sqrt(time_maturity));
  double d2 = d1 - sigma * std::sqrt(time_maturity);
  
  if(type == 'c') {
    return (-spot * norm_pdf(d1) * sigma / (2 * std::sqrt(time_maturity)) - rate * strike * std::exp(-rate * time_maturity) * norm_cdf(d2)) / 365.0;
  } else if(type == 'p') {
    return (-spot * norm_pdf(d1) * sigma / (2 * std::sqrt(time_maturity)) + rate * strike * std::exp(-rate * time_maturity) * norm_cdf(-d2)) / 365.0;
  } else {
    throw std::invalid_argument("Incorrect option type, it should be either 'c' or 'p'");
  }
}

// "Rho is the first derivative of option price 
//  with respect to interest rate r. It is different 
//  for calls and puts."
double rho_calculation(double rate, 
    double spot, 
    double strike, 
    double time_maturity, 
    double sigma, 
    char type) 
{
  double d1 = (std::log(spot/strike) + (rate + std::pow(sigma, 2) / 2.0) * time_maturity) / (sigma * std::sqrt(time_maturity));
  double d2 = d1 - sigma * std::sqrt(time_maturity);
  
  double rho;
  if(type == 'c') {
    rho = strike * time_maturity * std::exp(-rate * time_maturity) * norm_cdf(d2);
  } else if(type == 'p') {
    rho = -strike * time_maturity * std::exp(-rate * time_maturity) * norm_cdf(-d2);
  } else {
    throw std::invalid_argument("Incorrect option type, it should be either 'c' or 'p'");
  }
  return rho * 0.01;
}

// "Gamma is the second derivative of option price with respect to 
//  underlying price S. It is the same for calls and puts."
double gamma_calculation(double rate, 
    double spot, 
    double strike, 
    double time_maturity, 
    double sigma, 
    char type) 
{
  double d1 = (std::log(spot/strike) + (rate + std::pow(sigma, 2) / 2.0) * time_maturity) / (sigma * std::sqrt(time_maturity));

  double gamma = norm_pdf(d1) / (spot * sigma * std::sqrt(time_maturity));
  return gamma;  
}

