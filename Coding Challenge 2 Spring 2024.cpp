#include <iostream>
#include <cmath> //allows for complex math operation functions to be used

using namespace std; //places std in the namespace library

string cardCompany( string cardNumber ); //forward declaration of the 'cardCompany' function which displays the card company of an inputted card number

void validCard( string cardNumber ); //forward declaration of the 'validCard' function which displays if a card is valid based on the Hans Peter Luhn formula for finding synctactically correct numbers

int main()
{
	string cardNumber; //variable used to store the users entry for their card number
	
	cout << "Please enter your card number without hyphens: "; //prompts the user to enter their card number
	getline(cin, cardNumber); //stores their entry in 'cardNumber' using getline()
	
	while( cardNumber.empty() ) //while loop used to check for empty input
	{
		cout << "No input detected \n"; //alerts user if no input is detected
		cout << "Please enter your card number without hyphens: "; //reprompts the user to enter their card number
		getline(cin, cardNumber); //gets input again from the user again
	}                             //loop will run until it recieves any valid entry that isn't a newline
	
	cout << cardCompany(cardNumber); //calls the 'cardCompany' function using the users card entry as the argument
	validCard(cardNumber); //calls the validCard function using the users same card entry as the argument
} //end of main

string cardCompany( string cardNumber ) //function that will find the users credit card company if it has a valid starting number/numbers
{
	
	string cardCompanyName; //variable used to store the result of the 'cardCompany' function, which will be the card companys name
	unsigned long long int cardNumberInt = stoll( cardNumber ); //converts the string card number into a long long int called 'cardNumberInt' so the number can be used in finding the first digit or digits in the card number            
	int partialCardNumber = cardNumberInt / (pow(10,(cardNumber.size() - 2))); //used to find the first two digits in the card number which will be stored in 'partialCardNumber'

	if( partialCardNumber > 39 && partialCardNumber < 50) //checks for VISA's starting digit which is a 4 (will check between 40 and 49 as it will be handed 2 digits, but that doesn't matter)
	{
		cardCompanyName = "Visa"; //will display if the above is true
		return cardCompanyName; //returns the result as a variable instead of just a cout statement in case the result needs to be verified in an expanded program
	}
	else if( partialCardNumber > 50 && partialCardNumber < 56 ) //checks for MasterCard's starting digits between 51 and 55
	{
		cardCompanyName = "MasterCard"; //same logic as above condition
		return cardCompanyName;
	}
	else if( partialCardNumber == 34 || partialCardNumber == 37 ) //checks for AMEX starting digits which are 34 or 37
	{
		cardCompanyName = "AMEX"; //same logic as above condition
		return cardCompanyName;
	}
	else //if the entry doesn't match any of the above cardholders, will display this "error" message
	{
		cardCompanyName = "Couldn't match card to any credit/debit company, so the"; //sentence continued in combination with the validCard function
		return cardCompanyName;
	}
	
} //end of cardCompany function

void validCard( string cardNumber ) //function used to calculate if the entered card number is valid
{
	
	unsigned long long int cardNumberInt = stoll( cardNumber ); //converts the string card number into a long long int called 'cardNumberInt'
	int index = cardNumber.size() - 2; // (1/3) variable will hold the index of the string, starting at the second to last cell
	int cardNumCalc = 0, cardNumCalcTemp = 0; //creates the variales used to hold the results of the Hans Peter Luhn calculation. 'cardNumCalc' will hold the actual calculation result, while 'cardNumCalcTemp'
	int counter = cardNumber.size() / 2; //will be the counter to stop the loop, which is half the number length as the numbers used alternate 			// (2/3) will hold the digit of the value of the indexed cell which is necessary to have a seperate variable a in case the calc
																																	// (3/3) results in 2 digits after the multiplication of the alternated digits
	while( counter > 0 ) //loop used to multiply each alternated digit by 2 individually, starting with the 2nd to last digit of the card number
	{
		cardNumCalcTemp = (cardNumber[index] - '0') * 2; //holds the value of the indexed cell time 2 after converting the "char" cell of that digit into an integer using an ASCII calculation
		
		if(cardNumCalcTemp < 10 ) //if value of the indexed cell time 2 is less than 10
		{
			cardNumCalc += cardNumCalcTemp; //add it to the 'cardNumCalc' variable
		}
		else //else if the result of the indexed cell is greater than 10
		{
			cardNumCalc += (cardNumCalcTemp / 10 + cardNumCalcTemp % 10); //find the sum of each digit and add them together
		}
		index -= 2; //moves the index down 2, so the loop can work on the next alternated cell
		counter--; //decrement the counter by 1
	} //end of the while loop
	
	index = cardNumber.size() - 1; //resets the index to start at the last cell (the minus one is necessary as the size is always one greater than the cell number as cells start at 0)
	counter = cardNumber.size() / 2; //resets the counter
	
	while( counter > 0 ) //loop used to add the digits not used in the above calculation to the summation of the digits calculated above
	{
		cardNumCalc += (cardNumber[index] - '0'); //adds the indexed digit value to the 'cardNumCalc' variable, after converting the "char" cell of that digit into an integer using an ASCII calculation
		index -= 2; //moves the index down 2, so the loop can work on the next alternated cell
		counter--; //decrement the counter by 1
	}
	
	if( cardNumCalc % 10 == 0 ) //if the result of the above while loops, stored in 'cardNumCalc's' modulo is congruent to 0
	{
		cout << " card number is valid."; //tells the user they entered a valid card number
	}
	else //if the modulo of 'cardNumCalc' doesn't equal 0
	{
		cout << " card number isn't valid."; //tell the user they haven't entered a valid number
	}
} //end of 'validCard' function

/*Please enter your card number without hyphens: 4734619231293574
Visa card number is valid.
Please enter your card number without hyphens: 132435345345345
Couldn't match card to any credit/debit company, so the card number isn't valid.
*/