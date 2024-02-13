#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <sstream>

std::string read_file_contents(const std::string& file_path);

class Shader 
{
	public:
		GLuint ID;
		Shader(const std::string& vertex_file, const std::string& fragment_file);

		void Activate();
		void Delete();

	private:
		void compileErrors(unsigned int shader, std::string type);
};

#endif // !SHADER_CLASS_H
