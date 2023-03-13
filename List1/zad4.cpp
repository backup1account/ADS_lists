#include <iostream>
#include <cmath>

double f(double x)
{
    return 2*x - 1;
}

// metoda bisekcji dziala na zlozonosci O(log(n)) - po kazdej iteracji redukuje polowe rozwiazan
double bisection_method(double a, double b, double epsilon)
{
    if (f(a) * f(b) > 0)
    {
        std::cout << "Funkcja musi przyjmowac rozne znaki na koncach przedzialu" << '\n';
        return NAN;
    }

    double x1;

    while ((b - a) > epsilon)
    {
        x1 = (a+b)/2;

        if (f(x1) <= epsilon) { return x1; }
        else if (f(x1) * f(a) < 0) 
        { 
            b = x1; 
        }
        else 
        { 
            a = x1; 
        }
    }
    return x1;
}


int main()
{
    double a = 0.0;
    double b = 2.0;
    double epsilon = 0.001;

    double f_x1 = bisection_method(a, b, epsilon);

    if (!isnan(f_x1))
    {
        std::cout << "Miejscem zerowym funkcji jest: " << f_x1 << '\n';
    }

    return 0;
}