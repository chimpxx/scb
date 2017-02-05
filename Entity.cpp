#include "Header.h"


Entity::Entity(TexturedModel *TexturedModelPtr,
						   glm::vec3 position,
						   glm::vec3 scale,
						   float rotateAngle,
						   glm::vec3 rotateAxis)
		: pTexturedModel(TexturedModelPtr)
		, position(position)
		, scale(scale)
		, rotateAngle(rotateAngle)
		, rotateAxis(rotateAxis)
{
	matrixUpdated = false;
    active = true;
}


Entity::~Entity()
{
	delete pTexturedModel;
}

void Entity::updateTransformMatrix() {
	glm::mat4 referenceMatrix(1.0f);
	referenceMatrix = glm::translate(referenceMatrix, position);
	referenceMatrix = glm::scale(referenceMatrix, scale);
	transformMatrix = glm::rotate(referenceMatrix, glm::radians(rotateAngle), rotateAxis);
	matrixUpdated = true;
}

glm::mat4& Entity::getTransformMatrix(){
	if(!matrixUpdated)
		updateTransformMatrix();
	return transformMatrix;
}

TexturedModel* Entity::getModelPointer(){
	return pTexturedModel;
}

void Entity::setTexturedModel(TexturedModel* TexturedModelPtr){	
	this->pTexturedModel = TexturedModelPtr;
}

void  Entity::addChild(Entity* childEntity)
{
	children.push_back(childEntity);
	childEntity->setParent(this);
}
const std::vector<Entity*>&  Entity::getChildren() const
{
	return children;
}
