#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int main() {
    char names[5][20];
    int marks[5][3];
    int total[5], top = 0;
    double avg[5];

    // Input names, 3 marks, and calculate total and average
    for(int i = 0; i < 5; i++) {
        cout << "Enter student name("<<i+1<<")";
        cin.getline(names[i], 20);

        total[i] = 0;
        for (int j = 0; j < 3; j++) {
            cout <<"Enter mark "<<j + 1<< ": ";
            cin >> marks[i][j];
            total[i] += marks[i][j];
        }
        avg[i] = total[i] / 3.0;
        cin.ignore(1000, '\n'); // Clear input newline
    }
    // Find the student with the highest total
    for (int i = 1; i < 5; i++) {
        if (total[i] > total[top])
            top = i;
    }
    // Display the mark sheet
    cout << "\n";
    cout << left << setw(20) << "NAME"
         << right << setw(6) << "M1"
         << setw(6) << "M2"
         << setw(6) << "M3"
         << setw(8) << "TOTAL"
         << setw(8) << "Avg" << '\n';

    for (int i = 0; i < 5; i++) {
        cout<<left<<setw(20)<<names[i]
             <<right<<setw(6)<<marks[i][0]
             <<setw(6)<<marks[i][1]
             <<setw(6)<<marks[i][2]
             <<setw(8)<<total[i]
             <<setw(8)<<fixed << setprecision(1)
             <<avg[i]<<'\n';
    }
    // Display the top student
    cout <<"\nTop student:" <<names[top]<<'\n';

    return 0;
}