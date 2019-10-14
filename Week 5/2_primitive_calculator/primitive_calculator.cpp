#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;

  int dynam[n + 1];
  dynam[0] = 0;
  dynam[1] = 0;
  dynam[2] = 1;
  int minn = 0;
  int x;
  for (int i = 3; i < n + 1; i++){
    minn = dynam[i -1];
    if ((i % 2) ==  0){
        x = dynam[i / 2];
        minn = (x <= minn)? x : minn;
    }
    if ((i % 3) ==  0){
        x = dynam[i / 3];
        minn = (x <= minn)? x : minn;
    }
    dynam[i] = minn + 1;
  }sequence.push_back(n);
  //cout<<"DYNAM IS "<<dynam[n]<<endl;
  while (n > 1) {
    int min_num = n - 1;
    minn = dynam[min_num];

    if ((n % 3) == 0) {
        x = dynam[n / 3];
        if (x <= minn){
            minn = x;
            min_num = n/3;
        }
    }
    if (n % 2 == 0) {
        x = dynam[n / 2];
        if (x <= minn){
            minn = x;
            min_num = n/2;
        }
    }

    n = min_num;
    sequence.push_back(n);
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
