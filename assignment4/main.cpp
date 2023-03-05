#include <iostream>
#include "robot.h"

using namespace std;

/* function declaretion */
void match(Robot& r1, Robot& r2); 

int main()
{
    int damage = 0;

    /* setting strenght and hitpoint variables */
    Roomba Jazz(20, 50); 
	Bulldozer Ironhide(20, 50);
	OptimusPrime Prime(20, 50);
	Robocop Bumblebee(20, 50);

    /* matches */
    match(Jazz, Bumblebee);
    match(Ironhide, Prime);

	cout << endl << endl;
	return 0;
}

/* match function */
void match(Robot& r1, Robot& r2)
{
    int health = 0;

    cout << "\n\n" << r1.getType() << " vs " << r2.getType();
    while(1)
    {
        cout << "\n" << r2.getType() << " strikes";
        health = r1.getHitpoints() - r2.getDamage();
        r1.setHitpoints(health);
        if(r1.getHitpoints() < 0)
        {
            /* when r1 dies, game over */
            cout << "\n" << r1.getType() << " defeated";
            break;
        }    
        
        cout << "\n" << r1.getType() << " strikes";
        health = r2.getHitpoints() - r1.getDamage();
        r2.setHitpoints(health);
        if(r2.getHitpoints() < 0)
        {
            /* when r2 dies, game over */
            cout << "\n" << r2.getType() << " defeated";
            break;
        }
    }
}
