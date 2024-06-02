#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> s = {'h', 'a', 'n', 'n', 'a', 'h'};
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }

    for (char& c : s) 
        cout << c << " ";
    
    return 0;
}