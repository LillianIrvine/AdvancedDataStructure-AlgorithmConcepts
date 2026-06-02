#include <iostream>
using namespace std;

int main() {

	int a [3][3];
	cout << "0,0: " << &a[0, 0] << endl;
	cout << "1,0: " << &a[1, 0] << endl;
	cout << "2,0: " << &a[2, 0] << endl;
	
	cout << "0,1: " << &a[0, 1] << endl;

	return 0;
};