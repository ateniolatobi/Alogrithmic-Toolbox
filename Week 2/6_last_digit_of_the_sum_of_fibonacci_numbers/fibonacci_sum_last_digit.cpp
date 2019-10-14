#include <iostream>

using namespace std;


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fibonacci_sum_fast(long long n){
    int rep = n % 60;
    int x = 0, y = 1, sum = 1;
    if (rep == 0){
        sum = 0;
    }
    for (int i = 2; i <= rep; i++){
        int z = (x + y) % 10;
        x = y;
        y = z;
        sum += y;
        sum = sum  % 10;
    }
    return sum;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
