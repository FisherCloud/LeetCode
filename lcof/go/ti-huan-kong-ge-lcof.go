/*
 * @Author: FisherCloud 
 * @Date: 2020-02-26 18:45:08 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-26 19:33:19
 */
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
package main

import (
	"fmt"
)

func replaceSpace(s string) string {
	var ans string
	for i := 0; i < len(s); i++ {
		if ' ' == s[i] {
			ans += "%20"
		} else {
			ans += string(s[i])
		}
	}
	return ans
}

func main() {
    fmt.Println(replaceSpace("We are happy."))
}
