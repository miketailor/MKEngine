#include <iostream>
#include <GLFW/glfw3.h>

int main()
{
	if (!glfwInit())
		std::cout << "error" << std::endl;
	else
		std::cout << "OK" << std::endl;
	
	return 0;

}