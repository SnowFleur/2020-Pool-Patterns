#include<iostream>
#include<memory>
#include"TestCode.h"


int main() {
    //std::unique_ptr<CTestCode> test = std::make_unique<CTestCode>();
    CTestCode test;
#ifdef _DEBUG
    std::cout << " **********Excute Debug Mode**********\n\n";
#endif // _DEBUG
    test.Run();
} 