//
//  main.cpp
//  8-01.insert
//
//  Created by Ruiwen Feng on 2017/8/1.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void insert(int a[],int num) {

    for (int i = 0; i < num - 1; i ++) {
        for (int j = i + 1; j >=1 && a[j-1] > a[j] ; j--) {
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    insert(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    
    
    return 0;
}
