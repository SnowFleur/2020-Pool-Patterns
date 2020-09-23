#include <algorithm>
#include<stdlib.h>
#include"FixedMemoryBlock.h"

CFixedMemoryBlock::CFixedMemoryBlock(size_t fixedMemorySize)
    :arena_size_{fixedMemorySize}, memoryHandle_{nullptr}, block_size_{ 0 } {
    
    memoryHandle_ = (char*)malloc(arena_size_);

}

void* CFixedMemoryBlock::Allocate(size_t size) {

    //메모리가 이미 할당됐다면 nullptr 반환
    if (Empty() == false) {
        return nullptr;
    }


    //요구하는 size가 더 크면 그 사이즈만큼
    //작다면 포인터 크기만큼 size를 잡는다.
    block_size_ = std::max(size, sizeof(void*));
    size_t count = Capacity();

    //요구하는 크기만큼 메모리를 줄수가 없다.
    if (count == 0) {
        return nullptr;
    }

    //메모리 핸들을 1바이트씩 자를 수 있는 char* 포인터형으로 캐스팅
    char* p = reinterpret_cast<char*>(memoryHandle_);

    //블록간의 연결리스트 생성
    for (; count > 1; --count, p += size) {
        *reinterpret_cast<char**>(p) = p + size;
    }
    //마지막은 nullptr
    *reinterpret_cast<char**>(p) = nullptr;
    return memoryHandle_;
}

size_t CFixedMemoryBlock::Block_size()const {
    return block_size_;
}

size_t CFixedMemoryBlock::Capacity()const {
    if (block_size_ == 0)
        return 0;
    return arena_size_ / block_size_;
}

void CFixedMemoryBlock::Clear() {
    block_size_ = 0;
}

bool CFixedMemoryBlock::Empty()const {
    if (block_size_ == 0) {
        return true;
    }
    return false;
}

