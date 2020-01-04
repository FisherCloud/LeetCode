/*
 * @Description: https://leetcode-cn.com/problems/sort-array-by-parity-ii/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-04 14:28:29
 * @LastEditTime: 2020-01-04 14:38:09
 */

#[derive(Debug)]
struct Solution {
}

use std::collections::VecDeque;

impl Solution {
    pub fn sort_array_by_parity_ii(a: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![];
        let mut queue: VecDeque<i32> = VecDeque::new();
        for item in a {
            if 0 == item & 0x01 {
                queue.push_front(item); // 偶数放前面
            } else {
                queue.push_back(item); // 奇数放后面
            }
        }

        while !queue.is_empty() {
            ans.push(queue.pop_front().unwrap()); // 偶数位置放偶数
            ans.push(queue.pop_back().unwrap()); // 奇数位置放奇数
        }

        (ans)
    }
}

fn main() {
    
}