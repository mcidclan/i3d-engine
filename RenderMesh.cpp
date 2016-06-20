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

unsigned int RenderMesh::getDataSize(void) const
{
	return (this->ncoordinates * sizeof(float) * 3);
}

GLfloat const* RenderMesh::getData(void) const
{
	return this->coordinates;
}
