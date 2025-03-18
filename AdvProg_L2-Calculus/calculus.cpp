#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    const int N = 10; 
    double term = 1.0, sum = 1.0;
    
    for (int i = 1; i < N; ++i) {
        term *= -x * x / (2 * i * (2 * i - 1));
        sum += term;
    }
    
    return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    const int N = 10;
    double term = x, sum = x;
    
    for (int i = 1; i < N; ++i) {
        term *= -x * x / ((2 * i + 1) * (2 * i));
        sum += term;
    }
    
    return sum;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double guess = x;
    const double epsilon = 1e-6; 

    while (fabs(guess * guess - x) > epsilon) {
        guess = (guess + x / guess) / 2.0;
    }
    
    return guess;
}
