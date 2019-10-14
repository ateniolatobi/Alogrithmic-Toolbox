#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>

using std::vector;

using namespace std;

struct Segment {
  int start, end;
};

void merge__sort(Segment *n, int length){

    int loop = length;
    Segment sorted[length];
    int sep = 2;
    int remain_b = 0;
    int items = 1;
    int remain;

    while (true){
        remain = loop % sep;
        loop = loop / sep;
        items = items * 2;
        int i1 = 0;
        int i2 = items/2;
        int temp_i1 = i1;
        int temp_i2 = i2;
        int k = 0;
        for (int i =0;i < loop; i++){
            i1 = temp_i1;
            i2 = temp_i2;
            bool ismaxi1 = false;
            bool ismaxi2 = false;
            for(int j = 0; j < items; j++){
                if (((n[i1].start <= n[i2].start) && !ismaxi1) || ismaxi2){
                    sorted[k] = n[i1];
                    i1 += 1;
                    k++;
                }else{
                    sorted[k] = n[i2];
                    i2 += 1;
                    k++;
                }
                if (i1 == temp_i2){
                    ismaxi1 = true;
                }
                if (i2 == (items/2+temp_i2)){
                    ismaxi2 = true;
                }
            }
            temp_i1 += items;
            temp_i2 += items;
        }


        if ((remain_b == 1) && (remain == 1)){
            i1 = loop * items;
            if (loop == 0){
                i1 = 0;
                k = 0;
            }
            i2 = i1 + items / 2;
            int range = length - i1;
            temp_i1 =i1;
            temp_i2 =i2;
            bool ismaxi1 = false;
            bool ismaxi2 = false;
            for  (int i = 0; i < range; i++){
                if (((n[i1].start <= n[i2].start) && !ismaxi1) || ismaxi2){
                        sorted[k] = n[i1];
                        i1 += 1;
                        k++;
                }else{
                    sorted[k] = n[i2];
                    i2 += 1;
                    k++;
                }
                if (i1 == temp_i2){
                    ismaxi1 = true;
                }
                if (i2 == length){
                    ismaxi2 = true;
                }
            }
        }else{
            for (int i  = loop * items; i <length; i++){
                sorted[i] = n[i];
            }
        }
        if (remain == 1)
            remain_b = remain;
        // for (int i = 0; i < length; i++){
        //     n[i] = sorted[i];
        // }
        memcpy( (void*)n, (void*)sorted, length * sizeof(Segment) );
        if (loop == 0)
            break;
    }
}


vector<int> optimal_points(int n, Segment *seg) {
  vector<int> points;
  //write your code here
  /**
  for (int  i = 0; i < n; ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  **/
  merge__sort(seg, n);
  int limit[2];
  limit[0] = seg[0].start;
  limit[1] = seg[0].end;
  for (int i = 1; i < n; i++){

    if ((limit[1] - seg[i].start) >= 0){
        limit[0] = seg[i].start;

        if (seg[i].end < limit[1] ){
            limit[1]  = seg[i].end;
        }
    }else{
        points.push_back(limit[0]);
        limit[0] = seg[i].start;
        limit[1] = seg[i].end;
    }
  }
  points.push_back(limit[0]);
  return points;
}

int main() {
  int n;
  std::cin >> n;
  Segment segments[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(n, segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
