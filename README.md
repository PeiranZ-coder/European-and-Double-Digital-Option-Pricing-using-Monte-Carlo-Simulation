# European-and-Double-Digital-Option-Pricing-using-Monte-Carlo-Simulation

Implements a flexible option pricing framework in C++ using object-oriented programming principles and Monte Carlo simulation techniques. The framework supports pricing of standard European options (Call and Put) as well as a Double Digital Option under the Black-Scholes model.

The primary objective is to demonstrate the use of inheritance, polymorphism, abstract classes, and payoff abstraction while building a reusable Monte Carlo pricing engine.

---

## Option Payoff Definitions

### European Call Option

The payoff at maturity is:

[
C_T = \max(S_T - K, 0)
]

where:

* (S_T) = underlying asset price at maturity
* (K) = strike price

### European Put Option

The payoff at maturity is:

[
P_T = \max(K - S_T, 0)
]

### Double Digital Option

A Double Digital Option pays:

[
D_T =
\begin{cases}
1, & K_1 < S_T < K_2 \
0, & \text{otherwise}
\end{cases}
]

where:

* (K_1) = lower strike
* (K_2) = upper strike

---

## Project Structure

The pricing framework consists of the following components:

* `PayOff.h / PayOff.cpp`

  * Abstract payoff base class
  * European Call payoff implementation
  * European Put payoff implementation

* `DoubleDigital.h / DoubleDigital.cpp`

  * Double Digital payoff implementation
  * Double strike parameter handling

* `Random.h / Random.cpp`

  * Standard normal random number generation

* `SimpleMC.h / SimpleMC.cpp`

  * Generic Monte Carlo pricing engine

* `DDMain.cpp`

  * Main program for pricing and testing

---

## Object-Oriented Design

The project uses polymorphism to decouple payoff definitions from the pricing engine.

### Base Class

```cpp
class PayOff {
public:
    virtual double operator()(const double& S) const = 0;
};
```

### Derived Classes

* `PayOffCall`
* `PayOffPut`
* `PayOffDoubleDigital`

Each derived class overrides the payoff operator while sharing the same Monte Carlo pricing engine.

This design allows new exotic options to be added without modifying the simulation framework.

---

## Monte Carlo Pricing Methodology

Under the Black-Scholes assumptions, the terminal asset price is simulated as:

[
S_T =
S_0
\exp
\left(
(r-\frac{1}{2}\sigma^2)T
+
\sigma \sqrt{T} Z
\right)
]

where:

* (S_0) = initial asset price
* (r) = risk-free interest rate
* (\sigma) = volatility
* (Z \sim N(0,1))

For each simulated path:

1. Generate a standard normal random variable.
2. Simulate the terminal stock price.
3. Evaluate the option payoff.
4. Average all payoffs.
5. Discount the expected payoff back to present value.

The option value is estimated by:

[
V_0 =
e^{-rT}
\frac{1}{N}
\sum_{i=1}^{N}
Payoff_i
]

---

## Numerical Experiment

### Parameters

| Parameter           | Value  |
| ------------------- | ------ |
| Maturity (T)        | 1 year |
| Initial Price (S_0) | 50     |
| Lower Strike (K_1)  | 43     |
| Upper Strike (K_2)  | 57     |
| Strike (K)          | 50     |
| Volatility (\sigma) | 30%    |
| Risk-Free Rate (r)  | 5%     |

The Monte Carlo engine is used to price:

* European Call Option
* European Put Option
* Double Digital Option

under identical market conditions.

---

## Key Learning Outcomes

* Applied object-oriented programming concepts in C++
* Implemented inheritance and runtime polymorphism
* Built a reusable Monte Carlo pricing framework
* Simulated Black-Scholes asset dynamics
* Priced both vanilla and exotic derivatives
* Established a scalable architecture for future extensions such as:

  * Asian Options
  * Barrier Options
  * Greeks Estimation
  * Variance Reduction Techniques

---

## Technologies

* C++
* Object-Oriented Programming (OOP)
* Monte Carlo Simulation
* Black-Scholes Model
* Financial Derivatives Pricing
