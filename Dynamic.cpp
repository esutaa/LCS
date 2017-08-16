// File Dynamic.cpp
// COP4531
// Esther Adu
// 22 March 2017

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int ** c;

int lcsLength(vector <char> x, vector <char> y);
int max(int a, int b);

int main(int arg, char *argv[])
{
	ifstream ifFile;	// Declaring variables
	char str;
	vector <char> file1;
	vector <char> file2;
	
	// Checking to see correct amount of arguments
	if (arg < 3 || arg > 3)
	{
		cout << "\nError! Usage: <executable-name> <string1-file-name> <string2-file-name>\n";
		cout << "Try again?\n";
		return 0;
	}

	// Open file one
	ifFile.open(argv[1]);

	// Unable to open file one
	if (!ifFile) {
		cout << "\nFile: " << argv[1] << " could not be opened.\n";
		cout << "Try again?\n";
		return 0;
	}

	// Pushing back string
	while (ifFile.get(str)) {
		file1.push_back(str);
	}
	
	// Close file one
	ifFile.close();

	// Open file two
	ifFile.open(argv[2]);

	// Unable to open file two
	if(!ifFile) {
                cout << "\nFile: " << argv[2] << " could not be opened.\n";
                cout << "Try again?\n";
		return 0;
	}
	
	// Pushing back string
	while (ifFile.get(str)) {
		file2.push_back(str);
	}

	// Close file two
	ifFile.close();

	// Calculate length and find lcs
	lcsLength(file1, file2);

	return 0;
}

// Finds length of LCS and prints LCS to screen
int lcsLength(vector <char> x, vector <char> y)
{
	int m = x.size(), n = y.size();		// Declaring and initializing variables
	int l, len;

        c = new int*[x.size()];     // Making new size of file 1

        for (int i = 0; i < x.size(); i++)  // Creating 2D array
                c[i] = new int[y.size()];
	
	for (int i = 0; i < m; i++) // Initializing array
		c[i][0] = 0;

	for (int i = 0; i < n; i++)
		c[0][i] = 0;

	for (int i = 0; i < m; i++)
	{                
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0)	// If empty
				c[i][j] = 0;
			
			else if (x.at(i - 1) == y.at(j - 1))	// If strings equal
				c[i][j] = c[i-1][j-1] + 1;	// Match! Add 1
			
			else					// Else find which is less or equal for position
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}
	}
	
	l = c[m - 1][n - 1] + 1;	// length of lcs, adding 1 for out of bounds
	
	char arr[l]; 	// New char array to store LCS data
	arr[l] = '\0';		// End string
        	
	while (m > 0 && n > 0) {
		if (x.at(m - 1) == y.at(n - 1)) {	 // If strings equal
			arr[l - 1] = x.at(m - 1);		// Store string
			m--;	
			n--;
			l--;
		}

		else if (c[m - 1][n] > c[m][n - 1]) 	// If strings don't equal
			m--;

		else 
			n--; 
	}

	cout << "\n" << arr;		// Print LCS to screen 
}


// Find the max in array
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
