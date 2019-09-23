/**
 * Basic usege of OpenGL and GLFW. 
 */

#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 500
#define HEIGHT 500

float position = -1.0f;
float position2 = 0.5f;
float direction = 1.0f;
float direction2 = 1.0f;
float tamanho = 0.6;

int main() {
	GLFWwindow* window;
	int width, height;


	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}
	
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world, GLFW!", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);


		// Aula dia 19/08/2019

		// Exercise 1
		// glBegin(GL_LINES);
		// 	glColor3f(1.0f, 0.0f, 0.0f);
		// 	glVertex3f(-1.0f, -1.0f, 0.0f);
		// 	glVertex3f(1.0f, 1.0f, 0.0f);
		// glEnd();

		// Exercise 2
		// glBegin(GL_LINES);
		// 	glColor3f(1.0f, 0.0f, 0.0f);
		// 	glVertex3f(-0.5f, -0.6f, 0.0f);
		// 	glVertex3f(-0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.0f, 0.0f, 1.0f);
		// 	glVertex3f(0.5f, -0.6f, 0.0f);
		// 	glVertex3f(0.5f, 0.6f, 0.0f);
		// glEnd();

		// Exercise 3

		// glColor3f(0.0f, 0.0f, 1.0f);
		// glBegin(GL_LINES);
		// 	glVertex3f(-0.5f, -0.6f, 0.0f);
		// 	glVertex3f(-0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glVertex3f(-0.5f, -0.6f, 0.0f);
		// 	glVertex3f(0.5f, -0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glVertex3f(0.5f, -0.6f, 0.0f);
		// 	glVertex3f(0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glVertex3f(-0.5f, 0.6f, 0.0f);
		// 	glVertex3f(0.5f, 0.6f, 0.0f);
		// glEnd();
		
		// Aula dia 22

		// position += 0.01f * direction;

		// // Exercise 1
		// glBegin(GL_LINES);
		// 	glColor3f(0.0f, 0.0f, 1.0f);
		// 	glVertex3f(position, -0.5f, 0.0f);
		// 	glVertex3f(position, 0.5f, 0.0f);
		// glEnd();

		// if(position >= 1.0f || position <= -1.0f){
		// 	direction *= -1;
		// }

		// Exercise 2

		// position += 0.01f * direction;

		// glColor3f(0.0f, 0.0f, 1.0f);
		// glBegin(GL_LINES);
		// 	glVertex3f(position, -0.3f, 0.0f);
		// 	glVertex3f(position, 0.3f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glVertex3f(position, -0.3f, 0.0f);
		// 	glVertex3f(position + tamanho, -0.3f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glVertex3f(position, 0.3f, 0.0f);
		// 	glVertex3f(position + tamanho, 0.3f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glVertex3f(position + tamanho, -0.3f, 0.0f);
		// 	glVertex3f(position + tamanho, 0.3f, 0.0f);
		// glEnd();

		// if(position + tamanho >= 1.0f || position + tamanho <= -1.0f + tamanho){
		// 	direction *= -1;
		// }

		// Exercise 3

		position += 0.01f * direction;
		position2 += 0.01f * direction2;

		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(position, -0.3f, 0.0f);
			glVertex3f(position, 0.3f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(position, -0.3f, 0.0f);
			glVertex3f(position + tamanho, -0.3f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(position, 0.3f, 0.0f);
			glVertex3f(position + tamanho, 0.3f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(position + tamanho, -0.3f, 0.0f);
			glVertex3f(position + tamanho, 0.3f, 0.0f);
		glEnd();

		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(position2, -0.3f, 0.0f);
			glVertex3f(position2, 0.3f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(position2, -0.3f, 0.0f);
			glVertex3f(position2 + tamanho, -0.3f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(position2, 0.3f, 0.0f);
			glVertex3f(position2 + tamanho, 0.3f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(position2 + tamanho, -0.3f, 0.0f);
			glVertex3f(position2 + tamanho, 0.3f, 0.0f);
		glEnd();

		if(position + tamanho >= 1.0f || position + tamanho <= -1.0f + tamanho){
			direction *= -1;
		}

		if(position2 + tamanho >= 1.0f || position2 + tamanho <= -1.0f){
			direction2 *= -1;
		}
		






		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
