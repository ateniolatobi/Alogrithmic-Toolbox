#include <iostream>
#include <cstring>

using namespace std;

void merge__sort(int *n, int length){

    int loop = length;
    int sorted[length];
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
                if (((n[i1] <= n[i2]) && !ismaxi1) || ismaxi2){
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
        memcpy( (void*)n, (void*)sorted, length * sizeof(int) );
        if (loop == 0)
            break;
    }
}


int main(){
    int l =  28;
    int i[l] = {7, 6, 5,4,3,2,1,7, 6, 5,4,3,2,1,7, 6, 5,4,3,2,1,7, 6, 5,4,3,2,1};
    merge__sort(i, l);
     for (int j = 0; j < 28; j++){
        cout<<i[j]<<endl;
    }

    return 0;
}
