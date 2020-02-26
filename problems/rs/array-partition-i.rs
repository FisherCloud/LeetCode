/*
 * @Description: https://leetcode-cn.com/problems/array-partition-i/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 20:21:56
 * @LastEditTime: 2020-01-03 20:33:10
 */

fn array_pair_sum(nums: Vec<i32>) -> i32 {
    let mut numbers = nums;
    let mut sum = 0i32;
    let mut index = 0usize;
    numbers.sort();
    loop {
        sum += numbers[index];
        index += 2;
        if index == numbers.len() {
            break;
        }
    }
    (sum)
}

fn main() {
    println!("{:?}", array_pair_sum(vec![1i32, 4, 3, 2]));
}