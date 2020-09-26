#pragma once

//Select to Pool
#define MEMORY_POOL 1
//#define OBJECT_POOL 2
//#define THREAD_POOL 3

constexpr int       MAX_LOOP_NUMBER = 10000000; //성능 테스트 루프
constexpr size_t    MEMORY_SIZE = 1000; //메모리 풀 사이즈

#include<iostream>
#include<chrono>
#include<memory>
#include"GameObject.h"

#ifdef OBJECT_POOL  //ObJect Pool
    #include"..\ObjectPool\objectPool.h"
    using UPtrPool = std::unique_ptr<CObjectPool<CGameObject>>;
#elif MEMORY_POOL //Memory Pool
    #include"..\MemoryPool\CMemoryManager.h"
    #include"..\MemoryPool\FixedMemoryBlock.h"
    using UPtrPool = std::unique_ptr<CMemoryManager<CFixedMemoryBlock>>;
#elif THREAD_POOL  //Thread Pool
    #include"..\ThreadPool\"
    using UPtrPool = std::unique_ptr<CThreadPool>;
#endif

using namespace std::chrono;

class CTestCode {
private:
#ifdef MEMORY_POOL  //Memory Pool
    static UPtrPool uPtrPoolHandle_;
#else
    UPtrPool    uPtrPoolHandle_;
#endif
    void        RunPool();
    void        NotUsePool();
    void        UsePool();

public:
    CTestCode();
    void* operator new(size_t memorySize);
    void operator delete(void* DeletePtr);
    void        Run();
};
