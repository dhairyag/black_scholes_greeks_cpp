#include <iostream>
#include "black_scholes.h"
#include "greeks.h"
#include <iomanip> 

int main() 
{
  // inputs to calculate option prices and greeks
  // risk free interest rate
  double rate = 0.01;
  // underlying price
  double spot = 100.0;
  // strike price
  double strike = 95.0;
  // time till expiration in fraction of a year
  double time_maturity = 3.0 / 12.0;
  // volatility sigma
  double sigma = 0.50;
  // 'c' for call and 'p' for put option
  char option_type = 'c';

  try {
    auto call_price = black_scholes(rate, spot, strike, time_maturity, sigma, 'c');
    auto put_price = black_scholes(rate, spot, strike, time_maturity, sigma, 'p');
    std::cout << "call option price: " << std::fixed << std::setprecision(3) << call_price << std::endl;
    std::cout << "put option price: " << std::fixed << std::setprecision(3) << put_price << std::endl;
    
    // Delta
    auto delta_result = delta_calculation(rate, spot, strike, time_maturity, sigma, option_type);  
    std::cout << "delta: " << std::fixed << std::setprecision(3) << delta_result << std::endl;

    // Gamma
    auto gamma_result = gamma_calculation(rate, spot, strike, time_maturity, sigma, option_type);
    std::cout << "gamma: " << std::fixed << std::setprecision(3) << gamma_result << std::endl;

    // Vega
    auto vega_result = vega_calculation(rate, spot, strike, time_maturity, sigma, option_type);  
    std::cout << "vega : " << std::fixed << std::setprecision(3) << vega_result << std::endl;

    // Theta
    auto theta_result = theta_calculation(rate, spot, strike, time_maturity, sigma, option_type);  
    std::cout << "theta: " << std::fixed << std::setprecision(3) << theta_result  << std::endl;

    // Rho
    auto rho_result = rho_calculation(rate, spot, strike, time_maturity, sigma, option_type);
    std::cout << "rho  : " << std::fixed << std::setprecision(3) << rho_result << std::endl;
    
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

