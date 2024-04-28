#include <iostream>     //allows for input/output stream
#include <string>       //string operations
#include <vector>       //vector container
#include <map>          //map container
#include <sstream>      //string stream operations
#include <cctype>       //character handling functions
#include <algorithm>    //algorithm operations
#include <unordered_map> //for unordered_map

using namespace std; //places std in the namespace

// Forward declarations
int getValidNumberInput(const string& prompt, int minValue, int maxValue); //forward declaration for getting a valid integer input
string getValidLetterInput(const string& prompt, int length); //forward declaration for getting a valid string input containing only letters
vector<vector<char>> createGrid(int rows, int cols); //forward declaration for creating the grid of letters
string getValidWordInput(const string& prompt); //forward declaration for getting a valid word input containing only letters
map<char, int> countLetters(const string& word); //forward declaration for counting the occurrences of each letter in a word
bool depth(const string& word, vector<vector<char>>& grid, int row, int col, int idx); //depth-first search function declaration
bool canFormWord(const string& word, vector<vector<char>>& grid); //function declaration for checking if the word can be formed from the letters in the grid

int main() //beginning of main
{
    //gets the number of rows and columns for the grid
    int rows = getValidNumberInput("Enter the number of rows (1-1000): ", 1, 1000); //used to hold the amount of rows that will be used
    int cols = getValidNumberInput("Enter the number of columns (1-1000): ", 1, 1000); //used to hold the amount of columns there will be

    //create the grid
    vector<vector<char>> grid = createGrid(rows, cols); //function call for createGrid function used to hold the values entered by the user
    //get the word to search for
    string word = getValidWordInput("Enter a word (1-1000 letters): "); //gets the word input from the user

    //check if the word can be formed from the letters in the grid
    if (canFormWord(word, grid)) //if true
	{
        cout << "The word can be formed from the letters in the grid." << endl; //the word can be formed
    } 
	else //else if false
	{
        cout << "The word cannot be formed from the letters in the grid." << endl; //the word cannot be formed
    }

    return 0; //ends program
} //end of main

//function to get a valid integer input within a specified range
int getValidNumberInput(const string& prompt, int minValue, int maxValue) 
{
    string input; //variable to store user input
    int value;    //variable to store converted integer value
    do //do prompt before checking condition
	{
        cout << prompt; //display prompt to the user
        getline(cin, input); //get user input
        stringstream(input) >> value; //convert user input to integer
        //check if the input is valid
        if (!input.empty() && all_of(input.begin(), input.end(), ::isdigit) && value >= minValue && value <= maxValue) //if input is invalid
		{
            return value; //return the valid input
        }
        cout << "Invalid input. Please enter a valid number between " << minValue << " and " << maxValue << "." << endl; //prompts the user to enter correct values, stating proper parameters
        //display error message for invalid input
    } 
	while (true); //repeat until valid input is obtained
} //end of getValidNumberInput function

//function to get a valid string input containing only letters of a specified length
string getValidLetterInput(const string& prompt, int length) 
{
    string input; //variable to store user input
    do //doprompt before checking condition
	{
        cout << prompt; //display prompt to the user
        getline(cin, input); //get user input
        //check if the input is valid
        if (!input.empty() && input.size() == length && all_of(input.begin(), input.end(), ::isalpha)) //if input is invalid
		{
            return input; //return the valid input
        }
        if (input.empty()) //if input is empty
		{
            cout << "Input cannot be empty. Please enter exactly " << length << " letters." << endl;  //display error message for empty input
        } 
		else 
		{
			if (input.size() != length) //if input is larger than parameters
			{
            cout << "Input must contain exactly " << length << " letters. Please try again." << endl; //display error message for invalid length
        	} 
			else //if user enters an invalid character
			{
            cout << "Input must contain only letters. Please try again." << endl; //display error message for invalid characters
        	}
    	}
	}
	while (true); //repeat until valid input is obtained
} //end of getValidLetterInput function

//function to create the grid of letters
vector<vector<char>> createGrid(int rows, int cols) 
{
    vector<vector<char>> grid(rows, vector<char>(cols)); //create a 2D vector grid
    for (int i = 0; i < rows; i++) 
	{
        string rowInput = getValidLetterInput("Enter letters for row " + to_string(i + 1) + " (exactly " + to_string(cols) + " letters): ", cols); //get valid letter input for each row
        for (int j = 0; j < cols; j++) //convert letters to uppercase and assign them to the grid
		{
            grid[i][j] = rowInput[j]; //assign each letter to the corresponding cell in the grid
        }
    }
    return grid; //return the created grid
} //end of createGrid function

//function to get a valid word input containing only letters
string getValidWordInput(const string& prompt) 
{
    string word; //variable to store user input
    do //prompt before checking condition
	{
        cout << prompt; //display prompt to the user
        getline(cin, word); //get user input
        if (!word.empty() && all_of(word.begin(), word.end(), ::isalpha)) //if input is invalid
		{
            return word; //return the valid input
        }
        cout << "Input cannot be empty and must contain only letters. Please try again." << endl; //display error message for invalid input
    } 
	while (true); //repeat until valid input is obtained
} //end of getValidWordInput function

//function to count the occurrences of each letter in a word
map<char, int> countLetters(const string& word) 
{
    map<char, int> letterCounts; //map to store letter counts
    for (char letter : word) //as long as there are letters to check against the word
	{
        if (isalpha(letter)) //check if the character is a letter
		{ 
            letterCounts[toupper(letter)]++; //convert to uppercase and count the occurrences
        }
    }
    return letterCounts; //return the map of letter counts
} //end of countLetters function

bool depth(const string& word, vector<vector<char>>& grid, int row, int col, int idx) 
{
    // base case: all letters in the word are found
    if (idx == word.length()) 
	{
        return true; //the word can be found
    }
    //check if the current cell is out of bounds or contains a mismatched letter
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != word[idx]) 
	{
        return false; //the word could not be found
    }
    char original = grid[row][col]; //store the original letter in the current cell
    grid[row][col] = '#'; //mark the cell as visited
    //recursively search for the remaining letters in all eight directions (up, down, left, right, and diagonally)
    bool found = depth(word, grid, row + 1, col, idx + 1) || depth(word, grid, row - 1, col, idx + 1) ||
                 depth(word, grid, row, col + 1, idx + 1) || depth(word, grid, row, col - 1, idx + 1) ||
                 depth(word, grid, row + 1, col + 1, idx + 1) || depth(word, grid, row - 1, col - 1, idx + 1) ||
                 depth(word, grid, row + 1, col - 1, idx + 1) || depth(word, grid, row - 1, col + 1, idx + 1);
    grid[row][col] = original; //restore the cell's original letter
    return found; //return true if the word is found starting from this cell
} //

//function to check if the word can be formed from the letters in the grid
bool canFormWord(const string& word, vector<vector<char>>& grid) 
{
    unordered_map<char, int> wordCount; //count occurrences of letters in the word
    for (char letter : word) 
	{
        wordCount[letter]++; //increment the count for each letter in the word
    }

    //count occurrences of letters in the grid
    unordered_map<char, int> gridCount;
    for (const auto& row : grid) 
	{
        for (char letter : row) 
		{
            gridCount[letter]++; //increment the count for each letter in the grid
        }
    }

    //check if each letter in the word occurs at least as many times in the grid as in the word
    for (const auto& pair : wordCount) 
	{
        char letter = pair.first; //get the letter from the word count
        int count = pair.second; //get the count of the letter in the word
        if (gridCount[letter] < count) 
		{
            return false; //if any letter occurs fewer times in the grid, return false
        }
    }

    return true; //if all letters occur at least as many times in the grid, return true
} //end of canFormWord function

/* Showing all input validation
Enter the number of rows (1-1000):
Invalid input. Please enter a valid number between 1 and 1000.
Enter the number of rows (1-1000): w
Invalid input. Please enter a valid number between 1 and 1000.
Enter the number of rows (1-1000): 1001
Invalid input. Please enter a valid number between 1 and 1000.
Enter the number of rows (1-1000): 4
Enter the number of columns (1-1000):
Invalid input. Please enter a valid number between 1 and 1000.
Enter the number of columns (1-1000): w
Invalid input. Please enter a valid number between 1 and 1000.
Enter the number of columns (1-1000): 1001
Invalid input. Please enter a valid number between 1 and 1000.
Enter the number of columns (1-1000): 4
Enter letters for row 1 (exactly 4 letters):
Input cannot be empty. Please enter exactly 4 letters.
Enter letters for row 1 (exactly 4 letters): 2
Input must contain exactly 4 letters. Please try again.
Enter letters for row 1 (exactly 4 letters): eeeee
Input must contain exactly 4 letters. Please try again.
Enter letters for row 1 (exactly 4 letters): cttt
Enter letters for row 2 (exactly 4 letters): rott
Enter letters for row 3 (exactly 4 letters): wwdt
Enter letters for row 4 (exactly 4 letters): wwwe
Enter a word (1-1000 letters):
Input cannot be empty and must contain only letters. Please try again.
Enter a word (1-1000 letters): 3
Input cannot be empty and must contain only letters. Please try again.
Enter a word (1-1000 letters): code
The word can be formed from the letters in the grid.

--------------------------------
Process exited after 134.4 seconds with return value 0
Press any key to continue . . .

Running with correct inputs
Enter the number of rows (1-1000): 4
Enter the number of columns (1-1000): 4
Enter letters for row 1 (exactly 4 letters): ciio
Enter letters for row 2 (exactly 4 letters): tttt
Enter letters for row 3 (exactly 4 letters): tttt
Enter letters for row 4 (exactly 4 letters): dtte
Enter a word (1-1000 letters): code
The word can be formed from the letters in the grid.

--------------------------------
Process exited after 21.26 seconds with return value 0
Press any key to continue . . .
*/