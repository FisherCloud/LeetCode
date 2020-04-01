// https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![];
        let mut count = 0i32;
        for ch in seq.chars() {
            if ch == '(' {
                count += 1;
                ans.push(count & 1);
            } else {
                ans.push(count & 1);
                count -= 1;
            }
        }
        ans
    }
}

fn main() {
    println!("{:?}", Solution::max_depth_after_split(String::from("(()())")));
}