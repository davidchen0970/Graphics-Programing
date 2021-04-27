#include <GL/glut.h>

void mydisplay() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glPointSize(10.0);
	glLineWidth(5.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-5.0, 5.0, 0.0);
	glVertex3f(-10.0, 5.0, 0.0);
	glVertex3f(-10.0, -5.0, 0.0);
	glVertex3f(-5.0, -5.0, 0.0);
	glVertex3f(-5.0, 0.0, 0.0);
	glVertex3f(-10.0, 0.0, 0.0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(5.0, 5.0, 0.0);
	glVertex3f(0.0, 5.0, 0.0);
	glVertex3f(0.0, -5.0, 0.0);
	glVertex3f(5.0, -5.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);

	glEnd();

	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv) {
	glutInitWindowSize(500, 500);
	glutCreateWindow("simple");
	glutDisplayFunc(mydisplay);

	init();

	glutMainLoop();
}