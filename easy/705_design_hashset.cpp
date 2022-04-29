class MyHashSet {
public:
    MyHashSet()
        : tbl(TBL_SIZE, nullptr)
    {
    }

    void add(int key) {
        TblNode*& pos = tbl[hash(key)];
        if (pos)
        {
            TblNode* head = pos;
            while (head->key != key && head->next)
            {
                head = head->next;
            }
            if (head->key != key)
            {
                head->next = new TblNode(key, nullptr, head);
            }
        }
        else
        {
            pos = new TblNode{key, nullptr, nullptr};
        }
    }

    void remove(int key) {
        TblNode* loc = locate(key);
        if (loc)
        {
            if (loc->prev) //< Not the first entry in linked list
            {
                loc->prev->next = loc->next;
            }
            else
            {
                tbl[hash(key)] = loc->next;
                if (loc->next)
                {
                    loc->next->prev = nullptr;
                }
            }
            delete loc;
        }
    }

    bool contains(int key) {
        return locate(key) != nullptr;
    }
private:
    int hash(int key)
    {
        return key % TBL_SIZE;
    }

    struct TblNode
    {
        int key{-1};
        TblNode* next{};
        TblNode* prev{};

        TblNode(int key_, TblNode* next_, TblNode* prev_)
            : key(key_), next(next_), prev(prev_)
        {
        }
    };

    // Returns ptr to the node containing the key,
    // or nullptr if not present.
    TblNode* locate(int key)
    {
        TblNode* head = tbl[hash(key)];
        while (head && head->key != key)
        {
            head = head->next;
        }
        return head;
    }

    void print()
    {
        for (int i = 0; i < TBL_SIZE; ++i)
        {
            auto const* head = tbl[i];
            if (head)
            {
                cout << "Entry " << i << ": ";
                while (head)
                {
                    cout << head->key << ' ';
                    head = head->next;
                }
                cout << endl;
            }
        }
    }

    static int const TBL_SIZE{1003};
    vector<TblNode*> tbl;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
