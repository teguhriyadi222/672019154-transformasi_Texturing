#pragma once
#include <stdio.h>


GLuint loadjpg_custom(const char* imagepath)
{

	unsigned char header[54];
	unsigned int datapos;
	unsigned int width, height;
	unsigned int imagesize;

	unsigned char* data;

	FILE* file;
	fopen_s(&file, imagepath, "rb");
	if (!file) { printf("gambar tidak bisa dibuka \n"); return 0; }

	if (fread(header, 1, 54, file) != 54) {

		printf("not a correct bmp file\n");
		fclose(file);
		return 0;

	

	}

	if (header[0] != 'B' || header[1] != 'M') {

		printf("not a correct bmp file\n");
		fclose(file);
		return 0;

	}

	if (*(int*)&(header[0x1E]) !=0) 
	{
		printf("not bmp file");
		return 0;
	}
	if (*(int*)&(header[0x1C]) != 24)
	{
		printf("not bmp file");
		return 0;
	}
	if (header[0] != 'B' || header[1] != 'M') {

		printf("not a correct bmp file\n");
		fclose(file);
		

	}
	datapos = *(int*)&(header[0x0A]);
	imagesize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	if (imagesize == 0) imagesize = width * height * 3;
	if (datapos == 0) datapos = 54;

	data = new unsigned char[imagesize];
	fread(data, 1, imagesize, file);
	fclose(file);

	GLuint textureID;

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	delete[] data;

	return textureID;

	

	

}



