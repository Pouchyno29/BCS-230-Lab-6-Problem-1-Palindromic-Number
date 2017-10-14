/**
   Programmer's name    : Stanley 
   Class                : BCS 230 Foundations of Computer Programming II
   Date                 : 10/11/2017
   Lab                  : Lab 6 Assignment Palindromic Number
   Professor's name     : Moaath Alrajab
   Software uses        : Visual Studio 2012
**/

/*
	A palindromic number reads the same	both ways. The largest palindrome	
	made from the product of two 2-digit numbers is 9009 = 91 × 99.	Find	
	the	largest	palindrome	made from the product of two 3-digit numbers.	
		Design	requirements:		
		• must have a function	that uses c-string to check	if a number is	
		  palindrome.	
		• should use camelCase	naming convention.
		• Should use multiline comments.[/*....*/]
	      //and line comments [//.....]
*/


#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

int isPalindrome(int orig);
int getTheReverse(int newNumber, int &reverseNumber);
bool checkIfPalindrome(int newNumber, int reverseNumber);

int main(void) {

  int max = 0;			//Variable that will save the current lagest palindrome found
  int newNumber;		//Variable to hold the current number that being check for palindrome
  int count = 0;		//Variable to count the number of palindrome found
  //int temp;
  int reverseNumber;
  
  
  //Start count from the smallest number to the largest number which is 999
  for (int index1 = 100; index1  <= 999; index1++) {
	  //Start count from the larger number to the smallest number which is 100
    for (int index2  = 999; index2 >= 100; index2--) {
		//Get the product of both numbers and save it to newNumber variable
      newNumber = index1*index2;

	  reverseNumber = getTheReverse(newNumber, reverseNumber);
		//Check if the current number is a palindrome
	  if(checkIfPalindrome(newNumber, reverseNumber) == true){
		//Check if the current palindrome is greater than the previous palindrome
		if(	newNumber > max) {
		//If the first two conditions are true then save the current largest palindrome found to max variable 
        max = newNumber; 
		//Print out the current largest aplindrome found
			cout << "The " << ++count << " palindrome found "<< string(5, ' ') << max << endl;
      }
    }
  }
 }

	//Print out the final largest palindrome found
  cout << endl << "The Largest palindrome is: \t\t"<< max << endl;  
  system("Pause");
  return 0;
}


//Function to get the reverse of a number
int getTheReverse(int newNumber, int &reverseNumber){

	int temp;										
	reverseNumber = 0;
	while(newNumber != 0){								//loop as long as the original number is no equal to zero
		temp = newNumber % 10;							//Temporary save the remainder of the original number divided by 10
		reverseNumber  = reverseNumber * 10 + temp;		//Reserver is equal its current value multiply by 10 plus the remainder of the previous operation
		newNumber  = newNumber/10;						//The original number divided by 10
	}
	return reverseNumber;								//Return the reverse number once the original number equal ZERO
}

//Function to Check if the two numbers are equal
bool checkIfPalindrome(int newNumber, int reverseNumber){
	
	string num1 = to_string(newNumber);			//Convert the original number into string
	string num2 = to_string(reverseNumber);		//Convert the reverse number into string

	if(num1 == num2){							//Check if both strings are equal
		return true;							//Return true if there are equal
	}else{
		return false;							//Return false if there are not equal
	}

}



