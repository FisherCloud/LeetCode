/*
 * @Description: https://leetcode-cn.com/problems/intersection-of-two-arrays/comments/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 21:08:25
 * @LastEditTime: 2020-01-03 21:19:54
 */

 use std::collections::HashSet;

fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut set: HashSet<i32> = HashSet::new();
    for item in nums1 {
        if nums2.contains(&item) {
            set.insert(item);
        }
    }
    let mut ans: Vec<i32> = Vec::new();
    for item in set {
        ans.push(item);
    }
    (ans)
}

fn main() {
    println!("{:?}", intersection(vec![1, 2, 2, 3], vec![2, 2]));
}
