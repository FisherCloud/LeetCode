// https://leetcode-cn.com/problems/is-unique-lcci/
use std::collections::HashSet;

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn is_unique(astr: String) -> bool {
        let mut set = HashSet::new();
        for c in astr.chars() {
            if set.insert(c) == false {
                return false;
            }
        }
        true
    }
}

fn main() {
    println!("{:?}", Solution::is_unique("LEETCODEISHIRING".to_string()));
}
