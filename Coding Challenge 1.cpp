//Branden Farano
//This program will take a users text input, and tell them the appropriate grade level for reading the text
//by using the Coleman-Liau index calculation

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int word_count( string w ); //forward declaration for word count function

int main()
{
	float i = 0, sentences = 0, letters = 0, S, L;//i is a counter
	string text; //varaible holding user input
	
	cout << "Enter your text to reveal its recommended grade level: ";
	getline( cin, text);
	int length_of_sentence = text.size();
	
	while( i < length_of_sentence) //loop and if statement will find amount of sentences in the users input by checking special character parameters
	{
		if( text[ i ] == '.' || text[ i ] == '!' || text[ i ] == '?')
		{
			sentences++;
		} 
		i++;
	}
	
	i = 0;
	
	while( i < length_of_sentence) //loop and if statement will find the amount of letters in the users input by checking special character parameters
	{
		letters++;
		if( text[ i ] == ' ' || text[ i ] == '!' || text[ i ] == '@' || text[ i ] == '#' || text[ i ] == '$' || text[ i ] == '%' || text[ i ] == '^' 
		|| text[ i ] == '&' || text[ i ] == '*' || text[ i ] == '(' || text[ i ] == ')' || text[ i ] == '-' || text[ i ] == '_' || text[ i ] == '='
		|| text[ i ] == '+' || text[ i ] == '[' || text[ i ] == ']' || text[ i ] == '{' || text[ i ] == '}' || text[ i ] == '|'|| text[ i ] == '\\' 
		|| text[ i ] == ';'|| text[ i ] == ':' || text[ i ] == '"' || text[ i ] == '<' || text[ i ] == ',' || text[ i ] == '>'|| text[ i ] == '.' 
		|| text[ i ] == '/' || text[ i ] == '?' || text[ i ] == '\'')
		{
			letters--;
		}
		i++;
	}
	float words =  word_count( text ); //calls the word count function and stores the output in 'words'
	L = letters / words * 100;
	S = sentences / words * 100;
	float total = 0.0588 * L - 0.296 * S - 15.8;
	
	cout << "The recommended grade level for this text is grade " << round( total );
	
}

int word_count( string w ) //function that finds the amount of words in the users input
{
	stringstream str( w );
	
	string ind_Word;
	
	int k = 0;
	
	while( str >> ind_Word)
	
	k++;
	
	return k;
}