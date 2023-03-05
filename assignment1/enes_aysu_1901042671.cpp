#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int const TRY = 100;
int const MAX_DIGIT = 10;

/* function declarations */
void operationFunc(string operation, int number);
int generateNumber(int digit);
int firstCount(int number, int guess);
int secondCount(int number, int guess);
int countDigit(int number);
bool checkProper(int guess, int number);
bool checkNumber(int guess);
bool checkUnique(int guess);

void operationFunc(string operation, int number)
{
	int guess = 0, 
		randomNumber, 
		count = 0;
		
	bool flag1, 
		 flag2, 
		 flag3;
	
	/* if operation is "-r" */
	if(operation == "-r") 
	{
		/* digit numbers must be between 0 and 10 */
		if(number <= 0 || number >= MAX_DIGIT)
		{
			cout << "E0" << endl;
			return;
		}
		
		/* the program generates the number to be estimated */
		randomNumber = generateNumber(number);
		
		while(guess != randomNumber && count < TRY)
		{
			/* gets number from user */
			cin >> guess; 
			
			/* if input is not a number program prints "E2" */
			flag2 = checkNumber(guess);
			if(flag2 == false)
			{
				cout << "E2" << endl;
				return;
			}
			
			/* input must have the desired number of 
			digits otherwise program prints "E1" */
			flag1 = checkProper(guess, number);
			if(flag1 == false)
			{
				cout << "E1" << endl;
				return;
			}
			
			/* input must be unique, if it is not
			program prints "E0" */
			flag3 = checkUnique(guess);
			if(flag3 == false){
				cout << "E0" << endl;
			return;
			}
			
			/* counting turn */
			count++;
			
			/* prints hints to user */
			if(guess != randomNumber)
			{
				cout << firstCount(randomNumber, guess) << " ";
				cout << secondCount(randomNumber, guess) << endl;
			}
			
			/* if user found the number, program prints "FOUND" */
			else
				cout << "FOUND " << count << endl;
		}
		
		/* if user couldn't find number in 100 
		attempt, program prints "FAILED" */
		if(count >= TRY)
		{
			cout << "FAILED" << endl;
		}	
	}
		
	/* if operation is "-u" */	
	else if(operation == "-u")
	{	
		/* secret number must be unique, if it is not
		program prints "E0" */
		flag1 = checkUnique(number);
		if(flag1 == false)
		{
			cout << "E0" << endl;
			return;
		}
		
		/* secret number must more than 0, 
		otherwise program prints "E0" */
		if(number <= 0)
		{
			cout << "E0" << endl;
			return;
		}		

		/* calculates the number of digits of the secret number */
		if(countDigit(number) >= MAX_DIGIT)
		{
			cout << "E0" << endl;
			return;
		}
			
		while(guess != number && count < TRY)
		{
			cin >> guess;

			/* if input is not a number program prints "E2" */
			flag3 = checkNumber(guess);
			if(flag3 == false)
			{
				cout << "E2" << endl;
				return;
			}

			/* input must have the desired number of 
			digits otherwise program prints "E1" */
			flag1 = checkProper(guess, countDigit(number));
			if(flag1 == false)
			{
				cout << "E1" << endl;
				return;
			}
			
			/* input must be unique, if it is not
			program prints "E0" */
			flag2 = checkUnique(guess);
			if(flag2 == false)
			{
				cout << "E0" << endl;
				return;
			}

			/* counting turn */
			count++;
			
			/* prints hints to user */
			if(guess != number)
			{
				cout << firstCount(number, guess) << " ";
				cout << secondCount(number, guess) << endl;
			}
			
			/* if user found the number, program prints "FOUND" */
			else
				cout << "FOUND " << count << endl;
		}
		
		/* if user couldn't find number in 100 
		attempt, program prints "FAILED" */
		if(count >= TRY)
		{
			cout << "FAILED" << endl;
		}			
	}
	
	/* if first argument is not "-r" or "-u",
	program prints "E0" */
	else
	{
		cout << "E0" << endl;
		return;
	}
}

/* function that generates secret number with the desired digit */
int generateNumber(int digit)
{
	int remainder,
		temp = 0, 
		number = 0, 
		flag = 0;

	bool inFlag;

	srand(time(0));
	
	while(flag < digit)
	{
		remainder = rand() % MAX_DIGIT;
		inFlag = true;
		
		while(temp != 0)
		{
			if(remainder == (temp % MAX_DIGIT))
			{
				inFlag = false;
			}

			temp /= MAX_DIGIT;
		}
		
		if(inFlag)
		{
			/* by combining the digits, it creates the number */
			number = (MAX_DIGIT * number) + remainder;
			
			/* first digit of number cant be 0 */
			if(number != 0)
			{
				flag++;
			}	
		}

		temp = number;
	}

	return number;
}

/* in the user guess if there is same number at same place 
according to random nomber, this function returns amount of them */
int firstCount(int number, int guess)
{
	int count = 0;
	
	while(guess != 0 && number != 0)
	{
		if(guess % MAX_DIGIT == number % MAX_DIGIT)
		{
			count++;
		}

		guess /= MAX_DIGIT;
		number /= MAX_DIGIT; 
	}

	return count;
}

/* in the user guess if there is some number but wrong place 
according to random number, this function returns amount of them */
int secondCount(int number, int guess)
{
	int count = 0, 
		flag1 = 0, 
		flag2 = 0, 
		temp,
		remainder;
	
	temp = number;
	
	while(guess != 0)
	{
		remainder = guess % MAX_DIGIT;
	
		while(temp != 0)
		{
			if(remainder == temp % MAX_DIGIT && flag1 != flag2)
			{
				count++;
			}

			temp /= MAX_DIGIT;
			flag2++; 
		}

		temp = number;
		guess /= MAX_DIGIT;

		flag1++;
		flag2 = 0;
	}	

	return count;
}

/* secret and guess number must have
same number of digits */
bool checkProper(int guess, int number)
{
	bool flag;
	int count;
	
	count = countDigit(guess);
	
	if(count == number)
	{
		flag = true;
	}	

	else
	{
		flag = false;
	}
		
	return flag; 	
}

/* input must be a number */
bool checkNumber(int guess)
{
	bool flag = true; 
	
	/* checks whether the input is a number */
	if(cin.fail())
	{
		flag = false;
	}

	return flag;
}

/* input must be unique */
bool checkUnique(int guess)
{
	int remainder, 
		temp;

	bool flag = true;	
	
	while(guess > 0)
	{
		remainder = guess % MAX_DIGIT;
		temp = guess / MAX_DIGIT;
		
		while(temp != 0)
		{
			if(remainder == temp % MAX_DIGIT)
			{
				flag = false;
			}
			
			temp /= MAX_DIGIT; 
		}

		guess /= MAX_DIGIT;
	}

	return flag;
}

/* counts digit of secret number from -u operation */
int countDigit(int number)
{
	int count = 0;

	while(number > 0)
	{
		number /= MAX_DIGIT;
		count++; 
	}

	return count;
}

/* main function */
int main(int argc, char** argv)
{
	string operation;
	int number;
	
	/*if the user enters more or less arguments 
	than the desired number, it gives an error */
	if(argc != 3) 
	{
		cout << "E0" << endl;
		return 0;
	}
	
	/* storing first argument (-r or -u) */
	operation = argv[1]; 
	/* storing second argument (digit or number) */
	number = stoi(argv[2]); 

	/* all operations are performed in this function */
	operationFunc(operation, number); 
		
	return 0;
}
