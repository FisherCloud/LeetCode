/*
 * @Author: FisherCloud 
 * @Date: 2020-02-28 20:14:15 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-28 20:16:33
 */
//  https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/

package main

func numWays(n int) int {
	var dp []int = []int{1, 1}
	for i := 2; i <= n; i++ {
		dp = append(dp, (dp[i - 1] + dp[i - 2]) % 1000000007);
	}
	return dp[n];
}
