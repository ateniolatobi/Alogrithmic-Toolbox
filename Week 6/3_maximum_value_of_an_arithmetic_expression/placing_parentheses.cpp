#include <iostream>
#include <cassert>
#include <string>
#include <vector>
/***
using std::vector;
using std::string;
using std::max;
using std::min;

**/
using namespace std;
long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
 // cout<<"The string is "<<exp.size()<<endl;
  int str_num = exp.size();
  int num = str_num - (str_num / 2);
  int num_exp = str_num / 2;
  char s = '9';
  int c = s - '0';
  cout<<"The value is "<<0%2<<endl;
  /*for (int i = 0; i < str_num; i++){
    if ((i%2) == 0){

    }else{

    }
  }*/

  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
