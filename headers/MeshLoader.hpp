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

			/// Return the indices buffer pointer.
			uint* getIndices(void) const;

			/// Return the normals buffer pointer.
			float* getNormals(void) const;

			/// Return the uvcoords buffer pointer.
			float* getUVCoords(void) const;

			/// Return the vertices buffer pointer.
			float* getCoordinates(void) const;

			/// Return the number of vertices.
			uint getNumberOfVertices(void) const;

			/// Return the number of vertex coordinates.
			uint getNumberOfCoordinates(void) const;

		protected:
			/// Number of vertices.
			uint nvertices;

			/// Number of available coordinates.
			uint ncoordinates;

			/// Indices buffer pointer.
			uint* indices;

			/// Normals buffer pointer.
			float* normals;

			/// UVCoords buffer pointer.
			float* uvcoords;

			/// Vertices buffer pointer.
			float* coordinates;

			/// Allows to release the mesh data.
			void release(void);

	};

#endif
