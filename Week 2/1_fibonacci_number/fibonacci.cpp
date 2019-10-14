#include <iostream>
#include <cassert>

using namespace std;
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n) {
    // write your code here
    long long x[n + 1];
    x[0] = 0;
    x[1] = 1;
    for (int i = 2; i <= n; i++){
        x[i] = x[i - 1] + x[i - 2];
    }

    return x[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    cin >> n;
    cout << fibonacci_naive(n) << '\n';
    return 0;
}
