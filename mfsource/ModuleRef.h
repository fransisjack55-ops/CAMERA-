# ModuleRef.h

#ifndef MODULEREF_H
#define MODULEREF_H

#include <atomic>

class ModuleRef {
public:
    ModuleRef() : ref_count(0) {}
    
    void addRef() {
        ref_count++;
    }
    
    void release() {
        if (--ref_count == 0) {
            delete this;
        }
    }
    
private:
    std::atomic<int> ref_count;
};

#endif // MODULEREF_H
