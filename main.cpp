#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

//Some global variables
bool correct = false;
string directory_path;

//Less important variables
int user_answear;
string current_object;

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
    cout << "Directory entries: \n";

    fs::directory_iterator koniec;
    for (fs::directory_iterator it(directory_path); it != koniec; ++it) {
        current_object = it->path();

        //printing path
        //std::cout << it->path() << "\n";
        
        //printing extension
        if (it->path().has_extension()) {
            //cout << "Extentsion: " << it->path().extension() << "\n\n";
            cout << "";
        }else{
            //skipping non files
            //cout << "Extension: NOT A FILE!\n\n";
            cout << "";
        }

        if (current_object.find("S") != string::npos && current_object.find("E") != string::npos){
            int info_position = current_object.find("S");
            cout << "Found possible episode: S" << 
                current_object[info_position+1] <<
                current_object[info_position+2] <<
                "E" <<
                current_object[info_position+4] <<
                current_object[info_position+5] << "\n";
        }
        
    }

    return 0;
}