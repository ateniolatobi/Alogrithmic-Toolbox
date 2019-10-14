#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(int *a, int x, int n) {
  //write your code here
  int siz = n;
  int loc = (siz%2 != 0)?(siz/2 + 1):siz/2;
  int i = -1 + loc;
  while (siz > 0){
    if (a[i] == x){
        return i;
    }else if (x > a[i]){
        siz = siz - loc;
        loc = (siz%2 != 0)?(siz/2 + 1):siz/2;
        i = i + loc;
    }else{
        siz = (siz%2 == 0)?siz-(loc+1):siz-loc;
        loc = (siz%2 != 0)?(siz/2 + 1):siz/2;
        i = (siz%2 == 0)? i - (loc+1):i - loc;
    }

  }
  return -1;
}

int binary_search_recurs(int *a, int x, int siz, bool f = false, int loc = 0, int i = 0) {
  //write your code here
  if (f == false){
    loc = (siz%2 != 0)?(siz/2 + 1):siz/2;
    i = -1 + loc;
   }
    if (siz == 0) return -1;
    if (a[i] == x){
        return i;
    }else if (x > a[i]){
        siz = siz - loc;
        loc = (siz%2 != 0)?(siz/2 + 1):siz/2;
        i = i + loc;
        return binary_search_recurs(a, x, siz, true,loc, i);
    }else{
        siz = (siz%2 == 0)?siz-(loc+1):siz-loc;
        loc = (siz%2 != 0)?(siz/2 + 1):siz/2;
        i = (siz%2 == 0)? i - (loc+1):i - loc;
        return binary_search_recurs(a, x, siz, true, loc, i);
    }
  return -1;
}

int linear_search(int *a, int x, int n) {
  int p = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == x){
        p = i;
        break;
    }
  }
  return p;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  int b[m];
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search_recurs(a, b[i], n) << ' ';
  }
}
