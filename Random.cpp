#include "Random.h"
#include <cstdlib>
#include <cmath>

#if !defined(_MSC_VER_)
using namespace std;
#endif

// Static block to set the seed once when the program starts
static bool seed_initialized = []() {
    srand(static_cast<unsigned>(12345)); // Seed with current time
    return true;
}();


double GetOneGaussianByBoxMuller() {
    double result;
    double x, y;
    double sizeSquared;

    do {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        sizeSquared = x * x + y * y;
    } while (sizeSquared >= 1.0);

    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
    return result;
}
