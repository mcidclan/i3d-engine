#ifndef RENDERER_HPP
#define RENDERER_HPP

	#include <iostream>
	#include <GL/glew.h>
	#include <GL/glut.h>
	#include "constants.hpp"

	using namespace std;

	class Renderer
	{
		public:
			/// Create an Opengl 2.x Renderer using Glut.
			Renderer(int, char**);

			/// Destructor.
			~Renderer();

			///
			void start(void);

			/// Allows to set the internal drawing process. 
			void setProcess(void (*)(void));

		private:
			/// The current Renderer.
			static Renderer *current;

			/// Internal drawing process.
			void (* process)(void);

			/// Init the Opengl Context.
			void init(void);

			/// Glut reshape function.
			static void reshape(int, int);

			/// Glut display function.
			static void display(void);

			/// Glut idle function.
			static void idle();

			/// Drawing process.
			void draw(void);

	};

#endif
