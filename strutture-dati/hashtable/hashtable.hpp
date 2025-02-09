#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP


template <typename T>
class hashTable{
    private:
        T * table;
        std::size_t capacity;
        std::size_t keysNo;
        enum class _slotState { empty, deleted, taken };
        _slotState * slotState;
        int hashFunc(T val, int i);
        void set(int index, T val);
        
    public:
        hashTable(int capacity);
        ~hashTable();
        void print();
        T get(int index);
        void insert(T val);
        void del(T val);
        int search(T val);
        bool isIn(T val);
        bool isFull();
};

#include "hashtable.tpp"

#endif