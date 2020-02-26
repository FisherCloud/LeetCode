/*
 * @Description: https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-05 19:36:15
 * @LastEditTime: 2020-01-05 20:41:56
 */

#[derive(Debug)]
struct Solution {
}

use std::collections::{ HashMap, HashSet };

impl Solution {
    /**
     *  执行用时 :16 ms, 在所有 Rust 提交中击败了100.00%的用户
     *  内存消耗 :2.3 MB, 在所有 Rust 提交中击败了100.00%的用户
     */
    // pub fn repeated_n_times(a: Vec<i32>) -> i32 {
    //     let mut map: HashMap<i32, i32> = HashMap::new();

    //     let n = a.len() / 2;
    //     for item in a {
    //         if map.contains_key(&item) {
    //             if let Some(x) = map.get_mut(&item) {
    //                 *x += 1;
    //             }
    //         } else {
    //             map.insert(item, 1);
    //         }
    //     }

    //     for (key, val) in map.iter() {
    //         // println!("{:?}", (n, *key, *val));
    //         if n as i32 == *val {
    //             return *key;
    //         }
    //     }

    //     0
    // }

    // 4ms,2.1mb
    // pub fn repeated_n_times(a: Vec<i32>) -> i32 {
    //     let mut set = HashSet::new();
    //     for item in a {
    //         if set.contains(&item) {
    //             return item;
    //         } else {
    //             set.insert(item);
    //         }
    //     }
    //     0i32
    // }

    // 4ms,2mb
    // pub fn repeated_n_times(a: Vec<i32>) -> i32 {
    //     let mut arr: Vec<i32> = vec![];
    //     for item in a {
    //         if arr.contains(&item) {
    //             arr.clear();
    //             return item;
    //         } else {
    //             arr.push(item);
    //         }
    //     }
    //     0i32
    // }

    // 0ms,2.1mb
    pub fn repeated_n_times(a: Vec<i32>) -> i32 {
        let len = a.len();
        for i in 0..(len - 2) {
            if a[i] == a[i + 1] || a[i] == a[i + 2] {
                return a[i];
            }
        }
        a[len - 1]
    }
}

fn main() {
    println!("{:?}", Solution::repeated_n_times(vec![1, 2, 3, 3]));
}
