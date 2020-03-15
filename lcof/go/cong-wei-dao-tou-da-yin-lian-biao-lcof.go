/*
 * @Author: FisherCloud 
 * @Date: 2020-02-26 20:06:15 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-26 20:37:44
 */
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/

package main

import (
	"fmt"
)

type ListNode struct {
	Val int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	var ans, tmp []int
	for head != nil {
		tmp = append(tmp, head.Val)
		head = head.Next
	}
	
	for i := (len(tmp) - 1); i >= 0; i-- {
		fmt.Println(i)
		ans = append(ans, tmp[i])
	}

	return ans
}

// func main() {
// 	// fmt.Println(reversePrint)
// }