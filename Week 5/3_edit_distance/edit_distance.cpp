#include <iostream>
#include <string>

using namespace std;






int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int len1 = str1.length() + 1;
  int len2 = str2.length() + 1;

  int str_mat[len1][len2];
    for (int j = 0; j < len2; j++){
        str_mat[0][j] = j;
    }
  for (int i =1; i < len1; i++){
    str_mat[i][0] = i;
  }

  for (int i = 0; i < len1; i++){
    for(int j = 0; j <len2; j++){

    }
  }

  for (int i = 1; i < len1; i++){
    for (int j = 1; j < len2; j++){
        if (str1[i - 1] == str2[j - 1]){
            str_mat[i][j] = str_mat[i - 1][j - 1];
            continue;
        }
        if ((str_mat[i-1][j] <= str_mat[i][j-1]) && (str_mat[i-1][j] <= str_mat[i-1][j-1])){
            str_mat[i][j] = str_mat[i-1][j] + 1;
        }else if ((str_mat[i][j-1] <= str_mat[i-1][j-1]) && (str_mat[i][j-1] <= str_mat[i-1][j])){
            str_mat[i][j] = str_mat[i][j-1] + 1;
        }else{
            str_mat[i][j] = str_mat[i-1][j-1] + 1;
        }

        /**if ((i == 3) && (j == 3)){
            cout<<"last one "<<str_mat[i][j]<<endl;
            cout<<"left "<<str_mat[i][j-1]<<endl;
            cout<<"top "<<str_mat[i-1][j]<<endl;
            cout<<"skew "<<str_mat[i-1][j-1]<<endl;
            cout<<"str1 "<<str1[i -1]<<endl;
            cout<<"str2 "<<str2[j - 1]<<endl;
        }**/
    }
  }
/**
  for (int i = 0; i < len1; i++){
    for(int j = 0; j <len2; j++){
        cout<<str_mat[i][j]<< " ";
    }
    cout<<endl;
  }**/

  //cout<<"oh yeah "<<len1<<endl;
  //cout<<"Oh no "<<len2<<endl;
  return str_mat[len1 - 1][len2 - 1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  //cout<<str1.length()<<endl;
  return 0;
}
