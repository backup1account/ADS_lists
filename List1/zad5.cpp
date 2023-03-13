#include <iostream>
#include <vector>

// b) Horner's method
double oblicz(std::vector<double> a, double x) 
{
    int n = a.size();
    double result = 0.0;

    for (int i = n - 1; i > 0; i--) {
        result = (result * x) + a[i];
    }

    result += a[0];
    return result;
}

int main()
{
    std::cout << oblicz({4, 5, 3, 0, 0, 18}, 10) << '\n';
    return 0;
}