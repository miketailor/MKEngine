#include "window.h"

namespace mike { namespace graphics {

	void window_resize_callback(GLFWwindow* window, int width, int height);



	Window::Window(const char* title, int width, int height)
		:title(title),width(width),height(height)
	{
		if (!init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();

	}

	bool Window::init()
	{

		if (!glfwInit())
		{
			std::cout << "Failed to initilize GLFW" << std::endl;
			return false;
		}

		
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			std::cout << "failed to create GLFW window"<<std::endl;
			return false;
		}
		glfwMakeContextCurrent(window);
		glfwSetWindowSizeCallback(window,window_resize_callback);

		std::cout <<"OpenGL: " << glGetString(GL_VERSION) << std::endl;

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;

		}



		return true;
	}

	void Window::update() 
	{
		glfwPollEvents();
	
		glfwSwapBuffers(window);


	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void window_resize_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


}}

