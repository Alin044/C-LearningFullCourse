#include <iostream>

class IRenderer{
    public:
        //This is a true virtual funciton
        virtual void Draw() = 0;
        virtual void Update() = 0;
        virtual void DrawOptimized() = 0;
};

class OpenGL : public IRenderer{
    public:
        void Draw() override{
            std::cout << "OpenGL Draw " << std::endl;
        }
        void Update() override{
            std::cout << "OpenGL Update " << std::endl;
        }
        void DrawOptimized() override{

        }
};

class Vulkan : public IRenderer{
    public:
        void Draw() override{
            std::cout << "Vulkan Draw " << std::endl;
        }
        void Update() override{
            std::cout << "Vulkan Update " << std::endl;
        }
        void DrawOptimized() override{
            
        }
};

int main(){

    IRenderer* myRenderer = new OpenGL;
    myRenderer -> Draw();
    myRenderer -> Update();

    return 0;
}