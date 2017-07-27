//
//  main.cpp
//  7-27希尔排序
//
//  Created by Ruiwen Feng on 2017/7/27.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>



void shellSort(int a[],int num) {
    for (int step = num/2; step>0; step/=2) {
        for (int i = step+1;i < num; i ++) {
            for (int j = i - step; j >= 0 && a[j] >= a[j+step]; j-=step) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}




int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    
    shellSort(a, sizeof(a)/sizeof(int));
    
    for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
        std::cout<<a[i]<<" ";
    }
    
    return 0;
}
