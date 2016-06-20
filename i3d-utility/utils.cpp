#include <png.h>
#include "utils.hpp"

namespace utils
{
	GLuint getMipMap(uchar* const data, uint const width,
	uint const height, GLint const format)
	{
		GLuint id;

		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glPixelStorei(GL_PACK_ALIGNMENT, 4);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
		0, format, GL_UNSIGNED_BYTE, data);

		glGenerateMipmap(GL_TEXTURE_2D);

		return id;
	}

	GLuint loadPng32(const char* filename)
	{
		FILE *fp;
		GLuint id;

		id = 0;
		fp = fopen(filename, "rb");

		if(fp != NULL)
		{
			int bitdepth;
			int colortype;
			png_uint_32 i;
			png_uint_32 width;
			png_uint_32 height;
			png_infop info_ptr;
			png_structp png_ptr;

			uchar* data = NULL;
			png_bytep* row_pointers;
		
			png_ptr = png_create_read_struct(
			PNG_LIBPNG_VER_STRING, NULL, NULL,	NULL);
			png_init_io(png_ptr, fp);

			info_ptr = png_create_info_struct(png_ptr);
			png_read_info(png_ptr, info_ptr);

			png_get_IHDR(png_ptr, info_ptr, &width, &height,
			&bitdepth, &colortype, NULL, NULL, NULL);
	
			data = new uchar[width * height * 4];
			row_pointers = new png_bytep[height];
	
			for(i = 0; i < height; ++i)
			{
				row_pointers[i] = (png_bytep)
				(data + (height - (i + 1)) * width * 4);
			}

			png_read_image(png_ptr, row_pointers);
			png_read_end(png_ptr, NULL);
			png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

			delete [] (row_pointers);

			fclose(fp);

			id = getMipMap(data, width, height, GL_RGBA);

			delete [] data;
		}

		return id;
	}

	GLuint loadBmp24(const char* filename)
	{
		GLuint id;
		uint size;
		uint width;
		uint height;
		uint datapos;
		uchar header[54];

		FILE* file;
		uchar* data;

		file = fopen(filename,"rb");
		
		if(!file)
		{
			cout << filename << " not found!\n";
			return 0;
		}

		if(fread(header, 1, 54, file) != 54)
		{ 
			cout << "Wrong bmp file format.\n";
			return 0;
		}

		if((header[0] != 'B') || (header[1] != 'M'))
		{
			cout << "Wrong bmp file format.\n";
			return 0;
		}

		if(*(int*)&(header[0x1E]) != 0)
		{
			cout << "Wrong bmp file format.\n";
			return 0;
		}

		if(*(int*)&(header[0x1C]) != 24)
		{
			cout << "Wrong bmp file format.\n";
			return 0;
		}
		
		size = *(int*)&(header[0x22]);
		width = *(int*)&(header[0x12]);
		height = *(int*)&(header[0x16]);
		datapos = *(int*)&(header[0x0A]);

		if(size == 0) size = width * height * 3;
		if(datapos == 0) datapos = 54;

		data = new uchar[size];

		fread(data, 1, size, file);

		fclose(file);

		id = getMipMap(data, width, height, GL_BGR);

		delete [] data;

		return id;
	}
}

