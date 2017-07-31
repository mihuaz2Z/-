//
//  main.cpp
//  7-31.快速
//
//  Created by Ruiwen Feng on 2017/7/31.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>



int devide(int a[],int low,int high){
    
    if (low >= high) {
        return low;
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
    
    
    return left;
}

void sort (int a[],int low,int high) {
    if (low >= high) {
        return;
    }
    int mid = devide(a, low, high);
    sort(a, low, mid-1);
    sort(a, mid+1, high);
}

void quickSort(int a[],int num) {

    sort(a, 0, num-1);
    
}




int main(int argc, const char * argv[]) {
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = 11;

    quickSort(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] <<" ";
    }
    return 0;
}
