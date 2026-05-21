#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes
void showBookMenu();
void displayFileContent(string fileName);

int main() {
    int choice;

    do {
        showBookMenu();
        cout << "\nEnter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Reading C++ History from external file
                displayFileContent("history.txt");
                break;
            case 2:
                // Reading C++ Programming Concepts from external file
                displayFileContent("concepts.txt");
                break;
            case 3:
                cout << "\n\033[35mExiting the Book System. Keep learning! Goodbye!\033[0m" << endl;
                break;
            default:
                cout << "\n\033[31mInvalid choice! Please choose a number between 1 and 3.\033[0m" << endl;
        }
        cout << "\n\033[34m--------------------------------------------------\033[0m\n";
    } while (choice != 3);

    return 0;
}

// Function to display the system menu
void showBookMenu() {
    cout << "\n\033[36m==================================================\033[0m" << endl;
    cout << "      Foundations and History of C++ Book System  " << endl;
    cout << "\033[36m==================================================\033[0m" << endl;
    cout << " [1] View the History of C++" << endl;
    cout << " [2] Learn about C++ Concepts" << endl;
    cout << " [3] Exit Program" << endl;
    cout << "\033[36m==================================================\033[0m" << endl;
}

// Function using ifstream to read and print text files row by row
void displayFileContent(string fileName) {
    ifstream inputFile(fileName); // Open the file
    string fileLine;

    cout << "\n\033[33m--- Loading Content from " << fileName << " ---\033[0m\n" << endl;

    // Check if the file exists and opened successfully
    if (inputFile.is_open()) {
        while (getline(inputFile, fileLine)) {
            cout << fileLine << endl; // Print each line
        }
        inputFile.close(); // Close file after finishing
    } else {
        // Fallback hardcoded text if files are not created yet (as allowed by professor)
        cout << "\033[31m[Note: External file '" << fileName << "' not found! Displaying summary instead.]\033[0m\n" << endl;

        if (fileName == "history.txt") {
            cout << "CHAPTER 1: Origins of C++\n- Developed by Bjarne Stroustrup in 1979 at Bell Labs.\n- Initially named 'C with Classes' and later renamed to C++ in 1983." << endl;
        } else if (fileName == "concepts.txt") {
            cout << "CHAPTER 2: Core Programming Concepts\n- Data Types & Variables\n- Control Flow (if-else, switch)\n- Loops (for, while, do-while)\n- Arrays & File Streams (ifstream/ofstream)" << endl;
        }
    }
}
