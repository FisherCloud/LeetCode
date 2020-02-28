/*
 * @Author: FisherCloud 
 * @Date: 2020-02-28 20:02:23 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-28 20:07:16
 */
// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn num_ways(n: i32) -> i32 {
        let mut dp = vec![1, 1];
        let len = n as usize;
        for i in 2..(len + 1) {
            dp.push((dp[i - 1] + dp[i - 2]) % 1000000007);
        }
        return dp[len];
    }
}
