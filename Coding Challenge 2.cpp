//Branden Farano

//This program will create a rudimentary scrabble game that will compare the word entered by 2 players, and announce a winner

#include <iostream> 
#include <sstream> //allows input output operations on strings
#include <string> //allows manipulation of string input
#include <cctype> //allows the use of the 'isalpha' function, which checks if a value is a letter

using namespace std; //removes need 'std:' in front of 'cin' and 'cout'

int main() //main method
{
	int player1score; //variable that will hold the value of player 1's score
	int player2score; //variable that will hold the value of player 2's score
	string tempValueString; //variable used to hold score of the users word as a string
	string text; //string variable holding user input
	char choice; //used to check if player(s) would like to play again
	
	string scrabbleScorer( string text ); //forward declaration of scrabbleScorer method (line 45)
	void winnerDecider( int player1score, int player2score ); //forward declaration of winnerDecider method (line 133)
	void playAgain( char choice ); //forward declaration of playAgain method (line 158)
	
	cout << "Player 1 enter word: ";
	getline( cin , text ); //gets user input and stores it in text variable
	
	string value1 = scrabbleScorer( text ); //gets score of player 1 from scrabbleScorer method
	player1score = stoi( value1 ); //converts the score of player 1 being held as a string, into an integer and stores it in variable player1score
	
	cout << "Player 2 enter word: ";
	getline( cin , text ); //gets user input and stores it in text variable
	
	string value2 = scrabbleScorer( text ); //gets score of player 2 from scrabbleScorer method
	player2score = stoi( value2 ); //converts the score of player 2 being held as a string, into an integer and stores it in variable player2score
	
	winnerDecider( player1score , player2score ); //prints output of winnerDecider method, displaying the Scrabble winner to the user(s)
	
	cout << "\nWould you like to play again? Y/N _\b"; 
	cin >> choice; //gets user input to be used in 'playAgain' method
	
	playAgain( choice ); //calls playAgain method to determine if the game continues
	
} //end of main block

string scrabbleScorer( string text ) //method parsing user input to determine the score of the word entered and return its value
{                         
	int counter = 0; //variable used to move pointer to next letter in string variable 'text'
	int length_of_word = text.size(); //variable used to hold the length of the word the user enters
	int value = 0; //variable used to hold score of word. Resets to 0 when method is called so it can score a new word
	
	while( counter < length_of_word) //loop and if statement will find amount of sentences in the users input by checking special character parameters
	{	
		text[ counter ] = toupper( text[ counter ] ); //makes letter being checked uppercase, so program has to check less cases
		if( !isalnum(text[ counter ] ) || isdigit( text[ counter ] ) )// skips to next cell if it is a letter (first if)
		{
			counter++; //skips to next cell if value is not a letter
		} //end of first if statement
		else //first else
		{
			if( text[ counter ] == 'A' || text[ counter ] == 'E' || text[ counter ] == 'I' || text[ counter ] == 'L' || text[ counter ] == 'N' || text[ counter ] == 'O' || //(second if)
			    text[ counter ] == 'R' || text[ counter ] == 'S' || text[ counter ] == 'T' || text[ counter ] == 'U') //checks for letters A,E,I,L,N,O,R,S,T,U and adds 1 to variable 'value' if they are found
			    {																									 //(second if)
			    	value +=1 ; //adds 1 to variable 'value'
			    	counter++; //moves onto next letter if one matching above parameters is found
				} // end of second if
				else //second else
				{
					if( text[ counter ] == 'D' || text[ counter ] == 'G') // checks for letters D or G, and adds 2 to variable 'value' if they are found (third if)
					{
						value += 2; //adds 2 to variable 'value'
						counter ++; //moves onto next letter if one matching above parameters is found
					} //end of third if
					else //third else
					{																												
						if ( text[ counter ] == 'B' || text[ counter ] == 'C' || text[ counter ] == 'M' || text[ counter ] == 'P') //checks for letters B,C,M,P and adds 3 to variable 'value' if they are found
						{																										  //(fourth if)
							value += 3; //adds 3 to variable 'value'
							counter++; //moves onto next letter if one matching above parameters is found
						} //end of fourth if
						else //fourth else
						{
							if ( text[ counter ] == 'F' || text[ counter ] == 'H' || text[ counter ] == 'V' || text[ counter ] == 'W' || text[ counter ] == 'Y') //checks for letters B,C,M,P and adds 4 to variable 'value' if they are found
							{																																	//(fifth if)
								value += 4;
								counter++;
							} //end of fifth if
							else //fifth else
							{
								if ( text[ counter ] == 'K' ) //checks for the letter K and adds 5 to variable 'value' if found (sixth if)
								{
									value += 5; //adds 5 to variable 'value'
									counter++; //moves onto next letter if the one matching the above parameters is found
								} //end of sixth if
								else //sixth else
								{
									if( text[ counter ] == 'J' || text[ counter ] == 'X') //checks for the letters J or X and adds 8 to variable 'value' if found (seventh if)
									{
										value += 8; //adds 8 to variable 'value'
										counter++; //moves onto next letter if the one matching the above parameters is found
									} //end of seventh if
									else //seventh if
									{
										if ( text[ counter ] == 'Q' || text[ counter ] == 'Z') //checks for the letters Q or Z and adds 10 to variable 'value' if found (eighth if)
										{
											value += 10; //adds 10 to variable 'value'
											counter++; //moves onto next letter if the one matching the above parameters is found
										} //end of eighth if
										
									} //end of seventh else
									
								} //end of sixth else
								
							} //end of fifth else
							
						} // end of fourth else
						
					} //end of third else
					
				} //end of second else	
				
		} //end of first else
	
	} //end of while loop
		
	stringstream tempValueSS; //creates a stringstream variable that will hold the value of the variable 'value'
	tempValueSS << value; //variable created to temporarily make 'value' a stringstream
	string tempValueString = tempValueSS.str(); //converts the stringstream into a string
	
	return tempValueString; //returns string value to wherever the method is called
	
} //end of scrabbleScorer block

void winnerDecider( int player1score , int player2score ) //method checking players scores to determine a winner
{
	if ( player1score > player2score ) //if player 1 wins (first if)
	{
		cout << "Player 1 Wins!"; //prints this
	} //end of first if statement
	else //first else
	{
		if( player2score > player1score ) //if player 2 wins (second if)
		{
			cout << "Player 2 Wins!"; //prints this
		} //end of second if statement
		else //second else
		{
			if ( player1score == player2score ) // if the players tie (third if)
			{
				cout << "Tie!"; //prints this
			} //end of third if
			
		} //end of second else
		
	} //end of first else
	
} //end of winnerDecider block

void playAgain( char choice ) //will check if player wishes to play again after every game, and will close the program when they type 'N' or 'n'
{
		fflush( stdin ); //empties input buffer so first input isnt skipped
	
		if ( choice == 'Y' || choice == 'y') //if user chooses to play again (first if)
		{
			int player1score; //variable that will hold the value of player 1's score
			int player2score; //variable that will hold the value of player 2's score
			string tempValueString; //variable used to hold score of the users word as a string
			string text; //string variable holding user input
			
			cout << "Player 1 enter word: ";
			getline( cin , text ); //gets user input and stores it in text variable
	
			string value1 = scrabbleScorer( text ); //gets score of player 1 from scrabbleScorer method
			player1score = stoi( value1 ); //converts the score of player 1 being held as a string, into an integer and stores it in variable player1score
	
			cout << "Player 2 enter word: ";
			getline( cin , text ); //gets user input and stores it in text variable
	
			string value2 = scrabbleScorer( text ); //gets score of player 2 from scrabbleScorer method
			player2score = stoi( value2 ); //converts the score of player 2 being held as a string, into an integer and stores it in variable player2score
			winnerDecider( player1score , player2score ); //prints output of winnerDecider method, displaying the Scrabble winner to the user(s)
	
			cout << "\nWould you like to play again? Y/N _\b"; 
			cin >> choice; //gets user input to be used in 'playAgain' method
	
			playAgain( choice ); //calls playAgain method to determine if the game continues
	
		} //end of first if
		else //first else
		{
			if ( choice != 'Y' || 'y' ) //if user doesn't wish to continue (second if)
			{
				cout << "Thanks for playing!";
				return; //ends program
			} //end of second if
		
		} //end of first else
	
} //end of playAgain block