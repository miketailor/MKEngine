#pragma once
#include <GL/glew.h>
#include "../utils/fileutils.h"
namespace mike { namespace graphics {

	class Shader
	{
	private:
		const char* vertPath, *fragPath;

	public:
		GLuint shaderID;
		Shader(const char* vertPath, const char* fragPath);
		~Shader();


		void enable() const;
		void disable() const;
	private:
		GLuint load();


	};

} }