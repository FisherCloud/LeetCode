// https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/
use std::collections::HashMap;

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut tmp = HashMap::new();
        for item in deck.iter() {
            tmp.insert(item, deck.iter().filter(|&x| x == item).count() as i32);
        }

        // println!("{:?}", tmp);

        for x in 2..(1 + deck.len() as i32) {
            let mut count = 0usize;
            for i in tmp.values() {
                // println!("{:?}", (x, i));
                if (i % x) == 0 {
                    count += 1;
                }
            }
            if count == tmp.len() {
                return true;
            }
        }

        return false;
    }
}

fn main() {
    unimplemented!();
}
