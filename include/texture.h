#pragma once

#include "glad/glad.h"

#include <string>

#include "shaderClass.h"

class Texture {
	public:
		GLuint ID;
		GLenum type;
		Texture(const std::string image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

		void texUnit(Shader& shader, const std::string uniform, GLuint unit);
		void Bind();
		void Unbind();
		void Delete();
};