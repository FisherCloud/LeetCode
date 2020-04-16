// https://leetcode-cn.com/problems/merge-intervals/
struct Solution;

impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut intervals_copy = intervals.clone();
        intervals_copy.sort();
        let mut merged: Vec<Vec<i32>> = Vec::new();
        for i in 0..(intervals_copy.len()) {
            let l = intervals_copy[i][0];
            let r = intervals_copy[i][1];
            let len = merged.len();
            if merged.is_empty() || merged[len - 1][1] < l {
                merged.push(vec![l, r]);
            } else {
                merged[len - 1][1] = merged[len - 1][1].max(r);
            }
        }
        merged
    }
}

fn main() {
    println!("{:?}", Solution::merge(vec![vec![1, 3], vec![2, 6], vec![8, 10], vec![15, 18]]));
}
