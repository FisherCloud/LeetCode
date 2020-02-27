/*
 * @Author: FisherCloud 
 * @Date: 2020-02-27 18:20:39 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-27 18:28:24
 */
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn fib(n: i32) -> i32 {
        let mut dp = vec![0i32, 1];
        let len = 1 + n as usize;
        for i in 2..len {
            dp.push((dp[i - 1] + dp[i - 2]) % 1000000007);
        }
        return dp[len - 1];
    }
}
