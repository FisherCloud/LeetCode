/*
 * @Author: FisherCloud 
 * @Date: 2020-02-26 17:43:14 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-26 18:29:35
 */
// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn replace_space(s: String) -> String {
        // return s.replace(" ", "%20"); // 自带函数，一行
        let mut ans = String::from("");
        for ch in s.as_str().chars() {
            if ch == ' ' {
                ans += "%20";
            } else {
                ans.insert(ans.len(), ch);
            }
        }
        return ans;
    }
}

fn main() {
    print!("{:?}", Solution::replace_space(String::from("We are happy.")));
}
