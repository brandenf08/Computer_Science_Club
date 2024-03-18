#include <iostream> //for input/output operations
#include <algorithm> //for sorting operations
#include <vector> //allows use of vectors
#include <limits> //for cin.ignore operations
#include <cmath>  //for complex math operations

using namespace std; //places std in the global namespace


//forward declarations for functions further down
vector<int> vectorEntry(); //prompts user for integers, and stores them in a vector
int targetSum(); //prompts user for their target number and stores it in an integer
vector<int> vectorSortAndElim(int, vector<int>); //sorts the user's vector and eliminates values higher than the target number
void possibilities(); //runs each further function in a loop until every possibility of numbers has been checks
void binarySet(int); //associates a binary value to each element which will tell the element checker function to only use certain elements
void elementChecker(vector<int>); //adds elements together if they are associated with the binary value of one from the above function
void sumChecker(int, vector<int>); //prints each subset of numbers that add up to the target number

vector<int> userVector = vectorEntry(); //stores the user's vector as a global variable so it can be used by the functions below
int userTargetSum = targetSum(); //stores the user's target number as a global variable
vector<int> sortedVector = vectorSortAndElim(userTargetSum, userVector); //stores the sorted vector into a global variable

int main() //main method
{ 
	possibilities(); //calls the possibilities function which starts the chain of functions that will find the subset of numbers
}

vector<int> vectorEntry() //prompts user for integers, and stores them in a vector
{	
	vector<int> userVector; //vector that will store the users vector of values
	int input; //used as the input argument for the vector
	
	cout << "Enter your integers when prompted.\nOnce integer has been input, press enter to continue."
	<< "\nAfter all integers have been entered, press enter without entering any value when prompted for next integer."
	<< "\nEnter Integer " << userVector.size() + 1 << ": ";
	
	while(cin >> noskipws >> input) //will run as long as the user enters a valid input
	{	
		userVector.push_back(input); //stores each value into a cell in the vector, which index changes as the loop progresses
		cout << "Enter integer " << userVector.size() + 1 << ": "; //prompts user for their next integer
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes newline from the input buffer
		cin.clear(); //clears any errors in the input buffer
	}
	
	return userVector; //returns the vector of values that the user input
} //end of the vectorEntry function
		
int targetSum()  //prompts user for their target number and stores it in an integer
{          
	int targetSum; //integer variable that will store the users target number                                    
	cin.clear(); //clears any errors in the input vector
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes newline from the input buffer
	
	cout << "\nNo value detected\nEnter your target sum: "; //prints when user presses enter without any value, and prompts them to enter their target number
	cin >> noskipws >> targetSum; //takes input as long as the user enters a valid value
	cout << "Subset(s): "; //prints the subsets if they exist after the functions have been run
	
	return targetSum; //returns the users target sum
} //end of the target sum function

vector<int> vectorSortAndElim(int targetSum, vector<int> userVector) //sorts the user's vector and eliminates values higher than the target number
{
	sort(userVector.begin(), userVector.end()); //sorts the vector in ascending order
	
	int index = 0;
	
	while(index < userVector.size()) //while loop that checks if the value in the vector element is higher than the target number
	{
		if(userVector[index] > targetSum)
		{
			userVector.erase(userVector.begin() + index); //deletes value if it is higher than target number
			index--; //moves to index before which will be the next value as the previous cell was deleted
		}
		index++; 
	}
	
	return userVector; //returns the sorted vector
} //end of the sortAndElim function

void possibilities() //runs each further function in a loop until every possibility of numbers has been checks
{
    int numOfPossibilities = pow(2, sortedVector.size()), index = 1; //calculates the total amount of value combinations possible
    while(index < numOfPossibilities) //the loop will run until all possible combinations have been checked
	{
		binarySet(index); //runs the next functions until all combinations have been tested
        index++; //progressed to next possible value in the permutation
    }
    
} //end of the possibilities function

void binarySet(int possibilityIndex) //associates a binary value to each element which will tell the element checker function to only use certain elements
{
	vector<int> binaryVector; //associates a binary value with the users value that will determine if that number is tested in the combinations
	int vectorIndex = sortedVector.size() - 1; //stores the last index value
	
	while(possibilityIndex > 0) //loop that will associate the binary value with the user's value
	{
		binaryVector.push_back(possibilityIndex % 2); //the remainder will either be a one or a zero, creating the binary value
		possibilityIndex = possibilityIndex / 2; //lowers the value closer to zero
		vectorIndex--; //moves the the next value in the vector
	}
	
	elementChecker(binaryVector); //calls the elementChecker function, passing the vector of associated binary values to it
} //end of the binarySet function

void elementChecker(vector<int> binaryVector) //adds elements together if they are associated with the binary value of one from the above function
{	
	int sum = 0, index = 0; //sum will hold the sum of the numbers and index will check the cell of that element
	
	while(index < userVector.size()) //loop that adds values together to be checked by the sumChecker function, which comes next
	{
		if (binaryVector[index] == 1) //if the binary value calculated above equals one
		{
            sum += userVector[index]; //then the associated value will be added to the sum variable
		}
		index++; //moves to the next value
	}
	sumChecker(sum, binaryVector); //calls the sumChecker function, passing the sum and the binaryVector to it
} //end of the elementChecker function

void sumChecker(int sum, vector<int> binaryVector) //prints each subset of numbers that add up to the target number
{
	if (sum == userTargetSum) //if the values added in the sumChecker function add up to the target number, print out those values
	{ 
		int index = 0; 
        cout << "["; //begins the brackets containing the subset of numbers
        while(index < userVector.size()) //while the index is smaller than the size of the vector
		{
            if (binaryVector[index] == 1) //if the element selected has an associated binary value of one
			{
                cout << userVector[index]; //print out that value
                if (index != userVector.size() - 1)  //if the index isn't on the final value
				{
                    cout << ", "; //print out a comma to separate the next coming value from the last one
                }
            }
            index++; //move onto the next value in the vector
        }
        cout << "], "; //closes the bracket for the subset of numbers, with a comma in case another subset exists
    }
} //end of the sumChecker function

//Output//
/*
Enter your integers when prompted.
Once integer has been input, press enter to continue.
After all integers have been entered, press enter without entering any value when prompted for next integer.
Enter Integer 1: 2
Enter integer 2: 0
Enter integer 3: 3
Enter integer 4: 11
Enter integer 5: 17
Enter integer 6: 5
Enter integer 7: 10
Enter integer 8:

No value detected
Enter your target sum: 21
Subset(s): [2, 3, 11, 5, ], [2, 0, 3, 11, 5, ], [11, 10], [0, 11, 10],
--------------------------------
Process exited after 33.88 seconds with return value 0
Press any key to continue . . .
*/

