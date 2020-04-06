// https://leetcode-cn.com/problems/fizz-buzz-multithreaded/
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class FizzBuzz {
   private:
    int n;
    int count = 1;
    mutex mtx;
    condition_variable cv;

   public:
    FizzBuzz(int n) { this->n = n; }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(mtx);
        while (count <= n) {
            cv.wait(lock, [this]() {
                return count > n || count % 3 == 0 && count % 5 != 0;
            });
            if (count > n) break;
            printFizz();
            ++count;
            cv.notify_all();
        }
        cv.notify_all();
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(mtx);
        while (count <= n) {
            cv.wait(lock, [this]() {
                return count > n || count % 3 != 0 && count % 5 == 0;
            });
            if (count > n) break;
            printBuzz();
            ++count;
            cv.notify_all();
        }
        cv.notify_all();
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(mtx);
        while (count <= n) {
            cv.wait(lock, [this]() {
                return count > n || count % 3 == 0 && count % 5 == 0;
            });
            if (count > n) break;
            printFizzBuzz();
            ++count;
            cv.notify_all();
        }
        cv.notify_all();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (count <= n) {
            cv.wait(lock, [this]() {
                return count > n || count % 3 != 0 && count % 5 != 0;
            });
            if (count > n) break;
            printNumber(count);
            ++count;
            cv.notify_all();
        }
        cv.notify_all();
    }
};

int main(int argc, char const *argv[]) {
    auto fizzbuzz = new FizzBuzz(15);

    function<void()> printFizz = [] { cout << "fizz" << endl; };
    function<void()> printBuzz = [] { cout << "buzz" << endl; };
    function<void()> printFizzBuzz = [] { cout << "fizzbuzz" << endl; };
    function<void(int)> printNumber = [](int count) { cout << count << endl; };

    // printFizz();
    // printBuzz();
    // printFizzBuzz();
    // printNumber(10);

    // error
    thread tfizz(&FizzBuzz::fizz, std::ref(fizzbuzz), printFizz);
    thread tbuzz(&FizzBuzz::buzz, std::ref(fizzbuzz), printBuzz);
    thread tfizzbuzz(&FizzBuzz::fizzbuzz, std::ref(fizzbuzz), printFizzBuzz);
    thread tnumber(&FizzBuzz::number, std::ref(fizzbuzz), printNumber);

    tfizz.join();
    tbuzz.join();
    tfizzbuzz.join();
    tnumber.join();
    delete fizzbuzz;
    return 0;
}
