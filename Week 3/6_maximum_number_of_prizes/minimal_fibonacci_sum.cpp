#include <iostream>
#include <vector>

using std::vector;
using namespace std;


vector<long long> optimal_summands(int n) {
  vector<long long> summands;
  //write your code here
    long long x = 1;
    long long y = 1;
    long long sum = 0;
    int counter = 0;
    long long points[60];
  for (int i = 0; i < n; i++){
        long long z;
        if (i == 0){
            z = x;
        }else{
            z = x + y;
            x = y;
            y = z;
        }
        sum += z;
        //cout<<z<<endl;
        points[i] = z;

        if (sum >= n){
            counter = i;
            break;
        }
  }
  //cout<<"The sum now"<<sum<<endl;
  //cout<<"The counter now"<<endl;
  int j = 0;
  for (int i = counter; i > -1; i--){

        if ((sum - points[i]) < n){
            n -= points[i];
            //summands[j] = points[i];
            //cout<<"A point "<<points[i]<<endl;
            summands.push_back(points[i]);
            j++;
        }
        sum -= points[i];
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
