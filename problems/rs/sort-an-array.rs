// https://leetcode-cn.com/problems/sort-an-array/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let mut nums_copy = nums;
        /* 库函数 */
        // nums_copy.sort(); 

        // 快排
        nums_copy = Self::quick_sort(nums_copy);
        
        // 归并

        // 堆排序

        // Return sorted array
        nums_copy
    }
    //========================================
    /** 快排 **/
    pub fn quick_sort(nums: Vec<i32>) -> Vec<i32> {
        if nums.len() <= 1 {
            return nums;
        }
        let mut vec1: Vec<i32> = Vec::new();
        let mut vec2: Vec<i32> = Vec::new();
        for  i in 1..nums.len() {
            if nums[i] >= nums[0] {
                vec2.push(nums[i]);
            } else {
                vec1.push(nums[i]);
            }
        }
        let mut result = Self::quick_sort(vec1);
        result.push(nums[0]);
        result.append(&mut Self::quick_sort(vec2));
        result
    }
    //========================================
}

fn main() {
    unimplemented!();
}
