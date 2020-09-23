#pragma once

template<class MemoryBlock>
class CMemoryManager{
private:
    struct freeBlock {
        freeBlock* next_;
    };
    freeBlock*      freeBlockPtr_;
    MemoryBlock     memoryBlockHandle_;
    size_t          blockSize_;
public:
    CMemoryManager(size_t fixedMemorySize);
    ~CMemoryManager() = default;

    CMemoryManager(const CMemoryManager&) = delete;
    CMemoryManager(CMemoryManager&&) = delete;
    CMemoryManager& operator=(const CMemoryManager&) = delete;
    CMemoryManager& operator=( CMemoryManager&&) = delete;

    void*           Allocate(size_t size);
    bool            Empty()const;
   // size_t          BlockSize()const;
    size_t          Capacity()const;
    void            Clear();
    void            Deallocate(void*);
};

#include"CMemoryManager.inl"
