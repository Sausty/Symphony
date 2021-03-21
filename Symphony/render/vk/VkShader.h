#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <string>

#include "render/Shader.h"

namespace symphony
{
	class VulkanShader : public Shader
	{
	public:
		// Can't compile shaders in runtime, they must already be in SPIRV format
		// TODO : Include a runtime shader compiler
		VulkanShader(std::string vertexFile, std::string fragmentFile);
		~VulkanShader();

		virtual void* GetVertexShader() override {
			return (void*)m_VertexShader;
		}

		virtual void* GetFragmentShader() override {
			return (void*)m_FragmentShader;
		}

		virtual void* GetLinkedProgram() override {
			return nullptr;
		}
	private:
		VkShaderModule m_VertexShader;
		VkShaderModule m_FragmentShader;
		const VkDevice& m_DeviceCopy;
	};
}