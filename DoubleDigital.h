#ifndef __PayOffDoubleDigital__  
#define __PayOffDoubleDigital__  

#include <vector>  
#include "PayOff.h"  

class DoubleDigitalPayOffParameters : public BasePayOffParameters {
public:
	DoubleDigitalPayOffParameters(const double& K_1, const double& K_2);
	virtual ~DoubleDigitalPayOffParameters() {}; // Virtual destructor

	virtual double GetLowerStirke() const;
	virtual double GetUpperStrike() const;
private:
	double K1; // Strike lower level  
	double K2; // Strike upper level  
};  

class PayOffDoubleDigital : public PayOff {
private:  
	double K1; // Strike lower level  
	double K2; // Strike upper level  

public:  
	PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Param_);
	virtual ~PayOffDoubleDigital() {};  
	
	// Pay-off operator (this will determine arithmetic or geometric)  
	virtual double operator()(const double& S) const;  
};  

#endif