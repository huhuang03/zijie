#include <iostream>

using namespace std;

void print_array(int *arr, int len) {
    cout << "[";
    for (int i = 0; i < len; i++) {
        cout << arr[i];
        if (i != len - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int get_max(int *arr, int len, int m) {
    int max= 0;
    for (int i = 0; i < len; i++) {
        int sum = 0;

        

        if (max < sum) {
            max = sum;
        }
    }
    return max;
}

int main() {
    int m, n;
    bool end = false;
    int c1 = 0;
    int c2 = 0;
    cin >> n;
    cin >> m;

    int *arr = (int*)calloc(n, sizeof(int));
    
    // int *count_a = (int*)calloc(n, sizeof(int));
    // int *count_b = (int*)calloc(n, sizeof(int));
    
    // int ai = 0;
    // int bi = 0;
    // int a = 0;
    // int b = 0;
    
    int i = 0;
    while (n--) {
        char c;
        cin >> c;
        bool is_a = c == 'a';
        int v = is_a == c? 1: 0;

        arr[i++] = v;
    }
    
    // // print_array(count_a, ai);

    // int max_a = get_max(count_a, ai, m);
    // int max_b = get_max(count_b, bi, m);
    // int max = max_a > max_b ? max_a: max_b;
    // cout << max << endl;
    
}