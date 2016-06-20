#include "MeshLoader.hpp"

MeshLoader::MeshLoader()
{
	this->nvertices = 0;
	this->ncoordinates = 0;

	this->indices = NULL;
	this->normals = NULL;
	this->uvcoords = NULL;
	this->coordinates = NULL;
}

MeshLoader::~MeshLoader()
{
	this->release();
}

void MeshLoader::release(void)
{
	delete [] indices;
	delete [] normals;
	delete [] uvcoords;
	delete [] coordinates;
}

void MeshLoader::load(char const* const filename)
{
	FILE* file;

	file = fopen(filename, "rb");

	if(file != NULL)
	{		
		uint filesize;
		uint ncomponents;

		fseek(file, 0, SEEK_END);
		filesize = ftell(file);
		rewind(file);

		fread(&this->nvertices, 4, 1, file);

		this->indices = new uint[this->nvertices];
		fread(this->indices, 4, this->nvertices, file);

		ncomponents = (this->nvertices * 3);
		this->normals = new float[ncomponents];
		fread(this->normals, 4, ncomponents, file);

		ncomponents = (this->nvertices * 2);
		this->uvcoords = new float[ncomponents];
		fread(this->uvcoords, 4, ncomponents, file);

		ncomponents = (filesize - ftell(file)) / 4;
		this->ncoordinates = ncomponents / 3;

		this->coordinates = new float[ncomponents];
		fread(this->coordinates, 4, ncomponents, file);

		fclose(file);
	}
	else cout << "File not found.";
}

uint* MeshLoader::getIndices(void) const
{
	return this->indices;
}

float* MeshLoader::getNormals(void) const
{
	return this->normals;
}

float* MeshLoader::getUVCoords(void) const
{
	return this->uvcoords;
}

float* MeshLoader::getCoordinates(void) const
{
	return this->coordinates;
}

uint MeshLoader::getNumberOfVertices(void) const
{
	return this->nvertices;
}

uint MeshLoader::getNumberOfCoordinates(void) const
{
	return this->ncoordinates;
}
