// https://leetcode-cn.com/problems/longest-palindrome/

use std::collections::HashMap;

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let len = s.len();
        let mut chars: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            if chars.contains_key(&c) {
                if let Some(n) = chars.get_mut(&c) {
                    *n += 1i32;
                }
            } else { chars.insert(c, 1i32); }
        }

        let mut count = 0;
        for val in chars.values() {
            if val % 2 == 1 { count += 1; } else { count += 0;}
        }

        if count == 0 { return len as i32; } else { return len as i32 - count + 1; }
    }
}

fn main() {
    println!("{:?}", Solution::longest_palindrome(String::from("abccccdd")));
}