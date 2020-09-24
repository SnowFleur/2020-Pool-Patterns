# pragma once

template<class MemoryBlock>
inline CMemoryManager<MemoryBlock>::CMemoryManager(size_t fixedMemorySize)
    :freeBlockPtr_{ nullptr }, memoryBlockHandle_{fixedMemorySize}, blockSize_{ 0 } {}

template<class MemoryBlock>
inline void* CMemoryManager<MemoryBlock>::Allocate(size_t size) {
    // free_Ptr�� nullptr�̶��
    if (Empty()) {
        //Memory Block���� �޸𸮸� �޾ƿͼ� FreeBlock���� ĳ����
        freeBlockPtr_ = reinterpret_cast<freeBlock*>(memoryBlockHandle_.Allocate(size));
        //�䱸�� �޸� ũ�⸸ŭ ����
        blockSize_ = size;
        
        //������ freeBlockPtr�� nullptr �̸�
        //bad_alloc() ���� ����
        if (Empty() ) {
            throw std::bad_alloc();
        }
    }
    //�䱸�ϴ� ������� blockSize�� �۴ٸ�
    //���⿡���� �� ū �޸𸮿䱸�� ���� ����ó���� �Ѵٴ� �͵� ����(���� �޸𸮺��̱� ����)
    //bad_alloc() ���� ����
    if (size > blockSize_) {
        throw std::bad_alloc();
    }

    //freeBlockPtr�� �޸𸮸� p�� �Ҵ��ϰ�
    //freeBlockPtr�� ���� �޸𸮷� �̵�
    auto p = freeBlockPtr_;
    freeBlockPtr_ = freeBlockPtr_->next_;
    return p;
}

template<class MemoryBlock>
inline bool CMemoryManager<MemoryBlock>::Empty()const {
    if (freeBlockPtr_ ==nullptr) {
        return true;
    }
    return false;
}

template<class MemoryBlock>
inline size_t CMemoryManager<MemoryBlock>::Capacity()const {
    //�޸𸮺� �ڵ��� �� ����
    return memoryBlockHandle_.Capacity();
}

template<class MemoryBlock>
inline void CMemoryManager<MemoryBlock>::Clear() {
    freeBlockPtr_ = nullptr;
    memoryBlockHandle_.clear();
}


template<class MemoryBlock>
inline void CMemoryManager<MemoryBlock>::Deallocate(void* ptr) {

    if (ptr != nullptr) {
        //freeBlock���� ĳ����
        auto freePtr = reinterpret_cast<freeBlock*>(ptr);

        freePtr->next_ = freeBlockPtr_;
        freeBlockPtr_ = freePtr;
    }
}




