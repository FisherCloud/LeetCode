// https://leetcode-cn.com/problems/reverse-words-in-a-string/

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut words = s.split_whitespace().collect::<Vec<_>>();
        if words.is_empty() {
            return "".to_string();
        }
        words.reverse();
        let mut _str = words[0].to_string();
        for i in 1..words.len() {
            _str.push(' ');
            _str.push_str(words[i]);
        }
        _str
    }
}

fn main() {
    println!("{:?}", Solution::reverse_words("there is a horse".to_string()));
}
