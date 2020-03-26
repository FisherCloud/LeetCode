// https://leetcode-cn.com/problems/length-of-last-word/

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let tmp = s.split_whitespace().collect::<Vec<_>>();
        let x = tmp.iter().filter(|x| !x.is_empty()).last();
        if x.is_none() {
            return 0;
        }
        x.unwrap().len() as i32
    }
}

fn main() {
    unimplemented!();
}
