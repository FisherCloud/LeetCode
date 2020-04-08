// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn moving_count(m: i32, n: i32, k: i32) -> i32 {
        Self::bfs(m, n, k)
    }

    /// [题解](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/bfsmo-ban-yi-ci-bei-hui-chu-chu-shi-yong-by-fuxuem/)
    pub fn bfs(m: i32, n: i32, k: i32) -> i32 {
        let directions = vec![vec![-1, 0], vec![0, -1], vec![1, 0], vec![0, 1]];
        let mut visited = vec![vec![0usize; n as usize]; m as usize];
        let mut queue =  std::collections::VecDeque::new();
        queue.push_back(vec![0, 0]);
        let mut count = 0i32;
        visited[0][0] = 1;
        while !queue.is_empty() {
            let front = queue.pop_front().unwrap();
            let x = front[0];
            let y = front[1];
            count += 1;
            for d in directions.iter() {
                let _x = x + d[0];
                let _y = y + d[1];
                if _x < 0 || _x >= m || _y < 0 || _y >= n || visited[_x as usize][_y as usize] == 1 || Self::sum_digital(_x, _y) > k {
                    continue;
                }
                queue.push_back(vec![_x, _y]);
                visited[_x as usize][_y as usize] = 1;
            }
        }
        count
    }

    pub fn dfs(m: i32, n: i32, k: i32) -> i32 {
        0
    }

    pub fn sum_digital(m: i32, n: i32) -> i32 {
        let mut sum = 0i32;
        let mut i = m;
        let mut j = n;
        while i > 0 {
            sum += i % 10;
            i /= 10;
        }
        while j > 0 {
            sum += j % 10;
            j /= 10;
        }
        sum
    }
}

fn main() {
    println!("{:?}", Solution::moving_count(2, 3, 1));
}
