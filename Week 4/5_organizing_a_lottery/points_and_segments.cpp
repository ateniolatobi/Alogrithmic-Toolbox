#include <iostream>
#include <vector>

using namespace std;





void merge_sort(int *x, int *y, int start, int half, int endd){
    int n = endd - start;
    int result[n];
    int result2[n];
    int ind1 = start;
    int ind2 = half;
    bool endList1 = false;
    bool endList2 = false;
    for (int i = 0; i < n; i++){
        if (((x[ind1] <= x[ind2]) && !endList1)|| endList2){
            result[i] = x[ind1];
            result2[i] = y[ind1];
            ind1++;
            if (ind1 == half){
                endList1 = true;
            }
        }else if (!endList2){
            result[i] = x[ind2];
            result2[i] = y[ind2];
            ind2++;
            if (ind2 == endd){
                endList2 = true;
            }
        }
    }
    for (int i = 0; i < n; i++){
        x[start] = result[i];
        y[start] = result2[i];
        start++;
    }
}
void merger(int *x, int *y,int start, int endd){
    if((endd - start) == 1){
        return;
    }

    int half = (endd-start) / 2;
    half = half + start;
    merger(x, y, start, half);
    merger(x, y, half, endd);
    merge_sort(x, y, start, half, endd);
}

vector<int> fast_count_segments(int* starts, int* ends, int* points, int n, int m) {
  vector<int> cnt;
  //write your code here
 // cout<<"points size "<<points.size()<<endl;
  for (int i = 0; i < m; i++){
    int point = points[i];
    int counter = 0;
    for (int j = n; j >= 0; j--){
        if (ends[j] >= point){
        //cout<<"This is j "<<j<<" and j is "<<ends[j]<<" point is "<<point<<"also counter is "<<counter<<endl;
            if (point >= starts[j]){
                counter++;

            }
        }else{
            break;
        }
    }
   // cout<<endl;
    cnt.push_back(counter);
  }
  return cnt;
}
/**
vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

vector<vector <int>> merger(vector<vector <int>> f_half, vector<vector <int>> s_half){

    vector <int> sf_half = f_half[0];
    vector <int> ef_half = f_half[1];

    vector <int> ss_half = s_half[0];
    vector <int> es_half = s_half[1];

    int n = ef_half.size() + es_half.size();
    //cout<<"The value of n is "<<n<<endl;
    vector <int> start;
    vector <int> endd;
    for (size_t i = 0; i < n; i++){
        if (((ef_half.size() != 0) && (ef_half[0] <= es_half[0])) || (es_half.size() == 0)){
            endd.push_back(ef_half[0]);
            start.push_back(sf_half[0]);
            ef_half.erase(ef_half.begin());
            sf_half.erase(sf_half.begin());

        }else{
            endd.push_back(es_half[0]);
            start.push_back(ss_half[0]);
            es_half.erase(es_half.begin());
            ss_half.erase(ss_half.begin());

        }
    }

    vector <vector <int>> sorted = {start, endd};
    return sorted;

}
vector <vector <int>> arrange_segments(vector <int> start, vector <int> ends){


    if (ends.size() == 1){
        vector <vector <int>> a = {start, ends};
        return a;
    }

    int len = start.size();
    int half = len / 2;
    vector <int> start_1;
    vector <int> start_2;

    vector <int> ends_1;
    vector <int> ends_2;

    for (size_t i = 0; i < half; i++) {
        start_1.push_back(start[i]);
        ends_1.push_back(ends[i]);
    }

    for (size_t i = half; i < len; i++) {
        start_2.push_back(start[i]);
        ends_2.push_back(ends[i]);
    }

    vector <vector <int>> sorted_start = arrange_segments(start_1, ends_1);
    vector <vector <int>> sorted_end = arrange_segments(start_2, ends_2);
    return merger(sorted_start, sorted_end);
}
**/
int main() {
  int n, m;
  std::cin >> n >> m;
  int starts[n], ends[n];
  for (int i = 0; i < n; i++) {
    std::cin >> starts[i] >> ends[i];
  }
  int points[m];

  for (int i = 0; i < m; i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  merger(ends, starts, 0, n);
  //vector <vector <int> > sortd_segs = arrange_segments(starts, ends);
  //vector<int> cnt = naive_count_segments(starts, ends, points);

  /**starts = sortd_segs[0];
  ends = sortd_segs[1];**/
  /**cout<<"Length is "<<sortd_segs.size()<<endl;**/
  /**for (int i = 0; i < n; i++){
    cout<<"Sorted "<<i+1<<" as "<<starts[i]<< "  "<<ends[i]<<endl;
  }**/

  vector<int> cnt = fast_count_segments(starts, ends, points, n-1, m);
   for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
