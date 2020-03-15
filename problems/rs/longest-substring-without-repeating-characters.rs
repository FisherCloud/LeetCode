/*
 * @Description: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-06 14:29:59
 * @LastEditTime: 2020-01-06 15:02:57
 */

#[derive(Debug)]
struct Solution {
}

use std::collections::VecDeque;

impl Solution {
    // 4ms. 2.2mb
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut queue: VecDeque<u8> = VecDeque::new();
        let mut count: Vec<i32> = Vec::new();

        for item in s.bytes() {
            if queue.contains(&item) {
                let len = queue.len();
                count.push(len as i32);
                while queue.contains(&item) {
                    queue.pop_front();
                }
            }
            queue.push_back(item);
        }
        let len = queue.len();
        count.push(len as i32);

        (*count.iter().max().unwrap())
    }
}

fn main() {
    println!("{:?}", Solution::length_of_longest_substring(String::from("pwwkew")));
}
