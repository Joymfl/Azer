//
// Created by joydm on 17-11-2025.
//

#include "Renderer.h"

#include <iostream>
#include <vulkan/vulkan_core.h>

VkResult Renderer::init() {
VkResult result = VK_SUCCESS;
    VkApplicationInfo appInfo = {};
    VkInstanceCreateInfo instanceCreateInfo = {};

    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "TestApp";
    appInfo.applicationVersion = 1;
    appInfo.apiVersion = VK_MAKE_VERSION(1,0,0);

    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;

    result = vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance);

    if (result == VK_SUCCESS) {
        uint32_t physicalDeviceCount = 0;
        vkEnumeratePhysicalDevices(m_instance, &physicalDeviceCount, nullptr);

        m_physicalDevices.resize(physicalDeviceCount);
        vkEnumeratePhysicalDevices(m_instance, &physicalDeviceCount, &m_physicalDevices[0]);
        for (auto Device: m_physicalDevices) {
            VkPhysicalDeviceProperties props;
            vkGetPhysicalDeviceProperties(Device, &props);
            std::cout<< "Physical devices: " << props.deviceName << std::endl
            << "\t vendorID: " << props.vendorID
            << std::endl
            << "\t Device type:" << props.deviceType << std::endl;
        }
    }

    return result;
}

