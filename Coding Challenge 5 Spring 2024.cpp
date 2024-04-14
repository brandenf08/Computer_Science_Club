#include <iostream> //allows for input output operations
#include <cmath> //allows for complex math operation functions to be used

using namespace std; //places std in the namespace

int josephusCalc(int, int, int); //forward declaration for the 'josephusCalc' function taking in 3 integers as arguments

int main() //beginning of main
{
	int startNum, numOfPeople, elimInterval; //starting index, total number of people in the circle, elimination interval
	
	cout << "Enter your values- \nNumber of People: "; //prompts the user to enter the amount of people in the circle
	cin >> numOfPeople;
	
	cout << "Elimination Interval: "; //prompts the user to enter the elimination interval
	cin >> elimInterval;
	
	cout << "Starting Index: "; //prompts the user for the starting positions
	cin >> startNum;

	cout << "He/She who won the lottery is lucky person " << abs(josephusCalc(numOfPeople, elimInterval, startNum)); 
	//prints the lucky survivor using the absolute value of the 'josephusCalc' function as the result is sometimes negative despite being the correct person
	
	return 0;
} //end of main

int josephusCalc(int num, int elim, int start) //recursive function that will calculate the josephus problem
{
	if(num == 1) //if num = 1 i.e. if the final survivor has been found
	{
		return start; //return the position of the survivor when it has been found
	}
	else
	{
		return (josephusCalc(num - 1, elim, start) + elim - start) % num + 1;
		//continually recursively breaks down the circle into smaller versions of itself by continually calling the function it is in
		//finding who survives in each circle until there is only one person left
	}
} //end of 'josephusCalc' function



