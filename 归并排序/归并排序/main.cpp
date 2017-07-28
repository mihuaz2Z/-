//
//  main.cpp
//  归并排序
//
//  Created by Ruiwen Feng on 2017/7/28.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void mergeArray(int a[],int left,int mid,int right,int result[]){
    
    int i = left;
    int j = mid +1;
    int m = mid;
    int n = right;
    int k = 0;
    
    //合并到result
    while (i <= m && j <= n) {
        if (a[i] <= a[j]) {
            result[k++] = a[i++];
        }
        else
        {
            result[k++] = a[j++];
        }
    }
    
    //把剩余的补到背后。
    while (i <= m) {
        result[k++] = a[i++];
    }
    while (j <= n) {
        result[k++] = a[j++];
    }

    //再把它补回原数组
    for (int i = 0; i < k; i++) {
        a[left+i] = result[i];
    }
    
    
}


void mergeSort(int a[], int left, int right, int temp[]){
    
    if (left < right) {
        int mid = (left+right)/2;
        mergeSort(a, left, mid, temp);
        mergeSort(a, mid+1, right, temp);
        mergeArray(a, left, mid, right, temp);
    }
    
}


int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    int c[size];
    
    mergeSort(a,0,size-1,c);
    
    for (int i = 0; i < size; i ++) {
        std::cout << i << " "<< a[i] << " " <<std::endl;
    }
    std::cout << std::endl;
    return 0;
}
