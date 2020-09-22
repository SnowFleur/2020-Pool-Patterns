#include"FixedMemoryBlock.h"


 void* CFixedMemoryBlock::Allocate(size_t size){}


 size_t CFixedMemoryBlock::Block_size()const {
     return block_size_;
 }

 size_t CFixedMemoryBlock::Capacity()const {
     return arena_size_;
 }

 void CFixedMemoryBlock::Clear() {}


 bool CFixedMemoryBlock::Empty()const {}

