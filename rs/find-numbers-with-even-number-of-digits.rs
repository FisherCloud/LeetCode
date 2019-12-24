/*
 * @Description: https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-12-24 22:32:23
 * @LastEditTime: 2019-12-24 23:36:28
 */

 fn find_numbers(nums: Vec<i32>) -> i32 {
    let mut count = 0i32;
    for item in nums {
        let ss = item.to_string();// convert i32 to string
        if 0 == ss.len() % 2 {// ss.len() is even?
            count += 1;
        }
    }
    return count;
}

fn main() {
    let arr = vec![12,345,2,6,7896];
    println!("{}", find_numbers(arr));
}