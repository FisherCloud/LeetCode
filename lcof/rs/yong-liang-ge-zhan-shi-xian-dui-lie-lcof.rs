/*
 * @Author: FisherCloud 
 * @Date: 2020-02-27 16:48:36 
 * @Last Modified by: FisherCloud
 * @Last Modified time: 2020-02-27 17:22:06
 */
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

use std::collections::LinkedList;

struct CQueue {
    stackone: LinkedList<i32>, // Vec,VecDeque,LinkedList均可，但测试过后VecDeque效率更高
    stacktwo: LinkedList<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl CQueue {

    fn new() -> Self {
        CQueue{
            stackone: LinkedList::new(),
            stacktwo: LinkedList::new(),
        }
    }
    
    fn append_tail(&mut self, value: i32) {
        self.stackone.push_back(value);
    }
    
    fn delete_head(&mut self) -> i32 {
        if self.stacktwo.is_empty() {
            if self.stackone.is_empty() {
                return -1;
            } else {
                while !self.stackone.is_empty() {
                    self.stacktwo.push_back(self.stackone.pop_back().unwrap());
                }
            }   
        }
        return self.stacktwo.pop_back().unwrap();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * let obj = CQueue::new();
 * obj.append_tail(value);
 * let ret_2: i32 = obj.delete_head();
 */
