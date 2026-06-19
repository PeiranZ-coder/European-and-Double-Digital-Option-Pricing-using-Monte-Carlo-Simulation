#ifndef __PAY_OFF__  
#define __PAY_OFF__  

#include <algorithm> // This is needed for the std::max  
// comparison function, used in the pay-off calculations  

class PayOff 
{
public:
	PayOff() {}; // Default (no parameter) constructor  
	virtual ~PayOff() {}; // Virtual destructor  

	// Overloaded () operator, turns the PayOff into an abstract  
	// function object  
	virtual double operator()(const double& S) const = 0;
};

class BasePayOffParameters 
{
public:
	BasePayOffParameters() {}; // Default (no parameter) constructor  
	virtual ~BasePayOffParameters() {}; // Virtual destructor  
};

class PayOffParameters : public BasePayOffParameters 
{
public:
	PayOffParameters(const double& K);
	virtual ~PayOffParameters() {}; // Virtual destructor  

	virtual double GetStrike() const;

private:
	double K_;
};

class PayOffCall : public PayOff
{
private:
	double K; // Strike price  

public:
	PayOffCall(const PayOffParameters& Param_);
	virtual ~PayOffCall() {};

	// Virtual function is now over-ridden
	// (not pure-virtual anymore)  
	virtual double operator()(const double& S) const;
};

class PayOffPut : public PayOff {
private:
	double K; // Strike  

public:
	PayOffPut(const PayOffParameters& Param_);
	virtual ~PayOffPut() {};
	virtual double operator()(const double& S) const;
};

#endif