#include <iostream>
#include <vector>

using namespace std;

void Progonka(vector<vector<double>>& matrix, int n) {
    vector<double> a(n), b(n), c(n), d(n);
    vector<double> cPrime(n);

    for (int i = 0; i < n; i++) {
        b[i] = matrix[i][i];
        d[i] = matrix[i][n];
        if (i < n - 1) {
            c[i] = matrix[i][i + 1];
        }
        if (i > 0) {
            a[i] = matrix[i][i - 1];
        };
    }

    cPrime[0] = c[0] / b[0];

    for (int i = 1; i < n; i++) {
        cPrime[i] = c[i] / (b[i] - a[i] * cPrime[i - 1]);
    }

    vector<double> x(n);
    vector<double> y(n);
    y[0] = d[0] / b[0];

    for (int i = 1; i < n; i++) {
        y[i] = (d[i] - a[i] * y[i - 1]) / (b[i] - a[i] * cPrime[i - 1]);
    }

    x[n - 1] = y[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        x[i] = y[i] - cPrime[i] * x[i + 1];
    }

    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<double>> matrix = 
    { 
     {9, 2, 0, 0, 0, 6},
     {1, 3, 1, 0, 0, 8},
     {0, 4, 5, 1, 0, 4},
     {0, 0, 5, 9, 7, 5},
     {0, 0, 0, 3, 7, 1} };

    Progonka(matrix, n);

    return 0;
}