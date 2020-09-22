#pragma once
#include<memory>
#include<queue>
#include<utility>
#include<iostream>

template<class T>
class CObjectPool {
    using SharedPtr     = std::shared_ptr<T>;
    using UniquePtr     = std::unique_ptr<T>;
    using ObjectQueue   = std::queue<UniquePtr>;
private:
    ObjectQueue objectQueue_;
public:
    CObjectPool(size_t initMemorySize);
    std::shared_ptr<T> GetMemory();
};

template<class T>
CObjectPool<T>::CObjectPool(size_t initMemorySize) {
    for (size_t i = 0; i < initMemorySize; ++i) {
        objectQueue_.emplace(std::make_unique<T>());
    }
}

template<class T>
std::shared_ptr<T> CObjectPool<T>::GetMemory() {

    if (objectQueue_.empty()) {
        objectQueue_.emplace(std::make_unique<T>());
       // std::cout << "ADD Pool\n";
    }

    UniquePtr frontobject = std::move(objectQueue_.front());
    objectQueue_.pop();
    
    SharedPtr obj(frontobject.release(), [this](T* t) {
        objectQueue_.emplace(t);
    });

    return obj;
}