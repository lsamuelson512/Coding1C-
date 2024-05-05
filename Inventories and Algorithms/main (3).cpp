#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

void InventoryCreate() {
    vector<string> inventory;
    
    inventory.push_back("wallet");
    inventory.push_back("keys");
    inventory.push_back("phone");

    cout << "There are " << inventory.size() << " items in our inventory.\n";
    for(int i = 0; i < inventory.size(); i++){
        cout << inventory[i] << "\n";
    }
    cout << "\n";

    cout << "We left the keys behind, and picked up brass knucles.\n\n";
    inventory[1] = "brass knucles";

    cout << "uhoh a pickpocket got your phone!\n\n";
    inventory.pop_back();

    cout << "There are " << inventory.size() << " items in our inventory.\n";
    for(int i = 0; i < inventory.size(); i++){
        cout << inventory[i] << "\n";
    }
}
void IteratorsSucks() {
    vector<string> friends {"Parker", "Sophia", "Shclatt", "Ash", "Sam"};
    cout << "There are " << friends.size() << " friends in our vector.\n";
    
    for (vector<string>::iterator it = friends.begin() ; it != friends.end(); ++it){
        cout << *it << "\n";
    }
}
void AlgorithmTime() {
    srand(time(0));
    vector<int> scores;

    for(int i = 0; i < 10; i++){
        scores.push_back(rand() % 100 + 1);
    }
    for(int i = 0; i < scores.size(); i++){
        cout << scores[i] << endl;
    }
    
    cout << "Numbers sorted:\n";
    sort(scores.begin(), scores.end());
    for(int i = 0; i < scores.size(); i++){
        cout << scores[i] << endl;
    }
    cout << endl;
    
    cout << "Reverse sorted:\n";
    reverse(scores.begin(), scores.end());
    for(int i = 0; i < scores.size(); i++){
        cout << scores[i] << endl;
    }
    cout << endl;
    
    cout << "Random shuffle:\n";
    random_shuffle(scores.begin(), scores.end());
    for(int i = 0; i < scores.size(); i++){
        cout << scores[i] << endl;
    }
    cout << endl;

    int input = 0;
    while(input != -1 && scores.size() > 0){
        cout << "What number should we remove?\n";
        cin >> input;
        
        vector<int>::iterator it = find(scores.begin(), scores.end(), input);
        if(it != scores.end()) {
            scores.erase(it);
        } else {
            cout << "Sorry, couldn't find that number.\n";
        }

        for(int i = 0; i < scores.size(); i++){
            cout << scores[i] << endl;
        }
        cout << endl;
    }
}

int main() {
    cout << "What would you like to do?\nPress 1 to run the Inventory program.\n";
    cout << "Press 2 to run Iterator program.\nPress 3 to run Algorithm program\n";
    int select = 0;
    cin >> select;
    cout << endl;
    if(select == 1){
        cout << "Let's create an inventory!\n";
        InventoryCreate();
    } else if(select == 2){
        IteratorsSucks();
    } else if (select == 3){
        AlgorithmTime();
    } else {
        cout << select << " wasn't one of the options.\n";
    }

    return 0;
}