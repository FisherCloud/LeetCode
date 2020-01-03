/*
 * @Description: https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 12:22:25
 * @LastEditTime: 2020-01-03 12:34:12
 */

fn sum_zero(n: i32) -> Vec<i32> {
    let mut sum = 0i32;
    let mut arr: Vec<i32> = vec![0; n as usize];
    
    for i in 0..(n-1) {
        arr[i as usize] = i + 1;// 1 -- (n-1)
        sum += arr[i as usize];
    }
    arr[n as usize - 1] = 0 - sum;// 最后一位数是前面所以数和的相反数

    (arr)
}

fn main() {
    for i in sum_zero(5) {
        print!("{},", i);
    }
}