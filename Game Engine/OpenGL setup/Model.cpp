#include "Model.h"
#include <iostream>
using namespace std;
Model::Model()
{
	//create a cube by default
}

Model::Model(const string& objPath, const string& texturePath)
{
	vector<glm::vec3> vertex;
	vector<glm::vec2> uv;
	vector<glm::vec3> normal;

	bool OBJSuccess = loadObject(objPath, vertex, uv, normal);
	vertexAmount = initBuffers(vertex, uv, normal);
	//cout << vertexAmount << endl;

	textureDDS = loadTexture(texturePath);
}

Model::~Model()
{
	glDeleteBuffers(1, &VBO);			//Delete the VBO
	glDeleteBuffers(1, &UVBuffer);		//Delete the uv buffer
	glDeleteBuffers(1, &normalBuffer);	//Delete the normal buffer
	glDeleteTextures(1, &textureDDS);
}

int Model::initBuffers(const vector<glm::vec3>& vertices, const vector<glm::vec2>& uv, const vector<glm::vec3>& normal)
{
	glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &UVBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, UVBuffer);
    glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(glm::vec2), &uv[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(glm::vec3), &normal[0], GL_STATIC_DRAW);

	return vertices.size();
}

void Model::draw(const GLuint& programID, const GLuint& textureID, const GLuint& lightProgram, const GLuint& MVPID, const GLuint& modelID, const GLuint& viewID)
{
	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	glUseProgram(programID);

	glUniformMatrix4fv(MVPID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(modelID, 1, GL_FALSE, &modelMatrix[0][0]);
    glUniformMatrix4fv(viewID, 1, GL_FALSE, &viewMatrix[0][0]);

	glm::vec3 lightPos = glm::vec3(-4,-3,-3);						//set the position of the light
    glUniform3f(lightProgram, lightPos.x, lightPos.y, lightPos.z);	//apply the light program

    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureDDS);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(textureID, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, UVBuffer);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, vertexAmount);//display the specified GL_TRIANGLES primitives

    glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

GLuint Model::loadTexture(const string& filepath)//load the DDS file
{
	unsigned char header[124];

        FILE *fp; 
 
        /* try to open the file */ 
		fp = fopen(filepath.c_str(), "rb"); 
        if (fp == NULL){
                printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", filepath); getchar(); 
                return 0;
        }
   
        /* verify the type of file */ 
        char filecode[4]; 
        fread(filecode, 1, 4, fp); 
        if (strncmp(filecode, "DDS ", 4) != 0) { 
                fclose(fp); 
                return 0; 
        }
        
        /* get the surface desc */ 
        fread(&header, 124, 1, fp); 

        unsigned int height      = *(unsigned int*)&(header[8 ]);
        unsigned int width       = *(unsigned int*)&(header[12]);
        unsigned int linearSize  = *(unsigned int*)&(header[16]);
        unsigned int mipMapCount = *(unsigned int*)&(header[24]);
        unsigned int fourCC      = *(unsigned int*)&(header[80]);

 
        unsigned char * buffer;
        unsigned int bufsize;
        /* how big is it going to be including all mipmaps? */ 
        bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize; 
        buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char)); 
        fread(buffer, 1, bufsize, fp); 
        /* close the file pointer */ 
        fclose(fp);

        unsigned int components  = (fourCC == FOURCC_DXT1) ? 3 : 4; 
        unsigned int format;
        switch(fourCC) 
        { 
        case FOURCC_DXT1: 
                format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT; 
                break; 
        case FOURCC_DXT3: 
                format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT; 
                break; 
        case FOURCC_DXT5: 
                format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT; 
                break; 
        default: 
                free(buffer); 
                return 0; 
        }

        // Create one OpenGL texture
        GLuint textureID;
        glGenTextures(1, &textureID);

        // "Bind" the newly created texture : all future texture functions will modify this texture
        glBindTexture(GL_TEXTURE_2D, textureID);
        glPixelStorei(GL_UNPACK_ALIGNMENT,1);   
        
        unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16; 
        unsigned int offset = 0;

        /* load the mipmaps */ 
        for (unsigned int level = 0; level < mipMapCount && (width || height); ++level) 
        { 
                unsigned int size = ((width+3)/4)*((height+3)/4)*blockSize; 
                glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,  
                        0, size, buffer + offset); 
         
                offset += size; 
                width  /= 2; 
                height /= 2; 

                // Deal with Non-Power-Of-Two textures. This code is not included in the webpage to reduce clutter.
                if(width < 1) width = 1;
                if(height < 1) height = 1;

        } 

        free(buffer); 
		printf("Texture loaded successfully\n");

        return textureID;
}
bool Model::loadObject(const string& filepath, vector<glm::vec3>& vertices, vector<glm::vec2>& uvs, vector<glm::vec3>& normals)	//load the OBJ file
{
	printf("Loading OBJ file %s...\n", filepath);

        std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
        std::vector<glm::vec3> temp_vertices; 
        std::vector<glm::vec2> temp_uvs;
        std::vector<glm::vec3> temp_normals;


		FILE * file = fopen(filepath.c_str(), "r");
        if( file == NULL ){
                printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
                getchar();
                return false;
        }

        while( 1 ){

                char lineHeader[128];
                // read the first word of the line
                int res = fscanf(file, "%s", lineHeader);
                if (res == EOF)
                        break; // EOF = End Of File. Quit the loop.

                // else : parse lineHeader
                
                if ( strcmp( lineHeader, "v" ) == 0 ){
                        glm::vec3 vertex;
                        fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
                        temp_vertices.push_back(vertex);
                }else if ( strcmp( lineHeader, "vt" ) == 0 ){
                        glm::vec2 uv;
                        fscanf(file, "%f %f\n", &uv.x, &uv.y );
                        uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
                        temp_uvs.push_back(uv);
                }else if ( strcmp( lineHeader, "vn" ) == 0 ){
                        glm::vec3 normal;
                        fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
                        temp_normals.push_back(normal);
                }else if ( strcmp( lineHeader, "f" ) == 0 ){
                        std::string vertex1, vertex2, vertex3;
                        unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                        int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
                        if (matches != 9){
                                printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                                return false;
                        }
                        vertexIndices.push_back(vertexIndex[0]);
                        vertexIndices.push_back(vertexIndex[1]);
                        vertexIndices.push_back(vertexIndex[2]);
                        uvIndices    .push_back(uvIndex[0]);
                        uvIndices    .push_back(uvIndex[1]);
                        uvIndices    .push_back(uvIndex[2]);
                        normalIndices.push_back(normalIndex[0]);
                        normalIndices.push_back(normalIndex[1]);
                        normalIndices.push_back(normalIndex[2]);
                }else{
                        // Probably a comment, eat up the rest of the line
                        char stupidBuffer[1000];
                        fgets(stupidBuffer, 1000, file);
                }
        }

        // For each vertex of each triangle
        for( unsigned int i=0; i<vertexIndices.size(); i++ ){

                // Get the indices of its attributes
                unsigned int vertexIndex = vertexIndices[i];
                unsigned int uvIndex = uvIndices[i];
                unsigned int normalIndex = normalIndices[i];
                
                // Get the attributes thanks to the index
                glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
                glm::vec2 uv = temp_uvs[ uvIndex-1 ];
                glm::vec3 normal = temp_normals[ normalIndex-1 ];
                
                // Put the attributes in buffers
                vertices.push_back(vertex);
                uvs     .push_back(uv);
                normals .push_back(normal);
        
        }
		printf("OBJ loaded successfully\n");
        return true;
}

void Model::modelTransform(const glm::mat4& model)	//Set the model matrix
{
	modelMatrix = model;
}

void Model::updateViewProjection(const glm::mat4& view, const glm::mat4& projection)
{
	viewMatrix = view;
	projectionMatrix = projection;
}

void Model::rotate(const glm::vec3 &axis, const float& w)//Rotate the model
{
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	modelMatrix = glm::rotate(modelMatrix, w, axis);
}

void Model::scale(const glm::vec3& scaling)//Scale the model
{
	modelMatrix = glm::scale( modelMatrix, scaling);
}

void Model::translate(const glm::vec3& translate)//Translate the model
{
	modelMatrix = glm::translate(modelMatrix, translate);
}