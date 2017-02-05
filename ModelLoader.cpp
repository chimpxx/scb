
#include "Header.h"


ModelLoader::ModelLoader()
{
}

ModelLoader::~ModelLoader()
{
}

Entity* ModelLoader::loadModel(const char* fileName){
	int width, height;
	Entity* retVal = nullptr;
	int textureID = bufferLoader.loadTexture(fileName, &width, &height);
	if (textureID >= 0) {
		TexturedModel* texturedQuad = createTexturedQuad((float)width, (float)height, new Material(textureID, ShaderPtr));

		retVal = new Entity(texturedQuad, glm::vec3(0.0f), glm::vec3(1.0f));

		Entitys.push_back(retVal);
	}
	return retVal;
}

void ModelLoader::createBasicShader() {
	ShaderPtr = new Shader();
	ShaderPtr->createShader("./shaders/vs.mvp.glsl", "./shaders/fs.mvp.glsl");
}

TexturedModel* ModelLoader::createTexturedQuad(float width, float height, Material* MaterialPtr) {
	float halfWidth = width / 200.0f, halfHeight = height / 200.0f;
	std::vector<float> positions;
	std::vector<float> uv;
	std::vector<int> indices;

	//leftDown top triangle
	positions.push_back(-halfWidth);
	positions.push_back(-halfHeight);
	positions.push_back(0);
	
	uv.push_back(0);
	uv.push_back(1);

	positions.push_back(-halfWidth);
	positions.push_back(halfHeight);
	positions.push_back(0);
	
	uv.push_back(0);
	uv.push_back(0);

	positions.push_back(halfWidth);
	positions.push_back(halfHeight);
	positions.push_back(0);
	
	uv.push_back(1);
	uv.push_back(0);

	positions.push_back(halfWidth);
	positions.push_back(-halfHeight);
	positions.push_back(0);
	
	uv.push_back(1);
	uv.push_back(1);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);

	RawModel* RawModelPtr = bufferLoader.loadToBuffer(positions, uv, indices);

	positions.clear();
	uv.clear();
	indices.clear();

	return new TexturedModel(RawModelPtr, MaterialPtr);
}

void ModelLoader::freeMemory() {
	delete ShaderPtr;
	bufferLoader.freeBuffer();
	for (Entity* e : Entitys) {
		delete e;
	}
}