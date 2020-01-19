/*
 * @Description: https://leetcode-cn.com/problems/roman-to-integer/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-19 19:44:07
 * @LastEditTime: 2020-01-19 20:54:53
 */

#[derive(Debug)]
struct Solution {
}

use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let map: HashMap<&str, i32> = [("I", 1), ("IV", 4), ("V", 5), ("IX", 9), ("X", 10), ("XL", 40), ("L", 50), ("XC", 90), ("C", 100), ("CD", 400), ("D", 500), ("CM", 900), ("M", 1000)].iter().cloned().collect();
        let mut ans = 0i32;
        let mut one = "0";
        let mut two = "0";
        let mut i = 0usize;
        let len = s.len();
        while i < len {
            one = s.get(i..(i + 1)).unwrap();
            if map.contains_key(&one) {
                if i < len - 1 {
                    two = s.get(i..(i + 2)).unwrap();
                    if map.contains_key(&two) {
                        one = two;
                        i += 1;
                    }
                }
                ans += map.get(&one).unwrap();
                i += 1;
            }
        }
        (ans)
    }
}

fn main() {
    println!("{:?}", Solution::roman_to_int(String::from("MCM"));
}