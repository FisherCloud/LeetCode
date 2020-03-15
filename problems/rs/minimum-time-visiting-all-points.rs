/*
 * @Description: https://leetcode-cn.com/problems/minimum-time-visiting-all-points/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-12-25 21:26:34
 * @LastEditTime: 2019-12-25 22:23:26
 */
use std::cmp::*;

pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
    let mut path_count = 0i32;
    let len = points.len();
    
    for i in 0..(len-1) {
        path_count += max((points[i][0] - points[i+1][0]).abs(), (points[i][1] - points[i+1][1]).abs());
    }

    (path_count)
}

fn main() {
    let points:Vec<Vec<i32>> = vec![vec![1,1],vec![3,4],vec![-1,0]];
    println!("start......");
    println!("{}", points.len());
    println!("{}", min_time_to_visit_all_points(points));
}
