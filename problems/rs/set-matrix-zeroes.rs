// https://leetcode-cn.com/problems/set-matrix-zeroes/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        if matrix.is_empty() || matrix[0].is_empty() {
            return;
        }
        let len_r = matrix.len();
        let len_c = matrix[0].len();
        let mut mark = vec![0usize; len_r + len_c]; // additional space O(m + n)
        for i in 0..len_r {
            for j in 0..len_c {
                if matrix[i][j] == 0 {
                    mark[i] = 1;
                    mark[j + len_r] = 1;
                }
            }
        }
        for r in 0..len_r {
            if mark[r] == 1 {
                for i in 0..len_c {
                    if matrix[r][i] != 0 {
                        matrix[r][i] = 0;
                    }
                }
            }
        }
        for c in 0..len_c {
            if mark[len_r + c] == 1 {
                for j in 0..len_r {
                    if matrix[j][c] != 0 {
                        matrix[j][c] = 0;
                    }
                }
            }
        }
    }
}

fn main() {
    let mut matrix = vec![
                    vec![0, 1, 2, 0],
                    vec![3, 4, 5 ,2],
                    vec![1, 3, 1, 5]
                    ];
    Solution::set_zeroes(&mut matrix);
    assert_eq!(vec![
                vec![0, 0, 0, 0],
                vec![0, 4, 5, 0],
                vec![0, 3, 1, 0]
                ], matrix);
}
