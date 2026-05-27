#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int scavengerNaive(){

    int currentValue;
    cout << "ENTER INTEGER TO START GAME: ";
    cin >> currentValue;
    int counter = 0;

if(currentValue < 10){
    cout << "your number survived 0 rounds\n";
    return 0;
}

while(currentValue >= 10){//start loop
    counter ++;// update counter
    //seperate digits to multiply
    int copy = currentValue;
    int product = 1;

    //multiply each digit
    while (copy > 0){
        int digit = copy % 10;
        product *= digit;
        copy /= 10;
    }

    currentValue = product;
    
    cout << "round " << counter << ":" << currentValue << "\n";
    
}

        cout << "youre number survived " << counter << " rounds";

        return 0;
}

int scavengerOptimized(){

int currentValue;
    cout << "ENTER INTEGER TO START GAME: ";
    cin >> currentValue;

    int counter = 0;

    while (currentValue >= 10) {
        counter++;

        int temp = currentValue;
        int product = 1;

        do {
            int digit = temp % 10;

            if (digit == 0) { 
                product = 0;
                break;
            }

            product *= digit;
            temp /= 10;

        } while (temp > 0);

        currentValue = product;

        cout << "Round " << counter << ": " << currentValue << "\n";

        if (currentValue == 0)
            break;
    }

    cout << "Your number survived " << counter << " rounds\n";

    return 0;
};

int scavengerBinary(){
     int currentValue;
    cout << "ENTER INTEGER (interpreted in base 10, processed in base 2): ";
    cin >> currentValue;

    int counter = 0;

    while (currentValue >= 2) {  // more than one binary digit
        counter++;

        int copy = currentValue;
        int product = 1;

        do {
            int digit = copy % 2;

            if (digit == 0) {
                product = 0;
                break;
            }

            product *= digit;
            copy /= 2;

        } while (copy > 0);

        currentValue = product;

        cout << "Round " << counter << ": " << currentValue << "\n";

        if (currentValue == 0)
            break;
    }

    cout << "Number survived " << counter << " rounds\n";
    return 0;
};

int scavengerHex(){

    int currentValue;
    cout << "ENTER INTEGER (processed in base 16): ";
    cin >> currentValue;

    int counter = 0;

    while (currentValue >= 16) {   // more than one hex digit
        counter++;

        int copy = currentValue;
        int product = 1;

        do {
            int digit = copy % 16;

            if (digit == 0) {
                product = 0;
                break;
            }

            product *= digit;
            copy /= 16;

        } while (copy > 0);

        currentValue = product;

        cout << "Round " << counter << ": " << currentValue << "\n";

        if (currentValue == 0)
            break;
    }

    cout << "Number survived " << counter << " rounds\n";
    return 0;

};

int main(){


scavengerNaive();
//scavengerOptimized();
//scavengerBinary();
//scavengerHex();

    return 0;
}