/*
 * @Description: https://leetcode-cn.com/problems/delete-columns-to-make-sorted/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 14:59:07
 * @LastEditTime: 2020-01-03 16:11:47
 */

fn min_deletion_size(a: Vec<String>) -> i32 {
    let str_len = a[0].len();
    let arr_len = a.len();
    let mut count = 0i32;
    let mut str_arr = vec![];

    for item in a {
        let tmp = item.bytes().collect::<Vec<_>>(); // item.bytes().collect::<Vec<_>>()效率比item.chars().collect::<Vec<_>>()高
        str_arr.push(tmp);
    }

    for i in 0..str_len {
        for j in 1..arr_len {
            // if a[j as usize].chars().nth(i).unwrap() < a[j as usize - 1].chars().nth(i).unwrap() { // 这种方式访问效率太低了
            //     count += 1;
            //     break;
            // }

            if str_arr[j as usize][i] < str_arr[j as usize - 1][i] {
                count += 1;
                break;
            }
        }
    }

    (count)
}

fn main() {
    println!("{:?}", min_deletion_size(vec![String::from("rrjk"), String::from("furt"), String::from("guzm")]));
}
