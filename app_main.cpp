#include "App.h"

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    // Instantiate a new App
    App* myApp = new App("MyApp", 50, 50, 1000, 1000);

	// Start the app
    myApp->run();
}
