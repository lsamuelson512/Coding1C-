#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

bool askYN(string input){
    while(true){
        if(input.at(0) == 'y' || input.at(0) == 'Y'){
            return true;
        } else if(input.at(0) == 'n' || input.at(0) == 'N'){
            return false;
        }
        cout << "Apologies I didn't quite understand that. \n";
        cin >> input;
    }
}
int rollDie(int sides = 6, int bonus = 1){
    return rand() % sides + bonus;
}


class Goblin {
    public: 
    int health = 10;
    int maxHealth = 10;
    int die = 4;
    int hitBonus = -1;
    int goldAmount = 5;

    void revive(int starter) {
        maxHealth = (starter / 3) * 5 + 20;
        health = maxHealth;
        hitBonus += (starter / 5); 
    }
    Goblin(){}

    bool IsAlive(){
        if(health > 0)
            return true;
        else
            return false;
    }

};
class Orc {
    public: 
    int health = 20;
    int maxHealth = 20;
    int die = 6;
    int critChance = 5;
    int hitBonus = 2;
    int goldAmount = 10;

    void revive(int starter) {
        maxHealth = (starter / 4) * 5 + 20;
        health = maxHealth;
        hitBonus += (starter / 5);
    }
    Orc() {}

    bool IsAlive(){
        if(health > 0)
            return true;
        else
            return false;
    }
    int attack(int critChance){
        if(rand() % (100 - critChance) == 0){
            return rollDie(die, hitBonus) * 2;
        } else {
            return rollDie(die, hitBonus);
        }
    }
};
class Player {
    public: 
    int maxHealth = 50;
    int health = 25;
    int die = 6;
    int critChance = 5;
    int hitBonus = 2;
    int gold = 0;
    int attack(int critChance){
        if(rand() % (100 - critChance) == 0){
            return rollDie(die, hitBonus) * 2;
        } else {
            return rollDie(die, hitBonus);
        }
    }
};

bool purchase(string input, vector <int> &prices, Player &p){
    if(input.at(0) == 'n'){
        cout << "Alrighty come back any time!\n\n";
        return false;
    } 
    if(input.at(0) < 48 || input.at(0) > 52) {
        cout << "Sorry I didn't get quite that.\n";
        return true;
    }
    int purchased = stoi(input);

    if(purchased == 1 && p.gold >= prices.at(0)){
        p.maxHealth += 25;
        p.gold -= prices.at(0);
        prices.at(0) += 10;
        cout << "Upgrade bought! You have " << p.gold << " gold remaining.\n\n";
    } else if (purchased == 2 && p.gold >= prices.at(1)) {
        p.critChance += 5;
        p.gold -= prices.at(1);
        prices.at(1) += 5;
        cout << "Upgrade bought! You have " << p.gold << " gold remaining.\n\n";
    } else if (purchased == 3 && p.gold >= prices.at(2)) {
        p.hitBonus += 2;
        p.gold -= prices.at(2);
        prices.at(2) += 10;
        cout << "Upgrade bought! You have " << p.gold << " gold remaining.\n\n";
    } else if (purchased == 4 && p.gold >= prices.at(3)) {
        p.die += 2;
        p.gold -= prices.at(3);
        prices.at(3) *= 2;
        cout << "Upgrade bought! You have " << p.gold << " gold remaining.\n\n";
    } else {
        cout << "Sorry, but you can't afford that.\n";
    }
        
    return true;
}
void creatureSlain(int goldRange, Player &p){
    cout << "You earned " << goldRange << " gold pieces!\n";
    p.gold += goldRange;
    cout << "You currently have a total of " << p.gold << " gold pieces!\n";
}
void printAttacks(int playerDamage, int monsterDamage, Player p, Goblin g){
    cout << "You attack the goblin for " << playerDamage << ", and it has " << g.health;     cout << " hp left.\nThe goblin attacks you for " << monsterDamage;
    cout << ", and you have " << p.health << "hp left.\n\n";
}
void printAttacks(int playerDamage, int monsterDamage, Player p, Orc o){
    cout << "You attack the orc for " << playerDamage << ", and it has " << o.health;
    cout << " hp left.\nThe orc attacks you for " << monsterDamage;
    cout << ", and you have " << p.health << "hp left.\n\n";
}
void shop(vector<int> &prices){
    cout << "Would you like to buy anything from the shop?\n";
    cout << "1. Health Boost" << setw(10) << prices.at(0) << " Gold\n";
    cout << "2. Crit Boost" << setw(12) << prices.at(1) << " Gold\n";
    cout << "3. Damage Boost" << setw(10) << prices.at(2) << " Gold\n";
    cout << "4. Die Raise" << setw(12) << prices.at(3) << " Gold\n";
    cout << "If you would like to purchase, type in the number ";
    cout << "or type N to leave.\n";
}

int main() {
    srand(time(0));
    int counter = 1;
    int playerAttack = 0;
    int monsterAttack = 0;
    string name; 
    string playInput;
    string actionInput;
    vector <int> prices = {15, 10, 20, 25};
    
    Orc o;
    Goblin g;
    Player pl;
    
    cout << "What's your name?\n";
    cin >> name;
    cout << name << ", would you like to go an adventure?\n";
    cin >> playInput;
    if(askYN(playInput)){
        do {
            if(counter % 5 == 0){
                cout << "Welcome to the shop! Let me fully heal you\n";
                do{
                    shop(prices);
                    cin >> actionInput;
                }while(purchase(actionInput, prices, pl));
                pl.health = pl.maxHealth;
            } else if (counter > 10) {
                while(o.health > 0 && pl.health > 0){
                    monsterAttack = o.attack(o.critChance);
                    playerAttack = pl.attack(pl.critChance);
                    o.health -= playerAttack;
                    pl.health -= monsterAttack;
                    printAttacks(playerAttack, monsterAttack, pl, o);
                }
                if(o.health <= 0){
                    o.revive(counter);
                    creatureSlain(rollDie(o.goldAmount, o.goldAmount), pl);
                }
            } else {
                while(g.health > 0 && pl.health > 0){
                    monsterAttack = rollDie(g.die, g.hitBonus);
                    playerAttack = pl.attack(pl.critChance);
                    g.health -= playerAttack;
                    pl.health -= monsterAttack;
                    printAttacks(playerAttack, monsterAttack, pl, g);
                }
                if(g.health <= 0){
                    g.revive(counter);
                    creatureSlain(rollDie(g.goldAmount, g.goldAmount), pl);
                }
            }
            
            if(pl.health <= 0){
                cout << "Uhoh you've fallen all your journey.\n You reached ";
                cout << counter << " counters.\n Better luck next time!\n";
                break;
            }
            
            counter++;
            cout << "Would you like to continue?\n";
            cin >> playInput;
            cout << endl;
        } while (askYN(playInput));
        
        if(pl.health > 0){
            cout << "You've retired from the journey! Good job on clearing " << counter;
            cout << " counters!\n Good luck on your next quest!\n";
        }
        
    } else {
        cout << "No worries, come back another time!\n";
    }
}