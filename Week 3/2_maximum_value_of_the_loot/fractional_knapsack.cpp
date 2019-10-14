#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>

using std::vector;




using namespace std;


void merge__sort(double *n, int *weights, int *values, int length){

    int loop = length;
    double sorted[length];
    int sorted_w[length];
    int sorted_v[length];
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
                if (((n[i1] <= n[i2]) && !ismaxi1) || ismaxi2){
                    sorted[k] = n[i1];
                    sorted_v[k] = values[i1];
                    sorted_w[k] = weights[i1];
                    i1 += 1;
                    k++;
                }else{
                    sorted[k] = n[i2];
                    sorted_v[k] = values[i2];
                    sorted_w[k] = weights[i2];
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
                if (((n[i1] <= n[i2]) && !ismaxi1) || ismaxi2){
                        sorted[k] = n[i1];
                        sorted_v[k] = values[i1];
                        sorted_w[k] = weights[i1];
                        i1 += 1;
                        k++;
                }else{
                    sorted[k] = n[i2];
                    sorted_v[k] = values[i2];
                    sorted_w[k] = weights[i2];
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
                sorted_v[i] = values[i];
                sorted_w[i] = weights[i];
            }
        }
        if (remain == 1)
            remain_b = remain;
        // for (int i = 0; i < length; i++){
        //     n[i] = sorted[i];
        // }
        memcpy( (void*)n, (void*)sorted, length * sizeof(double) );
        memcpy( (void*)values, (void*)sorted_v, length * sizeof(int) );
        memcpy( (void*)weights, (void*)sorted_w, length * sizeof(int) );
        if (loop == 0)
            break;
    }
}

double get_optimal_value(int n, int capacity, int *weights, int *values) {
  double value = 0.0;
  double v_w[n];

  for (int i = 0; i < n; i++){
    v_w[i] = (double)values[i]/(double)weights[i];
    /**v_w[i] = roundf(v_w[i]*1000000000000)/1000000000000;**/
  }

  /**for (int i = 0; i < n; i++){
    cout<<v_w[i]<<endl;
  }**/
  merge__sort(v_w, weights, values, n);
  for (int i = n - 1; i >= 0; i--){
    if (capacity > 0){
        if (weights[i] >= capacity){
            value += v_w[i] * (double)capacity;
            capacity = 0;
        }else{
            value += (double)values[i];
            capacity -= weights[i];
        }

    }else{
        break;
    }
  }

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  int values[n];
  int weights[n];
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n, capacity, weights, values);
  /**optimal_value = roundf(optimal_value *1000)/1000;**/
  std::cout << std::fixed;
  std::cout << std::setprecision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
