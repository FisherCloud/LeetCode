/*
 * @Author: FisherCloud 
 * @Date: 2020-02-26 19:56:24 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-26 20:03:52
 */
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}
#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn reverse_print(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut ans:Vec<i32>  = vec![];
        let mut headlist = head;
        while let Some(node) = headlist {
            ans.push(node.val);
            headlist = node.next;
        }
        ans.reverse();
        return ans;
    }
}

fn main() {
    
}
