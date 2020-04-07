// https://leetcode-cn.com/problems/rotate-matrix-lcci/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        // 水平翻转
        for i in 0..(n / 2) {
            for j in 0..n {
                let tmp = matrix[i][j];
                matrix[i][j] = matrix[n - i - 1][j];
                matrix[n - i - 1][j] = tmp;
            }
        }

        // 主对角线翻转
        for i in 0..n {
            for j in 0..i {
                let tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}

fn main() {
    let mut matrix = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    Solution::rotate(&mut matrix);
    // println!("{:?}", Solution::rotate(&mut matrix));
    println!("{:?}", matrix);
}
