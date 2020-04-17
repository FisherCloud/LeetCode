// https://leetcode-cn.com/problems/jump-game/
// [题解]
// 链接：https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/
// 来源：力扣（LeetCode）
struct Solution;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let len = nums.len();
        let mut rightmost = 0i32;
        for i in 0..len {
            if i as i32 <= rightmost {
                rightmost = rightmost.max(i as i32+ nums[i]);
                if rightmost > (len - 1) as i32 {
                    return true;
                }
            }
        }
        false
    }
}

fn main() {
    assert_eq!(true, Solution::can_jump(vec![2, 3, 1, 1, 4]));
    // println!("{:?}", Solution::can_jump(vec![2, 3, 1, 1, 4]));
    assert_eq!(false, Solution::can_jump(vec![3, 2, 1, 0, 4]));
}
