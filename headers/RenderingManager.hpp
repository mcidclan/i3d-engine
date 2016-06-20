#ifndef RENDERINGMANAGER_HPP
#define RENDERINGMANAGER_HPP

	#include "utils.hpp"
	#include "ShaderSources.hpp"

	#include "RenderText.hpp"
	#include "RenderTriangle.hpp"
	#include "RenderRectangle.hpp"

	///
	/// Define all rendering element type
	/// that can be generated by the Manager.
	///
	enum ShapeType
	{
		RM_SHAPE_TRIANGLE = 0,
		RM_SHAPE_RECTANGLE,
		RM_SHAPE_NUMBER
	};

	class RenderingManager
	{
		public:
			///
			/// Constructor.
			///
			RenderingManager();

			///
			///  Empty constructor.
			///
			RenderingManager(void*);

			///
			/// Destructor.
			///
			~RenderingManager();

			///
			/// Set the current font by passing his id.
			///
			void setCurrentFont(unsigned int const);

			///
			/// Add a new font from a given source file.
			///
			void addNewFont(char const* const);

			///
			/// Get the specified RenderText.
			///
			RenderText* getRenderText(char const* const);

			///
			/// Add a new RenderText. An id must be given.
			///
			void addNewRenderText(char const* const);

			///
			/// Allows to choose the current ShaderProgram.
			///
			void setCurrentShaderProgram(unsigned int const);

			///
			/// Add a new ShaderProgram to the RenderingManager,
			/// and set the current ShaderProgram.
			///
			void addNewShaderProgram(ShaderSources&);

			///
			/// Add a new RenderShape according to the given ShapeType.
			///
			void addNewBufferedShape(ShapeType const);

			///
			/// Call the draw process.
			///
			void draw(void);

		private:
			///
			/// GL_STATIC_DRAW buffers.
			///
			static GLuint buffers[];

			///
			/// Current ShaderProgram to be used.
			///
			ShaderProgram* currentshader;

			///
			/// ShaderProgram stack.
			///
			vector<ShaderProgram*> shaders;

			///
			/// RenderShape stack.
			///
			vector<RenderShape*> shapes;

			///
			/// 
			///
			map<string, RenderText*> texts;

			///
			/// Current font to be used.
			///
			FTGLPixmapFont* currentfont;
			
			///
			/// Font stack.
			///
			vector<FTGLPixmapFont*> fonts;

			///
			/// Draw all RenderText that was added.
			///
			void drawText(void);

			///
			/// Draw all RenderShape that was added.
			///
			void drawShapes(void);

			///
			/// Create and return a new buffered RenderShape. 
			///
			RenderShape* getNewBufferedShape(ShapeType const);

			///
			/// Return a new RenderShape indicated by the given ShapeType.
			///
			RenderShape* getNewShape(ShapeType const);

	};

#endif
