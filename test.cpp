#include <iostream>

using namespace std;

void test(int *a) {
    *a += 1;
}

int main() {
    int i = 100;
    test(&i);
    cout << i << endl;
    return 0;
}