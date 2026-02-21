#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Some global variables
bool correct = false;
string directory_path;

//Less important variables
int user_answear;

string get_directory_path(){
    cout << "Enter path to the directory: ";
    cin >> directory_path;
    return directory_path;
}

int main() {
    while (correct != true){
        directory_path = get_directory_path();
        cout << "Is this path correct?\n";
        cout << directory_path << "\n";
        cout << "yes(1) / no(2)\n>";
        cin >> user_answear;

        switch (user_answear){
            case 1:
                correct = true;
                break;
            case 2:
                break;
            default:
                cout << "Please next time type 1 or 2.";
        }
    }

    cout << "Working directory is: " << directory_path << "\n";

    return 0;
}