//
// Created by joydm on 17-11-2025.
//

#ifndef AZR_ENG_2_0_RENDERER_H
#define AZR_ENG_2_0_RENDERER_H
#include <vector>
#include <vulkan/vulkan_core.h>

class Renderer {
public:
    Renderer() {
        m_instance = nullptr;
    }

    ~Renderer() {
        m_instance = nullptr;
    }

    VkResult init();

private:
    VkInstance m_instance;
    std::vector<VkPhysicalDevice> m_physicalDevices;


};


#endif // AZR_ENG_2_0_RENDERER_H
