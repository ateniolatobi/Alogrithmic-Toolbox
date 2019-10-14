#include <iostream>

using namespace std;

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n){
    int xact = n % 60;
    int x = 0, y = 0, sq = 0, sum = 0;
    for (int i = 0; i <= xact; i++){
        int z = (x + y) % 10;
        x = y;
        y = z;
        if (i == 1){
            y = 1;
        }
        sq = (y * y) % 10;
        sum += sq;
        sum = sum % 10;
    }
    return sum;

}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
