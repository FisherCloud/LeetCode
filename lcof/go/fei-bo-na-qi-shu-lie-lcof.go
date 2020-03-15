/*
 * @Author: FisherCloud 
 * @Date: 2020-02-27 18:30:23 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-27 18:49:15
 */
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

package main

func fib(n int) int {
	var dp []int= []int{0, 1}
	for i := 2; i <= n; i++ {
		dp = append(dp, (dp[i - 1] + dp[i - 2]) % 1000000007)
	}
	return dp[n]
}