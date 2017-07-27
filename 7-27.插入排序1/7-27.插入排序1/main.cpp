//
//  main.cpp
//  7-27.插入排序1
//
//  Created by Ruiwen Feng on 2017/7/27.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void inserSort(int a[],int num) {
    
    for (int i = 1; i < num; i ++) {
        for (int j = i-1; j >= 0 && a[j] >= a[j+1]; j--) {
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
}



int main(int argc, const char * argv[]) {
    
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    
    inserSort(a, sizeof(a)/sizeof(int));
    
    for (int i = 0; i < sizeof(a)/sizeof(int); i ++) {
        std::cout << a[i] << " ";
    }
    
    return 0;
}
