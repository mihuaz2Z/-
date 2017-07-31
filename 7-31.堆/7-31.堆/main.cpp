//
//  main.cpp
//  7-31.堆
//
//  Created by Ruiwen Feng on 2017/7/31.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

void adjustHeap(int a[],int num,int parent) {
    
    int left = parent*2+1;
    int right = parent*2+2;
    int max_c = 0;
    
    if (left > num-1) {
        return;
    }
    else if (right > num-1) {
        max_c = left;
    }
    else {
        max_c = a[left] >= a[right] ? left : right;
    }

    if (a[parent] < a[max_c]) {
        int temp = a[parent];
        a[parent] = a[max_c];
        a[max_c] = temp;
        
        adjustHeap(a, num, max_c);
    }

}

void heapSort(int a[],int num){

    if (num < 2) {
        return;
    }
    
    for (int i = (num-1)/2; i >=0; i --) {
        adjustHeap(a, num, i);
    }
    
    for (int i = num-1; i > 0; i --) {
        
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        adjustHeap(a,i,0);
        
    }
    
}




int main(int argc, const char * argv[]) {
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    
    heapSort(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i]<<" ";
    }
    return 0;
}
