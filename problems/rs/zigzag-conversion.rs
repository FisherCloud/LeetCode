/// [LeetCode](https://leetcode-cn.com/problems/zigzag-conversion/)
/// 每一行字母的所有下标其实是有规则的
/// 我们先假定有 numRows=4 行来推导下，其中 2*numRows-2 = 6 , 我们可以假定为 step=2*numRows-2 ，我们先来推导下规则：
///
/// 第0行： 0 - 6 - 12 - 18
///
/// ==> 下标间距 6 - 6 - 6 ==> 下标间距 step - step - step
///
/// 第1行： 1 - 5 - 7 - 11 - 13
///
/// ==> 下标间距 4 - 2 - 4 - 2 ==> 下标间距step-2*1(行)-2*1(行)-step-2*1(行)-2*1(行)
///
/// 第2行： 2 - 4 - 8 - 10 - 14
/// ==> 下标间距 2 - 4 - 2 - 4 ==> 下标间距step-2*2(行)-2*2(行)-step-2*2(行)-2*2(行)
///
/// 第3行：3 - 9 - 15 - 21
///
/// ==> 下标间距间距 6 - 6 - 6 ==>下标间距step - step - step
///
/// 可以得出以下结论：
///
/// 起始下标都是行号
///
/// 第0层和第numRows-1层的下标间距总是step 。
///
/// 中间层的下标间距总是step-2*行数，2*行数交替。
///
/// 下标不能超过len(s)-1
///
/// 作者：bian-bian-xiong
/// 链接：https://leetcode-cn.com/problems/zigzag-conversion/solution/6-z-zi-xing-bian-huan-c-c-by-bian-bian-xiong/
/// 来源：力扣（LeetCode）
/// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#[derive(Debug)]
struct Solution {
}

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if (num_rows <= 1) {
            return s;
        }
        let mut step = num_rows as usize * 2 - 2;           // 间距
        let mut index = 0usize;                             // 记录s的下标
        let len = s.len();                                  // 字符串长度
        let mut add = 0usize;                               // 真实的间距
        let mut ss = String::from("");                      // 用于保存新的字符串
        let mut arr_s = s.chars().collect::<Vec<char>>();   // 将String转为Vec数组
        for i in 0..(num_rows as usize) {                   // i为行号
            index = i;                                      // 记录行
            add = i * 2;                                    // 计算间距
            while index < len {                             // 超出字符串长度计算下一层
                ss.push(arr_s[index]);                      // 添加字符串到新字符串
                add = step - add;                           // 第一次间距是step -2*i，第二次是2*i, 
                if i == 0 || i == num_rows as usize - 1 {   // 0行和最后一行使用step间距，其余使用add间距
                    index += step;
                } else {
                    index += add;
                }
            }
        }
        ss
    }
}

fn main() {
    println!("{:?}", Solution::convert("LEETCODEISHIRING", 3));
}
