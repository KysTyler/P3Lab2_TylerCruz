/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tyler C
 *
 * Created on October 23, 2020, 1:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
double factorial(int);
double exponential(int, int);
double serieTaylor(double, int);
void primeFactorization(int array[], int num);

/*
 * 
 */
int main(int argc, char** argv) {
    int mainOption = 0;
    while (mainOption != 4) {
        cout << "Menu " << endl
                << "Ejercicio 1 (1) " << endl
                << "Ejercicio 2 (2) " << endl
                << "Ejercicio 3 (3)" << endl
                << "Salir (4)" << endl;
        cout << " Ingrese cual opcion deseas" << endl;
        cin >> mainOption;
        switch (mainOption) {
            case 1:
            {
                int size = 25, valuePrimeNumber;
                int foo[size] = {16, 2, 77, 40, 120};
                int array1[size] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 73, 79, 83, 89};
                cout << "Ingrese un valor: " << endl;
                cin >> valuePrimeNumber;
                primeFactorization(array1, valuePrimeNumber);
                break;
            }
            case 2:
            {
                double var, limit;
                cout << "Ingrese un valor para el x" << endl;
                cin >>var;
                cout << "Ingrese el limit" << endl;
                cin >> limit;
                if (limit == 0) {
                    cout << "Resultado del serie de Taylor: " << 1 << endl;
                } else {
                    double result = serieTaylor(var, limit);
                    cout << "Resultado del serie de Taylor: " << result << endl;
                }
                //                cout << "factorial " << factorial(3) << endl;
                //                cout << "exponential "<<exponential(9,1,2) << endl;
                break;
            }
            case 3:
            {

                break;
            }
        }
    }
    return 0;
}

void primeFactorization(int array[], int num) {
    int result = 1, i = 0, exp = 0;
    string expression = "";
    while (num != 1) {
        if (num % array[i] == 0) {
            num /= array[i];
            exp++;
            cout << "Num" << num << endl;
            //cout << array[i];
        } else {
            expression += to_string(array[i]);
            expression += "^";
            expression += to_string(exp);
            expression += "*";
            exp = 0;
            i++;
        }
        if (num == 1) {
            expression += to_string(array[i]);
            cout << "Expression" << expression << endl;
        }
    }
}

double factorial(int n) {
    if (n < 0)
        return (-1); /*Wrong value*/
    if (n == 0)
        return (1); /*Terminating condition*/
    else {
        return (n * factorial(n - 1));
    }
}

double exponential(int base, int elevation) {
    if (elevation == 0) {
        return 1.0;
    }
    return base * exponential(base, elevation - 1);
}

double serieTaylor(double n, int limit) {
    double result = 0, exponent, _factorial;
    for (int i = 0; i < limit; i++) {
        exponent = exponential(n, i);
        _factorial = factorial(i);
        result += exponent / _factorial;
        //        cout << "Result: " << result << endl;
        //        cout << "exponential is: " << n << "^" << i << "=" << exponential(n,i) << endl;
        //        cout << "factorial of " << i << " is = " << factorial(i) << endl;
    }
    return result;
}
