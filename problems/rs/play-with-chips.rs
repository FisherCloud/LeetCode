/*
 * @Description: https://leetcode-cn.com/problems/play-with-chips/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-04 15:49:48
 * @LastEditTime: 2020-01-04 15:56:00
 */

#[derive(Debug)]
struct Solution {
}

use std::cmp::min;

impl Solution {
    pub fn min_cost_to_move_chips(chips: Vec<i32>) -> i32 {
        let mut even_count = 0i32;
        let len = chips.len();
        
        for item in chips {
            if 0 == item & 0x01 {
                even_count += 1;
            }
        }

        min(even_count, len as i32 - even_count)
    }
}

fn main() {
    println!("{:?}", Solution::min_cost_to_move_chips(vec![1, 2, 3, 4, 5]));
}