#pragma once
#ifndef DND_XP_calculator_H
#define DND_XP_calculator_H

// Damage types
enum damageType = {bludgening = 1 , slashing, piercing}

//a weapons struct
struct weapons {
	string name;
	string weaponType;
	damageType type;

};