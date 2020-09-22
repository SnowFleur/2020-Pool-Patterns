#pragma once

class CFixedMemoryBlock{
private:
	void*		arena_;
	size_t		arena_size_;
	size_t		block_size_;
public:
	void*		Allocate(size_t);
	size_t		Block_size() const;
	size_t		Capacity() const;
	void		Clear();
	bool		Empty() const;
};

