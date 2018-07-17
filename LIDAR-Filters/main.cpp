////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	main.cpp
//
// summary:	Implements the main class
//			For testing.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Range_Filter.h"
#include "Temporal_Median_Filter.h"

using namespace std;

int main() {
	cout << "TEST SESSION" << endl;
	cout << "Loading LIDAR_data.csv" << ' ';
	ifstream in_file("LIDAR_data.csv");
	string line_str;
	vector<vector<float>> LIDAR_data;
	while (getline(in_file, line_str))
	{
		stringstream ss(line_str);
		string entry_str;
		vector<float> line_array;
		while (getline(ss, entry_str, ',')) { line_array.push_back(stoi(entry_str)); }
		LIDAR_data.push_back(line_array);
	}
	cout << "Done" << endl;

	std::cout << "Range_Filter test"<<std::endl;
	float max = 500;
	float min = 0.03;
	cout << "Enter max:";
	cin >> max;
	cout << "Enter min:";
	cin >> min;
	cout << "Filtering LIDAR_data using Range_Filter/writing result to rf_result.csv" << ' ';
	vector<vector<float>> rf_test_data = LIDAR_data;
	Range_Filter rf(min, max);
	ofstream out_file1("rf_result.csv");
	for (auto data : rf_test_data) {
		rf.update(data);
		for (auto e : data) { out_file1 << e << ','; }
		out_file1 << endl;
	}
	out_file1.close();
	cout << "Done" << endl;
	
	cout << "Temporal_Median_Filter test" << endl;
	int D = 5;
	cout << "Enter D:";
	cin >> D;
	cout << "Filtering LIDAR_data using Temporal_Median_Filter/writing result to tmf_result.csv" << ' ';
	vector<vector<float>> tmf_test_data = LIDAR_data;
	Temporal_Median_Filter tmf(tmf_test_data[0].size(), D);
	ofstream out_file2("tmf_result.csv");
	for (auto data : tmf_test_data) {
		tmf.update(data);
		for (auto e : data) { out_file2 << e << ','; }
		out_file2 << endl;
	}
	out_file2.close();
	cout << "Done" << endl;

	getchar();
	return 0;
}