// https://leetcode-cn.com/problems/qiu-12n-lcof/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn sum_nums(n: i32) -> i32 {
        (1..(n + 1)).fold(0, |sum, x| sum + x)
    }
}

fn main() {
    unimplemented!();
}
