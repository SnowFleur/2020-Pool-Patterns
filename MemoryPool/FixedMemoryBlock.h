#pragma once

class CFixedMemoryBlock{
private:
	void*		memoryHandle_;
	size_t		arena_size_;
	size_t		block_size_;
public:
    CFixedMemoryBlock(size_t fixedMemorySize);
	~CFixedMemoryBlock();
    CFixedMemoryBlock(const CFixedMemoryBlock&) = delete;
    CFixedMemoryBlock(CFixedMemoryBlock&&) = delete;
    CFixedMemoryBlock& operator=(const CFixedMemoryBlock&) = delete;
    CFixedMemoryBlock& operator=(CFixedMemoryBlock&&) = delete;

	void*		Allocate(size_t);
	size_t		Block_size() const;
	size_t		Capacity() const;
	void		Clear();
	bool		Empty() const;
};

