#include "PayOff.h"

PayOffParameters::PayOffParameters(const double& K) {
    K_ = K;
}

double PayOffParameters::GetStrike() const
{
    return K_;
}

PayOffCall::PayOffCall(const PayOffParameters& Param_)
{
	K = Param_.GetStrike();
}

double PayOffCall::operator()(const double& S) const
{
    return std::max(S - K, 0.0);

}

PayOffPut::PayOffPut(const PayOffParameters& Param_)
{
    K = Param_.GetStrike();// Need to change
}

double PayOffPut::operator()(const double& S) const
{
    return std::max(K - S, 0.0);
}