//
//  main.cpp
//  7-28.冒泡
//
//  Created by Ruiwen Feng on 2017/7/28.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void bubbleSort(int a[],int num){
    
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j ++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    bubbleSort(a,size);
    
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    
    return 0;
}
