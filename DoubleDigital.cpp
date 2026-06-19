#include "DoubleDigital.h"

DoubleDigitalPayOffParameters::DoubleDigitalPayOffParameters(const double& K_1, const double& K_2) 
{
	K1 = K_1;
	K2 = K_2;
}

double DoubleDigitalPayOffParameters::GetLowerStirke() const
{
	return K1;
}
double DoubleDigitalPayOffParameters::GetUpperStrike() const
{
	return K2;
}

PayOffDoubleDigital::PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Param_)
{
	K1 = Param_.GetLowerStirke();
	K2 = Param_.GetUpperStrike();
}

double PayOffDoubleDigital::operator()(const double& S) const
{
	if (S >= K1 && S <= K2) {
		return 1.0;
	}
	else {
		return 0.0;
	}
}