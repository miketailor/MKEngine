#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
namespace mike {	namespace graphics {

	class Window
	{
	private:
		int width, height;
		const char* title;
		GLFWwindow* window;
		bool closed;
		
		bool  init();
		
	public:
		Window(const char* title, int width, int height);
		~Window();
		void update() ;
		void clear() const;

		bool isClosed() const { return glfwWindowShouldClose(window); };
	};


}}