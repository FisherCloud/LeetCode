// https://leetcode-cn.com/problems/search-insert-position
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        nums.iter().filter(|&&x| x < target).fold(0, |acc, x| acc + 1)
    }
}

fn main() {
    unimplemented!();
}
