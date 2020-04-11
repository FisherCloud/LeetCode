/// [LeetCode](https://leetcode-cn.com/problems/super-egg-drop/)
/// [题解](https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution/)
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn super_egg_drop(k: i32, n: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        let mut f = vec![vec![0i32; k as usize + 1]; n as usize + 1];
        for i in 1..=(k as usize) {
            f[1][i] = 1;
        }
        let mut answer = -1i32;
        for i in 2..=(n as usize) {
            for j in 1..=(k as usize) {
                f[i][j] = 1 + f[i - 1][j - 1] + f[i - 1][j];
            }
            if f[i][k as usize] >= n {
                answer = i as i32;
                break;
            }
        }
        answer
    }
}

fn main() {
    println!("{:?}", Solution::super_egg_drop(3, 14));
}
