/*
 * @Description: https://leetcode-cn.com/problems/di-string-match/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 16:49:06
 * @LastEditTime: 2020-01-03 19:02:59
 */

fn di_string_match(s: String) -> Vec<i32> {
    let len = s.len();
    let mut ans = vec![];
    let mut max = len as i32;
    let mut min = 0i32;

    let str_arr = s.chars().collect::<Vec<_>>();
    for index in 0..len {
        if 'I' == str_arr[index] {
            ans.push(min);
            min += 1;
        } else {
            ans.push(max);
            max -= 1;
        }
    }
    ans.push(max);

    (ans)
}

fn main() {
    println!("{:?}", di_string_match(String::from("DDI")));
}
