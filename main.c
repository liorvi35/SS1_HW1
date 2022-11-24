/**
 * this file contains the main function
 * @version 1.0, 24 November 2022
 * @authors Lior Vinman (ID: 213081763) & Daniel Bespalov (ID: 213446479)
*/

// including libraries
#include <stdio.h>
#include "NumClass.h"

/**
 * this main function gets input of 2 integers and prints all armstrongs, palindromes, primes, strongs numbers between them
 * @return 0
*/
int main()
{
	int low = 0, high = 0;
	scanf("%d %d", &low, &high);
	printf("The Armstrong numbers are:");
	for(int i = low; i <= high; i++)
	{
		if(isArmstrong(i) == 1)
			printf(" %d", i);
	}
	printf("\n");
	printf("The Palindromes are:");
	for(int i = low; i <= high; i++)
	{
		if(isPalindrome(i) == 1)
			printf(" %d", i);
	}
	printf("\n");
	printf("The Prime numbers are:");
	for(int i = low; i <= high; i++)
	{
		if(isPrime(i) == 1)
			printf(" %d", i);
	}
	printf("\n");
	printf("The Strong numbers are:");
	for(int i = low; i <= high; i++)
	{
		if(isStrong(i) == 1)
			printf(" %d", i);
	}
	printf("\n");
	return 0;
}
