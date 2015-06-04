
//Longest non-decreasing sequence using Dynamic Programming

#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;

int find_longest_seq(int [], int);

int main(){
	int numbers[] = {5,3,6,7,8,10,1,2,3,6,7,8,9,10,8,9,10};
	int size = sizeof(numbers) / sizeof(numbers[0]);

	int result;
	result = find_longest_seq(numbers, size);
	cout << "The longest non-decreasing sequence is: " << result << endl;
	return 0;
}

int find_longest_seq(int numbers[], int size){
	int sum[size];
	int i,j, max = 0, index = 0;

	// initialize the seq array
	for(i = 0; i < size; i++){
		sum[i] = 1;
	}

	// fill the seq array
	for(i = 1; i < size; i++){
		for(j = 0; j < i; j++){
			if(numbers[j] < numbers[i] && (sum[j] + 1 > sum[i])){
				sum[i] = sum[j] + 1;				
			} 		
		}
	}

	// find the maximum in the seq array
	for(i = 0; i < size; i++){
		//cout << "The seq array is: " << sum[i] << endl;
		if(max < sum[i]){
			index = i;
			max = sum[i];
		}
	}


	// prints the sequence
	cout << "The longest sequence of numbers are: " << endl;
	for(i = index - max + 1 ; i <= index; i++){
		cout << numbers[i] << endl;
	}
	return max;
}

