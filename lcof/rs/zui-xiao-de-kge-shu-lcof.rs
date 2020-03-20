// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn get_least_numbers(arr: Vec<i32>, k: i32) -> Vec<i32> {
        let mut tmp = arr;
        tmp.sort();
        tmp.resize(k as usize, 0);
        tmp
    }
}

fn main() {
    
}
