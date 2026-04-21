#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;
void task1() {
    double x, y, z;
    cout << "Input x, y: ";
    cin >> x >> y;
    z = pow(x, y);
    cout << "z=" << z << " " << scientific << z << endl;
}

void task2() {
    char str[10];
    unsigned long long x, y = 0;
    cout << "Enter numbers (10 digits each): " << endl;
    while(cin.get(str, 10)){
        x = atoll(str);
        y += x;
    }
    cout << "y=" << y << endl;
}

void task3() {
    unsigned n;
    cout << "n=";
    cin >> n;
    for(unsigned i = 1; i <= n; i++) {
        cout.width(7); cout << i;
    }
    cout << "\n";
    for(unsigned i = 1; i <= n; i++) {
        cout.width(7); cout.precision(3); cout << sqrt(i);
    }
    cout << endl;
}

void task4() {
    int n;
    cout << "n=";
    cin >> n;
    int* m = new int[n];
    double* x = new double[n];
    
    cout << "Enter powers:" << endl;
    for(int i = 0; i < n; i++) cin >> m[i];
    cout << "Enter bases:" << endl;
    for(int i = 0; i < n; i++) cin >> x[i];
    
    for(int i = 0; i < n; i++) cout << pow(x[i], m[i]) << " ";
    cout << endl;
    
    delete[] m; delete[] x;
}

void task5() {
    ifstream f("pr10.txt");
    if (!f.is_open()){
       cerr << "Error: File pr10.txt not found!" << endl;
       return;
    }
    
    vector<double> data;
    double val;
    while(f >> val) {
        data.push_back(val);
    }
    f.close();
    
    cout << "Results (reverse order):" << endl;
    for(int i = data.size() - 1; i >= 0; i--) {
        cout << fixed << setprecision(3) << sqrt(data[i]) << endl;
    }
}

int main() {
    // task1();
    // task2();
    // task3();
    // task4();
     task5();
}