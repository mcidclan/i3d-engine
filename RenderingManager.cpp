#include "RenderingManager.hpp"

GLuint RenderingManager::vbuffers[RM_SHAPE_NUMBER];

GLuint RenderingManager::uvbuffers[RM_SHAPE_NUMBER];

RenderingManager::RenderingManager()
{
	unsigned int i;

	this->currentfont = NULL;
	this->currentshape = NULL;
	this->currentshader = NULL;
	this->currentfilename = NULL;

	i = 0;
	while(i < RM_SHAPE_NUMBER)
	{
		RenderingManager::vbuffers[i] = 0;
		RenderingManager::uvbuffers[i] = 0;
		i++;
	}
}

RenderingManager::RenderingManager(void*)
{
	cout << "Could be called by a root ScriptSheet.\n";
}

RenderingManager::~RenderingManager()
{
	this->clean();
}

void RenderingManager::clean(void)
{
	utils::dynamicDelete(this->texts);
	utils::dynamicDelete(this->fonts);
	utils::dynamicDelete(this->shapes);
	utils::dynamicDelete(this->shaders);

	cout << "RenderingManager clean process.\n";
}

void RenderingManager::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->drawShapes();
	this->drawText();
}

void RenderingManager::drawText(void)
{
	map<string, RenderText*>::const_iterator a, b;

	a = this->texts.begin();
	b = this->texts.end();

	while(a != b)
	{
		a->second->draw();
		a++;
	}
}

void RenderingManager::drawShapes(void)
{
	unsigned int i;
	
	i = 0;
	while(i < this->shapes.size())
	{
		this->shapes[i]->draw();
		i++;
	}
}

RenderText* RenderingManager::getRenderText(char const* const name)
{
	map<string, RenderText*>::const_iterator a, b;

	a = this->texts.find(name);
	b = this->texts.end();

	if(a != b) return a->second;
	return NULL;
}

void RenderingManager::setCurrentFont(unsigned int const id)
{
	this->currentfont = fonts[id];
}

void RenderingManager::addNewFont(char const* const filename)
{
	FTGLPixmapFont* font;

	font = new FTGLPixmapFont(filename);

	if(!font->Error())
	{
		this->fonts.push_back(font);
		this->currentfont = this->fonts.back();
	}
	else cout << "An error has occurred during font file loading.\n";
}

void RenderingManager::addNewRenderText(char const* const name)
{
	RenderText* rendertext;

	if(this->currentfont != NULL)
	{
		rendertext = new RenderText(this->currentfont);
		this->texts[name] = rendertext;
	}
	else cout << "Please set current text font.\n";
}

void RenderingManager::setCurrentShaderProgram(unsigned int const id)
{
	this->currentshader = this->shaders[id];
}

void RenderingManager::addNewShaderProgram(ShaderSources& shadersource)
{
	unsigned int i;
	ShaderProgram* shaderprogram;
	
	i = 0;
	shaderprogram = new ShaderProgram();

	while(i < shadersource.size())
	{
		GLuint type;
		unsigned int linenumber;

		type = shadersource.getType(i);
		linenumber = shadersource.getLineNumber(i);

		shaderprogram->addSource(type, shadersource.at(i), linenumber);
		i++;
	}

	this->shaders.push_back(shaderprogram);
	this->currentshader = shaderprogram;

	cout << "A new ShaderProgram was added.\n";
}

void RenderingManager::addNewShape(ShapeType const type)
{
	if(type != RM_SHAPE_NUMBER)
	{
		this->addNewBufferedShape(type);
		SSDataBridge::target = this->shapes.back();
	}
	else cout << "This shape does not exist.\n";
}

void RenderingManager::addNewMesh(char const* const filename)
{
	this->currentfilename = filename;
	this->addNewShape(RM_SHAPE_MESH);
}

void RenderingManager::addNewTexturedMesh(char const* const mfname,
CustomString const tfname)
{
	string ext;

	this->addNewMesh(mfname);

	ext = tfname.find_part_after_last_of(".");

	if(ext == "bmp")
	{
		this->currentshape->setTextureId(utils::loadBmp24(tfname.c_str()));
	}
	else if(ext == "png")
	{
		this->currentshape->setTextureId(utils::loadPng32(tfname.c_str()));
	}
}

void RenderingManager::addNewBufferedShape(ShapeType const type)
{
	if(this->currentshader != NULL)
	{
		this->currentshape = this->getNewBufferedShape(type);
		this->currentshape->setShaderProgram(this->currentshader);
		this->shapes.push_back(this->currentshape);
	}
	else cout << "Please set current shader program.\n";
}

RenderShape* RenderingManager::getNewBufferedShape(ShapeType const type)
{
	RenderShape* shape;

	shape = this->getNewShape(type);

	if(shape != NULL)
	{
		GLuint vbufferid;
		GLuint uvbufferid;

		vbufferid = RenderingManager::vbuffers[type];
		uvbufferid = RenderingManager::uvbuffers[type];

		if(!RenderingManager::vbuffers[type])
		{
			glGenBuffers(1, &vbufferid);
			glBindBuffer(GL_ARRAY_BUFFER, vbufferid);
			glBufferData(GL_ARRAY_BUFFER, shape->getDataSize(V_BUFFER),
			shape->getData(V_BUFFER), GL_STATIC_DRAW);

			glGenBuffers(1, &uvbufferid);
			glBindBuffer(GL_ARRAY_BUFFER, uvbufferid);
			glBufferData(GL_ARRAY_BUFFER, shape->getDataSize(UV_BUFFER),
			shape->getData(UV_BUFFER), GL_STATIC_DRAW);

			if(type != RM_SHAPE_MESH)
			{
				RenderingManager::vbuffers[type] = vbufferid;
				RenderingManager::uvbuffers[type] = uvbufferid;
			}
		}

		shape->setBufferId(V_BUFFER, vbufferid);
		shape->setBufferId(UV_BUFFER, uvbufferid);
	}
	return shape;
}

RenderShape* RenderingManager::getNewShape(ShapeType const type)
{
	switch(type)
	{
		case RM_SHAPE_MESH:
		{
			RenderMesh* mesh = new RenderMesh();
			mesh->load(this->currentfilename);
			return mesh;
		}

		case RM_SHAPE_TRIANGLE:
			return new RenderTriangle();

		case RM_SHAPE_RECTANGLE:
			return new RenderRectangle();

		case RM_SHAPE_NUMBER:
			return NULL;

	}
	return NULL;
}

vector<RenderShape*>* RenderingManager::getShapes(void)
{
	return &this->shapes;
}

