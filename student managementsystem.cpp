#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX = 40;
const int QUIZ = 5;

struct Student {
    int id;
    string name;
    float average;
    char grade;
};

// Function declarations
void inputData(Student s[], int marks[][QUIZ], int &n);
void calculate(Student s[], int marks[][QUIZ], int n);
void display(Student s[], int n);
void searchStudent(Student s[], int n);
void sortByAverage(Student s[], int n);
void saveToFile(Student s[], int n);

int main() {
    Student s[MAX];
    int marks[MAX][QUIZ];
    int n = 0, choice;

    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Enter Student Data";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student (Sequential)";
        cout << "\n4. Sort by Average";
        cout << "\n5. Save to File";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputData(s, marks, n);
                calculate(s, marks, n);
                break;
            case 2:
                display(s, n);
                break;
            case 3:
                searchStudent(s, n);
                break;
            case 4:
                sortByAverage(s, n);
                break;
            case 5:
                saveToFile(s, n);
                break;
            case 6:
                cout << "Program Ended.";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 6);

    return 0;
}

void inputData(Student s[], int marks[][QUIZ], int &n) {
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // ignore newline

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Student ID: ";
        cin >> s[i].id;
        cin.ignore(); // ignore newline

        cout << "Enter Name: ";
        getline(cin, s[i].name);

        cout << "Enter 5 quiz marks:\n";
        for (int j = 0; j < QUIZ; j++) {
            cin >> marks[i][j];
        }
    }
}

void calculate(Student s[], int marks[][QUIZ], int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < QUIZ; j++)
            sum += marks[i][j];

        s[i].average = sum / static_cast<float>(QUIZ);

        if (s[i].average >= 80) s[i].grade = 'A';
        else if (s[i].average >= 70) s[i].grade = 'B';
        else if (s[i].average >= 60) s[i].grade = 'C';
        else s[i].grade = 'F';
    }
}

void display(Student s[], int n) {
    Student *p = s;
    for (int i = 0; i < n; i++) {
        cout << "\n----------------";
        cout << "\nID: " << (p + i)->id;
        cout << "\nName: " << (p + i)->name;
        cout << "\nAverage: " << (p + i)->average;
        cout << "\nGrade: " << (p + i)->grade;
    }
}

void searchStudent(Student s[], int n) {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {
            cout << "Student Found!";
            cout << "\nName: " << s[i].name;
            cout << "\nAverage: " << s[i].average;
            cout << "\nGrade: " << s[i].grade;
            return;
        }
    }
    cout << "Student not found!";
}

void sortByAverage(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].average < s[j + 1].average) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    cout << "\n--- Students Sorted by Average ---\n";
    display(s, n);
}

void saveToFile(Student s[], int n) {
    ofstream file("students.txt");
    for (int i = 0; i < n; i++) {
        file << s[i].id << " "
             << s[i].name << " "
             << s[i].average << " "
             << s[i].grade << endl;
    }
    file.close();
    cout << "Data saved to file successfully.";
}
