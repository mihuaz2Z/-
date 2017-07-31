//
//  main.cpp
//  7-31.希尔
//
//  Created by Ruiwen Feng on 2017/7/31.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void shellSort(int a[],int num) {

    for (int step = (num)/2; step > 0; step /= 2) {
        for (int i = step ; i < num; i += step) {
            for (int j = i - step; j >= 0 && a[j] > a[j+step]; j-= step) {
                int temp = a[j];
                a[j] = a[j+step];
                a[j+step] = temp;
            }
        }
    }
    
}



int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    
    shellSort(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i]<<" ";
    }
    
    return 0;
}
