//
//  main.cpp
//  8-10.Sort
//
//  Created by Ruiwen Feng on 2017/8/10.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

void quickSort(int a[],int low, int high) {
    
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

void mergeArray(int a[],int left,int mid,int right) {
    
    int i = left;
    int j = mid + 1;
    int temp[right-left];
    int index = 0;
    
    while (i <= mid && j <= right) {
        if (a[i] <= a[right]) {
            temp[index++] = a[i++];
        }
        else
        {
            temp[index++] = a[j++];
        }
    }
    
    while (i <= mid) {
        temp[index++] = a[i++];
    }
    
    while (j <= right) {
        temp[index++] = a[j++];
    }
    
    for (int k = 0; k < index; k ++) {
        a[left+k] = temp[k];
    }
}

void mergeSort(int a[],int left,int right){
    
    if (left >= right) {
        return;
    }
    
    int mid = (left + right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);

    mergeArray(a, left, mid, right);
    
}

void adjustHeap (int a[],int num, int parent) {

    int left = parent * 2 + 1;
    int right = parent * 2 + 2;
    int max = 0;
    
    if (left >= num-1) {
        return;
    }
    else if (right >= num-1)
    {
        max = left;
    }
    else
    {
        max = a[left] > a[right] ? left : right;
    }
    
    if (a[max] > a[parent]) {
        int temp = a[max];
        a[max] = a[parent];
        a[parent] = temp;
        adjustHeap(a, num, max);
    }
}

void heapSort(int a[], int num) {
    
    if (num < 2) {
        return;
    }
    
    for (int i = (num-1)/2; i >= 0; i --) {
        adjustHeap(a, num, i);
    }

    for (int i = num-1; i >= 0; i --) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjustHeap(a, i, 0);
    }
    
}


int main(int argc, const char * argv[]) {
    
    int a[] = {9,8,7,6,5};
    int size = 5;
    
    heapSort(a,size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    
    
    return 0;
}
