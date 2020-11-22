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

int get_max(int *count_arr, int len, int m) {
    m = m + 2;
    int max = 0;
    for (int i = 0; i < len; i++) {
        int this_sum = 0;
        for (int j = 0; j < m; j++) {
            
            if (i + j < len) {
                this_sum += count_arr[i + j];
            }
        }

        if (max < this_sum) {
            max = this_sum;
        }
        if (i + m >= len) {
            break;
        }
    }
    return max;
}

void handle_1(int *arr1, int* arr1_index, int *arr2, int* arr2_index, int* arr1_c, int *arr2_c) {
    if (*arr2_c != 0) {
        // cout << "*arr2_c: "<< *arr2_c << endl;
        arr2[*arr2_index] = *arr2_c;
        *arr2_index += 1;
        *arr2_c = 0;
    }
    // cout << "*arr2_c: "<< 0 << endl;
    arr2[*arr2_index] = 1;
    *arr2_index += 1;

    *arr1_c += 1;
}

int main() {
    int m, n;
    bool end = false;
    int c1 = 0;
    int c2 = 0;
    cin >> n;
    cin >> m;
    
    int *count_a = (int*)calloc(n, sizeof(int));
    int *count_b = (int*)calloc(n, sizeof(int));
    
    int ai = 0;
    int bi = 0;
    int a = 0;
    int b = 0;
    
    while (n--) {
        char c;
        cin >> c;
        bool is_a = c == 'a';
        
        if (is_a) {
            // cout << "ia a" << endl;
            handle_1(count_a, &ai, count_b, &bi, &a, &b);
        } else {
            // cout << "ia b" << endl;
            handle_1(count_b, &bi, count_a, &ai, &b, &a);
        }
        
    }
    
    // print_array(count_a, ai);

    int max_a = get_max(count_a, ai, m);
    int max_b = get_max(count_b, bi, m);
    int max = max_a > max_b ? max_a: max_b;
    cout << max << endl;
    
}