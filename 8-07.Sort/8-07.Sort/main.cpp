//
//  main.cpp
//  8-07.Sort
//
//  Created by Ruiwen Feng on 2017/8/7.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

void swap(int *a,int *b){

    int temp = *a;
    *a = *b;
    *b= temp;

}

void bubbleSort(int a[],int num) {
    
    for (int i = 0; i < num; i ++) {
        for (int j = i + 1; j < num; j ++) {
            if (a[i] > a[j]) {
                swap(a+i, a+j);
            }
        }
    }
    
}

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
    
    quickSort(a,low,left-1);
    quickSort(a,left+1, high);
}

void selectSort (int a[],int num) {
    for (int i = 0; i < num; i++) {
        int min = i;
        for (int j = i + 1; j < num; j ++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a+min, a+i);
        }
    }
}

void adjustHeap (int a[], int num, int parent) {
    
    int left = parent * 2 + 1;
    int right = parent * 2 + 2;
    int max = 0;
    
    if (left > num-1) {
        return;
    }
    else if (right > num-1) {
        max = left;
    }
    else {
        max = a[left] > a[right] ? left:right;
    }
    
    if (a[max] > a[parent]) {
        swap(a+max, a+parent);
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
    
    for (int i = num-1; i>=0; i --) {
        swap(a+i, a);
        adjustHeap(a, i, 0);
    }
    
}

void insertSorrt (int a[],int num) {
    
    for (int i = 0; i < num - 1; i ++) {
        for (int j = i; j >= 0 && a[j+1] <a[j] ; j --) {
            swap(a+j, a+j+1);
        }
    }

}

void shellSort (int a[], int num) {
    
    for (int step = num/2; step > 0; step --) {
        for (int i = step; i < num - step; i += step) {
            for (int j = i; j < num && a[j+step] < a[j]; j -= step) {
                swap(a+j+step, a+j);
            }
        }
    }
}

void mergeArray(int a[],int low,int mid,int high) {

    int i = low;
    int j = mid +1;
    int k = 0;
    int temp[high-low];
    
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    
    while (j <= high) {
        temp[k++] = a[j++];
    }
    
    for (int z = 0; z < k; z ++) {
        a[low+z] = temp[z];
    }
}

void mergeSort (int a[],int left ,int right) {

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
    int size = sizeof(a)/sizeof(int);
    
    mergeSort(a,0,size-1);
    
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << std::endl;
    }
    
    return 0;
}
