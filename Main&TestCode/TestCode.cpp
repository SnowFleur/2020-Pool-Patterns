#include"TestCode.h"

CTestCode::CTestCode() {
#ifdef OBJECT_POOL  //Test Not ObJect Pool
    uPtrGameObjPoolHandle_ = std::make_unique<CObjectPool<CGameObject>>(10);
#elif MEMORY_POOL //Test Not Memory Pool

#elif THREAD_POOL //Test Not Thread Pool
#endif
}

void CTestCode::NotUsePool() {
#ifdef OBJECT_POOL  //Test Not ObJect Pool
    for (int i = 0; i < MAX_LOOP_NUMBER; ++i) {
        CGameObject* temp = new CGameObject();
        delete temp;
    }
#elif MEMORY_POOL //Test Not Memory Pool

#elif THREAD_POOL //Test Not Thread Pool

#endif // 
}

void CTestCode::UsePool() {
#ifdef OBJECT_POOL  //Test ObJect Pool
    for (int i = 0; i < MAX_LOOP_NUMBER; ++i) {
        auto temp = uPtrGameObjPoolHandle_->GetMemory();
    }
#elif MEMORY_POOL //Test Memory Pool


#elif THREAD_POOL //Test Thread Pool


#endif // 
}


void CTestCode::Run() {

    RunPool();

    system("pause");
}


void CTestCode::RunPool() {

    auto startTime = high_resolution_clock::now();
    UsePool();
    auto endTime = high_resolution_clock::now();
    duration<double>elapsedTime = endTime - startTime;

#ifdef OBJECT_POOL  //Test ObJect Pool
    std::cout << "Using ObjectPool elapsed Time: " << elapsedTime.count() << " s\n";
#elif MEMORY_POOL //Test Memory Pool
    std::cout << "Using MemoryPool elapsed Time: " << elapsedTime.count() << " s\n";
#elif THREAD_POOL //Test Thread Pool
    std::cout << "Using ThreadPool elapsed Time: " << elapsedTime.count() << " s\n";
#endif // 

    startTime = high_resolution_clock::now();
    NotUsePool();
    endTime = high_resolution_clock::now();

#ifdef OBJECT_POOL  //Test ObJect Pool
    std::cout << "Not Using ObjectPool elapsed Time: " << elapsedTime.count() << " s\n";
#elif MEMORY_POOL //Test Memory Pool
    std::cout << "Not Using MemoryPool elapsed Time: " << elapsedTime.count() << " s\n";
#elif THREAD_POOL //Test Thread Pool
    std::cout << "Not Using ThreadPool elapsed Time: " << elapsedTime.count() << " s\n";
#endif // 

}
