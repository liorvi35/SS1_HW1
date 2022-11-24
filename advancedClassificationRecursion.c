/**
 * this file contains the isPalindrome, isArmstrong that implemented recursively
 * @version 1.0, 24 November 2022
 * @authors Lior Vinman (ID: 213081763) & Daniel Bespalov (ID: 213446479)
*/

// including libraries
#include <stdio.h>
#include "NumClass.h"

// declaring functions that will be implemented recursively
int numDigits(int n);
int reverse(int n);
int isPalindrome(int n);
int isArmstrong(int n);
int isArmstrongHelper(int n, int num, int digits, int sum);
int myPOW(int n, int m);

/**
 * this function gets two integers and calculates the power
 * @param n - the base
 * @param m - the power
 * @return n^m = n * n * ... * n : m times
*/

int myPOW(int n, int m)
{
	if(m == 0)
		return 1;
	return n * myPOW(n, m-1);
}


/**
 * this function gets an integer and counts the digits number
 * @param n - the integer to count number of digits
 * @return digit number of n
*/
int numDigits(int n) {
	if(n < 10)
		return 1;
	return 1 + numDigits(n/10);
}

/**
 * this function gets an integer and reverses it
 * @param n - the integer to reverse
 * @return reverse of n (i.e. n^R)
*/
int reverse(int n) 
{
    int digits = numDigits(n) - 1;
    if (n < 10)
    	return n;
    return ((n % 10) * myPOW(10, digits) )+ reverse((n / 10));
}

/**
 * this function gets an integer and checks if its a palindrome. (n is palidrome iff n = n^R).
 * @param n - the integer to check
 * @return 1 if n is palidrome, 0 else
*/
int isPalindrome(int n)
{
	if(n != reverse(n))
		return 0;
	return 1;
}

/**
 * this function gets an integer and checks if its an armstrong number.
 * @param n - the integer to check
 * @param num - copy of n that will no be changed in the recusion
 * @param digits - the number of digits of n
 * @param sum - sum of the digits pow
 * @return 1 if n is armstrong, 0 else
*/
int isArmstrongHelper(int n, int num, int digits, int sum) 
{
	
	if(num == 0)
	{
		if(sum != n)
			return 0;
		return 1;
	}
	sum += myPOW(num % 10, digits);
	num /= 10;
	return isArmstrongHelper(n, num, digits, sum);
	
}

/**
 * shell function to isArmstrongHelper
 * @param n - integer to check if its an armstrong number
 * @return 1 if n is armstrong, 0 else
*/
int isArmstrong(int n)
{
	return isArmstrongHelper(n, n, numDigits(n), 0);
}