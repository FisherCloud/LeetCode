/*
 * @Description: https://leetcode-cn.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-12-26 22:42:01
 * @LastEditTime: 2019-12-26 22:51:51
 */
fn subtract_product_and_sum(n: i32) -> i32 {
    let mut num = n;
    let mut pro = 1i32;
    let mut sum = 0i32;

    while 0 != num {
        let temp = num % 10;
        pro *= temp;
        sum += temp;
        num /= 10;
    }

    (pro - sum)
}

fn main() {
    println!("{}", subtract_product_and_sum(234));
}