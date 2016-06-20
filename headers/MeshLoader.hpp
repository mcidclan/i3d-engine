#ifndef MESHLOADER_HPP
#define MESHLOADER_HPP

	#include "customtypes.hpp"

	class MeshLoader
	{
		public:
			/// Constructor.
			MeshLoader();

			/// Destructor.
			~MeshLoader();

			/// Allows to load a mesh from a binary i3d file.
			void load(char const* const);

			///
			uint* getIndices(void) const;

			///
			float* getNormals(void) const;

			///
			float* getUVCoords(void) const;

			///
			float* getVertices(void) const;

		private:
			///
			uint* indices;

			///
			float* normals;

			///
			float* uvcoords;

			///
			float* vertices;

	};

#endif
