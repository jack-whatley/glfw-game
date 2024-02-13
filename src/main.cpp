#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

GLfloat vertices[] =
{
	//                  positions                         /      colours
	-0.5f,     -0.5f * float(sqrt(3)) / 3,     0.0f,  0.8f, 0.3f,  0.02f,
	0.5f,      -0.5f * float(sqrt(3)) / 3,     0.0f,  0.8f, 0.3f,  0.02f,
	0.0f,       0.5f * float(sqrt(3)) * 2 / 3, 0.0f,  1.0f, 0.6f,  0.32f,
	-0.5f / 2,  0.5f * float(sqrt(3)) / 6,     0.0f,  0.9f, 0.45f, 0.17f,
	0.5f / 2,   0.5f * float(sqrt(3)) / 6,     0.0f,  0.9f, 0.45f, 0.17f,
	0.0f,      -0.5f * float(sqrt(3)) / 3,     0.f,   0.8f, 0.3f,  0.02f,
};

GLuint indices[] =
{
	0, 3, 5,
	3, 2, 4,
	5, 4, 1
};

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "glfw game window", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << "\n";
		glfwTerminate();

		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();

	glViewport(0, 0, 800, 800);

	Shader shaderProgram("default.vert", "default.frag");

	VAO vao1;
	vao1.Bind();

	VBO vbo1(vertices, sizeof(vertices));
	EBO ebo1(indices, sizeof(indices));

	vao1.LinkAttrib(&vbo1, 0, 3, GL_FLOAT, 6 * sizeof(float), nullptr);
	vao1.LinkAttrib(&vbo1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	vao1.Unbind();
	vbo1.Unbind();
	ebo1.Unbind();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.09f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();
		vao1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	vao1.Delete();
	vbo1.Delete();
	ebo1.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}