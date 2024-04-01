#include <iostream> //allows for input output operations
#include <string> //allows for string manipulations
#include <regex> //allows use of regular expressions 'regex' keywords
#include <ctime> //allows use of time manipulation features in the 'ctime' library
#include <sstream> //allows for stringstream operations
#include <iomanip> //allows for input/output manipulation

using namespace std; //places std in the namespace

bool isValidDate(string& dateStr); //forward declaration for the 'isValidDate' function that takes a reference to a string as an argument and checks if the date entered is in the proper initial format
string convertToYYYYMMDD(string& dateStr); //forward declaration for the 'convertToYYYYMMDD' function that takes a reference to a string as an argument and will convert the users date to the desired format

int main() //beginning of main
{
    string dateInput; //variable that will take the users date input and store it as a string in 'dateInput'
    while(true) //starts an infinite loop that prompts the user to enter the proper date format, which will then print the converted code and end the loop
	{
        cout << "Enter a date in MM/DD/YYYY format (example: 5/19/2002) or in the format (example: May 19, 2002): "; //prompts the user to enter their date in either format (p.s. example is my birthday!)
        getline(cin, dateInput); //calls the getline function and stores the users input into 'dateInput' using the cin stream
        if (!dateInput.empty() && isValidDate(dateInput)) //if 'dateInput' is not empty and the date entered is in the valid format
		{
            string yyyy_mm_dd_date = convertToYYYYMMDD(dateInput); //create a string variable 'yyyy_mm_dd_date' that hold the converted date given by the called 'convertToYYYYMMDD' function
            if (!yyyy_mm_dd_date.empty()) //if 'yyyy_mm_dd_date' is not empty
			{
                cout << "Converted date: " << yyyy_mm_dd_date << "\n"; //print the converted date for the user
                break; //exits the loop, ending the program
            } 
			else //else if 'yyyy_mm_date is empty', meaning the user didn't enter anything, prompt the user to enter their input again
			{
                cout << "Invalid date format. Please enter a valid date." << "\n";
            }
        } 
		else //if the date the user entered is invalid, have them enter it again until it's in the proper format
		{
            cout << "Invalid date format. Please enter a valid date." << "\n";
        }
    } //end of initial while loop
} //end of main

bool isValidDate(string& dateStr) //'isValidDate' function that takes a reference to a string as an argument and checks if the date entered is in the proper initial format and returns true or false
{
    tm time = {}; //creates a tm structure called 'time' that contains all zeros
    regex monthDayYearRegex("\\d{1,2}/\\d{1,2}/\\d{4}"); //declares a regular expression pattern to match the format MM/DD/YYYY
    regex monthDayYearNameRegex("\\w+ \\d{1,2}, \\d{4}"); //declares a regular expression pattern to match the format Month Name DD, YYYY.
    string monthName; //variable that will hold the month entered if entered as a word instead of a number

    if (regex_match(dateStr, monthDayYearRegex)) //if the date entered matches the regular expression pattern format using only numbers
	{
        istringstream ss(dateStr); //creates a stringstream object that will be able to parse the values from the date entered by the user
        char delim; //char variable that will be used to store the delimiters '/' or ',' (used to separate the values in the date) while the program parses the rest of the data without the delimiters
        ss >> time.tm_mon >> delim >> time.tm_mday >> delim >> time.tm_year; //separates the date into its individual parts using the stringstream extraction operation
        return (true); //returns true if initial date is valid
    } 
	else 
		{
			if (regex_match(dateStr, monthDayYearNameRegex)) //else if the date entered matches the regular expression pattern format using the string version of the month
			{
        		istringstream ss(dateStr); //creates a stringstream object that will be able to parse the values from the date entered by the user
        		char delim; //char variable that will be used to store the delimiters '/' or ',' (used to separate the values in the date) while the program parses the rest of the data without the delimiters
        		ss >> monthName >> time.tm_mday >> delim >> time.tm_year; //separates the date into its individual parts using the stringstream extraction operation
        	}
        	transform(monthName.begin(), monthName.end(), monthName.begin(), ::tolower); //converts entire 'monthName' string to lower case using the transform function
        	static const string months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"}; 
        	//creates a static constant array that holds the lowercase version of the month names that will be compared against 'monthName'
        	
        	auto monthMatch = find(begin(months), end(months), monthName); //auto variable that will store the month if it matches any of the strings in the 'months' array
        	if (monthMatch != end(months)) //if 'monthMatch' does not equal the end reference of the months array (meaning the entered month did not match any of the strings in the array)
			{
            	time.tm_mon = distance(begin(months), monthMatch) + 1; //the months value in the 'time' structure equals the distance between the beginning value (0) and the month value matched + 1,
            													   	  //giving the numeric representation of the entered string month
            	return (true); //returns true if initial date is valid
        	}
    }
    return false; //returns false if the entered date is not valid
} //end of 'isValidDate'

string convertToYYYYMMDD(string& dateStr) //'convertToYYYYMMDD' function that takes a reference to a string as an argument and will convert the users date to the desired format
{ 
    tm time = {}; //creates a tm structure called 'time' that contains all zeros
    if (isValidDate(dateStr)) //calls the isValidDate function
	{
        if (regex_match(dateStr, regex("\\d{1,2}/\\d{1,2}/\\d{4}"))) //if the date entered matches the regular expression pattern format using only numbers
		{
            istringstream ss(dateStr); //creates a stringstream object that will be able to parse the values from the date entered by the user
            char delim; //char variable that will be used to store the delimiters '/' or ',' (used to separate the values in the date) while the program parses the rest of the data without the delimiters
            ss >> time.tm_mon >> delim >> time.tm_mday >> delim >> time.tm_year; //separates the date into its individual parts using the stringstream extraction operation
        } 
		else 
		{
		 	if (regex_match(dateStr, regex("\\w+ \\d{1,2}, \\d{4}"))) //else if the date entered matches the regular expression pattern format using the string version of the month
		 	{
            	istringstream ss(dateStr); //creates a stringstream object that will be able to parse the values from the date entered by the user
            	string monthName; //variable that will hold the month entered if entered as a word instead of a number
            	char delim; //char variable that will be used to store the delimiters '/' or ',' (used to separate the values in the date) while the program parses the rest of the data without the delimiters
            	ss >> monthName >> time.tm_mday >> delim >> time.tm_year; //separates the date into its individual parts using the stringstream extraction operation
            	transform(monthName.begin(), monthName.end(), monthName.begin(), ::tolower); //converts entire 'monthName' string to lower case using the transform function
            	static const string months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
            	//creates a static constant array that holds the lowercase version of the month names that will be compared against 'monthName'
            	auto monthMatch = find(begin(months), end(months), monthName); //auto variable that will store the month if it matches any of the strings in the 'months' array
            	if (monthMatch != end(months)) //if 'monthMatch' does not equal the end reference of the months array (meaning the entered month did not match any of the strings in the array)
			{
                time.tm_mon = distance(begin(months), monthMatch) + 1; //the months value in the 'time' structure equals the distance between the beginning value (0) and the month value matched + 1,
            													   	  //giving the numeric representation of the entered string month
            }
     	 }
        }
        time.tm_year -= 1900; // Adjust year (since time_year is years since 1900)
        ostringstream oss; //creates an output extraction operator 'oss'
        oss << time.tm_year + 1900 << '-' << setw(2) << setfill('0') << time.tm_mon << '-' << setw(2) << setfill('0') << time.tm_mday; //formats the values using the extraction operator
        return oss.str(); //returns the extraction operator with the converted date
    }
    return ""; //retruns an empty string if no valid output could be given
} //end of 'convertToYYYYMMDD' function

//output
/*
Enter a date in MM/DD/YYYY format (example: 5/19/2002) or in the format (example: May 19, 2002): May 19, 2002
Converted date: 2002-05-19

--------------------------------
Process exited after 21.79 seconds with return value 0
Press any key to continue . . .
*/
