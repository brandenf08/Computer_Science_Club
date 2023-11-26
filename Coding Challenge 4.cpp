//Branden Farano
//Computer Science Club
//Coding Challenge 4
//11/26/23

//This program will allow a user(agent) to change a string by "encrypting" it using 'Caesar's Cipher'. The process involves asking the "agent" for the message they
//wish to encrypt followed by asking for the "key" (amount of spaces the letters will shift to form the cipher). The program will then print out the
//encrypted message, followed by a prompt asking the "agent" if they wish encrypt again that will ask at the end of every encryption until they type 'N' or 'n',
//or any value that isn't 'Y' or 'y'

#include <iostream> //allows for input output operations
#include <cctype> //allows use of various classification and trasnformation functions. isupper(), islower(), !isalnum, and isdigit are examples
				  //of classification functions used in this program

using namespace std; //averts necessity of using std::

void caesar_cipher(); //forward declaration of the caesar_cipher function found on line 27
void encrypt_again(); //forward declaration of the encrypt_again function found on line 67

int main() //main function
{	
	caesar_cipher(); //function call for the caesar_cipher function
	
	return 0; //ends program successfully
} //end of main function

void caesar_cipher() //function that processes the "encryption" for the "agent"
{
	string plain_text; //string variable used to hold the "agents" message they are encrypting
	int letter_shifter; //integer variable used to hold the "key" that will shift the "agents" message from being plain text to being cipher text
						
	cout <<"Agent, enter your message: "; //prints text asking the "agent" to enter their message
	
	getline( cin, plain_text ); //recieves the "agents" message input and stores it in string variable plain_text
	
	cout << "Enter the key: "; //prints text asking the "agent" to enter their key
	
	cin >> letter_shifter; //recieves the "agents" "key" input and stores it in integer variable letter_shifter
	
	int counter = 0; //integer variable used to stop loop declared and initialized to zero. Variable is also used to change which letter the if statement is checking by moving up one cell per iteration of the loop
	string cipher_text; //string variable used to hold the encrypted text
	
	while( counter < plain_text.size() ) //continues loop as long as the length of the message (all characters including spaces) is greater than the counter variable 
	{																							//'counter' will increase by one for each iteration of the loop
		if( !isalnum( plain_text[ counter ] ) || isdigit( plain_text[ counter ] ) ) //if the 'plain_text' cell is not an 'alphanumeric' character or is a digit
		{
			cipher_text += plain_text[ counter ] ; //adds character to 'cipher_text' variable
			counter++; //and adds 1 to the 'counter' variable, reiterating the loop if possible
		}
		else if( isupper( plain_text[ counter ] ) ) //if the 'plain_text' cell is an upper case letter
		{
			cipher_text += char( int(plain_text[ counter ] + letter_shifter - 65) % 26 + 65 ); 	////converts the 'plain_text' cell to its ascii value and processes caesar's algorithm, "encrypting" the ascii value,
			counter++; //and adds 1 to the 'counter' variable, reiterating the loop if possible	 ////and is then converted into a 'char' based on the changed ascii value and stored in 'cipher_text'
		}
		else //if the 'plain_text' cell is a lowercase letter
		{
			cipher_text += char( int(plain_text[ counter ] + letter_shifter - 97) % 26 + 97 );  ////converts the 'plain_text' cell to its ascii value and processes caesar's algorithm, "encrypting" the ascii value,
			counter++; //and adds 1 to the 'counter' variable, reiterating the loop if possible  ////and is then converted into a 'char' based on the changed ascii value and stored in 'cipher_text'
		}
	} //end of while loop
	
	cout << "Your encrypted message is: " << cipher_text; //prints text stating the "agents" encrypted text
	
	encrypt_again(); //calls encrypt_again function
} //end of caesar_cipher function

void encrypt_again() //will check if "agent" wishes to encrypt again after every encryption, and will run the caesar_cipher function if the "agent" types 'Y' or 'y' 
{					 //and closes the program when they type 'N' or 'n', or a secret third message if they type something else
		char choice; //char variable that will hold the letter the "agent" types in when prompted if they want to encrypt again
		
		cout << "\nDo you want to encrypt again agent? Y/N _\b"; //prints text asking "agent" if they wish to encrypt again
		cin >> choice; //gets "agent" input for the choice variable
		cin.ignore(); //clear newline after using 'cin' so next input functions properly
		
		if ( choice == 'Y' || choice == 'y') //if "agent" chooses to encrypt again
		{
			caesar_cipher(); //calls 'caesar_cipher' function to be used again if "agent" chooses to
		}
		else if ( choice == 'N' || choice == 'n' ) //if "agent" doesn't wish to continue
		{
			cout << "End of transmission\nReturn to base\nComputer will self-destruct in... \n 3\n\n 2\n\n 1\n\n\n\n\nJust kidding\nThis isn't some spy thriller"; //prints ending message
			return; //ends program
		}
		else //if "agent" or "imposter" struggles with a single key press
		{
			cout << "Agent can't follow simple instructions\nAgent is compromised or KIA\nEnd of Transmission"; //prints special message >;)
		}

} //end of encrypt_again block

/* Output:

Agent, enter your message: HELLO
Enter the key: 1
Your encrypted message is: IFMMP
Do you want to encrypt again agent? Y/N Y
Agent, enter your message: hello, world
Enter the key: 13
Your encrypted message is: uryyb, jbeyq
Do you want to encrypt again agent? Y/N Y
Agent, enter your message: be sure to drink your Ovaltine
Enter the key: 13
Your encrypted message is: or fher gb qevax lbhe Binygvar
Do you want to encrypt again agent? Y/N n
End of transmission
Return to base
Computer will self-destruct in...
 3

 2

 1




Just kidding
This isn't some spy thriller
--------------------------------
Process exited after 72.1 seconds with return value 0
Press any key to continue . . . */
