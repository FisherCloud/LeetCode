/*
 * @Description: https://leetcode-cn.com/problems/number-of-recent-calls/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-03 19:14:27
 * @LastEditTime: 2020-01-03 20:06:07
 */

use std::collections::VecDeque;

struct RecentCounter {
    ping_queue: VecDeque<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
    fn new() -> Self {
        let mut rc = RecentCounter {
            ping_queue: VecDeque::new(),
        };
        rc.ping_queue.reserve(10000);
        (rc)
    }
    
    fn ping(&mut self, t: i32) -> i32 {
        self.ping_queue.push_back(t);
        while let Some(x) = self.ping_queue.front() {
            if t - x > 3000 {
                self.ping_queue.pop_front();
            } else {
                break;
            }
        }
        (self.ping_queue.len() as i32)
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter::new();
 * let ret_1: i32 = obj.ping(t);
 */

fn main() {
    let mut obj = RecentCounter::new();
    println!("{:?}", obj.ping(1));
    println!("{:?}", obj.ping(100));
    println!("{:?}", obj.ping(3001));
    println!("{:?}", obj.ping(3002));
}
