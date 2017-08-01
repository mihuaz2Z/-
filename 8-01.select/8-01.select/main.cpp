//
//  main.cpp
//  8-01.select
//
//  Created by Ruiwen Feng on 2017/8/1.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>


void selectSort(int a[],int num) {

   
    
    for (int i = 0; i < num; i ++) {
        int min = i;
        for (int j = i + 1; j < num; j ++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    

}



int main(int argc, const char * argv[]) {
    
    int a[] = {1,3,5,3,8,2,1,7,8,6,5};
    int size = sizeof(a)/sizeof(int);
    selectSort(a, size);
    
    for (int i = 0; i < size; i ++) {
        std::cout << a[i] << " ";
    }
    
    
    return 0;
}
