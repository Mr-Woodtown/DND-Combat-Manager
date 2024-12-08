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


void askRoll() {
    dice whichDice;
    cout << "Which die would you like to roll? (type the letter d then number of sides.)" << endl;
    cin >> whichDice;
    whichDie(whichDice);
};

weapons defineWeapon() {
    string dummyVar, weaponName, weaponType; //Why on earth do I need a dummy variable? Who knows, but it doesn't work without it. If I'm not mistaken it's memory should be deallocated outside of this scope. 
    damageType type;
    dice damageDie;
    cout << "Please enter a name, weapon type (reaching, thrown, etc.), damage type (bludgening, slashing, or piercing), and die (d<#ofSides>). \nHit enter after each entry." << endl;
    cin >> dummyVar >> weaponName >> weaponType >> type >> damageDie;
    weapons weapon1(weaponName, weaponType, type, damageDie);
    return weapon1;
};

void showWeapon(weapons aWeapon) {
    //maybe translate the enumerators back into their named values so they aren't displayed as just numbers. 
    cout << "Your weapon's attributes are as follows: " << aWeapon.wName << ", " << aWeapon.weaponType << ", " << aWeapon.type << ", and " << aWeapon.damageDie << "." << endl;
}

template <typename T>
T verifyMonsterEntry(T monsterEntry) {
    //Control Flow variable
    char yesOrNo = 'N';
    do {
        cin >> monsterEntry;
        cout << endl << "You have entered: " << monsterEntry <<  endl << endl;
        cout << "Is this what you meant to enter? Y/N ";
        cin >> yesOrNo;
    } while (yesOrNo != 'Y');
    
    return monsterEntry;
};

//Allows monsters to be created at runtime in a more human friendly format.
Monster createMonster(){
    //Initialize monster input variables.
    string monsterName;
    int maxHitPoints = 0;
    weapons genericWeapon;
    int initMod = 0;
    int profeciencyBonus = 0;
    int attackBonus = 0;
    

    cout << "What is the name of your monster?" << endl;
    verifyMonsterEntry(monsterName);
    cout << "What are your monster's maximum hitpoints?" << endl;
    verifyMonsterEntry(maxHitPoints);
    cout << "Give your monster a weapon.";
    defineWeapon();
    cout << "What is your monster's initiative modifier?" << endl;
    verifyMonsterEntry(initMod);
    cout << "What is your monster's profeciency bonus?" << endl;
    verifyMonsterEntry(profeciencyBonus);
    cout << "What is your monster's attack bonus? "
      << "(This is added after your proficency bonus to get your attack modifier.)" << endl;
    verifyMonsterEntry(attackBonus);
    Monster monster1(monsterName, maxHitPoints, genericWeapon, initMod, profeciencyBonus, attackBonus);
    return monster1;
}


void copyMonster(Monster aMonster) {
    Monster monster2 = aMonster;
}

/*
void copyMonster(Monster aMonster, int numberOfCopies) {
    int monsterNumber;
    template < monster>
    while (numberOfCopies != 0) {
        Monster monster<monsterNumber> = aMonster;

    }
    // Make a while statement with the number of monsters of the same kind desired. 
    // ^^^ Probably not making it into this version. 
};
*/



int main() {
    srand(time(0));
    //createMonsters(); This step is done manually here but in future versions this can be part of the game logic as well. See 2nd cout bellow and the createMonster() function. 
    weapons greatAxe("Greataxe", "Melee", slashing, d12);
    weapons javalin("Javelin", "Thrown", piercing, d6);
    Monster monster1("Orc 1", 15, greatAxe, 1, 2, 3);
    Monster monster2("Orc 2", 15, javalin, 1, 2, 3);
    Monster monster3("Orc 3", 15, javalin, 1, 2, 3);
    Monster monster4("Orc 4", 15, javalin, 1, 2, 3);

    //game logic
    cout << "Hello, and welcome to DND Combat manager created by Cayden Wootton." << endl;
    cout << "Please start by defining the monsters for your encounter." << endl << endl;


    cout << "The end of the array is: " << findArrayEnd() << endl;
    
    

    //Turn logic
    //cout << "Did the monster take damage? (Y/N)";

    return 0;
}