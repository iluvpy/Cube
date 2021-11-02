#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Cube", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		perror("error while initializing glew!\n");
		glfwTerminate();
		return -1;
	}

	printf("%s\n", glGetString(GL_VERSION));
	glEnable(GL_DEPTH_TEST);
	float angle = 0.0f;
	float increment = 1.0f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		angle += increment;
		angle = (angle < 360.0f) ? angle : 0.0f;
		glLoadIdentity();
		glRotatef(angle, 1.0f, 1.0f, 0.0f);

		glBegin(GL_POLYGON);
		
		// face 1 (front)
		glColor3f(  1.0f, 0.0f, 0.0f);
		glVertex3f(-0.5f,  0.5f, 0.5f);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glVertex3f( 0.5f, -0.5f, 0.5f);
		glVertex3f( 0.5f,  0.5f, 0.5f);

		glEnd();
		glBegin(GL_POLYGON);

		// face 2 (left)
		glColor3f(  0.0f,  1.0f,  0.0f);
		glVertex3f(-0.5f,  0.5f,  0.5f);
		glVertex3f(-0.5f, -0.5f,  0.5f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glVertex3f(-0.5f,  0.5f, -0.5f);

		glEnd();
		glBegin(GL_POLYGON);

		// face 3 (right)
		glColor3f(  0.0f,  0.0f,  1.0f);
		glVertex3f( 0.5f,  0.5f,  0.5f);
		glVertex3f( 0.5f, -0.5f,  0.5f);
		glVertex3f( 0.5f, -0.5f, -0.5f);
		glVertex3f( 0.5f,  0.5f, -0.5f);

		glEnd();
		glBegin(GL_POLYGON);

		// face 4 (back)
		glColor3f(  0.5f,  0.5f,  0.5f);
		glVertex3f(-0.5f,  0.5f, -0.5f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glVertex3f( 0.5f, -0.5f, -0.5f);
		glVertex3f( 0.5f,  0.5f, -0.5f);

		glEnd();
		glBegin(GL_POLYGON);

		// face 5 (top)
		glColor3f(  1.0f,  1.0f,  1.0f);
		glVertex3f(-0.5f,  0.5f, -0.5f);
		glVertex3f(-0.5f,  0.5f,  0.5f);
		glVertex3f( 0.5f,  0.5f,  0.5f);
		glVertex3f( 0.5f,  0.5f, -0.5f);

		glEnd();
		glBegin(GL_POLYGON);

		// face 6 (bottom)
		glColor3f(  0.8f,  0.1f,  0.8f);
		glVertex3f(-0.5f, -0.5f,  0.5f);
		glVertex3f( 0.5f, -0.5f,  0.5f);
		glVertex3f( 0.5f, -0.5f, -0.5f);
		glVertex3f(-0.5f, -0.5f, -0.5f);

		glEnd();

	

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}