// https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        // 立方体个数
        let mut count = 0i32;
        // 重叠数
        let mut lap = 0i32;
        for item in grid.iter() {
            count += item.iter().fold(0, |acc, x| acc + x);
            lap += item.iter().filter(|&&x| x > 1).fold(0, |acc, x| acc + x - 1);
        }

        for i in 0..grid[0].len() {
            for j in 0..(grid.len() - 1) {
                lap += std::cmp::min(grid[j][i], grid[j + 1][i]);
                lap += std::cmp::min(grid[i][j], grid[i][j + 1]);
            }
        }

        count * 6 - lap * 2
    }
}

fn main() {
    unimplemented!();
}