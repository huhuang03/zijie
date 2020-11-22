//
// Created by huhua on 2020/11/18.
//

#include <iostream>

using namespace std;

long max(long x1, long x2, long x3) {
    return (x1 > x2)?
    (x2 > x3)? x1:
    (x1 > x3) ? x1: x3
        :(x1 > x3)? x2: (x2 > x3)? x2: x3;
}

bool check_min(long k, long y1, long y2, long y3) {
    long max_y = max(y1, y2, y3);
    long min_m = (k - 3 * max_y + (y1 + y2 + y3));
    return y1 >= 0 && y2 >= 0 && y3 >= 0 &&
           min_m >= 0 && min_m % 3 == 0;
}

bool check(long n, long k, long y1, long y2, long y3) {
//    cout << "check_min: " << check_min(k, y1, y2, y3) << endl;
//    cout << "y1: " << y1 << ", y2: " << y2 << ", y3: " << y3 << endl;
//    cout << "(y1 + y2 + y3) <= n - k: " << ((y1 + y2 + y3) <= n - k) << endl;
//    cout << "(n - k - (y1 + y2 + y2)) % 3 == 0: " << ((n - k - (y1 + y2 + y2)) % 3 == 0) << endl;
//    cout << "(n - k - (y1 + y2 + y2))" << ((n - k - (y1 + y2 + y2))) << endl;
//    cout << "(n - k - (y1 + y2 + y2)) % 3" << ((n - k - (y1 + y2 + y2)) % 3) << endl;
    return check_min(k, y1, y2, y3)
    && (y1 + y2 + y3) <= n - k
    && (n - k - (y1 + y2 + y3)) % 3 == 0;
}

void check1(long n, long k, long d1, long d2) {
    long rst = 0;
    // x1 < x2 < x3
    rst |= check(n, k, d1 + d2, d2, 0);

    // x3 < x1 < x2
    // x1 < x3 < x2 same as x3 < x1 < x2
    rst |= check(n, k, d1, 0, d2);

    // x1 > x2 > x3
    rst |= check(n, k, 0, d1, d1 + d2);

    // x1 > x3 > x2
//    cout << "x1 > x3 > x3" << endl;
//    cout << "y2: " << d1 << endl;
//    cout << "y3: " << d1 - d2 << endl;
    rst |= check(n, k, 0, d1, d1 - d2);

    // x3 > x1 > x2
    rst |= check(n, k, d2 - d1, d2, 0);

    if (rst) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main(int argc, char** argv) {
//    check1(150l, 31l, 15l, 16l);

    long rows;
    cin >> rows;
    while (rows--) {
        long n, k, d1, d2;
        cin >> n;
        cin >> k;
        cin >> d1;
        cin >> d2;
        check1(n, k, d1, d2);
    }
}