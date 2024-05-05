#include <iostream>
#include <string> 
using namespace std;

int main() {
    string name = "Luke";

    int counter = 0;
    string input = "";
    while(counter++ < 10){
        cout << "counter = " << counter << endl; 
    }
    cout << endl << endl;
    
    // do {
    //     cout << "Do you want to keep adventuring? Y/N" << endl;
    //     getline(cin, input);
    // } while(input != "N" && input != "n");

    // while(true){
    //     cout << "Do you want to keep adventuring? Y/N" << endl;
    //     getline(cin, input);
        
    //     if(input == "N" || input == "n"){
    //         break;
    //     }
    // }

    for(int i = 0; i < 10 ; i++) {
        cout << "counter = " << i << endl;
    }

    string favGames[10];
    int c = 0;
    while(true){        
        cout << "Please enter a command:\nAdd a game: a \nShow game list: s \nQuit: q\n";
        getline(cin, input);
        
        if((input == "add"|| input == "a")){
            if(c < 10){
                cout << "Please enter the name of your favorite game: " << endl;
                getline(cin, favGames[c]);
                c++;
            } else {
            cout << "Sorry I can't add anymore games. \n";
            }
        } else if(input == "show" || input == "s"){
            for(int i = 0; i < c; i++){
                cout << "Game " << i << ": " << favGames[i] << endl;
            }
        } else if(input == "quit" || input == "q"){
            break;
        } else {
            cout << "Apologies I didn't understand your request \n";
        }
    }
}