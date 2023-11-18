//Branden Farano
//Computer Science Club
//Coding Challenge 3
//11/17/23

//This program will allow for a user to simulate a ranked choice ballot. The program will start by asking the user for the candidates being used, followed by the amount
//of voters, followed by asking for each voters top 3 candidate choices

#include <iostream> //required for input and output in a program
#include <algorithm> //allows the use of the max() function, which returns the highest value input into it, and the transform function, which turns a string into all lowercase or all uppercase depending on parameters

using namespace std; //allows you to not have to use std:: before several statements

void voteWinnerCalc(); //forward declaration of the voteWinnerCalc() function

int main() //main function; required for program to run
{
	voteWinnerCalc(); //call for the voteWinnerCalc function
} //end of main function

void voteWinnerCalc() //function that simulates a ranked choice ballot. The function will start by asking the user for the candidates being used, followed by the amount
//of voters. The function will then use the amount of voters as a limit in the while loop, asking the user for votes until that limit is reached. It will then test the input against several if statements,
//and print out the winner of the ballot
{
	int numOfVoters, loopCounter = 0, candidate1Votes = 0, candidate2Votes = 0, candidate3Votes = 0, arraySetValue = 0; //numOfVoters is the variable used when asking the user for the number of voters
	string candidate1, candidate2, candidate3;																			//loopCounter is the variable that will act as the counter for the while loop
																														//candidateVotes1, candidateVotes2, candidateVotes3 are the variables that will hold the candiates votes
	cout << "Please enter your 3 candidates\n";	//ask user to enter their 3 candidates									//arraySetValue is the variable that will change which cell is in use in the candidateChoice variables
	cout << "Candidate 1: ";					//lines 29, 31, and 33 prompt the user to enter their candidate			//candidate1, candidate2, candidate3 are the variables used when asking the user which candidate they want to use in the vote
	cin >> candidate1;							//lines 30, 32, and 34 get the users input
	cout << "Candidate 2: ";
	cin >> candidate2;
	cout << "Candidate 3: ";
	cin >> candidate3;
	
	transform( candidate1.begin(), candidate1.end(), candidate1.begin(), ::tolower ); //next 3 lines changes the users candidate input into entirely lowercase. Will help lower the amount of conditions when checking in the below if statements
	transform( candidate2.begin(), candidate2.end(), candidate2.begin(), ::tolower );
	transform( candidate3.begin(), candidate3.end(), candidate3.begin(), ::tolower );
	
	cout << "Please enter the amount of voters: "; //asks user to enter the amount of voters
	cin >> numOfVoters;							   //gets users input for number of users
	
	cout << "Please enter your candidate choices by rank\n"; //prompts user to enter their candidate choices
	
	string candidateChoice1, candidateChoice2 [ numOfVoters ], candidateChoice3; //variables used to create several variables to hold the user's candidate choices
	
	while ( loopCounter < numOfVoters ) //loop used to ask user for their candidate choices, repeating as many times as equal to the numOfVoters variable
	{
		cout << "Rank 1: "; //prompts user to enter first candidate choice
		cin >> candidateChoice1; //temporarily stores input for the users first choice
		transform( candidateChoice1.begin(), candidateChoice1.end(), candidateChoice1.begin(), ::tolower ); //makes user input all lowercase
		
		cout << "Rank 2: "; //prompts user to enter second candidate choice
		cin >> candidateChoice2 [ arraySetValue ]; //stores each input for the second candidate choice in a separate cell to be used in an if statement below in the event of a run-off election
		transform( candidateChoice2[ arraySetValue ].begin(), candidateChoice2[ arraySetValue ].end(), candidateChoice2[ arraySetValue ].begin(), ::tolower ); //makes user input all lowercase
		
		cout << "Rank 3: "; //prompts user to enter third candidate choice
		cin >> candidateChoice3; //temporarily stores user input for the users third choice
		transform( candidateChoice3.begin(), candidateChoice3.end(), candidateChoice3.begin(), ::tolower ); //makes user input all lowercse
		cout << "\n";
		
		if ( candidateChoice1 == candidate1 ) //first condition checks if the users first choice was the first candidate entered above
		{
			candidate1Votes++; //adds 1 to candidate1Votes if above is true
		}
		else if ( candidateChoice1 == candidate2 ) //second condition checks if the users first choice was the second candidate entered above
		{
			candidate2Votes++;  //adds 1 to candidate2Votes if above is true
		}
		else if( candidateChoice1 == candidate3 ) ////third condition checks if the users first choice was the third candidate entered above
		{
			candidate3Votes++;  //adds 1 to candidate3Votes if above is true
		}
		
		loopCounter++; //adds 1 to the counter so the loop will only go on until loopCounter equals numOfVoters
		arraySetValue++; //adds 1 to the array variable so it changes to the next cell
						//loop resets here if loopCounter is still less than numOfVoters
		
	} //end of first while loop
	
	loopCounter = 0; //resets the counter variable so it can be used again in the while loop below
	arraySetValue = 0; //resets array variable so it can be used in the arrays where it is named below
	
	if ( max( {candidate1Votes, candidate2Votes, candidate3Votes} ) == candidate1Votes && candidate1Votes > numOfVoters / 2 ) //checks if candidate1Votes has a majority over the other variables
	{
		candidate1[ 0 ] = toupper( candidate1[ 0 ] ); //capitalizes the first char that was lowercased earlier for better presentation
		cout << candidate1 << " Wins!"; //displays the name of candidate1 followed by " Wins!" if the above is true
	}
	else if ( max( {candidate1Votes, candidate2Votes, candidate3Votes} ) == candidate2Votes && candidate2Votes > numOfVoters / 2 ) //checks if candidate2Votes has a majority over the other variables
	{
		candidate2[ 0 ] = toupper( candidate2[ 0 ] ); //capitalizes the first char that was lowercased earlier for better presentation
		cout << candidate2 << " Wins!"; //displays the name of candidate2 followed by " Wins!" if the above is true
	}
	else if ( max( {candidate1Votes, candidate2Votes, candidate3Votes} ) == candidate3Votes && candidate3Votes > numOfVoters / 2 ) //checks if candidate3Votes has a majority over the other variables
	{
		candidate3[ 0 ] = toupper( candidate3[ 0 ] ); //capitalizes the first char that was lowercased earlier for better presentation
		cout << candidate3 << " Wins!"; //displays the name of candidate3 followed by " Wins!" if the above is true
	}
	else if ( candidate1Votes == candidate2Votes || candidate1Votes == candidate3Votes || candidate3Votes == candidate2Votes ) //if none of the candidates have a majority, the while loop below will
	{																														  //run to determine a winner using the user's second choices
		while ( loopCounter < numOfVoters ) //similar loop to the one above except this one uses the second choice candidate
		{								    //to add votes, and doesn't need any user input
			if ( candidateChoice2 [ arraySetValue ] == candidate1 ) //checks if the first candidate entered above was the users second choice
			{
				candidate1Votes++; //adds 1 to candidate1Votes if the above is true
			}
			else if ( candidateChoice2 [ arraySetValue ] == candidate2 ) //checks if the second candidate entered above was the users second choice
			{
				candidate2Votes++; //adds 1 to candidate2Votes if the above is true
			}
			else if ( candidateChoice2 [ arraySetValue ] == candidate3 ) //checks if the third candidate entered above was the users second choice
			{
				candidate3Votes++; //adds 1 to candidate3Votes if the above is true
			}
			loopCounter++; //adds 1 to the counter so the loop will only go on until loopCounter equals numOfVoters
			arraySetValue++; //adds 1 to the array variable so it changes to the next cell
						     //loop resets here if loopCounter is still less than numOfVoters
		}
		
		if ( max( {candidate1Votes, candidate2Votes, candidate3Votes} ) == candidate1Votes && candidate1Votes > numOfVoters / 2 ) //checks if candidate1Votes has a majority over the other variables
		{
			candidate1[ 0 ] = toupper( candidate1[ 0 ] ); //capitalizes the first char that was lowercased earlier for better presentation
			cout << candidate1 << " Wins!"; //displays the name of candidate1 followed by " Wins!" if the above is true
		}
		else if ( max( {candidate1Votes, candidate2Votes, candidate3Votes} ) == candidate2Votes && candidate2Votes > numOfVoters / 2 ) //checks if candidate2Votes has a majority over the other variables
		{
			candidate2[ 0 ] = toupper( candidate2[ 0 ] ); //capitalizes the first char that was lowercased earlier for better presentation
			cout << candidate2 << " Wins!"; //displays the name of candidate2 followed by " Wins!" if the above is true
		}
		else if ( max( {candidate1Votes, candidate2Votes, candidate3Votes} ) == candidate3Votes && candidate3Votes > numOfVoters / 2 ) //checks if candidate3Votes has a majority over the other variables
		{
			candidate3[ 0 ] = toupper( candidate3[ 0 ] ); //capitalizes the first char that was lowercased earlier for better presentation
			cout << candidate3 << " Wins!"; //displays the name of candidate3 followed by " Wins!" if the above is true
		}
	} //end of else if used if none of candidates initally have a majority
} //end of voteWinnerCalc()

//output

/* Please enter your 3 candidates
Candidate 1: Alice
Candidate 2: Bob
Candidate 3: Charlie
Please enter the amount of voters: 5
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
Rank 2: Alice
Rank 3: Bob

Alice Wins!
--------------------------------
Process exited after 60.06 seconds with return value 0
Press any key to continue . . . */