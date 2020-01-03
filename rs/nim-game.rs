/*
 * @Description: https://leetcode-cn.com/problems/nim-game/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 19:09:19
 * @LastEditTime: 2020-01-03 19:10:40
 */

fn can_win_nim(n: i32) -> bool {
    (0 != n % 4)
}

fn main() {
    println!("{}", can_win_nim(4));
}
