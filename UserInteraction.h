
#pragma once

class UserInteraction {
public:
	UserInteraction();
	~UserInteraction();

	static void keyEvent(GLFWwindow* window, int key, int scancode, int action, int mode);

	static bool leftDown, rightDown, upDown, downDown, spaceDown, escape, mouseLeftButtonDown, mouseRightButtonDown;
	static bool leftPress, rightPress, upPress, downPress, spacePress;
	static int width, height;
	static double lastLeftMouseClickX, lastLeftMouseClickY, lastLeftMouseReleaseX, lastLeftMouseReleaseY;
	static double lastRightMouseClickX, lastRightMouseClickY, lastRightMouseReleaseX, lastRightMouseReleaseY;
	static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

};
