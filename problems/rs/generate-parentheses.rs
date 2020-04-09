/// [LeetCode](https://leetcode-cn.com/problems/generate-parentheses/)
/// [题解](https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/)
/// # 动态规划
/// ## 第 1 步：定义状态 dp[i]：使用 i 对括号能够生成的组合。
/// 注意：每一个状态都是列表的形式。
/// ## 第 2 步：状态转移方程：
/// `i` 对括号的一个组合，在 `i - 1` 对括号的基础上得到，这是思考 “状态转移方程” 的基础；
/// `i` 对括号的一个组合，一定以左括号 "(" 开始，不一定以 ")" 结尾。为此，我们可以枚举新的右括号 ")" 可能所处的位置，得到所有的组合；
/// 枚举的方式就是枚举左括号 "(" 和右括号 ")" 中间可能的合法的括号对数，而剩下的合法的括号对数在与第一个左括号 "(" 配对的右括号 ")" 的后面，这就用到了以前的状态。
/// 状态转移方程是：
/// `dp[i] = "(" + dp[可能的括号对数] + ")" + dp[剩下的括号对数]`
/// 
/// “可能的括号对数” 与 “剩下的括号对数” 之和得为 `i - 1`，故 “可能的括号对数” `j` 可以从 `0` 开始，最多不能超过 `i`， 即 `i - 1`；
/// `“剩下的括号对数” + j = i - 1`，故 “剩下的括号对数” = `i - j - 1`。
/// 整理得：
/// `dp[i] = "(" + dp[j] + ")" + dp[i- j - 1] , j = 0, 1, ..., i - 1`
/// 
/// ## 第 3 步： 思考初始状态和输出：
/// 初始状态：因为我们需要 0 对括号这种状态，因此状态数组 dp 从 0 开始，0 个括号当然就是 [""]。
/// 输出：dp[n] 。
/// 
/// ## 这个方法暂且就叫它动态规划，这么用也是很神奇的，它有下面两个特点：
/// 1、自底向上：从小规模问题开始，逐渐得到大规模问题的解集；
/// 2、无后效性：后面的结果的得到，不会影响到前面的结果。

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut dp: Vec<Vec<String>> = Vec::new();
        if n != 0 {
            dp.push(vec!["".to_string()]);
            for i in 1..=(n as usize) {
                let mut cur = Vec::new();
                for j in 0..i {
                    for s1 in dp[j].iter() {
                        for s2 in dp[i - j - 1].iter() {
                            let mut tch = "(".to_string(); tch.push_str(s1); tch.push_str(")"); tch.push_str(s2);
                            cur.push(tch);
                        }
                    }
                }
                dp.push(cur);
            }
        }
        let mut answer = dp.iter().last().unwrap().to_vec();
        answer.reverse();
        answer
    }
}

fn main() {
    println!("{:?}", Solution::generate_parenthesis(5));
}
