// https://leetcode-cn.com/problems/sort-an-array/
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let mut nums_copy = nums;
        /* 库函数 */
        // nums_copy.sort(); 

        // 快排
        // nums_copy = Self::quick_sort(nums_copy);

        // 堆排序
        // nums_copy = Self::heap_sort(nums_copy);

        // 归并
        nums_copy = Self::merge_sort(nums_copy);

        // Return sorted array
        nums_copy
    }
    //========================================
    /** 快排 **/
    // #[warn(dead_code)]
    pub fn quick_sort(nums: Vec<i32>) -> Vec<i32> {
        if nums.len() <= 1 {
            return nums;
        }
        let mut vec1: Vec<i32> = Vec::new();
        let mut vec2: Vec<i32> = Vec::new();
        for  i in 1..nums.len() {
            if nums[i] >= nums[0] {
                vec2.push(nums[i]);
            } else {
                vec1.push(nums[i]);
            }
        }
        let mut result = Self::quick_sort(vec1);
        result.push(nums[0]);
        result.append(&mut Self::quick_sort(vec2));
        result
    }
    //========================================
    /* 堆排序 */
    // #[warn(dead_code)]
    pub fn heap_sort(nums: Vec<i32>) -> Vec<i32> {
        let mut nums_copy = nums;
        // 初始化堆
        let mut i = (nums_copy.len() as i32) / 2 - 1;
        while i >= 0 {
            nums_copy = Self::heap_ajust(nums_copy.clone(), i as usize);
            i -= 1;
        }
        //从最后一个元素开始对序列进行调整
        let mut j = nums_copy.len() - 1;
        let mut ans: Vec<i32> = Vec::new();
        while j > 0 {
            let tmp = nums_copy[0]; nums_copy[0] = nums_copy[j]; nums_copy[j] = tmp;
            ans.push(tmp);
            nums_copy = Self::heap_ajust(nums_copy[0..j].to_vec(), 0);
            j -= 1;
        }
        ans.append(&mut nums_copy);
        ans.reverse();
        ans
    }
    
    /**
     * 已知nums[s…m]除了nums[s] 外均满足堆的定义
     * 调整nums[s],使其成为大顶堆.即将对第s个结点为根的子树筛选, 
     *
     * @param nums是待调整的堆数组
     * @param s是待调整的数组元素的位置
     */
    // #[warn(dead_code)]
    fn heap_ajust(nums: Vec<i32>, s: usize) -> Vec<i32> {
        let mut nums_copy = nums;
        let tmp = nums_copy[s];
        let mut child = 2 * s + 1; // 左孩子结点的位置。(i+1 为当前调整结点的右孩子结点的位置)
        let mut mut_s = s;
        while child < nums_copy.len() {
            if (child + 1) < nums_copy.len() && nums_copy[child] < nums_copy[child + 1] {
                child += 1;
            }
            if nums_copy[mut_s] < nums_copy[child] {
                nums_copy[mut_s] = nums_copy[child];
                mut_s = child;
                child = 2 * mut_s + 1;
            } else {
                break;
            }
            nums_copy[mut_s] = tmp;
        }
        nums_copy
    }
    //========================================
    /* 归并排序 */
    // #[warn(dead_code)]
    pub fn merge_sort(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        if len <= 1 {
            return nums;
        }
        let mid = len / 2;
        let left = Self::merge_sort(nums[..mid].to_vec());
        let right = Self::merge_sort(nums[mid..].to_vec());
    
        Self::merge(left, right)
    }

    fn merge(mut left: Vec<i32>, mut right: Vec<i32>) -> Vec<i32> {
        let mut res = vec![];
        while !left.is_empty() && !right.is_empty() {
            if left[0] <= right[0] {
                res.push(left[0]);
                left.remove(0);
            } else {
                res.push(right[0]);
                right.remove(0);
            }
        }
        if !left.is_empty() {
            res.extend(&left);
        }
        if !right.is_empty() {
            res.extend(&right);
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::sort_array(vec![5, 1, 1, 2, 0, 0]));
}
