#include <iostream>


using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


long long get_fibonacci_huge_fast(long long n, long long m){

    long long x = 0, y = 1;
    long long fibs[m * m];
    fibs[0] =x;
    fibs[1] = y;
    int period = 0;
    for (int i = 0; i < m * m; i++){
        long long z = (x + y) % m;
        x = y;
        y = z;
        fibs[i + 1] = x;
        fibs[i + 2] = y;

        if (x == 0 && y == 1){
            period = i + 1;
            break;
        }
    }


    return fibs[n % period];

}



int main() {
    long long n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_fast(n, m) << '\n';
}
