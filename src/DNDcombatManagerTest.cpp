#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
//include customized .h file
#include "DNDcombatManager.h"

using namespace std;


dice whichDice;


int main(){
    srand(time(0));

    //It's supposed to work like this:
    cout << "Which die would you like to roll? (type the letter d then number of sides.)" << endl;
    cin >> whichDice;






    cout << die6sided(4) << endl;
    cout << die6sided() << endl;



    cout << whichDie(d6) << endl;

    cout << "Which die would you like to roll? (type the number of sides.)" << endl;
    cin >> whichDice;

    //game logic
    
    return 0;
}