#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string largest_number(vector<int> a) {
  //write your code here
  stringstream ret;
  vector<string> greed(a.size());

  while(true){
    int num = a[0];
   // int num_t = a[0];
    /**if (a[0] < 10){
        num = (a[0] * 100) + (a[0] * 10) + a[0];
    }else if (a[0] < 100){
        num = (a[0] * 10) + (a[0] % 10);
    }
    if (num == 1000){
        num = 0;
    }**/
    int j = 0;
    for (size_t i = 0; i < a.size(); i++){
        int rep = a[i];
        /**if (a[i] < 10){
            rep = (a[i] * 100) + (a[i] * 10) + a[i];
        }else if (a[i] < 100){
            rep = (a[i] * 10) + (a[i] % 10);
        }**/
        std::stringstream ss;
        ss << num;
        std::string num_s;
        num_s = ss.str();
        std::stringstream tt;
        tt << rep;
        std::string rep_s;
        rep_s = tt.str();
        string n_r_s = num_s + rep_s;
        string r_n_s = rep_s + num_s;
        stringstream back_1(n_r_s);
        stringstream back_2(r_n_s);

        // The object has the value 12345 and stream
        // it to the integer x
        int n_r = 0;
        back_1 >> n_r;
        int r_n = 0;
        back_2 >> r_n;

        if (r_n >= n_r){
            num = rep;
            j = i;
        }
    }
    a.erase(a.begin() + j);
    std::stringstream ss;
    ss << num;
    std::string out_string;
    out_string = ss.str();

    greed.push_back(out_string);

    if ( a.size() == 0){
        break;
    }

  }

  for (size_t i = 0; i < greed.size(); i++) {
    ret << greed[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
  /**a.erase(a.begin() + 3);
  for (size_t i = 0; i < a.size(); i++) {
    std::cout << "This is one "<< a[i]<<endl;
  }**/

}
