#pragma once


#include<iostream>
#include<chrono>
#include<memory>
#include"objectPool.h"
#include"GameObject.h"
#include"FixedBlock.h"

using namespace std::chrono;

constexpr int MAX_LOOP_NUMBER = 10;

enum class POOL_TYPE {
    OBEJCT_POOL=1,
    MEMORY_POOL,
    THREAD_POOL,
};

class CTestCode {
private:
    std::unique_ptr<CObjectPool<CGameObject>> uPtrGameObjPoolHandle_;
    std::unique_ptr<CFixedBlcok<CGameObject>> uPtrMemoryPoolHandle_;

    void NotUsePool();
    void UsePool();
    void RunByMemoryPool();
    void RunByObjectPool();
    void RunByThreadPool();
public:
    CTestCode();
    void Run(POOL_TYPE type);
    
};
