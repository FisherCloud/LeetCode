// https://leetcode-cn.com/problems/lfu-cache/
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

//为 list 自定义一个内存管理类模板
template <typename T>
class SingleAlloctor {
    enum {
        MAXN = 5000,
    };
    static T *data;  //内存池为全局变量，防止重复申请。
    static int current;
    static int pool[MAXN];  // pool本质上是一个链表；current
                            // 为头结点，标记了哪些data可用。
   public:
    typedef T value_type;
    T *allocate(int num) {
        int cur = current;
        current = pool[current];
        return data + cur;
    }
    void deallocate(T *p, std::size_t) {
        ptrdiff_t offset = p - data;
        pool[offset] = current;
        current = offset;
    }
    SingleAlloctor() {
        if (data != nullptr) {  //应该还有对应的delete，哈哈偷懒了。
            return;
        }
        data = static_cast<T *>(::operator new(MAXN * sizeof(T)));
        for (int i = 0; i < MAXN; i++) {
            pool[i] = i - 1;
        }
        current = MAXN - 1;
    }
};

template <typename T>
int SingleAlloctor<T>::current;

template <typename T>
int SingleAlloctor<T>::pool[SingleAlloctor<T>::MAXN];

template <typename T>
T *SingleAlloctor<T>::data = nullptr;

class LFUCache {
    struct FreqNode;
    typedef list<FreqNode, SingleAlloctor<FreqNode>> FreqList;

    struct DataNode {
        int key;                 //索引
        int value;               //数据
        FreqList::iterator fit;  //对应的频次链表的结点
        DataNode(int k = 0, int v = 0,
                 FreqList::iterator f = FreqList::iterator())
            : key(k), value(v), fit(f) {}
    };
    typedef list<DataNode, SingleAlloctor<DataNode>> DataList;

    struct FreqNode {
        int cnt;            //频次
        DataList dataList;  //对应的数据结点列表
        FreqNode(int c = 0) : cnt(c) {}
    };
    FreqList cache;
    unordered_map<int, DataList::iterator> router;

    size_t capacity;

    void updateCache(int key) {
        auto rit = router.find(key);
        auto it = rit->second;
        if (it->fit == cache.begin()) {
            cache.push_front(
                FreqNode(it->fit->cnt + 1));  //更高频次的结点不存在，创建它！
        } else {
            FreqList::iterator pre = it->fit;
            --pre;
            if (pre->cnt !=
                it->fit->cnt + 1) {  // 更高频次的结点频次不匹配，插入一个新的。
                cache.insert(it->fit, FreqNode(it->fit->cnt + 1));
            }
        }
        auto curIt = it->fit;  //从当前数据链表断开，插入到更高频次的数据链表。
        auto preIt = it->fit;
        --preIt;
        preIt->dataList.push_front(DataNode(key, it->value, preIt));
        curIt->dataList.erase(it);
        rit->second = preIt->dataList.begin();  //更新 router
    }

    void swapOut() {
        for (auto it = --cache.end();;) {
            if (it->dataList.size()) {  //删除最后一个
                auto out = it->dataList.back();
                router.erase(out.key);
                it->dataList.pop_back();
                break;
            } else {  //可能存在若干个空的数据链表，清楚它。均摊 O(1)。
                cache.erase(it--);
            }
        }
    }

   public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = router.find(key);
        if (it == router.end()) {
            return -1;
        }
        int val = it->second->value;
        updateCache(key);
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        auto rit = router.find(key);
        if (rit != router.end()) {
            rit->second->value = value;  // key已存在，更新value。
            updateCache(key);
        } else {
            if (router.size() == capacity) {
                swapOut();
            }
            if (cache.empty() || cache.back().cnt != 1) {
                cache.push_back(
                    FreqNode(1));  //不存在频次为 1 的数据链表，创建一个。
            }
            auto it = --cache.end();
            it->dataList.push_front(
                DataNode(key, value, it));  //插入到数据链表。
            router.insert(make_pair(key, it->dataList.begin()));  //更新router
        }
    }
};

int main(int argc, char const *argv[]) { return 0; }
