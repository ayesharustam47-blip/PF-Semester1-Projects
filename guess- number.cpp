#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    char choice;

    do {
        srand(time(0));
        int scret = rand() % 10 + 1;
        int guess;
        int attempts = 0;

        cout << "\n🎮 Guess the Number Game\n";
        cout << "You have 5 attempts\n";

        do {
            cout << "Enter your guess number: ";
            cin >> guess;
            attempts++;

            if (guess == scret) {
                cout << "🎉 You win!\n";
                break;
            }
            else if (guess > scret) {
                cout << "Too high\n";
            }
            else {
                cout << "Too low\n";
            }

        } while (attempts < 5);

        if (guess != scret) {
            cout << "❌ Game Over! The number was: " << scret << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing 😊";
    return 0;
}
