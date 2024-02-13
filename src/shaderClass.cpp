#include "shaderClass.h"

#include <fstream>

std::string read_file_contents(const std::string& file_path)
{
	std::ifstream inf{ file_path, std::ios::binary };

	if (inf)
	{
		std::string file_contents;

		inf.seekg(0, std::ios::end);

		file_contents.resize(inf.tellg());

		inf.seekg(0, std::ios::beg);
		inf.read(&file_contents[0], file_contents.size());

		inf.close();

		return file_contents;
	}
	throw errno;
}

Shader::Shader(const std::string& vertex_file, const std::string& fragment_file)
{
	// load in shader file contents
	const std::string vertex_code = read_file_contents(vertex_file);
	const std::string fragment_code = read_file_contents(fragment_file);

	// convert to char arrays for glfw
	const char* vertexSource = vertex_code.c_str();
	const char* fragSource = fragment_code.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragSource, NULL);
	glCompileShader(fragmentShader);

	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}
