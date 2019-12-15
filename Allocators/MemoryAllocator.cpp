#include "MemoryAllocator.h"
#include <windows.h>
#include <cmath>

int MemoryAllocator::align(int size)
{
    auto value = pow(2, ceil(log2(size)));
    return value >=16 ? value : 16;
}

MemoryAllocator::MemoryAllocator()
{
    isInit = false;
	
}

MemoryAllocator::~MemoryAllocator()
{
    this->MemoryAllocator::destroy();
}

void MemoryAllocator::init()
{
    int start = 16;

    for (; start <= 512; start *= 2)
    {
        auto allocator = new FixedSizeAllocator(start);
        allocator->init();

        allocators.insert_or_assign(start, allocator);
    }

    isInit = true;
}

void* MemoryAllocator::alloc(int size)
{
    if (!isInit) return nullptr;
	if(size > 512)
	{
		return VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	}
    auto alignedSize = align(size);
    auto allocator = allocators[alignedSize];
    return  allocator->alloc();
}

void MemoryAllocator::free(void* ptr)
{
    if (!isInit) return;
    bool contains = false;
	for (auto it=allocators.begin(); it!=allocators.end();++it)
	{
       if( it->second->free(ptr)) contains=true;
	}
    if(!contains)
    VirtualFree(ptr, 0, MEM_RELEASE);
}

void MemoryAllocator::destroy()
{
    if (!isInit) return;
    for (auto it = allocators.begin(); it != allocators.end(); ++it)
    {
        it->second->destroy();
    }
    isInit = false;
}

void MemoryAllocator::dumpBlocks()
{
    if (!isInit) return;
    for (auto it = allocators.begin(); it != allocators.end(); ++it)
    {
        it->second->dumpBlocks();
    }
}


