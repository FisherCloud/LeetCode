/*
 * @Description: https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
 * @Author: 鱼摆摆
 * @Email: fishercloud@qq.com
 * @Github: https://github.com/FisherCloud
 * @Date: 2020-01-04 16:16:23
 * @LastEditTime: 2020-01-04 18:45:06
 */

#[derive(Debug)]
struct Solution {
}

use std::collections::VecDeque;

impl Solution { // 未通过
    pub fn shortest_subarray(a: Vec<i32>, k: i32) -> i32 {
        let len = a.len();
        let mut count: Vec<i32> = vec![];
        let mut queue: VecDeque<i32> = VecDeque::new();

        queue.push_back(a[0]);
        let mut i = 0usize;
        while !queue.is_empty() {
            println!("{},{:?}", i, queue);
            let sum: i32 = queue.iter().sum();
            if sum >= k {
                let mlen = queue.len();
                count.push(mlen as i32);
                queue.pop_front();
            } else {
                i += 1;
                if i < len {
                    queue.push_back(a[i]);
                } else {
                    if *queue.back().unwrap() < 0 {
                        queue.pop_back();
                    }
                }
                if *queue.front().unwrap() < 0 {
                    queue.pop_front();
                }
            };
        }
    
        if count.is_empty() {
            return -1;
        } else {
            return *count.iter().min().unwrap();
        }        
    }
}

// 别人的C++版本
// class Solution {
// public:
//     int shortestSubarray(vector<int>& A, int K) {
//         int n=A.size();
//         vector<int> sum(n+1,0);
//         for(int i=0;i<n;++i)
//         {
//             sum[i+1]=sum[i]+A[i];
//         }

//         deque<int> d;
//         int res=n+1;
//         for(int i=0;i<=n;++i)
//         {
//             while(!d.empty()&&sum[i]<=sum[d.back()])
//             {
//                 d.pop_back();
//             }
//             while(!d.empty()&&sum[i]-sum[d.front()]>=K)
//             {
//                 res=min(res,i-d.front());
//                 d.pop_front();
//             }
//             d.push_back(i);
//         }
//         return res<=n?res:-1;
//     }
// };

fn main() {
    println!("{:?}", Solution::shortest_subarray(vec![84, -37, 32, 40, 95], 167));
}
