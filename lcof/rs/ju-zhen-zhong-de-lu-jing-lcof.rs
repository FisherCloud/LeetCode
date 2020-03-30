// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
#[derive(Debug)]
struct Solution {
}

// 题解：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/shen-du-you-xian-sou-suo-by-z1m/
// DFS(Depth First Search)
impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        if board.is_empty() || word.is_empty(){
            return false;
        }
        let mut mut_board = board;
        let height = mut_board.len() as i32;
        let width = mut_board[0].len() as i32;
        for x in 0..height {
            for y in 0..width {
                if Self::dfs(&mut mut_board, word.to_string(), x, y) {
                    return true;
                }
            }
        }
        return false;
    }

    fn dfs(board: &mut Vec<Vec<char>>, word: String, x: i32, y: i32) -> bool {
        // println!("{:?}", (x, y));
        if word.is_empty() {
            return true;
        }
        if x < 0 || y < 0 || x as usize >= board.len() || y as usize >= board[0].len() || word.chars().nth(0) != Some(board[x as usize][y as usize]) {
            return false;
        }
        let tmp = board[x as usize][y as usize];
        board[x as usize][y as usize] = '0';
        let res = Self::dfs(board, word[1..].to_string(), x + 1, y) || Self::dfs(board, word[1..].to_string(), x, y + 1) || Self::dfs(board, word[1..].to_string(), x - 1, y) || Self::dfs(board, word[1..].to_string(), x, y - 1);
        board[x as usize][y as usize] = tmp;
        return res;
    }
}

fn main() {
    println!("{:?}", Solution::exist(vec![vec!['a','b']], "ba".to_string()));
}