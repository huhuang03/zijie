#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    int n;
    cin >> n;
    int magic[1000];
    int steps[1001] = {0};

    // now step
    for (int i = 0; i < n; i++) {
        cin >> magic[i];
    }

    int mod = 10e9 + 7;

    for (int i = 1; i <= n; i++) {
        steps[i] = (2 * steps[i - 1] + 2 - steps[magic[i - 1] - 1]) % mod;
    }

    cout << steps[n] << endl;

    return 0;
}
