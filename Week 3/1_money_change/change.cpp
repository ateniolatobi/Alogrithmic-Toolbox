#include <iostream>


using namespace std;




int get_change(int m) {
  //write your code here
  int n_ten = m / 10;
  int denom[3] = {10, 5, 1};
  int total = 0;
  for (int i = 0; i < 3; i++){
    int n_cash = m / denom[i];
    m =  m % denom[i];
    total += n_cash;
    if (m == 0){
        break;
    }
  }

  return total;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
