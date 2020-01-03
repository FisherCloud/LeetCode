/*
 * @Description: https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 20:43:26
 * @LastEditTime: 2020-01-03 21:00:09
 */

fn peak_index_in_mountain_array(a: Vec<i32>) -> i32 {
    let mut index = 0i32;
    let len = a.len();
    for i in 1..len {
        if a[i] > a[i - 1] {
            continue;
        } else {
            index = i as i32 - 1;
            break;
        }
    }

    (index)
}

fn main() {
    println!("{:?}", peak_index_in_mountain_array(vec![3, 4, 5, 1]));
}
