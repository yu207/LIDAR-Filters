//this is my first c++ program
#include <iostream>
#include "Range_Filter.h"
#include "Temporal_Median_Filter.h"

int main() {
	/*
	std::cout << "Range_Filter test"<<std::endl;
	Range_Filter rf;
	int size1 = 10;
	float array1 [10]= { 0.001,-0.5,100,25,3,1,-5,10,250,15 };
	rf.update(array1, size1);

	for (const auto& e : array1) {
	std::cout << e << std::endl;
	}
	*/

	std::cout << "Temporal_Median_Filter test" << std::endl;
	Temporal_Median_Filter tmf(5, 0);

	float matrix1[5][5] = { { 0,1,2,1,3 },
	{ 1,5,7,1,3 },
	{ 2,3,4,1,0 },
	{ 3,3,3,1,3 },
	{ 10,2,4,0,0 } };

	/*
	float matrix1[5][1] = { { 0 },
	{ 1 },
	{ 2 },
	{ 3 },
	{ 10 } };
	*/

	for (int i = 0; i < 5; i++) {
		tmf.update(matrix1[i], 5);
		for (const auto& e : matrix1[i]) {
			std::cout << e << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}