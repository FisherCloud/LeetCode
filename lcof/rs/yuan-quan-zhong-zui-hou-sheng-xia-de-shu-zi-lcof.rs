/// [LeetCode](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/)
/// 约瑟夫环
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn last_remaining(n: i32, m: i32) -> i32 {
        let mut answer = 0i32;
        (1..n).for_each(|i| answer = (m + answer) % (i + 1));
        answer
    }
}

fn main() {
    println!("{}", Solution::last_remaining(5, 3));
}
