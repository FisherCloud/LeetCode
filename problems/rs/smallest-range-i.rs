/*
 * @Description: https://leetcode-cn.com/problems/smallest-range-i/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-04 13:26:27
 * @LastEditTime: 2020-01-04 14:06:23
 */

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn smallest_range_i(a: Vec<i32>, k: i32) -> i32 {
        let x = a.iter().max().unwrap();
        let y = a.iter().min().unwrap();
        let ans = x - y - 2 * k;
        if ans <= 0 { // 小于0必然有0为最小差值
            return 0;
        } else {
            return ans;
        }
    }
}

fn main() {
    println!("{:?}", Solution::smallest_range_i(vec![1, 3, 6], 3));
}
