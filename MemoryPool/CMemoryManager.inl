# pragma once

template<class Memory>
inline void* CMemoryManager<Memory>::Allocate(size_t size) {
    if (Empty()) {
        freeBlockPtr_ = reinterpret_cast<freeBlock*>(handle_.Allocate(size));
    }
}

template<class Memory>
inline bool CMemoryManager<Memory>::Empty()const {

    if (blockSize_ == 0) {
        return true;
    }
    return false;
}

template<class Memory>
inline size_t CMemoryManager<Memory>::BlockSize()const {
    return blockSize_;
}

template<class Memory>
inline size_t CMemoryManager<Memory>::Capacity()const {
    return handle_.Capacity();
}

template<class Memory>
inline void CMemoryManager<Memory>::Clear() {


}


template<class Memory>
inline void CMemoryManager<Memory>::Deallocate(void* ptr) {


}




