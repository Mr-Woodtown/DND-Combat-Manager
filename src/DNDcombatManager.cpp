
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//include customized .h file
#include "DNDcombatManager.h"

using namespace std;

//Defining Weapons
weapons greatAxe("Greataxe", "Melee", slashing, d12);
weapons javalin("Javelin", "Thrown", piercing, d6);

//string name, string weaponType, damageType smackEtc,  
//weapons javelin();


void askRoll() {
    dice thisDie;
    std::cout << "Which die would you like to roll? (type the letter d then number of sides.)" << endl;
    cin >> thisDie;
    whichDie(thisDie);
};

weapons defineWeapon() {
    string weaponName, weaponType; //I had a dummy variable here as well but it looks like I don't need it anymore. Why did it not work before? Who knows?!
    damageType type;
    dice damageDie;
    char yesNo = 'N';

    std::cout << " \n\n Please enter a name and weapon type (reaching, thrown, etc.)\nHit enter after each entry.\n";
    std::cout << " \n\n Please enter a name and weapon type (reaching, thrown, etc.)\nHit enter after each entry.\n";
    do {        
        cin >> weaponName >> weaponType;
        cout << "You have entered " << weaponName << " for your weapon name and " << weaponType << " for your weapon's type. \nIs this what you wanted to enter? (Y/N) ";
        cin >> yesNo;
        if ((yesNo != 'Y') && (yesNo != 'y')) {
            cout << "Please enter the name and weapon type (can be anyting without a spacebar) again \n";
        }
    } while ((yesNo != 'Y') && (yesNo != 'y'));

    //Allow type verification without needing to type all the other attributes again.
    cout << "Please enter a damage type (bludgening, slashing, or piercing).\n";
    cin >> type;

    yesNo = 'N';
    cout << "Please enter a damage die (d<#ofSides>). (At the moment this program only supports a single damage die.) \n";
    do {
        cin >> damageDie;
        cout << "You have entered " << weaponName << " for your weapon name and " << weaponType << " for your weapon's type. \nIs this what you wanted to enter? (Y/N) ";
        cin >> yesNo;
        if ((yesNo != 'Y') && (yesNo != 'y')) {
            cout << "Please enter the name and weapon type (can be anyting without a spacebar) again \n";
        }
    } while ((yesNo != 'Y') && (yesNo != 'y'));
     
    cout << endl;
    weapons weapon1(weaponName, weaponType, type, damageDie);
    return weapon1;
};

void showWeapon(weapons aWeapon) {
    //maybe translate the enumerators back into their named values so they aren't displayed as just numbers. 
    std::cout << "Your weapon's attributes are as follows: " << aWeapon.wName << ", " << aWeapon.weaponType << ", " << aWeapon.type << ", and " << aWeapon.damageDie << "." << endl;
}

template <typename T>
T verifyMonsterEntry(T monsterEntry) {
    //Control Flow variable
    char yesOrNo = 'N';
    
    do {cin >> monsterEntry;
        std::cout << "\n" << "You have entered: " << monsterEntry << "\n" << endl;
        std::cout << "Is this what you meant to enter? Y/N ";
        cin >> yesOrNo;
        if ((yesOrNo != 'Y') && (yesOrNo != 'y')) {
            cout << "Please enter it again. \n";
        }
    } while ((yesOrNo != 'Y') && (yesOrNo != 'y'));
    cout << endl;
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
    

    std::cout << "What is the name of your monster?" << endl;
    verifyMonsterEntry(monsterName);
    std::cout << "What are your monster's maximum hitpoints?" << endl;
    verifyMonsterEntry(maxHitPoints);
    std::cout << "Give your monster a weapon. ";
    defineWeapon();
    std::cout << "What is your monster's initiative modifier?" << endl;
    verifyMonsterEntry(initMod);
    std::cout << "What is your monster's profeciency bonus?" << endl;
    verifyMonsterEntry(profeciencyBonus);
    std::cout << "What is your monster's attack bonus? "
      << "(This is added after your proficency bonus to get your attack modifier.)" << endl;
    verifyMonsterEntry(attackBonus);
    Monster monster1(monsterName, maxHitPoints, genericWeapon, initMod, profeciencyBonus, attackBonus);    
    return monster1;
}

//write this function
//Combatant rollMonstersInitiave() {}

void copyMonster(Monster aMonster, string ) {
    Monster monster2 = aMonster;
}


//This function is now replaced by overloading the assignment operator and calling the uncommented function copyMonster();
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

//A vector might be easier to impliment than an array for a later verison
int main() {
    srand(time(0));
    //Monster creation This step is done manually in this version but in future versions this will be part of the game logic as well. See 2nd std::cout bellow and the createMonster() function.     
    Monster monster1("Orc 1", 15, greatAxe, 1, 2, 3);
    Monster monster2("Orc 2", 15, javalin,  1, 2, 3);
    Monster monster3("Orc 3", 15, javalin,  1, 2, 3);
    Monster monster4("Orc 4", 15, javalin,  1, 2, 3);
    const int numberOfMonsters = 4;
    Player player1("One-Shoe", 39);
    Player player2("Stumble Duck", 42);
    Player player3("Drungeon", 54);
    const int numberOfPlayers = 3;

    //cout << "This should be a sequece of random numbers from 1 to 20." << '\n' << die20sided() << ' ' << die20sided() << ' ' << die20sided() << '\n' << "It is clearly not." << endl; \\It is now! ;)


    //game logic
    std::cout << "\nHello, and welcome to DND Combat manager created by Cayden Wootton." << endl;
    //std::cout << "Please start by defining the monsters for your encounter." << '\n' << endl;

    //Begin Combat
    
    
    std::cout << "How many monsters do you want to have?" << endl;
    cin >> numberOfCombatants;//Provides size of the array.
    if (numberOfCombatants < maxCombatants) {
    Combatant* monsterInitiativeArray = new Monster[numberOfCombatants];
    }
    else {
        std::cout << "The number of monsters cannot be handeled by this program. \nPlease restart the program and try again. \n\n\n\n\n";
    }
    int numberOfCombatants = numberOfMonsters + numberOfPlayers;

    Combatant* playerInitiativeArray = new Player[numberOfPlayers];
    

    //Roll Monster Initiative
    monster1.setInitiative();
    monster2.setInitiative();
    monster3.setInitiative();
    //monster4.setInitiative();


    Combatant* monsterInitiativeArray[numberOfMonsters] = {&monster1, &monster2, &monster3, &monster4};
    //Debugging line: std::cout << "The end of the array is: " << findArrayEnd(InitiativeArray) << endl;
    cout << "These are " << endl;
    for (int indexCounter = 0; indexCounter < numberOfMonsters; indexCounter++) {
        cout << monsterInitiativeArray[indexCounter]->getName() << '\n';
    }
    cout << endl;

    
    ///*
    //void determineMonsterOrder(Combatant* initArray[4])  
    cout << "These are the first two in the array." << endl;
    cout << monsterInitiativeArray[0]->getName() << " has an initiative of " << monsterInitiativeArray[0]->getInitNumber() << " and " 
        << monsterInitiativeArray[1]->getName() << " has an initiative of " << monsterInitiativeArray[1]->getInitNumber() << "." << endl;
    cout << "Sorting things. " << endl;
    if (monsterInitiativeArray[0]->getInitNumber() < monsterInitiativeArray[1]->getInitNumber()) {
        //swap the order in the array
        Combatant* temp = monsterInitiativeArray[0];
        monsterInitiativeArray[0] = monsterInitiativeArray[1];
        monsterInitiativeArray[1] = temp;
    }
    cout << "Now that is sorted lets see how we're doing." << endl;
    cout << monsterInitiativeArray[0]->getName() << " has an initiative of " << monsterInitiativeArray[0]->getInitNumber() << " and "
        << monsterInitiativeArray[1]->getName() << " has an initiative of " << monsterInitiativeArray[1]->getInitNumber() << "." << endl;
    //*/

    ///*
    for (int timesThroughArray = 0; timesThroughArray < numberOfMonsters - 1; timesThroughArray++) {
        for (int indexCounter = 0; indexCounter < numberOfMonsters - 1; indexCounter++) {
            if (monsterInitiativeArray[indexCounter]->getInitNumber() < monsterInitiativeArray[indexCounter + 1]->getInitNumber()) {
                //swap the order in the array
                Combatant* temp = monsterInitiativeArray[indexCounter];
                monsterInitiativeArray[indexCounter] = monsterInitiativeArray[indexCounter + 1];
                monsterInitiativeArray[indexCounter + 1] = temp;
            }
        }  
    };
    cout << '\n' << monsterInitiativeArray[0]->getName() << '\n'
    << monsterInitiativeArray[1]->getName() << '\n'
    << monsterInitiativeArray[2]->getName() << '\n'
    << monsterInitiativeArray[3]->getName() << endl;
    //*/

    
    std::cout << "Enter player's intiatives." << endl;
    player1.setInitiative();
    player2.setInitiative();
    player3.setInitiative();
    

    
    //Possible Round logic

    //Turn logic
    /*
    char playerBeforeMonster = 'N';
    char aMonsterDamage;
    while(playerBeforeMonster != ('Y' && 'y')) {
    std::cout << "Does a player go before this monster? (Y/N)";
    cin >> playerBeforeMonster;
    if (playerBeforeMonster != 'Y') {
        break;
        }
    //do subroutine
    //access any monster
    std::cout << "Did the monster take damage? (Y/N)";
    }
    */



    //Deallocate array memory
    
    return 0;
}