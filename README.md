# Option Pricing and Greeks with Black-Scholes Model

The code implements the formulae to get option prices and greeks for following input
parameters from `main.cpp` as-
```
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
```

The code can be compiled as follows-
```
$ make
```
The code execution is `./exe_out` and the output follows the format-
```
  call option price: 12.528
  put option price: 7.291
  delta: 0.633
  gamma: 0.015
  vega : 0.188
  theta: -0.053
  rho  : 0.127
```
