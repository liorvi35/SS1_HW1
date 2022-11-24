/**
 * this file contains the isPalindrome, isArmstrong that implemented iteratively
 * @version 1.0, 24 November 2022
 * @authors Lior Vinman (ID: 213081763) & Daniel Bespalov (ID: 213446479)
*/

// including libraries
#include <stdio.h>
#include "NumClass.h"

// declaring functions that will be implemented itaratively
int numDigits(int n);
int reverse(int n);
int isPalindrome(int n);
int isArmstrong(int n);
int myPOW(int n, int m);

/**
 * this function gets two integers and calculates the power
 * @param n - the base
 * @param m - the power
 * @return n^m = n * n * ... * n : m times
*/
int myPOW(int n, int m)
{
	int p = 1;
	for(int i = m; i > 0; i--)
		p *= n;
	return p;
}

/**
 * this function gets an integer and counts the digits number
 * @param n - the integer to count number of digits
 * @return digit number of n
*/
int numDigits(int n) 
{
	int digits = 0;
	while(n != 0)
	{
		digits++;
		n /= 10;
	}
	return digits;
}

/**
 * this function gets an integer and reverses it
 * @param n - the integer to reverse
 * @return reverse of n (i.e. n^R)
*/
int reverse(int n)
{
	int ans = 0;
	while(n != 0)
	{
		ans += n % 10;
		if(n / 10 != 0)
			ans *= 10;
		n /= 10;
	}
	return ans;
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
 * this function gets an integer and checks if its an armstrong.
 * @param n - the integer to check
 * @return 1 if n is armstrong number, 0 else
*/
int isArmstrong(int n)
{
	int digits = numDigits(n), sum = 0, num = n;
	while(num != 0)
	{
		sum += myPOW(num % 10, digits);
		num /= 10;
	}
	if(sum != n)
		return 0;
	return 1;
}