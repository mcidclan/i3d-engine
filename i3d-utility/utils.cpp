#include "utils.hpp"

namespace utils
{
	GLuint loadBmp24(const char* imagepath)
	{
		printf("Reading image %s\n", imagepath);

		unsigned char header[54];
		unsigned int dataPos;
		unsigned int imageSize;
		unsigned int width, height;

		unsigned char * data;

		FILE * file = fopen(imagepath,"rb");
		
		if(!file)
		{
			printf("%s could not be opened!\n", imagepath);
			return 0;
		}

		if(fread(header, 1, 54, file) != 54)
		{ 
			printf("Not a correct BMP file\n");
			return 0;
		}

		if(header[0]!='B' || header[1] != 'M')
		{
			printf("Not a correct BMP file\n");
			return 0;
		}

		if(*(int*)&(header[0x1E]) != 0)
		{
			printf("Not a correct BMP file\n");
			return 0;
		}

		if(*(int*)&(header[0x1C]) != 24)
		{
			printf("Not a correct BMP file\n");
			return 0;
		}

		dataPos    = *(int*)&(header[0x0A]);
		imageSize  = *(int*)&(header[0x22]);
		width      = *(int*)&(header[0x12]);
		height     = *(int*)&(header[0x16]);

		if(imageSize == 0) imageSize = width * height * 3;

		if(dataPos == 0) dataPos = 54;

		data = new unsigned char[imageSize];

		fread(data, 1, imageSize, file);

		fclose(file);

		GLuint textureID;
		glGenTextures(1, &textureID);
		
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		0, GL_BGR, GL_UNSIGNED_BYTE, data);

		delete [] data;

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
		glGenerateMipmap(GL_TEXTURE_2D);

		return textureID;
	}
}
