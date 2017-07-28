//
//  main.cpp
//  7-28.插入排序
//
//  Created by Ruiwen Feng on 2017/7/28.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

void insertSort(int a[],int num) {

    
    for (int i = 1; i < num; i ++) {
        for (int j = i - 1; j >=0 && a[j] > a[j+1]; j --) {
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    insertSort(a, size);
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] <<" ";
    }
    
    return 0;
}
