#include "src/graphics/window.h"


int main()
{
	mike::graphics::Window window("Mike", 960,540);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	
	while (!window.isClosed())
	{
		
		window.clear();
	
		
			std::cout<<window.getMouseX() << "x" <<window.getMouseY()<< std::endl; 
#if 1
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		window.update();
	} 
	
	return 0;

}