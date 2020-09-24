#include<iostream>
#include<memory>
#include"TestCode.h"


int main() {
    //std::unique_ptr<CTestCode> test = std::make_unique<CTestCode>();
    CTestCode test;
#ifdef _DEBUG
    std::cout << " **********Excute Debug Mode**********\n\n";
#endif // _DEBUG
    
#ifdef  WIN32
    std::cout << "**********Excute Releae Mode x86**********\n\n";
#else
    std::cout << "**********Excute Releae Mode x64**********\n\n";
#endif //  WIN32
    test.Run();
} 