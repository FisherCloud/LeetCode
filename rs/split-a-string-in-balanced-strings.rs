/*
 * @Description: https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-12-27 22:25:08
 * @LastEditTime: 2019-12-27 22:34:59
 */

fn balanced_string_split(s: String) -> i32 {
    let mut count = 0i32;
    let mut l_flag = 0i32;
    let mut r_flag = 0i32;

    for c in s.chars() {
        match c {
            'L' => l_flag += 1,
            'R' => r_flag += 1,
            _ => return -1,
        }

        if l_flag == r_flag {
            count += 1;
            l_flag = 0;
            r_flag = 0;
        }
    }

    (count)
}

fn main() {
    let s = String::from("RLRRLLRLRL");
    println!("{}", balanced_string_split(s));
}