//
//  main.cpp
//  7-27.插入排序
//
//  Created by Ruiwen Feng on 2017/7/27.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

void insertSort(int a[],int num){
    

    for (int i = 1; i < num; i ++) {
        for (int j = i -1; j >= 0 && a[j+1] <= a[j]; j--) {
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    int a[] = {5,2,3,1,4};
    for (int i = 0;i < sizeof(a)/sizeof(int); i++) {
        std::cout<< a[i] << " ";
    }
    std::cout <<std::endl;
    insertSort(a,sizeof(a)/sizeof(int));
    
    for (int i = 0;i < sizeof(a)/sizeof(int); i++) {
        std::cout<< a[i] << " ";
    }
    std::cout <<std::endl;
    return 0;
}
