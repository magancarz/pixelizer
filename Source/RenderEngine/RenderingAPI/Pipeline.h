#pragma once

#include <string>
#include <vector>

#include "PipelineConfigInfo.h"
#include "VulkanSystem.h"

class Pipeline
{
public:
    Pipeline(
        const Device& device,
        VkPipelineLayout pipeline_layout,
        const std::string& vertex_file_path,
        const std::string& fragment_file_path,
        const PipelineConfigInfo& config_info);
    ~Pipeline();

    Pipeline(const Pipeline&) = delete;
    Pipeline& operator=(const Pipeline&) = delete;

    void bind(VkCommandBuffer command_buffer);
    void bindDescriptorSets(VkCommandBuffer command_buffer, VkDescriptorSet* descriptor_sets, uint32_t descriptor_set_count);

    static void defaultPipelineConfigInfo(PipelineConfigInfo& config_info);

private:
    static std::vector<char> readFile(const std::string& file_path);
    void createGraphicsPipeline(const std::string& vertex_file_path, const std::string& fragment_file_path, const PipelineConfigInfo& config_info);
    void createShaderModule(const std::vector<char>& code, VkShaderModule* shader_module);

    const Device& device;
    VkPipelineLayout pipeline_layout;
    VkPipeline graphics_pipeline;
    VkShaderModule vertex_shader_module;
    VkShaderModule fragment_shader_module;
};
