#include "Renderer.hpp"
#include "scripts.hxx"

#include "MeshLoader.hpp"

static ScriptTree scripttree;

void initTies(void)
{
	{
		uint tie[] = {0};
		scripttree.setCurrentTie(tie);
		scripttree.addNewScriptSheet(home::script);
	}

	{
		uint tie[] = {0, 0};
		scripttree.setCurrentTie(tie);
		scripttree.addNewScriptSheet(area::script);
	}

	uint tie[] = {0};
	scripttree.setCurrentTie(tie);
	scripttree.setCurrentScriptSheet(0);
}

int main(int argc, char** argv)
{
	initTies();

	Renderer renderer(argc, argv);
	renderer.setProcess(ScriptTree::draw);
	renderer.start();

/*
	MeshLoader loader;

	uint* indices;
	float* normals;
	float* uvcoords;
	float* coordinates;

	loader.load("./model.i3d");
	
	indices = loader.getIndices();
	normals = loader.getNormals();
	uvcoords = loader.getUVCoords();
	coordinates = loader.getCoordinates();

	cout << "indices\n";
	cout << indices[0] << "," << indices[1] << "," << indices[2] << "\n";
	cout << indices[3] << "," << indices[4] << "," << indices[5] << "\n";

	cout << "normals\n";
	cout << normals[0] << "," << normals[1] << "," << normals[2] << "\n";
	cout << normals[3] << "," << normals[4] << "," << normals[5] << "\n";
	cout << normals[6] << "," << normals[7] << "," << normals[8] << "\n";
	cout << normals[9] << "," << normals[10] << "," << normals[11] << "\n";
	cout << normals[12] << "," << normals[13] << "," << normals[14] << "\n";
	cout << normals[15] << "," << normals[16] << "," << normals[17] << "\n";

	cout << "uvcoords\n";
	cout << uvcoords[0] << "," << uvcoords[1] << "\n";
	cout << uvcoords[2] << "," << uvcoords[3] << "\n";
	cout << uvcoords[4] << "," << uvcoords[5] << "\n";
	cout << uvcoords[6] << "," << uvcoords[7] << "\n";
	cout << uvcoords[8] << "," << uvcoords[9] << "\n";
	cout << uvcoords[10] << "," << uvcoords[11] << "\n";

	uint i = 0;
	uint offset = 0;

	cout << "coordinates\n";
	while(i < loader.getNumberOfCoordinates())
	{
		offset = (i * 3);
		cout << coordinates[0+offset] << "," << coordinates[1+offset] << "," << coordinates[2+offset] << "\n";
		i++;
	}
*/
	//getVertices

	return 0;
}
