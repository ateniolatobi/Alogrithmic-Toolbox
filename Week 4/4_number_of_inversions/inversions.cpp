#include <iostream>
#include <vector>

using std::vector;
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}


int merge_sort(int *x, int start, int half, int endd){
    int n = endd - start;
    int result[n];
    int ind1 = start;
    int ind2 = half;
    bool endList1 = false;
    bool endList2 = false;
    int inver_count = 0;
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

            if (!endList1){
                inver_count += (half - ind1);
            }
        }
    }
    for (int i = 0; i < n; i++){
        x[start] = result[i];
        start++;
    }

    return inver_count;
}
int merger(int *x, int start, int endd){
    if((endd - start) == 1){
        return 0;
    }

    int half = (endd-start) / 2;
    half = half + start;
    int i, j, k;
    i =merger(x, start, half);
    j = merger(x, half, endd);
    k = merge_sort(x, start, half, endd);
    return i+j+k;
}


int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::cout << merger(a, 0, n) << '\n';
}
