#include <iostream>
#include <string>
#include "robot.h"

using namespace std;

Robot::Robot()
{
    strength = 0;
    hitpoints = 0;
    type = "Robot";
}

Robot::Robot(int newStrength, int newHit)
{
    strength = newStrength;
    hitpoints = newHit;
    type = "Robot";
}

/* calculates attack power for every robot types */
int Robot::getDamage() const
{
    int damage;

	damage = (rand() % getStrength()) + 1;
	cout << "\n" << getType() << " attacks for " 
         << damage << " points!";

	return damage;
}

/* get functions */
int Robot::getStrength() const 
{
	return strength;
}

int Robot::getHitpoints() const 
{
	return hitpoints;
}

string Robot::getType() const 
{   
    return type;
}

/* set functions */
void Robot::setStrength(int newStrength) {
	this-> strength = newStrength;
	return;
}

void Robot::setHitpoints(int newHit) {
	this-> hitpoints = newHit;
	return;
}

void Robot::setType(string newType) {
	this-> type = newType;
	return;
}

Humanic::Humanic():Robot() 
{
	setType("Humanic");
}

Humanic::Humanic(int newStrength, int newHit):Robot(newStrength, newHit) 
{
	setType("Humanic");
}

/* calculates extra attack power for humanic robots */
int Humanic::getDamage() const 
{

	int damage;
	
    Robot Humanic(getStrength(), getHitpoints());
	Humanic.setType(getType());

	damage = Humanic.getDamage();

	if((rand() % 100) < 10) 
    {
		/* calculates tactical nuke attack and adds to total damage */
		damage = damage + 50; 
		cout << "\nTactical nuke attack inflicts 50 "
             << "additional damage points!";
	}

	return damage;
}

Roomba::Roomba():Robot() 
{
	setType("Roomba");
}

Roomba::Roomba(int newStrength, int newHit):Robot(newStrength, newHit) 
{
	setType("Roomba");
}

/* calculates extra attack power for roomba */
int Roomba::getDamage() const 
{ 

	int damage, damage_2;
	Robot Roomba(getStrength(), getHitpoints());

	Roomba.setType(getType());
	damage = Roomba.getDamage();

	/* calculates speed attack and adds to total damage */
	damage_2 = (rand() % getStrength()) + 1;
	cout << "\n" << getType() << " speed attack inflicts " 
         << damage_2 << " additional damage points!";
	damage = damage + damage_2;

	return damage;
}

Bulldozer::Bulldozer():Robot() 
{
	setStrength(10);
	setHitpoints(10);
	setType("Bulldozer");
}

Bulldozer::Bulldozer(int newStrength, int newHit):Robot(newStrength, newHit) 
{
	setStrength(newStrength);
	setHitpoints(newHit);
	setType("Bulldozer");
}

OptimusPrime::OptimusPrime():Humanic() 
{
	setType("OptimusPrime");
}

OptimusPrime::OptimusPrime(int newStrength, int newHit):Humanic(newStrength, newHit)
{
	setType("OptimusPrime");
}

/* calculates extra attack power for optimusprime */
int OptimusPrime::getDamage() const 
{
	int damage;
	Humanic OptimusPrime(getStrength(), getHitpoints());

	OptimusPrime.setType(getType());
	damage = OptimusPrime.getDamage();

	if((rand() % 15) == 0) 
    {
		/* calculates strong attack and adds to total damage */
		cout << "\nStrong attack inflicts " << damage 
             << " additional damage points!";
		damage = damage * 2;
	}

	return damage;
}

Robocop::Robocop():Humanic() 
{
	setType("Robocop");
}

Robocop::Robocop(int newStrength, int newHit):Humanic(newStrength, newHit) 
{
	setType("Robocop");
}