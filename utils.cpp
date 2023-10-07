#include <cmath>

// function to calculate cumulative distribution function
// of the standard normal distribution
double norm_cdf(double value) {
    return 0.5 * (1.0 + std::erf(value / std::sqrt(2.0)));
}

// function to calculate PDF of the standard normal distribution
double norm_pdf(double value) 
{
  return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * value * value);
}
