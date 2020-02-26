/*
 * @Description: https://leetcode-cn.com/problems/excel-sheet-column-number/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-06 14:00:56
 * @LastEditTime: 2020-01-06 14:28:04
 */

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let mut str_arr = s.bytes().collect::<Vec<_>>();
        let len = s.len();
        let mut res = 0i32;
        for i in 0..len {
            let tmp = str_arr[i] - 64;
            if i != (len - 1) {
                res = (res + tmp as i32) * 26;
            } else {
                res += tmp as i32;
            }
        }
        (res)
    }
}

fn main() {
    println!("{:?}", Solution::title_to_number(String::from("AAA")));
}
