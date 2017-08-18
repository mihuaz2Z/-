//
//  main.cpp
//  8-18.Sort
//
//  Created by Ruiwen Feng on 2017/8/18.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void quickSort (int a[],int low,int high) {
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
    
    quickSort(a, low, left-1);
    quickSort(a, left+1,high);
}


void mergeArray(int a[],int low,int mid,int high) {
    
    int i = low;
    int j = mid + 1;
    int index = 0;
    int temp[high-low];
    
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
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
    while (j < high) {
        temp[index++] = a[j++];
    }
    
    for (int k = 0; k < index; k++) {
        a[low+k] = temp[k];
    }
}

void mergeSort(int a[],int low,int high) {

    if (low >= high) {
        return;
    }
    int mid = (low+high)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    mergeArray(a, low, mid, high);
}


void adjustHeap (int a[],int num,int parent) {

    int left = parent * 2 + 1;
    int right = parent * 2 + 2;
    int max = 0;
    
    if (left > num-1) {
        return;
    }
    else if(right > num-1){
        max = left;
    }
    else {
        max = a[left] > a[right] ? left:right;
    }
    
    if (a[max] > a[parent]) {
        int temp = a[max];
        a[max] = a[parent];
        a[parent] = temp;
        
        adjustHeap(a, num, max);
    }
}

void heapSort (int a[],int num) {
    
    if (num < 2) {
        return;
    }
    
    for (int i = (num-1)/2; i >= 0; i --) {
        adjustHeap(a, num, i);
    }
    
    for (int i = num-1; i >= 1; i --) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjustHeap(a, i, 0);
    }
    
}


void shellSort(int a[],int num) {
    
    for (int step = num/2; step > 0; step /= 2) {
        for (int i = step; i < num-step; i += step) {
            for (int j = i + step; j >= step && a[j-1] > a[j]; j -= step) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    
}


int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    
    shellSort(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";

    }
    
    return 0;
}
