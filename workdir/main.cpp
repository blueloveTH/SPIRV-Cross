#include "CoreKeeperWorld.cpp"
#include <iostream>

int main(){
    std::cout << "hello!" << std::endl;
    spirv_cross_shader_t* shader = spirv_cross_construct();
    // 设置必要的参数
    // shader-> ...

    // 调用shader
    // spirv_cross_invoke(shader);
    spirv_cross_destruct(shader);
    return 0;
}