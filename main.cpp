//*****************************************
//	ECE4960
//	in class hacker: denormals
//	2/1/2019
//	Hongliang Si (hs983@cornell.edu)	
//*****************************************

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double x;
	x = 1.234567890123456789;
	x *= pow(10, -307);
	for (int i = 1; i < 20; i++) {
		
		cout << setprecision(16) <<x <<endl;
			x /= 10;
	}
	
	return 0;
}
