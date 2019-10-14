#include <algorithm>
#include <iostream>
#include <vector>





using std::vector;
using namespace std;
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

void merge_sort(int *x, int start, int half, int endd){
    int n = endd - start;
    int result[n];
    int ind1 = start;
    int ind2 = half;
    bool endList1 = false;
    bool endList2 = false;
    for (int i = 0; i < n; i++){
        if (((x[ind1] <= x[ind2]) && !endList1)|| endList2){
            result[i] = x[ind1];
            ind1++;
            if (ind1 == half){
                endList1 = true;
            }
        }else if (!endList2){
            result[i] = x[ind2];
            ind2++;
            if (ind2 == endd){
                endList2 = true;
            }
        }
    }
    for (int i = 0; i < n; i++){
        x[start] = result[i];
        start++;
    }
}
void merger(int *x, int start, int endd){
    if((endd - start) == 1){
        return;
    }

    int half = (endd-start) / 2;
    half = half + start;
    merger(x, start, half);
    merger(x, half, endd);
    merge_sort(x, start, half, endd);
}

int majority(int *x, int n){
    int counter = 0;
    int num = x[0];
    int major = 0;
    int target = n / 2;
    for (int i = 0; i < n; i++){
        if (num == x[i]){
            counter++;
        }else{
            num = x[i];
            counter = 1;
        }
        if (counter > target){
            major = 1;
            break;
        }
    }
    return major;
}


int main() {
  int n;
  cin >> n;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  //std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';**/
  merger(x, 0, n);
  cout<<majority(x, n)<<endl;
}
