#include "window.h"

namespace mike { namespace graphics {

	 //callbacks declaration
	void window_resize_callback(GLFWwindow* window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	




	Window::Window(const char* title, int width, int height)
		:title(title),width(width),height(height)
	{
		if (!init())
			glfwTerminate();


		for (int i = 0; i < MAX_KEYS; i++)
			keys[i] = false;

		for (int i = 0; i < MAX_BUTTONS; i++)
			mouseButtons[i] = false;

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

		glfwSetWindowUserPointer(window, this);
		glfwSetWindowSizeCallback(window,window_resize_callback);
		glfwSetKeyCallback(window, key_callback);
		glfwSetMouseButtonCallback(window, mouse_button_callback);
		glfwSetCursorPosCallback(window, cursor_position_callback);
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

	bool Window::isKeyPressed(unsigned int key) const
	{
		//TODO: log this
		if (key > MAX_KEYS)
			return false;
		
		return keys[key];
	}

	bool Window::isMouseButtonPressed(unsigned int button) const
	{
		if (button > MAX_BUTTONS)
			return false;
		return mouseButtons[button];
	}

	void window_resize_callback(GLFWwindow* window, int width, int height)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->setHeight(height);
		win->setWidth(width);
		glViewport(0, 0, width, height);
	}


	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
	
			win->keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mouseButtons[button] = action != GLFW_RELEASE;

	}
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;

	}

}}

