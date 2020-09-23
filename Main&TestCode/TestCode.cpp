#include"TestCode.h"

#ifdef MEMORY_POOL //Init Memory Pool
UPtrPool CTestCode::uPtrPoolHandle_ =
std::make_unique<CMemoryManager<CFixedMemoryBlock>>(MEMORY_SIZE);
#endif


CTestCode::CTestCode() {
#if OBJECT_POOL  //Init ObJect Pool
    uPtrPoolHandle_ = std::make_unique<CObjectPool<CGameObject>>(10);
#elif THREAD_POOL //Init Thread Pool
    uPtrPoolHandle_ = std::make_uniqueu<CThreadpool>;
#endif
}

void CTestCode::NotUsePool() {
    for (int i = 0; i < MAX_LOOP_NUMBER; ++i) {
#ifdef OBJECT_POOL  //Test Not ObJect Pool
        CGameObject* temp = new CGameObject();
        delete temp;
#elif MEMORY_POOL //Test Not Memory Pool
        int* ptr = (int*)malloc(100);
        free(ptr);
#elif THREAD_POOL //Test Not Thread Pool
#endif // 
    }
}

void CTestCode::UsePool() {
    for (int i = 0; i < MAX_LOOP_NUMBER; ++i) {
#ifdef OBJECT_POOL  //Test ObJect Pool
        auto temp = uPtrPoolHandle_->GetMemory();
#elif MEMORY_POOL //Test Memory Pool
        try {
            int* intPtr = reinterpret_cast<int*>(uPtrPoolHandle_->Allocate(100));
            uPtrPoolHandle_->Deallocate(intPtr);
        }
        catch (std::bad_alloc&) {
            std::cout << "Error: bad_alloc\n";
            while (1);
        }
#elif THREAD_POOL //Test Thread Pool
#endif // 
    }
}


void CTestCode::Run() {
    RunPool();
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
    elapsedTime = endTime - startTime;

#ifdef OBJECT_POOL  //Test ObJect Pool
    std::cout << "Not Using ObjectPool elapsed Time: " << elapsedTime.count() << " s\n";
#elif MEMORY_POOL //Test Memory Pool
    std::cout << "Not Using MemoryPool elapsed Time: " << elapsedTime.count() << " s\n";
#elif THREAD_POOL //Test Thread Pool
    std::cout << "Not Using ThreadPool elapsed Time: " << elapsedTime.count() << " s\n";
#endif // 

}

void* CTestCode::operator new(size_t memorySize) {
    return uPtrPoolHandle_->Allocate(memorySize);
}

void CTestCode::operator delete(void* DeletePtr) {
    uPtrPoolHandle_->Deallocate(DeletePtr);
}