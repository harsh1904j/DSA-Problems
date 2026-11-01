class LFUCache {
    struct ListNode {
        int key, val, freq;
        ListNode *prev, *next;
        ListNode(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };
    struct List {
        ListNode *head, *tail;
        int size = 0;
        List() {
            head = new ListNode(0, 0);
            tail = new ListNode(0, 0);
            head->next = tail;
            tail->prev = head;
        }
        ~List() { delete head; delete tail; }
        void addFront(ListNode* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }
        void remove(ListNode* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        ListNode* removeLast() {
            ListNode* node = tail->prev;
            remove(node);
            return node;
        }
    };
    int cap, minFreq;
    unordered_map<int, ListNode*> keyMap;
    unordered_map<int, List*> freqMap;
    void touch(ListNode* node) {
        List* oldList = freqMap[node->freq];
        oldList->remove(node);
        if (oldList->size == 0) {
            if (minFreq == node->freq) minFreq++;
            delete oldList;
            freqMap.erase(node->freq);
        }
        node->freq++;
        if (!freqMap.count(node->freq)) freqMap[node->freq] = new List();
        freqMap[node->freq]->addFront(node);
    }
public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    int get(int key) {
        auto it = keyMap.find(key);
        if (it == keyMap.end()) return -1;
        ListNode* node = it->second;
        touch(node);
        return node->val;
    }
    void put(int key, int value) {
        if (cap == 0) return;
        auto it = keyMap.find(key);
        if (it != keyMap.end()) {
            it->second->val = value;
            touch(it->second);
            return;
        }
        if ((int)keyMap.size() == cap) {
            List* minList = freqMap[minFreq];
            ListNode* victim = minList->removeLast();
            keyMap.erase(victim->key);
            delete victim;
            if (minList->size == 0) {
                delete minList;
                freqMap.erase(minFreq);
            }
        }
        ListNode* node = new ListNode(key, value);
        keyMap[key] = node;
        if (!freqMap.count(1)) freqMap[1] = new List();
        freqMap[1]->addFront(node);
        minFreq = 1;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */