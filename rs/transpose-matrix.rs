/*
 * @Description: https://leetcode-cn.com/problems/transpose-matrix/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-04 14:10:12
 * @LastEditTime: 2020-01-04 14:17:02
 */

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn transpose(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = vec![vec![0; a.len()]; a[0].len()];
        for i in 0..a[0].len() {
            for j in 0..a.len() {
                ans[i][j] = a[j][i];
            }
        }
        (ans)
    }
}

fn main() {
    println!("{:?}", Solution::transpose(vec![vec![1,2,3],vec![4,5,6]]));
}
