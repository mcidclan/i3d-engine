#include "RenderMesh.hpp"

RenderMesh::RenderMesh()
{
}

RenderMesh::~RenderMesh()
{
}

void RenderMesh::load(char const* const filename)
{
	MeshLoader::load(filename);
	this->vertexnumber = this->nvertices;
	this->vertexindices = this->indices;
}

unsigned int RenderMesh::getDataSize(BufferType type) const
{
	if(type == UV_BUFFER)
	{
		return this->ncoordinates * sizeof(float) * 2;
	}
	return (this->ncoordinates * sizeof(float) * 3);
}

GLfloat const* RenderMesh::getData(BufferType type) const
{
	if(type == UV_BUFFER)
	{
		return this->uvcoords;
	}
	return this->coordinates;
}
