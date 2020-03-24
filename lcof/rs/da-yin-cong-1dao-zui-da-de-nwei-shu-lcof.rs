// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn print_numbers(n: i32) -> Vec<i32> {
        (1..).take(10i32.pow(n as u32) as usize - 1).collect::<Vec<i32>>()
    }
}

fn main() {
    unimplemented!();
}
