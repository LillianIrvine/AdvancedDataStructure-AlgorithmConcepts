#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

bool josephusGameNaive(){
  //Randomly generate n (50–1000) and k (2–10)
    int n = 50 + rand() % 951;
    int k = 2 + rand() % 9;
    int guess;
//Prompt the user to pick a position to survive
    cout << "There are " << n <<  " people standing in a circle. Starting from the first person we will count every " << k << 
    " people and that person will be KILLED. Pick a position in the circle to stand and see if you're the last one still alive.";

do {
        cout << "\nPick your survival position (1–" << n << "): ";
        cin >> guess;

        if (guess < 1 || guess > n)
            cout << "Invalid position. Try again.\n";

    } while (guess < 1 || guess > n);

    std::vector<int> players;
    for (int i = 1; i <= n; i++)
        players.push_back(i);

    int index = 0;

    while (players.size() > 1) {
        index = (index + k -1) % players.size();
        players.erase(players.begin() + index);
    }

    int survivor = players[0];

    //cout << "\nSurviving position: " << survivor << endl;

    return (guess == survivor + 1);
}
bool josephusGameOptimized(){
      //Randomly generate n (50–1000) and k (2–10)
    int n = 50 + rand() % 951;
    int k = 2 + rand() % 9;
    int guess;

    //Prompt the user to pick a position to survive
    cout << "There are " << n <<  " people standing in a circle. Starting from the first person we will count every " << k << 
    " people and that person will be KILLED. Pick a position in the circle to stand and see if you're the last one still alive.";

    do {
        cout << "\nPick your survival position (1–" << n << "): ";
        cin >> guess;
    } while (guess < 1 || guess > n);

    int survivor = 0;

    for (int i = 1; i <= n; i++)
        survivor = (survivor + k) % i;

    return (guess == survivor + 1);

}


int main(){

    auto start = high_resolution_clock::now();

    //Simulate the game and display if they survive

    srand(time(0));

    bool survived = josephusGameNaive();
    //bool survived = josephusGameOptimized();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "runtime = " << duration.count() << " microseconds";

    if (survived)
        cout << "You Win!";
    else 
        cout << "you got killed!";

    

    return 0;
}


