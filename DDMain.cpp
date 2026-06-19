#include "SimpleMC.h"

using namespace std;

int main(int argc, const char* argv[]) {
	double T = 1;
	double S0 = 50;
	double K1 = 43; // Double Digital Option
	double K2 = 57;
	double K = 50; // European Option
	double vol = 0.30;
	double r = 0.05;
	unsigned long NumberOfPaths = 200;

	// Create PayOffParameter object
	DoubleDigitalPayOffParameters Param_double(K1, K2);
	PayOffParameters Param_euro(K);

	PayOffDoubleDigital ddPayOff(Param_double);
	
	PayOffCall CallPayOff(Param_euro);
	PayOffPut PutPayOff(Param_euro);

	double result_dd = SimpleMonteCarlo(ddPayOff,
										T,
										S0,
										vol,
										r,
										NumberOfPaths);
	double result_call = SimpleMonteCarlo(CallPayOff,
											T,
											S0,
											vol,
											r,
											NumberOfPaths);
	double result_put = SimpleMonteCarlo(PutPayOff,
											T,
											S0,
											vol,
											r,
											NumberOfPaths);
	
	// Results change depending on the order of computing option prices
	cout << "\nThe prices are: \nDouble Digital Option with strike prices between " 
		<< K1 << " and " << K2 << ": " << result_dd 
		<< "\nEuropean Call Option with a strike of " << K << ": " << result_call 
		<< "\nEuropean Put Option with a strike of " << K << ": " << result_put << "\n";

	double tmp;
	cin >> tmp;

	return 0;
}