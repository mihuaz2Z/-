//
//  main.cpp
//  7-29.归并排序2
//
//  Created by Ruiwen Feng on 2017/7/29.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void mergeArray(int a[],int left,int mid,int right) {

    int i = left;
    int j = mid+1;
    int m = mid;
    int n = right;
    int k = 0;
    int temp[12];
    
    while (i <= m && j <= n) {
        
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }

    }
 
    while (i <= m) {
        temp[k++] = a[i++];
    }
    while (j <= n) {
        temp[k++] = a[j++];
    }
    
    for (int z = 0; z < k; z ++) {
        a[left+z] = temp[z];
    }
    
}

void mergeSort(int a[],int left,int right) {
    
    if (left >= right) {
        return;
    }
    
    int mid = (left+right)/2;
    
    mergeSort(a,left,mid);
    mergeSort(a, mid+1, right);
    mergeArray(a, left, mid, right);
}



int main(int argc, const char * argv[]) {
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    mergeSort(a, 0, size-1);
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    return 0;
}
