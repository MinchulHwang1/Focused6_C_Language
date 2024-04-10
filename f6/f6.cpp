/*
* FILE : f6.cpp
* Project : focused 6
* Programmer : Minchul Hwang
* Frist Revision : 2022-10-31
* Description : This program get float numbers from user.
*				Take 4 numbers from user to calculate average and sum.
*				and the other thing is getting 4 numbers from user and put into array, and calculate average and sum
*				the last thing this program doing is changing all number as 40 and print out.
* The functions in this file are used to
*	int getDouble()
*	void calculateStats()
*	void calculateArrayStats()
*	void fillArray()
*/


#include<stdio.h>
#pragma warning(disable: 4996) // required by Visual Studio


int getDouble(double *pNumber);
void calculateStats(double d1, double d2, double d3, double d4, double *pAverage, double *pSum);
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage);
void fillArray(double values[], int numArray, double fillValue);


int main() {
	double num1 = 0, num2 = 0 , num3 = 0, num4 = 0;
	double average = 0, sum = 0;
	double array[4] = { 0.0 };
	double arrayValue = 0;
	int numArray = 0;
	double returnArrayValue = 0;
	double fillValue = 40;
	double returnValue1 = 0, returnValue2 = 0, returnValue3 = 0, returnValue4 = 0;
	
	printf("Input 4 float number.\n");
	printf("If you input invalid number, This program will be closed immediately.\n");

	//If the number is not float number, quit the program.
	returnValue1 = getDouble(&num1); 	
	if (returnValue1 != 0) {

		returnValue2 = getDouble(&num2);
		if (returnValue2 != 0) {

			returnValue3 = getDouble(&num3);
			if (returnValue3 != 0) {

				returnValue4 = getDouble(&num4);
				if (returnValue4 != 0) {

					calculateStats(num1, num2, num3, num4, &average, &sum);
					printf("\n");
					printf("The average and sum of the varibles : \n");
					printf("Average : %lf, Sum : %lf\n", average, sum);
					printf("\n");
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
	
	printf("\n");

	printf("Input 4 float number to put into array.\n");
	printf("If you input invalid number, This program will be closed immediately.\n");

	//Initialize average and sum value to calculate again.
	average = 0; sum = 0;

	//get number from user and put into array
	for (numArray; numArray < 4; numArray++) {

		returnArrayValue = getDouble(&arrayValue);
		//If input array value is not float number
		if (returnArrayValue != 0) {
			array[numArray] = arrayValue;
		}
		else {
			return 0;
		}
	}

	numArray = 0;			//Initialize numArray to pass 0 as parameter

	calculateArrayStats(array, numArray, &sum, &average);

	printf("\n");
	printf("The average and sum of the array elements : %lf, %lf\n", average, sum);
	printf("\n");

	fillArray(array, numArray, fillValue);

	printf("%lf, %lf, %lf, %lf \n", array[0], array[1], array[2], array[3]);
	return 0;
}



/*
* Function: getDouble()
* Parameter: double *pNumber: pointer to a variable that is filled in by the user input, if valid
* Return Value: int: 1 if the user entered a valid floating-point number, 0 otherwise
* Description: This function gets a floating-point number from the user.
			   If the user enters a valid floating-point number,
			   the value is put into the variable pointed to by the parameter and 1 is returned.
			   If the user-entered value is not valid, 0 is returned.
*/
int getDouble(double *pNumber)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;

	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	
	if (sscanf(record, "%lf", pNumber) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to 0 */	
		number = 0;
	}
	
	else {
		/* If input number in not floating number, then return 0 value */
		if (*pNumber - (int)*pNumber != 0) {
			number = 1;
		}
		else {
			number = 0;
		}
	}
	return number;
}



/*
* Function: calculateStats()
* Parameters: double d1, d2, d3, d4: four floating-point numbers
			  double *pAverage: pointer to a variable that is filled in by this function with the average of d1, d2, d3, and d4
			  double *pSum: pointer to a variable that is filled in by this function with the sum of d1, d2, d3, and d4
* Return Value: none
* Description: This function takes four floating-point numbers passed as doubles and calculates the average and sum of the numbers.
			   Once calculated, the average gets put into the variable pointed to by the pAverage parameter and
			   the sum gets put into the variable pointed to by the pSum parameter.
*/
void calculateStats(double d1, double d2, double d3, double d4, double* pAverage, double* pSum) {
	*pSum = d1 + d2 + d3 + d4;
	*pAverage = *pSum / 4;
}



/*
* Function: calculateArrayStats()
* Parameters: double values[]: floating-point numbers
			  int numArray: number of array elements
			  double *pSum: pointer to a variable that is filled in by this function with the sum of all elements in the array
			  double *pAverage: pointer to a variable that is filled in by this function with the average of all elements in the array
Return Value: none
Description: This function takes an array of floating-point (double) numbers, given the number of elements in the array as a parameter, and calculates the average and sum of the numbers.
			 Once calculated, the average gets put into the variable pointed to by the pAverage parameter and the sum gets put into the variable pointed to by the pSum parameter.
*/
void calculateArrayStats(double values[], int numArray, double* pSum, double* pAverage) {
	for (numArray; numArray < 4; numArray++) {
		*pSum += values[numArray];
	}
	*pAverage = *pSum / 4;
}



/*
* Function: fillArray()
* Parameters: double values[]: floating-point numbers
			  int numArray: number of array elements
			  double fillValue: value to put into array elements
* Return Value: none
* Description: This function takes an array of floating-point (double) numbers, given the number of elements in the array as a parameter, and puts the fillValue into each element of the array.
*/
void fillArray(double values[], int numArray, double fillValue) {
	for (numArray; numArray < 4; numArray++) {
		values[numArray] = fillValue;
	}
}