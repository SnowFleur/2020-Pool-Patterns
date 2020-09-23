#include <algorithm>
#include<stdlib.h>
#include"FixedMemoryBlock.h"

CFixedMemoryBlock::CFixedMemoryBlock(size_t fixedMemorySize)
    :arena_size_{fixedMemorySize}, memoryHandle_{nullptr}, block_size_{ 0 } {
    
    memoryHandle_ = (char*)malloc(arena_size_);

}

void* CFixedMemoryBlock::Allocate(size_t size) {

    //�޸𸮰� �̹� �Ҵ�ƴٸ� nullptr ��ȯ
    if (Empty() == false) {
        return nullptr;
    }


    //�䱸�ϴ� size�� �� ũ�� �� �����ŭ
    //�۴ٸ� ������ ũ�⸸ŭ size�� ��´�.
    block_size_ = std::max(size, sizeof(void*));
    size_t count = Capacity();

    //�䱸�ϴ� ũ�⸸ŭ �޸𸮸� �ټ��� ����.
    if (count == 0) {
        return nullptr;
    }

    //�޸� �ڵ��� 1����Ʈ�� �ڸ� �� �ִ� char* ������������ ĳ����
    char* p = reinterpret_cast<char*>(memoryHandle_);

    //��ϰ��� ���Ḯ��Ʈ ����
    for (; count > 1; --count, p += size) {
        *reinterpret_cast<char**>(p) = p + size;
    }
    //�������� nullptr
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

