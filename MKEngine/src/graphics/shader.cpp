#include "shader.h"
#include <vector>
#include <iostream>
namespace mike {
	namespace graphics {
		Shader::Shader(const char* vertPath, const char* fragPath)
			:vertPath(vertPath),fragPath(fragPath)
		{
			shaderID = load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(shaderID);
		}

		void Shader::enable() const
		{
			glUseProgram(shaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}
		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);


			std::string vertSourceString = FileUtils::read_file(vertPath);
			std::string fragSourceString = FileUtils::read_file(fragPath);
			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "failed to compile vertex shader "<<std::endl<< &error[0] << std:: endl;
				glDeleteShader(vertex);
				return 0;				
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "failed to compile fragment shader" <<std::endl<< &error[0] << std::endl;
				glDeleteShader(fragment);
				glDeleteShader(vertex);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(fragment);
			glDeleteShader(vertex);

			return program;
			 


			return GLuint();
		}
	}
}