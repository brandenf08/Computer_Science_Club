//Branden Farano
//Computer Science Club
//Coding Challenge 3
//11/17/23

//This program will allow for a user to simulate a ranked choice ballot. The program will start by asking the user for the amount
//of voters, followed by asking for each voters top 3 candidate choices

#include <iostream> //required for input and output in a program
#include <algorithm> //allows the use of the max() function, which returns the highest value input into it, and the transform function, which turns a string into all lowercase or all uppercase depending on parameters

using namespace std; //allows you to not have to use std:: before several statements

void voteWinnerCalc(); //forward declaration of the voteWinnerCalc() function

int main() //main function; required for program to run
{
	voteWinnerCalc(); //call for the voteWinnerCalc function
} //end of main

void voteWinnerCalc() //function that simulates a ranked choice ballot. The function will start by asking the user for the amount
//of voters. The function will then use the amount of voters as a limit in the while loop, asking the user for votes until that limit is reached. It will then test the input against several if statements,
//and print out the winner of the ballot
{
	int numOfVoters, loopCounter = 0, aliceVotes = 0, bobVotes = 0, charlieVotes = 0, arraySetValue = 0; //numOfVoters is the variable used when asking the user for the number of voters
																										 //loopCounter is the variable that will act as the counter for the while loop
																										 //aliceVotes, bobVotes2, charlieVotes3 are the variables that will hold the candiates votes
																									   	 //arraySetValue is the variable that will change which cell is in use in the candidateChoice variables
																											
	
	cout << "Please enter the amount of voters: "; //asks user to enter the amount of voters
	cin >> numOfVoters; 						   //gets users input for number of users
	
	cout << "Please enter your candidate choices by rank\n"; //prompts user to enter their candidate choices
	
	string candidateChoice1, candidateChoice2 [ numOfVoters ], candidateChoice3 [ numOfVoters ]; //variables used to create several variables to hold the user's candidate choices
	
	while ( loopCounter < numOfVoters ) //loop used to ask user for their candidate choices, repeating as many times as equal to the numOfVoters variable
	{
		cout << "Rank 1: "; //prompts user to enter first candidate choice
		cin >> candidateChoice1 ; //temporarily stores input for the users first choice
		transform( candidateChoice1.begin(), candidateChoice1.end(), candidateChoice1.begin(), ::tolower ); //makes user input all lowercase
		
		cout << "Rank 2: "; //prompts user to enter second candidate choice
		cin >> candidateChoice2 [ arraySetValue ]; //stores each input for the second candidate choice in a separate cell to be used in an if statement below in the event of a run-off election
		transform( candidateChoice2[ arraySetValue ].begin(), candidateChoice2[ arraySetValue ].end(), candidateChoice2[ arraySetValue ].begin(), ::tolower ); //makes user input all lowercase
		
		cout << "Rank 3: "; //prompts user to enter third candidate choice
		cin >> candidateChoice3 [ arraySetValue ]; //prompts user to enter third candidate choice
		transform( candidateChoice3[ arraySetValue].begin(), candidateChoice3[ arraySetValue ].end(), candidateChoice3[ arraySetValue ].begin(), ::tolower ); //makes user input all lowercase
		cout << "\n";
		
		if ( candidateChoice1 == "alice" ) //first condition checks if the users first choice was 'Alice'
		{
			aliceVotes++; //adds 1 to aliceVotes if above is true
		}
		else if ( candidateChoice1 == "bob" ) //second condition checks if the users first choice was 'Bob'
		{
			bobVotes++; //adds 1 to bobVotes if above is true
		}
		else if( candidateChoice1 == "charlie" ) //third condition checks if the users first choice was 'Charlie'
		{
			charlieVotes++; //adds 1 to charlieVotes if above is true
		}
		
		loopCounter++; //adds 1 to the counter so the loop will only go on until loopCounter equals numOfVoters
		arraySetValue++; //adds 1 to the array variable so it changes to the next cell
						 //loop resets here if loopCounter is still less than numOfVoters
		
	} //end of first while loop
	
	loopCounter = 0; //resets the counter variable so it can be used again in the while loop below
	arraySetValue = 0; //resets array variable so it can be used in the arrays where it is named below
	
	if ( max( {aliceVotes, bobVotes, charlieVotes} ) == aliceVotes && aliceVotes > numOfVoters / 2 ) //checks if aliceVotes has a majority over the other variables
	{
		cout << "Alice Wins!"; //displays "Alice Wins!" if the above is true
	}
	else if ( max( {aliceVotes, bobVotes, charlieVotes} ) == bobVotes && bobVotes > numOfVoters / 2 ) //checks if bobVotes has a majority over the other variables
	{
		cout << "Bob wins!"; //displays "Bob Wins!" if the above is true
	}
	else if ( max( {aliceVotes, bobVotes, charlieVotes} ) == charlieVotes && charlieVotes > numOfVoters / 2 ) //checks if charlieVotes has a majority over the other variables
	{
		cout << "Charlie Wins!"; //displays "Charlie Wins!" if the above is true
	}
	else if ( aliceVotes == bobVotes || aliceVotes == charlieVotes || charlieVotes == bobVotes ) //if none of the candidates have a majority, the while loop below will
																							    //run to determine a winner using the user's second choices
	{
		while ( loopCounter < numOfVoters ) //similar loop to the one above except this one uses the second choice candidate
		{									//to add votes, and doesn't need any user input
			if ( candidateChoice2 [ arraySetValue ] == "alice" ) //checks if the users second choice was 'Alice'
			{
				aliceVotes++; //adds 1 to aliceVotes if above is true
			}
			else if ( candidateChoice2 [ arraySetValue ] == "bob" ) //checks if the users second choice was 'Bob'
			{
				bobVotes++; //adds 1 to bobVotes if above is true
			}
			else if ( candidateChoice2 [ arraySetValue ] == "charlie" ) //checks if the users second choice was 'Charlie'
			{
				charlieVotes++; //adds 1 to charlieVotes if above is true
			}
			loopCounter++; //adds 1 to the counter so the loop will only go on until loopCounter equals numOfVoters
			arraySetValue++; //adds 1 to the array variable so it changes to the next cell
						     //loop resets here if loopCounter is still less than numOfVoters
		}
		
		if ( max( {aliceVotes, bobVotes, charlieVotes} ) == aliceVotes && aliceVotes > numOfVoters / 2 ) //checks if aliceVotes now has a majority over the other variables
		{
			cout << "Alice Wins!"; //displays "Alice Wins!" if the above is true
		}
		else if ( max( {aliceVotes, bobVotes, charlieVotes} ) == bobVotes && bobVotes > numOfVoters / 2 ) //checks if bobVotes now has a majority over the other variables
		{
			cout << "Bob wins!"; //displays "Bob Wins!" if the above is true
		}
		else if ( max( {aliceVotes, bobVotes, charlieVotes} ) == charlieVotes && charlieVotes > numOfVoters / 2 ) //checks if charlieVotes now has a majority over the other variables
		{
			cout << "Charlie Wins!"; //displays "Charlie Wins!" if the above is true
		}
	} //end of else if used if none of candidates initally have a majority
} //end of voteWinnerCalc()

//output

/* Please enter the amount of voters: 5
Please enter your candidate choices by rank
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Bob
Rank 3: Alice

Alice Wins! */
