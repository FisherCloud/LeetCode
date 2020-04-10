// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.is_empty() {
            return 0;
        }
        let mut ex_space = prices[0];
        let mut profit = 0 - ex_space;
        for price in prices.iter() {
            if *price >= ex_space {
                profit = (*price - ex_space).max(profit);
            } else {
                ex_space = *price;
            }
        }
        profit
    }
}

fn main() {
    println!("{:?}", Solution::max_profit(vec![7, 6, 4, 3, 1]));
}
