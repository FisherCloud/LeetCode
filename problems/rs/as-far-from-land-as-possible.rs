// https://leetcode-cn.com/problems/as-far-from-land-as-possible
use std::collections::VecDeque;

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn max_distance(grid: Vec<Vec<i32>>) -> i32 {
        /* Initial */
        let mut _grid = grid;
        let m = _grid.len();
        let n = _grid[0].len();
        let mut distance = -1i32;
        let mut queue: VecDeque<Vec<i32>> = VecDeque::new();
        let directions = vec![vec![-1i32, 0], vec![1, 0], vec![0, 1], vec![0, -1]];

        // push all land into queue
        for i in 0..m {
            for j in 0..n {
                if _grid[i][j] == 1 {
                    queue.push_back(vec![i as i32, j as i32]);
                }
            }
        }

        // land and ecean both exist
        if !queue.is_empty() && queue.len() != m * n {
            // BFS
            while !queue.is_empty() {
                distance += 1; 
                let mut len = queue.len();
                while len > 0 {
                    len -= 1;
                    let cur = queue.pop_front().unwrap();
                    for item in directions.iter() {
                        let x = cur[0] + item[0];
                        let y = cur[1] + item[1];

                        // outrange/isLand/scaned
                        if x < 0 || x as usize >= m || y < 0 || y as usize >= n || _grid[x as usize][y as usize] != 0{
                            continue;
                        }
                        _grid[x as usize][y as usize] = 2;
                        queue.push_back(vec![x, y]);
                    }
                }
            }
        }

        /* ReturnMaxDistance */
        distance
    }
}

fn main() {
    unimplemented!();
}
