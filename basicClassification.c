/**
 * this file contains the isPrime, isStrong that implemented iteratively
 * @version 1.0, 24 November 2022
 * @authors Lior Vinman (ID: 213081763) & Daniel Bespalov (ID: 213446479)
*/

// including libraries
#include <stdio.h>
#include "NumClass.h"

// declaring functions that will be implemented recursively
int factorial(int n);
int isStrong(int n);
int isPrime(int n);

/**
 * this function gets an integer and calculates its factorial
 * @param n - the integer to calculate
 * @return factorial of n (i.e. n!)
*/
int factorial(int n)
{
	if(n == 0) 
		return 1;
	return n * factorial(n-1); 
}

/**
 * this function gets an integer and checks if its a strong number
 * @param n - the integer to check
 * @return 1 if n is strong number, 0 else
*/
int isStrong(int n)
{
	int sum = 0, num = n;
	while(num != 0)
	{
		sum += factorial(num%10);
		num /= 10;
	}
	if(sum != n)
		return 0;
	return 1;
}

/**
 * this function gets an integer and checks if its a prime number
 * @param n - the integer to check
 * @return 1 if n is prime number, 0 else
*/
int isPrime(int n) 
{
	if(n <= 0)
		return 0;
	if(n == 1 || n == 2)
		return 1;
	for(int i = 2; i < n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}