#include <iostream>
#include <vector>

using namespace std;



int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  //vector<int> poss_array[][];
  int num_gold = w.size();
  int n = W+1;
  //int poss_array[num_gold][n];
  std::vector<std::vector<int>> poss_array;
  poss_array.resize(num_gold, std::vector<int>(n, 0));
  for (int i = 0; i < num_gold; i++){
    for (int j = 0; j < n; j++){
        int temp;
        if ((j - w[i]) >= 0){
            temp = w[i];
            if (((j - w[i]) > 0) && (i > 0)){
                temp += poss_array[i-1][j - w[i]];
            }
        }else if (i > 0){
            temp = poss_array[i-1][j];
        }else{
            temp = 0;
        }

        if (i > 0){
            if (poss_array[i-1][j] > temp){
                temp = poss_array[i-1][j];
            }
        }
        poss_array[i][j] =  temp;
    }
  }/**
  cout<<"DISPLAYED ARRAY "<<endl;
  for (int i =0; i < num_gold; i++){
    for (int j = 0; j < n; j++){
        cout<<poss_array[i][j]<< " ";
    }
    cout<<endl;
  }**/
  int current_weight = poss_array[num_gold-1][n-1];
  /**cout<<"The number of gold weights are "<<w.size()<<endl;
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }**/
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
