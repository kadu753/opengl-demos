/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

GLfloat speedX = 0.01f;
GLfloat positionX = 0.0f;
GLfloat rotateX = 0.0f;
GLfloat rotateSpeedX = 5.0f;
GLfloat scale = 1.0f;
GLfloat scaleSpeed = 0.0f;
GLfloat squareSize = 0.1f;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a blue square
	glColor3f(0, 0, 1);
	glTranslatef(positionX, 0.0f, 0);
	glScalef(scale, scale, 0.0f);
	glRotatef(-rotateX, 0.0f, 0.0f, 1.0f);
	glRectf(-squareSize, squareSize, squareSize, -squareSize);

	positionX += speedX;
	rotateX += rotateSpeedX;
	scale += scaleSpeed;

	if(positionX + scale * squareSize >= 1.0f){
		speedX = -0.01f;
	} else if(positionX <= -1.0f + scale * squareSize){
		speedX = 0.01f;
	}
	
	if(scale >= 6.0f){
		scaleSpeed *= -1;
	} else if(scale <= 0.5f){
		scaleSpeed *= -1;
	}

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	std::cout << key << std::endl;
	if (key == 27) {
		// ESC key
		exit(0);
	} 
	if(key == '1') {
		if(speedX == 0.00f){
			speedX = 0.01f;
		} else {
			speedX = 0.00f;
		}
	} 
	if(key == '2') {
		if(rotateSpeedX == 0.0f){
			rotateSpeedX = 5.0f;
		} else {
			rotateSpeedX = 0.0f;
		}
	}
	if(key == '3') {
		if(scaleSpeed == 0.0f){
			scaleSpeed = 0.05f;
		} else {
			scaleSpeed = 0.0f;
		}
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}