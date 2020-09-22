#pragma once

//Select to Pool
#define MEMORY_POOL 1
//#define OBJECT_POOL 2
//#define THREAD_POOL 3



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

#endif

using namespace std::chrono;

constexpr int MAX_LOOP_NUMBER = 10;

class CTestCode {
private:
    UPtrPool    uPtrPoolHandle_;
    void        RunPool();
    void        NotUsePool();
    void        UsePool();
public:
    CTestCode();
    void        Run();
    
};
