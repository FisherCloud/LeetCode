// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
#[derive(Debug)]
struct Solution {
}

// 题解：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/shen-du-you-xian-sou-suo-by-z1m/
// DFS(Depth First Search)
impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        if board.is_empty() || word.is_empty() {
            return false;
        }
        let mut mutBoard = board;
        let height = mutBoard.len();
        let width = mutBoard[0].len();
        for i in 0..height {
            for j in 0..width {
                return Self::dfs(&mut mutBoard, word, i, j);
            }
        }
        return false;
    }

    fn dfs(board: &mut Vec<Vec<char>>, word: String, x: usize, y: usize) -> bool {
        if word.is_empty() {
            return true;
        }
        if x < 0 || x >= board.len() || y < 0 || y >= board[0].len() || word.chars().nth(0) != Some(board[x][y]) {
            return false;
        }
        let tmp = board[x][y];
        board[x][y] = '0';
        let res = Self::dfs(board, word[1..].to_string(), x + 1, y) || Self::dfs(board, word[1..].to_string(), x, y + 1) || Self::dfs(board, word[1..].to_string(), x - 1, y) || Self::dfs(board, word[1..].to_string(), x, y - 1);
        board[x][y] = tmp;
        return res;
    }
}

fn main() {
    unimplemented!();
}