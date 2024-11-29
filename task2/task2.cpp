#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

double f(double x) {
    return 2 * std::pow(x, 7) + 3 * std::pow(x, 4) + 2 * std::pow(x, 2) + 2;
}

int main() {
    std::vector<double> x_vals = { 0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };

    std::vector<double> f_vals(x_vals.size());
    for (size_t i = 0; i < x_vals.size(); ++i) {
        f_vals[i] = f(x_vals[i]);
    }

    std::vector<double> a_vals(x_vals.size() - 1);
    std::vector<double> b_vals(x_vals.size() - 1);
    for (size_t i = 0; i < x_vals.size() - 1; ++i) {
        a_vals[i] = (f_vals[i + 1] - f_vals[i]) / (x_vals[i + 1] - x_vals[i]); 
        b_vals[i] = f_vals[i]; 
    }

    std::cout << "f(x) values:" << std::endl;
    for (size_t i = 0; i < x_vals.size(); ++i) {
        std::cout << "f(" << x_vals[i] << ") = " << f_vals[i] << std::endl;
    }

    std::cout << "\nSpline coefficients (a_i and b_i):" << std::endl;
    for (size_t i = 0; i < a_vals.size(); ++i) {
        std::cout << "a_" << i << " = " << a_vals[i] << ", b_" << i << " = " << b_vals[i] << std::endl;
    }

    std::cout << "\nSpline equations:" << std::endl;
    for (size_t i = 0; i < a_vals.size(); ++i) {
        double x0 = x_vals[i]; 
        double a = a_vals[i];   
        double b = b_vals[i];   

        double b_new = b - a * x0; 

        std::cout << "S_" << i << "(x) = " << a << "(x - " << x0 << ") + " << b << " => ";
        std::cout << "S_" << i << "(x) = " << a << "x + " << b_new << std::endl;
    }

    return 0;
}