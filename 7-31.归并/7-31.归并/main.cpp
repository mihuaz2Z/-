//
//  main.cpp
//  7-31.归并
//
//  Created by Ruiwen Feng on 2017/7/31.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

void mergeArray(int a[],int left,int mid,int right) {
    
    int temp[right-left];
    int k = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    
    while (i<=mid) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int i = 0; i < k; i ++) {
        a[left+i] = temp[i];
    }
}

void mergeSort(int a[],int left,int right){

    if (left >= right) {
        return;
    }
    int mid = (left+right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    mergeArray(a, left, mid, right);
}


int main(int argc, const char * argv[]) {
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = 11;

    mergeSort(a,0, size-1);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] <<" ";
    }
    return 0;
}
