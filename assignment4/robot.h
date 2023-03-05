/* HEADER
   FILE */

#ifndef _ROBOT_H
#define _ROBOT_H

#include <iostream>
#include <string>

using namespace std;

/* BASE CLASS */
class Robot
{
public:
    Robot();
    Robot(int newStrength, int newHit);

    virtual int getDamage() const;
    int getStrength() const;
    int getHitpoints() const;
    string getType() const;

    void setStrength(int newStrength);
    void setHitpoints(int newHit);
    void setType(string newType);

private:
    int strength;
    int hitpoints;
    string type;
};

/* DERIVED CLASSES */
class Humanic:public Robot
{
public:
    Humanic();
    Humanic(int newStrength, int newHit);
    /* includes special attacking skills of humanic robots */
    int getDamage() const override;
};

class Roomba:public Robot
{
public:
    Roomba();
    Roomba(int newStrength, int newHit);
    /* includes special attacking skills of roomba */
    int getDamage() const override;
};

class Bulldozer:public Robot
{
public:    
    Bulldozer();
    Bulldozer(int newStrength, int newHit);
};

class OptimusPrime:public Humanic
{
public:    
    OptimusPrime();
    OptimusPrime(int newStrength, int newHit);
    /* includes special attacking skills of optimusprime */
    int getDamage() const override; 
};

class Robocop:public Humanic
{
public:    
    Robocop();
    Robocop(int newStrength, int newHit);
};

#endif