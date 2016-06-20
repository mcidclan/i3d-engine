#ifndef RENDERMESH_HPP
#define RENDERMESH_HPP

	#include "MeshLoader.hpp"
	#include "RenderShape.hpp"

	class RenderMesh : public MeshLoader, public RenderShape
	{
		public:
			/// Constructor.
			RenderMesh();

			/// Destructor.
			~RenderMesh();

			///
			void load(char const* const);

			///
			unsigned int getDataSize(BufferType) const;

			///
			GLfloat const* getData(BufferType) const;

	};

#endif
