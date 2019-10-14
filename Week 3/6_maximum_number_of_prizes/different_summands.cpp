#include <iostream>
#include <vector>

using std::vector;
using namespace std;


vector<long long> optimal_summands(int n) {
  vector<long long> summands;
  //write your code here
  int counter = 1;
  while (n != 0){

    if ((counter * 2) < n){
       n -= counter;
       summands.push_back(counter);
    }else{
       summands.push_back(n);
       break;
    }
    counter++;

  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
