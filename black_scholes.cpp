#include "black_scholes.h"
#include <stdexcept>
#include "utils.h"

// Ref.
// https://www.macroption.com/black-scholes-formula/
// https://quantpy.com.au/

double black_scholes(double rate, 
    double spot, 
    double strike, 
    double time_maturity, 
    double sigma, 
    char type) 
{
  double d1 = (std::log(spot/strike) + (rate + std::pow(sigma, 2) / 2.0) * time_maturity) / (sigma * std::sqrt(time_maturity));
  double d2 = d1 - sigma * std::sqrt(time_maturity);
  
  double price;
  if(type == 'c') {
    price = spot * norm_cdf(d1) - strike * std::exp(-rate * time_maturity) * norm_cdf(d2);
  } else if(type == 'p') {
    price = strike * std::exp(-rate * time_maturity) * norm_cdf(-d2) - spot * norm_cdf(-d1);
  } else {
    throw std::invalid_argument("Incorrect option type, it should be either 'c' or 'p'");
  }
  
  return price;
}

