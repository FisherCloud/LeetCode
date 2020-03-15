// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn min_array(numbers: Vec<i32>) -> i32 {
        let mut left = 0usize;        
        let mut right = numbers.len() - 1usize;

        while left < right {
            let mid = (left + right) >> 1;
            if numbers[mid] > numbers[right] {
                left = mid + 1;
            } else if numbers[mid] == numbers[right] {
                right -= 1;
            } else {
                right = mid;
            }
        }

        numbers[left]
    }
}

fn main() {
    let nums = vec![3, 4, 5, 1, 2];
    println!("{:?}", Solution::min_array(nums));
}