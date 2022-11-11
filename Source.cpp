#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, sum;
	fin >> n;

	vector <vector<int>> Matrix(n, vector<int>(n));
	vector<int> array(n);

	for (int i = 0; i < n; i++) {
		fin >> array[i];
		Matrix[i][i] = array[i];
	}

	for (int i = 1; i < n; i++){
		for (int j = 0; j < n - i; j++){
			int sum = 0;
			for (int k = j; k <= j + i; k++)
				sum += array[k];
			Matrix[j][j + i] = sum - min(Matrix[j][j + i - 1], Matrix[j + 1][j + i]);
		}
	}

	fout << Matrix[0][n - 1];

}