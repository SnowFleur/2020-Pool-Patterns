#include"TestCode.h"

CTestCode::CTestCode() {
    uPtrGameObjPoolHandle_ = std::make_unique<CObjectPool<CGameObject>>(10);
    uPtrMemoryPoolHandle_ = std::make_unique<CFixedBlcok<CGameObject>>();
}

void CTestCode::NotUsePool() {
    for (int i = 0; i < MAX_LOOP_NUMBER; ++i) {
        CGameObject* temp = new CGameObject();
        delete temp;
    }
}

void CTestCode::UsePool() {
    for (int i = 0; i < MAX_LOOP_NUMBER; ++i) {
       auto temp = uPtrGameObjPoolHandle_->GetMemory();
    }
}

void CTestCode::Run(POOL_TYPE type) {


    switch (type){
    case POOL_TYPE::OBEJCT_POOL:
        break;
    case POOL_TYPE::MEMORY_POOL:
        break;
    case POOL_TYPE::THREAD_POOL:
        break;
    default:
        break;
    }


#ifdef  _DEBUG
#else   //_RELEASE
    auto startTime = high_resolution_clock::now();
    UsePool();
    auto endTime = high_resolution_clock::now();

    duration<double>elapsedTime = endTime - startTime;
    std::cout << "Using ObjectPool elapsed Time: " << elapsedTime.count() << " s\n";

    startTime = high_resolution_clock::now();
    NotUsePool();
    endTime = high_resolution_clock::now();

    elapsedTime = endTime - startTime;
    std::cout << "Not Using ObjectPool elapsed Time: " << elapsedTime.count() << " s\n";
#endif
    system("pause");
}
