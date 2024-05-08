#include <iostream>

using namespace std;

// always win if given an even number
// always lose if given an odd number
// base case: 1 = lose, 2 = win
bool divisorGame(int n) {
    if (n % 2 == 1)
        return false;
    
    return true;
}

int main() {
    cout << boolalpha << divisorGame(50);
    return 0;
}