// https://leetcode-cn.com/problems/master-mind-lcci/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn master_mind(solution: String, guess: String) -> Vec<i32> {
        let mut ret = vec![0i32, 0];
        let mut ss = solution.chars().collect::<Vec<char>>();
        let mut gs = guess.chars().collect::<Vec<char>>();
        for i in 0..4 {
            if ss[i] == gs[i] { // 猜中次数
                ret[0] += 1;
                ss[i] = '0';
                gs[i] = '0';
            }
        }
        for i in 0..4 {
            if gs[i] != '0' && ss.contains(&gs[i]) { // 伪猜中次数
                ret[1] += 1;
                let j = ss.iter().position(|&x| x == gs[i]).unwrap();
                ss[j] = '0';
                gs[i] = '0';
            }
        }
        ret
    }
}

fn main() {
    // println!("{:?}", Solution::master_mind("RGRB".to_string(), "BBBY".to_string()));
    assert_eq!(vec![0, 1], Solution::master_mind("RGRB".to_string(), "BBBY".to_string()));
}