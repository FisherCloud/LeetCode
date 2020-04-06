/// [LeetCode](https://leetcode-cn.com/problems/edit-distance/)
/// [官方题解](https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-by-leetcode-solution/)

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let mut distance = 0i32;
        let m = word1.len();
        let n = word2.len();
        if word1.is_empty() || word2.is_empty() {
            distance = (m + n) as i32;
        } else {
            let word1_tmp = word1.chars().collect::<Vec<_>>();
            let word2_tmp = word2.chars().collect::<Vec<_>>();
            let mut dp = vec![vec![0; n + 1]; m + 1];
            for i in 0..=m {
                dp[i][0] = i;
            }

            for j in 0..=n {
                dp[0][j] = j;
            }

            for i in 1..=m {
                for j in 1..=n {
                    let left = dp[i - 1][j] + 1;
                    let down =dp[i][j - 1] + 1;
                    let mut left_down = dp[i - 1][j - 1];
                    if word1_tmp[i - 1] != word2_tmp[j - 1] {
                        left_down += 1;
                    }
                    dp[i][j] = left.min(down.min(left_down));
                }
            }
            distance = dp[m][n] as i32;
        }
        distance
    }
}

fn main() {
    println!("{:?}", Solution::min_distance("horse".to_string(), "ros".to_string()));
}
