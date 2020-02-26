/*
 * @Description: https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 13:45:11
 * @LastEditTime: 2020-01-03 14:14:43
 */

fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
    let mut ans = arr;
    let len = ans.len();
    let mut rmax = ans[len - 1];
    ans[len - 1] = -1;

    for i in 2..(len + 1) {
        let temp = ans[len - i]; // 从右向左遍历
        ans[len - i] = rmax;
        if temp > rmax {
            rmax = temp;
        }
    }

    (ans)
}

fn main() {
    println!("{:?}", replace_elements(vec![17, 18, 5, 4, 6, 1]));
}