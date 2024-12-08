#pragma once
#ifndef DNDcombatManager_H
#define DNDcombatManager_H


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


//struct dice {
// };

//Die function prototypes
int die4sided();
int die6sided();
int die8sided();
int die10sided();
int die12sided();
int die20sided();

// Damage types
enum damageType {bludgening = 1 , slashing, piercing };
enum dice { d4 = 4, d6 = 6, d8 = 8, d10 = 10, d12 = 12, d20 = 20 };


dice whichDie(dice die) {
	switch (die) {
	case d4:
		cout << "Your roll: " << die4sided() << endl;
		break;
	case d6:
		cout << "Your roll: " << die6sided() << endl;
		break;
	case d8:
		cout << "Your roll: " << die8sided() << endl;
		break;
	case d10:
		cout << "Your roll: " << die10sided() << endl;
		break;
	case d12:
		cout << "Your roll: " << die12sided() << endl;
		break;
	case d20:
		cout << "Your roll: " << die20sided() << endl;
		break;
	default:
		cout << "That's not a valid number for a die in DND. " << endl;
		break;
	}
	return die;
}

int rollDie(dice die) {
	int diceRoll = 0;
	switch (die) {
	case d4:
		diceRoll = die4sided();
		break;
	case d6:
		diceRoll = die6sided();
		break;
	case d8:
		diceRoll = die8sided();
		break;
	case d10:
		diceRoll = die10sided();
		break;
	case d12:
		diceRoll = die12sided();
		break;
	case d20:
		diceRoll = die20sided();
		break;
	default:
		cout << "That's not a valid number for a die in DND. (rollDie error)" << endl;
		break;
	}
	return diceRoll;
}

//overload the >> operator for dice 
std::istream& operator>>(std::istream& is, dice& diceName) {
	int dNumberForDie;
	char aLetter;

	is >> aLetter >> dNumberForDie;

	switch (dNumberForDie) {
	case 4:	case 6:	case 8:	case 10: case 12: case 20:
		diceName = dice(dNumberForDie);
		break;
	default:
		throw out_of_range("That's not a valid number of sides for a die in DND. ");
		break;
	};
	cout << endl;

	return is;	
}

//overload the >> operator for damagetype
std::istream& operator>>(std::istream& is, damageType& typeName) {
	string type;

	do {
		is >> type;
		
		if (type == "bludgening") {
			typeName = damageType(1);
			break;
		}
		else if (type == "slashing") {
			typeName = damageType(2);
			break;
		}
		else if (type == "piercing") {
			typeName = damageType(3);
			break;
		}
		else { cout << "Either that damage type is not allowed in this program or you need to check your spelling." << endl << "Please try entering the damage type again; afterwards, continue." << endl; }
	} while (typeName != (bludgening || slashing || piercing));

	return is;
}


//a weapons struct 
struct weapons {
	string wName;
	string weaponType;
	damageType type;
	dice damageDie;
	
	//Weapons constructors
	weapons(): wName("Javelin"), weaponType("Thrown"), type(piercing), damageDie(d6) {};
	weapons(string wName, string weaponType, damageType type, dice damageDie): 
		wName(wName), weaponType(weaponType), type(type), damageDie(damageDie) {

	};

	//Overloading assignment operator
	weapons& operator=(const weapons& C)
	{
		// Check for self-assignment
		if (this != &C) {
			wName = C.wName;
			weaponType = C.weaponType;
			type = C.type;
			damageDie = C.damageDie;
		}
		return *this;
	}
};

class Combatant {
protected:
	string name;
	int maxHitPoints;
	int currentHitPoints;

	int initiativeNumber;
public:
	Combatant() : name("None"), initiativeNumber(0), maxHitPoints(0), currentHitPoints(0) {};
	Combatant(string name) : initiativeNumber(0), name(name), maxHitPoints(10), currentHitPoints(maxHitPoints) {};
	Combatant(string name, int max) : name(name), maxHitPoints(max), currentHitPoints(max), initiativeNumber(0) {};
	Combatant(string name, int max, int initiative) : name(name), maxHitPoints(max), currentHitPoints(max), initiativeNumber(initiative) {};
	Combatant(string name, int max, int curHP, int initiative) : name(name), maxHitPoints(max), currentHitPoints(curHP), initiativeNumber(initiative) {};

	void setIntative(int initiativeRoll, int initiativeMod) {
		initiativeNumber = initiativeRoll + initiativeMod;
	}
	void tookDamage(int damage) {
		currentHitPoints -= damage;
	};

	const int getCrntHitPoints() { return currentHitPoints; };
	const int getMaxHitPoints() { return maxHitPoints; };
	const string getName() { return name; };
	const int getInitNumber() { return initiativeNumber; };


	//Below is help from the internet atemting to do the same
	// Assignment operator overload
	Combatant& operator=(const Combatant& C)
	{
		// Check for self-assignment
		if (this != &C) {
			name = C.name;
			maxHitPoints = C.maxHitPoints;
			currentHitPoints = C.currentHitPoints;
			initiativeNumber = C.initiativeNumber;
		}
		return *this;
	}

	friend void
		switchCombatants(Combatant& combatant1, Combatant& combatant2);
};

class Monster : public Combatant{
private:
	weapons weapon;
	int initMod;
	//int strengthMod, = 0;
	//int dexterityMod, = 0;
	int proficencyBonus;
	int attackBonus;

public:
	//Public methods	
	void rollInitiative() {
		initiativeNumber = die20sided() + initMod;		
	};
	void makeAttack() {
		int atkRoll = die20sided() + getAttackBonus();
		std::cout << "The monster rolled a " << atkRoll << std::endl;
	};
	void tellDamage() {
		int damageRoll = rollDie(weapon.damageDie) + getAttackBonus();
		std::cout << "The monster rolled " << damageRoll << " for damage." << std::endl;
	};
	//Functions for displaying attributes
	const weapons getWeapon() { return weapon; };	
	const int getProfBonus() { return proficencyBonus; };
	const int getAttackBonus() { return attackBonus; };
	const int getInitMod() { return initMod; };
	 
	//create construtors
	Monster() :weapon(), initMod(2), proficencyBonus(2), attackBonus(0), Combatant("Commoner", 10 , 10)  {};
	Monster(string name, int max, weapons weapon, int initMod, int profBonus, int atkBonus) : weapon(weapon), initMod(initMod), proficencyBonus(profBonus), attackBonus(atkBonus),
		Combatant(name, max) {	cout << "Your monster has been created. \n"; }

	Monster& operator=(const Monster& C)
	{
		// Check for self-assignment
		if (this != &C) {
			name = C.name;
			maxHitPoints = C.maxHitPoints;
			currentHitPoints = C.currentHitPoints;
			initiativeNumber = C.initiativeNumber;
			weapon = C.weapon;
			initMod = C.initMod;
			proficencyBonus = C.proficencyBonus;
			attackBonus = C.attackBonus;
		}
		return *this;
	}
};

class Player : public Combatant{
private:
	
public:
	//constructors

	Player(string name, int maxHP, int curHP, int initNum) : Combatant(name, maxHP, curHP, initNum)
	{cout << "This player has been created with their current hit points and initiative. \n\n";	
	}
	Player(string name, int maxHP, int curHP) : Combatant(name, maxHP, curHP, 0)
	{
		cout << "This player has been created with their current hit points. \n\n";
	}
	//Comented bellow doesn't work because the constructor above also has one string then two int. 
	//Player(string name, int maxHP, int initNum) : Combatant(name, maxHP, initNum) 
	//{ cout << "This player has been created with their initiative. \n\n"; 
	//}
	Player(string name, int maxHP) :  Combatant(name, maxHP) 
	{ cout << "This player has been created. \n\n"; 
	}
	
	//Functions for Player inputs
	void rolledInit(int initiative) { 
		initiativeNumber = initiative;
	};
	void enterCurrentHP(int currentHitpoints) {
		currentHitPoints = currentHitpoints;
	}
};

//I don't think I can implement initaitive management without an array.
const int maxCombatants = 20;

Combatant initiativeArray[maxCombatants]; //I'm not really sure how I'll do this yet. 

//Logic for determining the order of initiatve. 
int findArrayEnd(Combatant InitiativeArray[maxCombatants]) {
	int index = 0;

	while (InitiativeArray[index].getName() != "None") {
		if (index >= maxCombatants) {
			break;
		}
		index++;
	}

	return index;
}

void addCombatantToList(Combatant InitArray[maxCombatants], Combatant& add) {
	//add the Combatant to the end of the list.
	int index = findArrayEnd(InitArray);
	// debug line 
	cout << "This is the name of the array index: " << InitArray[index].getName() << endl;
	InitArray[index] = add;
};

void switchMonsters(Monster& combatant1, Monster& combatant2){	
	Monster temp;
	temp = combatant1;
	combatant1 = combatant2;
	combatant2 = temp;
}

/*
void determineOrder(Combatant InitArray[maxCombatants]) {
	int numberOfCombatants = findArrayEnd(InitArray);
	int index = 0;
	while (InitArray[index].getName() != "None" && index > maxCombatants) {
		if (InitArray[index].getInitNumber() < InitArray[index + 1].getInitNumber()) {
			switchCombatants(InitArray[index], InitArray[index]);
		}
		index++;
	}
};
*/

//Full dice rolling functions

int die4sided() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 3;
	return total;
}
int die4sided(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 3;
	}
	return total;
}

int die6sided() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 5;
	return total;
}
int die6sided(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 5;
	}
	return total;
}

int die8sided() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 7;
	return total;
}
int die8sided(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 7;
	}
	return total;
}

int die10sided() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 9;
	return total;
}
int die10sided(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 9;
	}
	return total;
}

int die12sided() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 11;
	return total;
}
int die12sided(int quantity) {
	int total = 0;
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 11;
	}
	return total;
}

int die20sided() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 19;
	return total;
}
int die20sided(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 19;
	}
	return total;
}



#endif