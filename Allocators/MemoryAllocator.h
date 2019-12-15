#pragma once
#include <map>
#include "FixedSizeAllocator.h"
class MemoryAllocator
{
private:
	std::map<int, FixedSizeAllocator*> allocators;
	bool isInit;

	static int align(int size);
public:
	MemoryAllocator();
	~MemoryAllocator();
	virtual void init();
	virtual void* alloc(int size);
	virtual void free(void* ptr);
	virtual void destroy();
	virtual void dumpBlocks();
	
	
};

