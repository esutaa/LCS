// File Memoized.cpp
// Esther Adu
// COP4531
// 22 March 2017

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <char> file1;
vector <char> file2;
int ** c;

void lcsLength();
int memLCS(int m, int n);
int max(int a, int b);
void printLCS(int l);

int main(int arg, char *argv[])
{
        ifstream ifFile;        // Declaring variables
        char str;

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

	lcsLength();
return 0;
}

// Find length of LCS
void lcsLength()
{
	int l;
	c = new int*[file1.size()];	// Making new size of file 1

	for (int i = 0; i < file1.size(); i++)	// Creating 2D array
		c[i] = new int[file2.size()];

	for (int i = 0; i < file1.size(); i++) {
		for (int j = 0; j < file2.size(); j++)
			c[i][j] = -1;		// Initializing rows to -1
	}

	l = memLCS(file1.size() - 1, file2.size() - 1) + 1; 		// Memoization of LCS
	printLCS(l);

}

// A memoized form of LCS
int memLCS(int m, int n)
{
	if (c[m][n] != -1)
		return c[m][n];

	else if (m == 0 || n == 0)	// If first row or column, c is 0
		c[m][n] = 0;

	else if (file1.at(m - 1) == file2.at(n - 1))  	// If a match! Add 1
		c[m][n] = memLCS(m - 1, n - 1) + 1;

	else
		c[m][n] = max(memLCS(m - 1, n), memLCS(m, n - 1));	// Else find which row/column is greater

	return c[m][n];	
}

// Find max in array
int max(int a, int b)
{
        if (a > b)
                return a;
        else
                return b;
}

// Display LCS to screen
void printLCS(int l)
{
	char arr[l];
	int m = file1.size(), n = file2.size();

	arr[l] = '\0';	// End string of char array

	while (m > 0 && n > 0) {
		if (file1.at(m - 1) == file2.at(n - 1)) {	// If match
			arr[l - 1] = file1.at(m - 1);		// Add to array
			m--;
			n--;
			l--;
		}

		else if (c[m - 1][n] > c[m][n - 1])	// If greater, decrement
			m--;

		else
			n--;
	}

	cout << "\n" << arr;			// Display to screen
}
