#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
//include customized .h file
#include "DNDcombatManager.h"

using namespace std;

//Defining Weapons

//string name, string weaponType, damageType smackEtc,  
//weapons javelin();

int whichDice;
enum dice {d4 = 4, d6 = 6, d8 = 8, d10 = 10, d12 = 12, d20 = 20};

int main(){
    srand(time(0));

    cout << die6sided(4) << endl;
    cout << die6sided() << endl;


    cout << "Which die would you like to roll? " << endl;
    cin >> whichDice;

    switch (whichDice) {
    case d4:
    case d6:
        cout << "Your roll: " << die6sided() << endl;

    default:
        cout << "That's not a valid number for a die in DND. " << endl << "Try again." << endl; 
        break;
    }

    //game logic
    cout << "Hello world" << endl;
    return 0;
}