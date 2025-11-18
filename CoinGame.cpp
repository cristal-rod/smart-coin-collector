#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

void printHeads() {
    cout << "   _______\n";
    cout << " /       \\\n";
    cout << "|  HEADS  |\n";
    cout << " \\_______/\n";
}

void printTails() {
    cout << "   _______\n";
    cout << " /       \\\n";
    cout << "|  TAILS  |\n";
    cout << " \\_______/\n";
}

void coinAnimation() {
    for (int i = 0; i < 6; i++) {
        system("cls");
        cout << "FLIPPING...\n\n";

        if (i % 2 == 0) {
            printHeads();
        }
        else {
            printTails();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    system("cls");
}

int main() {
    srand(time(0));

    string guess;
    cout << "Guess heads or tails: ";
    cin >> guess;

    coinAnimation();

    int flip = rand() % 2;
    string result = (flip == 0) ? "heads" : "tails";

    if (result == "heads")
        printHeads();
    else
        printTails();

    cout << "\nThe coin landed on: " << result << "\n";

    if (guess == result)
        cout << "You WON!\n";
    else
        cout << "You lost :(\n";

    return 0;
}
