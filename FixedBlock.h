#pragma once

template<class T>
class CFixedBlcok{
private:
    struct freeBlock {
        freeBlock* next_;
    };
    freeBlock* freeBlockPtr_;
    size_t      blockSize_;
    T           handle_;
public:
    void* Allocate(size_t size);
    bool        Empty()const;
};



#include"FixedBlock.inl"
