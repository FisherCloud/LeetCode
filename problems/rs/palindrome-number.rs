/*
 * @Description: https://leetcode-cn.com/problems/palindrome-number/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-18 13:22:58
 * @LastEditTime: 2020-01-18 13:40:33
 */

#[derive(Debug)]
struct Solution {
}

impl Solution {
    // 4ms
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        let mut tmp = 0i32;
        let mut xxx = x;
        while xxx > 0 {
            tmp *= 10;
            tmp += xxx % 10;
            xxx /= 10;
        }
        
        if tmp == x {
            return true;
        } else {
            return false;
        }
    }
}

fn main() {
    println!("{:?}", Solution::is_palindrome(12302));
}