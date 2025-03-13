#include "CoreKeeperWorld.cpp"
#include "spirv_cross/external_interface.h"
#include <cstring>
#include <iostream>

#define NUM_WORKGROUPS 1

int main(){
    std::cout << "hello!" << std::endl;
    spirv_cross_shader_t* shader = spirv_cross_construct();

    Impl::Shader::Resources::CGlobals input;
    void* p_input = &input;
    memset(p_input, 0, sizeof(input));

	spirv_cross_set_resource(shader, 1, 0, &p_input, sizeof(input));

	uvec3 num_workgroups(NUM_WORKGROUPS, 1, 1);
	uvec3 work_group_id(0, 0, 0);
	spirv_cross_set_builtin(shader, SPIRV_CROSS_BUILTIN_WORK_GROUP_ID, &work_group_id, sizeof(work_group_id));
    spirv_cross_set_builtin(shader, SPIRV_CROSS_BUILTIN_NUM_WORK_GROUPS, &num_workgroups, sizeof(num_workgroups));
	for (unsigned i = 0; i < NUM_WORKGROUPS; i++)
	{
		work_group_id.x = i;
		spirv_cross_invoke(shader);
	}

    spirv_cross_destruct(shader);
    return 0;
}