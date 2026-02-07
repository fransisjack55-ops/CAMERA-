#include <iostream>

class StealthCamMFSource {
public:
    StealthCamMFSource() {
        ModuleAddRef();
    }
    ~StealthCamMFSource() {
        ModuleRelease();
    }
    
    void ModuleAddRef() {
        std::cout << "ModuleAddRef called" << std::endl;
    }
    
    void ModuleRelease() {
        std::cout << "ModuleRelease called" << std::endl;
    }
};

class StealthCamStream {
public:
    StealthCamStream() {
        ModuleAddRef();
    }
    ~StealthCamStream() {
        ModuleRelease();
    }
    
    void ModuleAddRef() {
        std::cout << "ModuleAddRef called" << std::endl;
    }
    
    void ModuleRelease() {
        std::cout << "ModuleRelease called" << std::endl;
    }
};

int main() {
    StealthCamMFSource source;
    StealthCamStream stream;
    return 0;
}