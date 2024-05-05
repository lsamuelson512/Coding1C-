#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Robot {
public: 
    string name;
    int charge;

    Robot(string n, int c){
        name = n;
        charge = c;
    }
    Robot(string n){
        name = n;
        charge = 100;
    }
    Robot(){
        name = "Turret";
        charge = 0;
    }

    void status() {
     cout << "[ Name: " << name << ", Charge: " << charge << " ]\n";   
    }
};

int main() {
    srand(time(0));
    
    Robot rob;
    Robot clap ("Cl4ptr4p");
    
    rob.status();
    rob.name = "Robbie";
    rob.charge = 100;
    cout << "My robot's name is " << rob.name << ".\nMy robot's charge is " << rob.charge <<        ".\n\n";
    
    rob.status();
    clap.status();
    cout << endl;
    
    vector<string> names = {"R2-D2", "Johnny 5", "Hal 9000", "Bender"};
    vector<Robot> robots;

    for(int i = 0; i < 10; i++){
        Robot r (names.at(rand()%4), rand()%101);
        robots.push_back(r);
    }
    for(int i = 0; i < robots.size(); i++){
        robots.at(i).status();
    }
}