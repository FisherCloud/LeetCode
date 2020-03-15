/*
 * @Description: https://leetcode-cn.com/problems/divisor-game/
 * @Author: 鱼摆摆
 * @Github: https://github.com/FisherCloud
 * @Date: 2019-08-26 18:50:22
 * @LastEditTime: 2019-08-26 19:04:35
 */
#include <iostream>

using namespace std;

/**
 * 判断的结果是，
 * 当N=1时，不符合题的回答，爱丽丝输了；
 * 当N=2时，爱丽丝选择1，鲍勃走的时候N-1=1，爱丽丝赢了。
 * 当N=3时，爱丽丝只能选择1，轮到鲍勃走的时候N-1=2，鲍勃将走1，结果爱丽丝面对1只能输了。
 * 当N=4时，爱丽丝选择1，鲍勃面对3，只有一种结果，鲍勃会输。
 * 。。。
 * 奇数的约数只能是奇数，偶数的约数可以是奇数或者偶数。如果N是奇数，那么爱丽丝只能选择奇数，鲍勃将得到偶数，
 * 那么鲍勃每次都选中1，爱丽丝将被迫一直面对奇数，所以爱丽丝会输。
 * 如果N是偶数，那么爱丽丝可以每次都选择1，将奇数抛给鲍勃，当轮到爱丽丝选择时N=2,那么爱丽丝就赢了。
 * 所以这道题的题解是判断N的值的奇偶，N是奇数爱丽丝就会输，N是偶数爱丽丝就会赢。
 */
bool divisorGame(int N)
{
    return N % 2 ? false : true;
}

int main(int argc, char const *argv[])
{
    cout << divisorGame(13) << endl;
    return 0;
}
