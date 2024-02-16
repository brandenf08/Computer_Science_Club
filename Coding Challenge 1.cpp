//Branden Farano
//This program will take a user's text input, and tell them the appropriate reading level for the text
//by using the Coleman-Liau index calculation

#include <iostream> //allows for input/output operations
#include <sstream> //allows for stings to be turned into stream objects
#include <string> //allows for extraction operations on string variables
#include <cmath> //allows for complex math operations
#include <cctype> //allows for isalpha function

using namespace std; //puts std in the global namespace library

int word_count( string w ); //forward declaration for word count function

int main()
{
	float i = 0, sentences = 0, letters = 0, avSentences, avLetters;//'i' is the counter variable, 'sentences' tracks the amount of sentences in the entered text
	string text; //varaible holding user input
	
	cout << "Enter your text to reveal its recommended grade level: ";
	getline( cin, text); //grabs user input and stores it in the 'text' variable
	int length_of_sentence = text.size(); //finds the length of the text entered by the user
	
	while( i < length_of_sentence) //loop and if statement will find the amount of sentences in the user's input by checking special character parameters
	{
		if( text[ i ] == '.' || text[ i ] == '!' || text[ i ] == '?') //finds amount of sentences by moving loop forward if one of the listed characters are found
		{															  //and moves forward until next end of sentence charcter is found
			sentences++; //when the end of sentence character is found, add 1 to the sentence variable
		} 
		i++; //moves the loop counter forward
	}
	
	i = 0; //resets counter variable

	while( i < length_of_sentence) //loop used to find amount of letters in the users entered text
		{
			letters++; //adds 1 to the 'letters' variable regardless of the character parsed
			
			if( isalpha(text[i]) == false ) //checks if the selected character is a letter
			{
				letters--; //subtracts 1 from 'letters' if the character isn't a letter
			}
			
			i++; //moves the counter forward
		}
	
	float words =  word_count( text ); //calls the word count function and stores the output in 'words'
	avLetters = letters / words * 100; //finds the average amount of letters in the text
	avSentences = sentences / words * 100; //finds the average amount of sentences in the text
	float total = 0.0588 * avLetters - 0.296 * avSentences - 15.8; //calculates the recommended reading level based on the Coleman-Liau index calculation
	
	cout << "The recommended grade level for this text is grade " << round( total ); //displays the recommended reading level
	
}

int word_count( string w ) //function that finds the amount of words in the users input
{
	stringstream str( w ); //creates a stringstream object called 'str' that holds the users text
	
	string ind_Word; //index variable
	
	int k = 0; //holds word count
	
	while( str >> ind_Word) //compares the stringstream object 'str' to the index of the text
	
	k++; //adds one to the amount of words if the stringstream object is greater than the index of the text
	
	return k; //returns word count
}

/* Enter your text to reveal its recommended grade level: Congratulations! Today is your day. You're off to Great Places! You're off and away!
The recommended grade level for this text is grade 3 */
