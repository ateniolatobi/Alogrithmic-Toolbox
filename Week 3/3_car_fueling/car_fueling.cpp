#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

using namespace std;


int compute_min_refills(int n_stops, int dist, int tank, int *stops) {
    // write your code here
    int stop = 0;
    int tank_temp = tank;
    int curr_stop = 0;

    if  (tank >= dist){
        return stop;
    }

    if (tank < stops[0]){
        return -1;
    }

    for (int i = 0; i < n_stops; i++){
        if (i != n_stops - 1){
           if (stops[i+1] > tank){

            if(stops[i+1] > (tank + tank_temp)){
                return -1;
            }
              stop++;
              curr_stop = stops[i];
              tank = stops[i] + tank_temp;
           }
        }else{
            if ((tank >= stops[i]) && (tank < dist)){
                stop++;
                tank =stops[i] + tank_temp;
            }
        }
    }

    if  (tank < dist){
        return -1;
    }
    return stop;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    int stops[n];
    for (size_t i = 0; i < n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(n, d, m, stops) << "\n";

    return 0;
}
