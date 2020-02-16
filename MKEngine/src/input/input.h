#pragma once

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace mike { namespace input {

	class Input {

	private:
		static Input* instance;
		bool keys[MAX_KEYS];
		bool buttons[MAX_BUTTONS];
		double mx, my;
	public:
		double getMouseX() { return mx; };
		double getMouseY() { return my; };
		



		static Input* getInstance()
		{
			if (!instance)
				instance = new Input();
			return instance;
		}




};



}  }