//
// Created by abijosh on 10/9/16.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "UserInteraction.h"

bool UserInteraction::leftDown = false;
bool UserInteraction::rightDown = false;
bool UserInteraction::upDown = false;
bool UserInteraction::downDown = false;
bool UserInteraction::spaceDown = false;

bool UserInteraction::leftPress = false;
bool UserInteraction::rightPress = false;
bool UserInteraction::upPress = false;
bool UserInteraction::downPress = false;
bool UserInteraction::spacePress = false;

bool UserInteraction::escape = false;
bool UserInteraction::mouseLeftButtonDown = false;
bool UserInteraction::mouseRightButtonDown = false;

double UserInteraction::lastLeftMouseClickX = 0.0;
double UserInteraction::lastLeftMouseClickY = 0.0;
double UserInteraction::lastLeftMouseReleaseX = 0.0;
double UserInteraction::lastLeftMouseReleaseY = 0.0;

double UserInteraction::lastRightMouseClickX = 0.0;
double UserInteraction::lastRightMouseClickY = 0.0;
double UserInteraction::lastRightMouseReleaseX = 0.0;
double UserInteraction::lastRightMouseReleaseY = 0.0;

int UserInteraction::width = 0;
int UserInteraction::height = 0;

UserInteraction::UserInteraction()
{
}
UserInteraction::~UserInteraction()
{
}

void UserInteraction::keyEvent(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	bool keyPress = false;
	bool keyDown = false;
	if (action == GLFW_PRESS) {
        keyPress = true;
        std::cout<<"Space"<<std::endl;
    }
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
		keyDown = true;

	switch (key)
	{
	case GLFW_KEY_LEFT:
	case GLFW_KEY_A:
			leftDown = keyDown;
			leftPress = keyPress;
			break;

	case GLFW_KEY_RIGHT:
	case GLFW_KEY_D:
			rightDown = keyDown;
			rightPress = keyPress;
			break;

	case GLFW_KEY_UP:
	case GLFW_KEY_W:
			upDown = keyDown;
			upPress = keyPress;
			break;

	case GLFW_KEY_DOWN:
	case GLFW_KEY_S:
			downDown = keyDown;
			downPress = keyPress;
			break;

	case GLFW_KEY_SPACE:
			spaceDown = keyDown;
			spacePress = keyPress;
			break;

	case GLFW_KEY_ESCAPE:
			escape = keyDown;
			break;
	}

}

void UserInteraction::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
	double mouseX, mouseY;
	glfwGetCursorPos(window, &mouseX, &mouseY);
	if (action == GLFW_PRESS){

		if (button == GLFW_MOUSE_BUTTON_1){
			lastLeftMouseClickX = mouseX;
			lastLeftMouseClickY = height - mouseY;
			mouseLeftButtonDown = true;
		}
		if (button == GLFW_MOUSE_BUTTON_2){
			lastRightMouseClickX = mouseX;
			lastRightMouseClickY = height - mouseY;
			mouseRightButtonDown = true;
		}
	}
	else if (action == GLFW_RELEASE){
		if (button == GLFW_MOUSE_BUTTON_1){
			lastLeftMouseReleaseX = mouseX;
			lastLeftMouseReleaseY = height - mouseY;
			mouseLeftButtonDown = false;
		}
		if (button == GLFW_MOUSE_BUTTON_2){
			lastRightMouseReleaseX = mouseX;
			lastRightMouseReleaseY = height - mouseY;
			mouseRightButtonDown = false;
		}
	}

}