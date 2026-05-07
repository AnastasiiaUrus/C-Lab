#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

double calculateGeometricMean(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Помилка: не вдалося відкрити файл!" << endl;
        return -1;
    }

    double number;
    double logSum = 0;
    int count = 0;

    while (file >> number) {
        if (number <= 0) {
            cerr << "Попередження: середнє геометричне визначене лише для додатних чисел." << endl;
            continue; 
        }
        logSum += log(number);
        count++;
    }

    file.close();

    if (count == 0) {
        cerr << "Помилка: у файлі немає коректних даних." << endl;
        return 0;
    }

    return exp(logSum / count);
}

int main() {
    string filename = "input.txt";
    ofstream outfile(filename);
    outfile << "2.5   4.1\t 10.0\n8.3"; 
    outfile.close();

    double result = calculateGeometricMean(filename);

    if (result > 0) {
        cout << "Середнє геометричне чисел у файлі: " << result << endl;
    }

    return 0;
}