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

//getting directory path
string get_directory_path(){
    cout << "Enter path to the directory: ";
    cin >> directory_path;
    return directory_path;
}


int main() {

    //getting correct path from user
    while (correct != true){
        directory_path = get_directory_path();
        cout << "Is this path correct?\n";
        cout << directory_path << "\n";
        cout << "yes(1) / no(2)\n>";
        cin >> user_answear;

        if (user_answear == 1){
            correct = true;
        }
    }

    cout << "Working directory is: " << directory_path << "\n";
    cout << "Directory entries: \n";

    fs::directory_iterator koniec;
    //searching for potencial episodes
    for (fs::directory_iterator it(directory_path); it != koniec; ++it) {
        current_object = it->path();

        //extracting Season number and episode number from filename
        if (current_object.find("S") != string::npos && current_object.find("E") != string::npos){
            int info_position = current_object.find("S");

            cout << "Found possible episode: S" << 
                current_object[info_position+1] <<
                current_object[info_position+2] <<
                "E" <<
                current_object[info_position+4] <<
                current_object[info_position+5];

            cout << " Original name: " << current_object  << "\n";
        }
    }

    cout << "Do you want to proceed with changing names of episodes?\n";
    cout << "yes(1) / no(2)\n>";
    cin >> user_answear;

    if (user_answear == 1){
        //proceeding if user agrees
        for (const auto& entry : fs::directory_iterator(directory_path)) {
            string full_path = entry.path().string();
            
            //establishing position of Episode and Season numbers
            size_t s_pos = full_path.find("S");
            size_t e_pos = full_path.find("E");

            
            //Getting SxxExx format
            string short_name = full_path.substr(s_pos, 6);

            //Getting extension
            string ext = entry.path().extension().string();

            //Building full path
            fs::path new_path = fs::path(directory_path) / (short_name + ext);

            //trying to rename
            try {
                fs::rename(entry.path(), new_path);
                //succes
                cout << "Renamed: " << entry.path().filename() << " -> " << short_name + ext << "\n";
            } catch (const fs::filesystem_error& e) {
                //failure
                cerr << "Error occured: " << e.what() << "\n";
            }
        }
    }else{
        //quitting with non 0 exit code
        return 1;
    }

    //quitting program
    return 0;
}