//
//  main.cpp
//  8-01.heap
//
//  Created by Ruiwen Feng on 2017/8/1.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

void adjustHeap (int a[],int num, int parent){

    int left = parent*2+1;
    int right = parent*2+2;
    int max = 0;
    if (left > num-1) {
        return;
    }
    else if (right > num -1) {
        max = left;
    }
    else {
        max = a[left] >= a[right] ? left : right;
    }
    
    if (a[max] > a[parent]) {
        int temp = a[max];
        a[max] = a[parent];
        a[parent] = temp;
        
        adjustHeap(a, num, max);
    }
}

void heapSort (int a[], int num){

    if (num < 2) {
        return;
    }
    
    for ( int i = (num-1)/2; i >= 0; i --) {
        adjustHeap(a, num, i);
    }
    
    for (int i = num - 1; i >= 1; i --) {
        
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        
        adjustHeap(a,i,0);
    }
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    heapSort(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    
    
    return 0;
}
