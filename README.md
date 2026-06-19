# European and Double Digital Option Pricing using Monte Carlo Simulation

## Overview

This project implements a flexible option pricing framework in C++ using object-oriented programming principles and Monte Carlo simulation techniques. The framework supports pricing of standard European options (Call and Put) as well as a Double Digital Option under the Black-Scholes framework.

The primary objective is to demonstrate inheritance, polymorphism, abstract classes, and payoff abstraction while building a reusable Monte Carlo pricing engine for derivative pricing.

---

## Option Payoff Definitions

### European Call Option

The payoff at maturity is

$$
C_T = \max(S_T - K,0)
$$

where:

* $S_T$ = underlying asset price at maturity
* $K$ = strike price

---

### European Put Option

The payoff at maturity is

$$
P_T = \max(K - S_T,0)
$$

---

### Double Digital Option

A Double Digital Option pays

$$
D_T =
\begin{cases}
1, & K_1 < S_T < K_2 \
0, & \text{otherwise}
\end{cases}
$$

where:

* $K_1$ = lower strike
* $K_2$ = upper strike

---

## Project Structure

The pricing framework consists of the following components:

```text
PayOff.h
PayOff.cpp

DoubleDigital.h
DoubleDigital.cpp

Random.h
Random.cpp

SimpleMC.h
SimpleMC.cpp

DDMain.cpp
```

### PayOff Module

* Abstract payoff base class
* European Call payoff implementation
* European Put payoff implementation

### DoubleDigital Module

* Double Digital payoff implementation
* Dual-strike parameter handling

### SimpleMC Module

* Generic Monte Carlo pricing engine
* Reusable pricing architecture for different payoff structures

---

## Object-Oriented Design

The project utilizes runtime polymorphism to separate payoff definitions from the pricing engine.

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

Each derived class overrides the payoff operator while sharing the same Monte Carlo simulation framework.

This design allows new exotic options to be introduced without modifying the pricing engine.

---

## Monte Carlo Pricing Methodology

Under the Black-Scholes assumptions, the terminal asset price is simulated as

$$
S_T =
S_0
\exp
\left(
(r-\frac{1}{2}\sigma^2)T
+
\sigma\sqrt{T}Z
\right)
$$

where:

* $S_0$ = initial asset price
* $r$ = risk-free interest rate
* $\sigma$ = volatility
* $T$ = time to maturity
* $Z \sim N(0,1)$

For each simulation path:

1. Generate a standard normal random variable.
2. Simulate the terminal stock price.
3. Evaluate the payoff function.
4. Accumulate the payoff values.
5. Discount the average payoff back to present value.

The Monte Carlo estimator is

$$
V_0
===

e^{-rT}
\frac{1}{N}
\sum_{i=1}^{N}
\text{Payoff}_i
$$

---


The Monte Carlo engine is used to price:

* European Call Option
* European Put Option
* Double Digital Option

under identical market conditions.

---

## Key Learning Outcomes

* Object-Oriented Programming in C++
* Abstract Classes and Virtual Functions
* Runtime Polymorphism
* Monte Carlo Simulation
* Black-Scholes Asset Dynamics
* European Option Pricing
* Exotic Option Pricing
* Financial Engineering Software Design



## Technologies

* C++
* Monte Carlo Simulation
* Black-Scholes Model
* Financial Engineering
* Quantitative Finance
* Object-Oriented Programming

