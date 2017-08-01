//
//  main.cpp
//  8-01.quick
//
//  Created by Ruiwen Feng on 2017/8/1.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void quick(int a[],int low,int high){

    if (low >= high) {
        return;
    }
    
    int key = a[low];
    int left = low;
    int right = high;
    
    while (left < right) {
        
        while (left < right && a[right] >= key) {
            right --;
        }
        a[left] = a[right];
        
        while (left < right && a[left] <= key) {
            left ++;
        }
        a[right] = a[left];
    }
    
    a[left] = key;
    
    
    quick(a, low, left-1);
    quick(a, left+1, high);

}



int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    quick(a,0,size-1);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    
    
    return 0;
}
