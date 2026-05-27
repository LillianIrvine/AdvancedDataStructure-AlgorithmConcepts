#include <iostream>
#include <math.h> 
using namespace std;


int getLength(long long value){
int counter = 0;
while (value != 0){
    counter ++;
    value /= 10;
}
    return counter;
}



long long karat(long long x, long long y){

    int xLength = getLength(x);
    int yLength = getLength(y);

    //get max of two int
    int N = fmax(xLength, yLength);

    if (N < 2){
        return x*y;
    }

    N = N/2 + N%2;

    long long multiplier = pow(10, N);

    long long a = x / multiplier;
    long long b = x % multiplier;

    long long c = y / multiplier;
    long long d = y % multiplier;

    long long z0 = karat(a, c);
    long long z1 = karat(a + b, c + d);
    long long z2 = karat(b, d);

    return z0*pow(10, 2*N) + z2 + multiplier*(z1 - z0 - z2);
}



int main(){

    cout << "Karatsuba Output: " << karat(5678, 1234) << endl;
    cout << "Standard Output: " << 1234*5678 << endl;

    return 0;
}