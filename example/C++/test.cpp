#include <iostream>
#include "shad5/include/shad5.hpp"
using namespace std;

int main(void){
    int t[10]{1,2,3,4,5,6,7,8,9,10};
    
    shad5 sh5 = shad5(10,&t[0]);
    sh5.sh5_encrypt();
    for(size_t i = 0; i < sh5.size(); ++i){
        cout<<sh5[i] << " ";
    }
    cout<<endl;
    sh5.sh5_decrypt();
    for(size_t i = 0; i < sh5.size(); ++i){
        cout<<sh5[i] << " ";
    }
}