#include "MeshLoader.hpp"

MeshLoader::MeshLoader()
{
	this->indices = NULL;
	this->normals = NULL;
	this->uvcoords = NULL;
}

MeshLoader::~MeshLoader()
{
	//Release.
}

void MeshLoader::load(char const* const filename)
{
	FILE* file;
	uint vertexnumber;

	file = fopen(filename, "rb");

	if(file != NULL)
	{		
		uint nnbyte;
		uint vnbyte;
		uint unbyte;
		uint filesize;

		fseek(file, 0, SEEK_END);
		filesize = ftell(file);
		rewind(file);

		fread(&vertexnumber, 4, 1, file);

		this->indices = new uint[vertexnumber];
		fread(this->indices, 4, vertexnumber, file);

		nnbyte = (vertexnumber * 3);
		this->normals = new float[nnbyte];
		fread(this->normals, 4, nnbyte, file);

		unbyte = (vertexnumber * 2);
		this->uvcoords = new float[unbyte];
		fread(this->uvcoords, 4, unbyte, file);

		vnbyte = filesize - ftell(file);
		this->vertices = new float[vnbyte];
		fread(this->vertices, 1, vnbyte, file);

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

float* MeshLoader::getVertices(void) const
{
	return this->vertices;
}
