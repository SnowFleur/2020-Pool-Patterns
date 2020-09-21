#include<iostream>
#include<memory>
#include"TestCode.h"

int main() {
    std::unique_ptr<CTestCode> test = std::make_unique<CTestCode>();
#ifdef _DEBUG
    std::cout << " Change to Release Mode\n";
#else
    //Set Test Type Pool
    test->Run(POOL_TYPE::OBEJCT_POOL);
#endif // _DEBUG
}