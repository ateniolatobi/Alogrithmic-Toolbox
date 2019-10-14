#include <iostream>






using namespace std;

int get_change(int m) {
  int dynam[m + 1];
  dynam[0] = 0;
  dynam[1] = 1;
  dynam[2] = 2;
  dynam[3] = 1;
  for (int i = 4; i < (m+1); i++){
    if ((dynam[i-1] <= dynam[i-3])&& (dynam[i-1] <= dynam[i-4])){
        dynam[i] = dynam[i-1] + 1;
    }else if ((dynam[i-3] <= dynam[i-1])&& (dynam[i-3] <= dynam[i-4])){
        dynam[i] = dynam[i-3] + 1;
    }else{
        dynam[i] = dynam[i-4] + 1;
    }
  }
  return dynam[m];
}
int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
