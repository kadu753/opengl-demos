/**
 * This demo shows how to periodically call an update() function to create
 * animations over time. In this case, the animation is to rotate a red square.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

// Constants to define the width/height of the window
const int WIDTH = 800;
const int HEIGHT = 800;

// Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 60;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

// Control the angle to rotate the red square
float angle = 0;

struct _vertex {
	float x;
	float y;
	float z;
};

struct _vertex point1;
struct _vertex point2;
struct _vertex point3;
struct _vertex point4;
struct _vertex point5;
struct _vertex point6;
struct _vertex point7;
struct _vertex point8;

void drawCube(){
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
		// Linha verical esquerda
		glVertex3f(point1.x, point1.y, point1.z);
		glVertex3f(point2.x, point2.y, point2.z);
	glEnd();
	glBegin(GL_LINES);
		// Linha horizontal de baixo
		glVertex3f(point1.x, point1.y, point1.z);
		glVertex3f(point3.x, point3.y, point3.z);
	glEnd();
	glBegin(GL_LINES);
		// Linha da direita
		glVertex3f(point3.x, point3.y, point3.z);
		glVertex3f(point4.x, point4.y, point4.z);
	glEnd();
	glBegin(GL_LINES);
		// Linha de cima
		glVertex3f(point2.x, point2.y, point2.z);
		glVertex3f(point4.x, point4.y, point4.z);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(point1.x, point1.y, point1.z);
		glVertex3f(point5.x, point5.y, point5.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point2.x, point2.y, point2.z);
		glVertex3f(point6.x, point6.y, point6.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point3.x, point3.y, point3.z);
		glVertex3f(point7.x, point7.y, point7.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point4.x, point4.y, point4.z);
		glVertex3f(point8.x, point8.y, point8.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point5.x, point5.y, point5.z);
		glVertex3f(point7.x, point7.y, point7.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point5.x, point5.y, point5.z);
		glVertex3f(point6.x, point6.y, point6.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point6.x, point6.y, point6.z);
		glVertex3f(point8.x, point8.y, point8.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point7.x, point7.y, point7.z);
		glVertex3f(point8.x, point8.y, point8.z);
	glEnd();
}

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-10.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(10.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -10.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -10.0f);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Rotate the red square by "angle" degrees.
	// glRotatef(angle, 0.0f, 0.0f, 1.0f);
	// glRotatef(angle, 0.0f, 1.0f, 1.0f);

	
	// Render a red square
	//        R  G  B
	glColor3f(1, 0, 0);
	//        x1    y1    x2     y2
	// glRectf(-1.0f, 1.0f, 1.0f, -1.0f);

	drawCube();

	// Start the rendering on a new frame
	glutSwapBuffers();
}

void update(int value)
{
	// Update the angle of rotation
	angle += 1;

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}
	// anda pra direita
	if (key == GLUT_KEY_RIGHT) {
		exit(0);
	}
	// anda pra esquerda
	if (key == GLUT_KEY_LEFT) {
		exit(0);
	}
	// anda pra cima
	if (key == GLUT_KEY_UP) {
		exit(0);
	}
	// anda pra baixo
	if (key == GLUT_KEY_DOWN) {
		exit(0);
	}
	// anda pra frente
	if (key == 'a') {
		point1.x += 0.2f;
		point2.x += 0.2f;
		point3.x += 0.2f;
		point4.x += 0.2f;

		point5.x += 0.2f;
		point6.x += 0.2f;
		point7.x += 0.2f;
		point8.x += 0.2f;
	}
	// anda pra trás
	if (key == 's') {
		point1.x -= 0.2f;
		point2.x -= 0.2f;
		point3.x -= 0.2f;
		point4.x -= 0.2f;
		point5.x -= 0.2f;
		point6.x -= 0.2f;
		point7.x -= 0.2f;
		point8.x -= 0.2f;
	}
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

//      5_________7
//	   /|		 /|
//    /_|_______/ |
// 	1|	|		|3|
//   | 	|6______|_|8
// 	 | /	 	| /
//  2|/_________|/4
// 

int main(int argc, char** argv)
{
	point1.x = -1.f, point1.y = 1.f, point1.z = 1.f;
	point2.x = -1.f, point2.y = -1.f, point2.z = 1.f;
	point3.x = 1.f, point3.y = 1.f, point3.z = 1.f;
	point4.x = 1.f, point4.y = -1.f, point4.z = 1.f;

	point5.x = -1.f, point5.y = 1.f, point5.z = -1.f;
	point6.x = -1.f, point6.y = -1.f, point6.z = -1.f;
	point7.x = 1.f, point7.y = 1.f, point7.z = -1.f;
	point8.x = 1.f, point8.y = -1.f, point8.z = -1.f;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);

	glutMainLoop();
	return 0;
}