/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int is_in_geoseq(int *arr, int len)
{
	int i;
	int temp;
	if (len <= 2)
		return 0;
	if (arr[1] % arr[0] == 0)
		temp = arr[1] / arr[0];
	else
		return 0;
	for (i = 1; i < len - 1; i++)
	{
		if (arr[i + 1] % arr[i] == 0 && arr[i + 1] / arr[i] == temp)
			continue;
		else
			break;
	}
	if (i >= 2)
		return i;
	return 0;
}
int is_in_artseq(int *arr, int len)
{
	int i;
	int temp;
	if (len <= 2)
		return 0;
	temp = arr[1] - arr[0];
	for (i = 1; i < len - 1; i++)
	{
		if (arr[i + 1] - arr[i] == temp)
			continue;
		else
			break;
	}
	if (i >= 2)
		return i;
	return 0;
}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int *final_array;
	int i, temp;
	int art_flag = 0;

	if (arr == NULL)
		return NULL;
	if (len <= 2)
		return NULL;
	final_array = (int*)malloc(sizeof(int)* 6);
	for (i = 0; i < len; i++)
	{
		temp = is_in_geoseq(arr + i, len - i);
		if (temp)
		{
			final_array[4] = i;
			final_array[5] = i + temp;
		}
		if (art_flag == 0)
		{
			temp = is_in_artseq(arr + i, len - i);
			if (temp)
			{

				final_array[0] = i;
				final_array[1] = i + temp;
				art_flag = final_array[1];
			}
		}
		else if (i > art_flag)
		{
			temp = is_in_artseq(arr + i, len - i);
			if (temp)
			{
				final_array[2] = i;
				final_array[3] = i + temp;
			}
		}
	}
	return final_array;
}