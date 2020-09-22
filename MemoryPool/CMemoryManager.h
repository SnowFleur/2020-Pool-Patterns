#pragma once

template<class Memory>
class CMemoryManager{
private:
    struct freeBlock {
        freeBlock* next_;
    };
    freeBlock*      freeBlockPtr_;
    size_t          blockSize_;
    Memory          handle_;
public:
    void*           Allocate(size_t size);
    bool            Empty()const;
    size_t          BlockSize()const;
    size_t          Capacity()const;
    void            Clear();
    void            Deallocate(void*);
};


#include"CMemoryManager.inl"
