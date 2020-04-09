/// [LeetCode](https://leetcode-cn.com/problems/container-with-most-water/)
/// [题解]()
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut answer = 0i32;
        let mut first = 0usize;
        let mut last = height.len() - 1;
        while first < last {
            let tmp = (last - first) as i32 * height[first].min(height[last]);
            if tmp > answer {
                answer = tmp;
            }
            if height[first] < height[last] {
                first += 1;
            } else {
                last -= 1;
            }
        }
        answer
    }
}

fn main() {
    println!("{:?}", Solution::max_area(5));
}
