/*
 * @Description: https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 12:43:34
 * @LastEditTime: 2020-01-03 13:37:09
 */

fn sorted_squares(a: Vec<i32>) -> Vec<i32> {
    let mut ans: Vec<i32> = a;
    
    for item in &mut ans {
        *item = item.pow(2); // 平方
    }
    ans.sort(); // 排序

    (ans)
}

fn main() {
    for item in sorted_squares(vec![-4, -1, 0, 3, 10]) {
        println!("{}", item);
    }
}