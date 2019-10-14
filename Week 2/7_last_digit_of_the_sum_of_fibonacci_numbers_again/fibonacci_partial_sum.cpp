#include <iostream>
#include <vector>
using std::vector;


using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


long long get_fibonacci_partial_sum_fast(long long from, long long to){

    long long x = 0, y = 0, sum = 0;
    long long s = from % 60;
    long long fibs[60];
    int j = 0;
    for (int i = 0; i < 120; i++){

        long long z = (x + y) % 10;
        x = y;
        y = z;
        if (i == 1){
            y =1;
        }

        if (i >= s && i < s + 60){
            sum += y;
            sum  = sum % 10;
            fibs[j] = sum;
            j++;
           /** cout<<"sum "<<sum<<endl;**/
        }
        if (i == s + 59){
            break;
        }
    }
    return fibs[(to % 60) - s];

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
