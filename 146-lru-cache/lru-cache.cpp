class LRUCache {
public:
struct ListNode {
    int key, val;
    ListNode *prev, *next;
    ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
    unordered_map<int, ListNode*> mpp;
    int capacity;
    ListNode* head;
    ListNode* tail;
    LRUCache(int capacity_) {
        capacity = capacity_;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void insertAfterHead(ListNode* node) {
        ListNode* curr = head->next;
        head->next = node;
        node->next = curr;
        node->prev = head;
        curr->prev = node;
    }
    void deleteNode(ListNode* node) {
        ListNode* prevNode = node->prev;
        ListNode* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }
    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        ListNode* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            ListNode* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {
                ListNode* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            ListNode* node = new ListNode(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */