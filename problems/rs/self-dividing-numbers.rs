/*
 * @Description: https://leetcode-cn.com/problems/self-dividing-numbers/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 14:30:06
 * @LastEditTime: 2020-01-03 14:45:01
 */

fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
    let mut ans: Vec<i32> = vec![];

    for i in left..(right + 1) {
        ans.push(i);
        let mut x = i;
        while 0 != x { // 判断是否自然数
            let tmp = x % 10;
            if 0 != tmp && 0 == (i % tmp) {
                x /= 10;
            } else {
                ans.pop();
                break;
            }
        }
    }

    (ans)
}

fn main() {
    println!("{:?}", self_dividing_numbers(1, 22));
}
