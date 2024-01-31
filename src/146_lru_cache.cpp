#include "utils/print_util.h"
#include "utils/test_assert.h"

struct LinkedListNode {
    int key;
    int val;
    LinkedListNode* pre{nullptr};
    LinkedListNode* next{nullptr};
};

class LinkedList {
public:
    LinkedList() {
        
    }
    ~LinkedList() {
        LinkedListNode* tmp = head;
        while (tmp) {
            LinkedListNode* del_node = tmp;
            tmp = tmp->next;
            delete del_node;
        }
    }
    LinkedListNode* head{nullptr};
    LinkedListNode* tail{nullptr};

    void add_head(LinkedListNode* node) {
        if (!head) {
            head = node;
            tail = node;
            //std::cout << "add node:" << node->key
            //<< ", head:" << head << ", tail:" << tail << std::endl;
            return;
        }
        node->next = head;
        head->pre = node;
        head = node;
        //std::cout << "add node:" << node->key
        //    << ", head:" << head << ", tail:" << tail << std::endl;
    }
    void del_node(LinkedListNode* node) {
        if (node->pre) {
            node->pre->next = node->next;
        }
        if (node->next) {
            node->next->pre = node->pre;
        }
        if (node == head) {
            head = node->next;
        }
        if (node == tail) {
            tail = node->pre;
        } 
        //std::cout << "del node:" << node->key << ", head:" << head << ", tail:" << tail << std::endl;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (_kv.count(key) == 0) {
            return -1;
        }
        LinkedListNode* node = _kv[key];
        if (node != _list.head) {
            _list.del_node(node);
            _list.add_head(node);
        }
        return node->val;
    }
    
    void put(int key, int value) {
        if (_kv.count(key) == 0 && _kv.size() >= _capacity) {
            //std::cout << "remove tail node:" << _list.tail->key << std::endl;
            if (_list.tail) {
                _kv.erase(_list.tail->key);
                LinkedListNode* last_node = _list.tail;
                _list.del_node(last_node);
                delete last_node;
            }
        }
        LinkedListNode* node = nullptr;
        if (_kv.count(key)) {
            node = _kv[key];
            _list.del_node(node);
        } else {
            node = new LinkedListNode();
        }
        
        node->key = key;
        node->val = value;
        _list.add_head(node);
        _kv[key] = node;
    }
    unordered_map<int, LinkedListNode*> _kv;
    LinkedList _list;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(1, 11);
    obj->put(2, 22);
    int ret = obj->get(1);
    ASSERT_EQUAL(11, ret);
    obj->put(3, 3);
    obj->put(3, 3);
    ret = obj->get(2);
    ASSERT_EQUAL(-1, ret);
    obj->get(3);
    obj->get(4);
    ret = obj->get(1);
    
    obj->get(6);
    delete obj;
    return 0;
}
