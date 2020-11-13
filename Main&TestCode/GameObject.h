#pragma once

#include<iostream>

class CGameObject{
private:
    char    name_[20];
    int     hp_;
    int     exp_;
    int     x_;
    int     y_;
    bool    isUsed_;
public:
    //CGameObject() = default;
    CGameObject() :name_{}, hp_{}, exp_{}, x_{}, y_{}, isUsed_{} {
        std::cout << "Call Constructor\n";
    }

    //~CGameObject() = default;
    ~CGameObject() {
        std::cout << "Call Distructor\n";
    }

};

