# pragma once

template<class T>
inline void* CFixedBlcok<T>::Allocate(size_t size) {

    if (Empty()) {
        freeBlockPtr_ = reinterpret_cast<freeBlock*>(handle_.Allocate(size));
    }

}

template<class T>
inline bool CFixedBlcok<T>::Empty()const {

    if (blockSize_ == 0) {
        return true;
    }
    return false;
}