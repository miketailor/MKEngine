#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32


namespace mike {	namespace graphics {

	class Window
	{
	private:
		int width, height;
		const char* title;
		GLFWwindow* window;
		bool closed;

		bool keys[MAX_KEYS];
		bool mouseButtons[MAX_BUTTONS];
		double mx, my;


		bool  init();
		
	public:
		Window(const char* title, int width, int height);
		~Window();
		void update() ;
		void clear() const;
		inline void setHeight(int h) { height = h; };
		inline void setWidth(int w) { width = w; };
		inline int getHeight() { return height; };
		inline int getWidth() { return width; };

		bool isClosed() const { return glfwWindowShouldClose(window); };

		bool isKeyPressed(unsigned int key) const;
		bool isMouseButtonPressed(unsigned int button) const;
		double getMouseX() const { return mx; } ;
		double getMouseY() const { return my; } ;



		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};


}}