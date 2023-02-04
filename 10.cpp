#include <iostream>
#include <math.h>
#define eps pow(10,-7)

using namespace std;

double F(double x) 
    { 
        return 1 / x; 
    }

double trapeciy(double a,  double b, int n,  double h) 
    {
        double S = 0;
        for (int i = 0; i <= n; i++) 
        //for (int i = n; i >= 0; i--) 
        {
            a += h;
            S += (F(a) + F(a + h)) / 2 * h;
        }
        printf("h: %.10f\n", h);
    return S;
    }

double simpson(double a, double b, int n, double x) 
    {
    double S = 0, h, C = 2;
    h = (b - a) / n;
    x = a + h;
    while (abs(S - C) > eps)
        {
            C = S;
            S += 4 * F(x);
            x += h;
            if (x >= b)
            break;
            S += 2 * F(x);
            x += h;
            cout << "S ==== " << S << endl;
        }
    cout << "S >> " << S << endl;
    cout << ">>>>>>" << (h / 3) << " " << S << " " << F(a) << " " << F(b) << endl;
    S = (h / 3) * (S + F(a) + F(b)); 
    printf("h: %.10f\n", h);
    return S;
    }

int main() 
    {
    double a = 1, b = 2, n = 10;
    int step = 1;
    long double h = 0;
    h = (b - a) / n;
    printf("Метод Трапеций:\n");
    printf("Шаг № 1\n");
    double res = trapeciy(a, b, n, h);
    double res1 = 0;
    while (fabs(res-res1) > eps)
        {
            
            printf("Результат: %.10f\n", res);

            res1 = res;
            step++;    
            printf("Шаг № %d\n", step);
            n *= 2;
            h = (b - a) / n;
            res = trapeciy(a, b, n, h);
       }
    printf("Результат: %.10f\n", res);
      
    step = 1;
    n = 10;
    h = (b - a) / n;
    cout << endl << endl; 
    printf("Метод Симпсона:\n");
    printf("Шаг № 1\n");
    res = simpson(a,b,n,h);
    res1 = 0;
    while (fabs(res-res1) > eps)
        {
            res1 = res;
            printf("Результат: %.15f\n", res);
            step++; 
            printf("Шаг № %d\n", step);
            n *= 2;
            h = (b - a) / n;
            res = simpson(a,b,n,h);
        }
    printf("Результат: %.15f\n", res);
    }
