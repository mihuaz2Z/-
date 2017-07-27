//
//  main.cpp
//  快速排序
//
//  Created by Ruiwen Feng on 2017/7/26.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



void quickSort(vector<int> *nums,int left,int right){

    if (left < right) {
        int key = (*nums)[left];//以最左边为基准。
        int low = left;
        int high = right;
        while(low < high){
            while(low < high && (*nums)[high] >= key){
                high--;
            }
            (*nums)[low] = (*nums)[high];
            while(low < high && (*nums)[low] <= key){
                low++;
            }
            (*nums)[high] = (*nums)[low];
        }
        (*nums)[low] = key;
        

        quickSort(nums, left, low-1);
        quickSort(nums, low+1, right);
    }
}




int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,3,2,1};
    quickSort(&nums,0,(int)nums.size()-1);
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<endl;
    }

    return 0;
}
