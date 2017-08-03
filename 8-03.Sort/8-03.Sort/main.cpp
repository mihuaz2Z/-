//
//  main.cpp
//  8-03.Sort
//
//  Created by Ruiwen Feng on 2017/8/3.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void swap(int*a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[],int num) {
    for (int i = 0; i < num; i ++) {
        for (int j = i +1; j < num; j ++) {
            if (a[i] > a[j]) {
                swap(a+i, a+j);
            }
        }
    }
}

void selectSort(int a[],int num) {
    for (int i = 0; i < num -1; i ++) {
        int min = i;
        for (int j = i +1; j < num; j ++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a+min, a+i);
        }
    }
}

void insertSort(int a[],int num) {
    for (int i = 0; i < num-1; i ++) {
        for (int j = i + 1; j >= 1 && a[j-1] > a[j]; j--) {
            swap(a+j, a+j-1);
        }
    }
}

void sheelSort(int a[],int num) {
    for (int step = num/2; step > 0; step/=2) {
        for (int i = step; i < num-step; i += step) {
            for (int j = i + step; j >= step && a[j-step] > a[j]; j-=step) {
                swap(a+j, a+j-step);
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    
    sheelSort(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    
    
    
    return 0;
}
