// https://leetcode-cn.com/problems/add-two-numbers-ii/
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

struct Solution;
// 数据结构使用栈
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut ll1 = &l1;
        let mut ll2 = &l2;
        let mut list_one: Vec<i32> = Vec::new();
        let mut list_two: Vec<i32> = Vec::new();

        while let Some(x) = ll1 {
            list_one.push(x.val);
            ll1 = &x.next;
        }

        while let Some(x) = ll2 {
            list_two.push(x.val);
            ll2 = &x.next;
        }

        let mut ans: Option<Box<ListNode>> = Option::None;
        let mut carry = 0;
        while !list_one.is_empty() || !list_two.is_empty() || carry > 0 {
            let (v1, v2) = (list_one.pop().unwrap_or(0), list_two.pop().unwrap_or(0));
            let tmp = v1 + v2 + carry;
            carry = tmp / 10;
            let mut node = Box::new(ListNode::new(tmp % 10));
            node.next = ans;
            ans = Option::Some(node);
        }
        ans
    }
}

fn main() {
    println!("{:?}",
        Solution::add_two_numbers(
            Some(
                Box::new(
                    ListNode {
                        val: 7, 
                        next: Some(
                            Box::new(
                                ListNode { 
                                    val: 2, 
                                    next: Some(
                                        Box::new(
                                            ListNode { 
                                                val: 4,
                                                next: Some(
                                                    Box::new(
                                                        ListNode { 
                                                        val: 3,
                                                        next: None
                                                        }
                                                    )
                                                )
                                            }
                                        )
                                    )
                                }
                            )
                        )
                    }
                )
            ), 
            Some(
                Box::new(
                    ListNode { 
                        val: 5, 
                        next: Some(
                            Box::new(
                                ListNode { 
                                    val: 6, 
                                    next: Some(
                                        Box::new(
                                            ListNode { 
                                                val: 4, 
                                                next: None 
                                            }
                                        )
                                    ) 
                                }
                            )
                        )
                    }
                )
            )
        )
    );
}
