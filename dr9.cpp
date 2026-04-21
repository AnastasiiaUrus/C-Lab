#include <iostream>
#include <string>
#include <cmath>

using namespace std;
struct Address { string city, street; int house, apt; }; 
struct Cost { int hrn, kop; };

void task6d() {
    Address a;
    cout << "task 6d" << endl;
    cout << "Enter City, Street, House, Apt: ";
    cin >> a.city >> a.street >> a.house >> a.apt;
    cout << "Result: " << a.city << ", " << a.street << ", " << a.house << "/" << a.apt << endl;
}

void task12() {
    int n;
    cout << "\nTask 12" << endl;
    cout << "Enter number of items: ";
    cin >> n;
    Cost* list = new Cost[n];
    
    for(int i = 0; i < n; i++) {
        cout << "Item " << i+1 << " (hrn kop): ";
        cin >> list[i].hrn >> list[i].kop;
    }

    int minIdx = 0, maxIdx = 0;
    for(int i = 1; i < n; i++) {
        int val = list[i].hrn * 100 + list[i].kop;
        int minVal = list[minIdx].hrn * 100 + list[minIdx].kop;
        int maxVal = list[maxIdx].hrn * 100 + list[maxIdx].kop;
        
        if(val < minVal) minIdx = i;
        if(val > maxVal) maxIdx = i;
    }
    
    cout << "Cheapest: " << list[minIdx].hrn << "." << list[minIdx].kop << endl;
    cout << "Most expensive: " << list[maxIdx].hrn << "." << list[maxIdx].kop << endl;

    double sum = 0;
    for(int i = 0; i < n; i++) sum += (list[i].hrn * 100 + list[i].kop);
    double avg = sum / n;
    
    cout << "<= 10 UAH:" << endl;
    for(int i = 0; i < n; i++) {
        if(abs((list[i].hrn * 100 + list[i].kop) - avg) <= 1000) {
            cout << list[i].hrn << "." << list[i].kop << " ";
        }
    }
    cout << endl;

    delete[] list;
}

int main() {
    task6d();
    task12();
}