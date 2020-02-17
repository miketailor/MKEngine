#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
int main()
{
	mike::graphics::Window window("Mike", 960,540);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	
	GLfloat verticies[] =
	{
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f

	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
	glEnableVertexAttribArray(0);


	mike::graphics::Shader shader("src/shaders/basic.vert","src/shaders/basic.frag");

	shader.enable();

	glm::mat4 ortho = glm::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

		
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "pr_matrix"), 1, GL_FALSE,glm::value_ptr(ortho));

	while (!window.isClosed())
	{
		
		window.clear();
	
		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	} 
	
	return 0;

}