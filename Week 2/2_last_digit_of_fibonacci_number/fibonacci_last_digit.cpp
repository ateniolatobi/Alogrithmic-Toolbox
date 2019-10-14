#include <iostream>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}


long long get_fibonacci_last_digit_fast(int n){
   long long x[n+1];
   x[0] = 0;
   x[1] = 1;

   for (int i = 2; i <= n; i++){

    x[i] = (x[i - 1] + x[i - 2]) % 10;
   }
   return x[n];

}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';
    }
