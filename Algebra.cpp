#include <bits/stdc++.h>
using namespace std;

// general quadratic formula: (-b ± √(b² - 4ac)) / (2a)
pair<long double, long double> general_formula(long double a, long double b, long double c){
    pair<long double, long double> res;
    long double discriminant = powl(b, 2) - 4 * a * c;
    if (discriminant < 0) return {NAN, NAN};
    long double sqrt_d = sqrtl(discriminant);
    res.first = (-b + sqrt_d) / (2 * a);
    res.second = (-b - sqrt_d) / (2 * a);
    return res;
}

