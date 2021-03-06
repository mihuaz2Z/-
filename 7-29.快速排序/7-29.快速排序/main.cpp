//
//  main.cpp
//  7-29.快速排序
//
//  Created by Ruiwen Feng on 2017/7/29.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>




void quickSort (int a[],int low ,int high) {

    if (low >= high) {
        return;
    }
    
    int key = a[low];
    int left = low;
    int right = high;
    
    
    while (left < right) {
        while (left < right && a[right] >= key) {
            right--;
        }
        a[left] = a[right];
        while (left < right && a[left] <= key) {
            left ++;
        }
        a[right] = a[left];
    }
    a[left] = key;
    
    quickSort(a, low, left-1);
    quickSort(a, left+1, high);
}


int main(int argc, const char * argv[]) {
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = 11;
    quickSort(a, 0, size-1);
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    
    return 0;
}
