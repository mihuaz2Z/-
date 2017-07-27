//
//  main.cpp
//  7-27.快排
//
//  Created by Ruiwen Feng on 2017/7/27.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


void quickSort(vector<int>*nums,int low,int high){

    if (high <= low) {
        return;
    }
    
    int key = (*nums)[low];
    int left = low;
    int right = high;
    
    while (left<right) {
        
        while (left<right&&(*nums)[right]>=key) {
            right--;
        }
        (*nums)[left] = (*nums)[right];
        while (left<right&&(*nums)[left]<=key) {
            left++;
        }
        (*nums)[right] = (*nums)[left];
    }
    (*nums)[left] = key;
    
    quickSort(nums, low, left-1);
    quickSort(nums, left+1, high);
}



int main(int argc, const char * argv[]) {
    
    vector<int> nums = {1,2,3,1,2,3,5};
    quickSort(&nums, 0, (int)nums.size()-1);
    
    for (int i = 0; i < nums.size(); i ++) {
        std::cout << nums[i] << " ";
    }
    
    return 0;
}
