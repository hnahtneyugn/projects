#include <iostream>

using namespace std;

void input(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
}

void findCommon(int a[], int b[], int c[], int x, int y, int z) {
    // initialize index of three arrays
    int i = 0, j = 0, k = 0;

    // loop until end of one of the arrays
    while (i < x && j < y && k < z) {
        if (a[i] == b[j] && b[j] == c[k]) {             // if an element presents in all three arrays,...
            cout << a[i] << " ";                        // ...then print it out, and increment index.
            i++;
            j++;
            k++;
        }

        else if (a[i] < b[j])                           // if x < y, increase index of x
            i++;

        else if (b[j] < c[k])                           // if y < z, increase index of y
            j++;

        else                                            // if (x > y and y > z) => z is the smallest
            k++;
    }
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int a[101], b[101], c[101];
    input(a, x);
    input(b, y);
    input(c, z);

    findCommon(a, b, c, x, y, z);

    return 0;
}