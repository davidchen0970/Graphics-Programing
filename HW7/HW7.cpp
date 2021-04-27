#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include<iostream>
using namespace std;
double angle = 0.0f;

double cha(int angle)
{
	//printf("%s\n",(double(angle) / 57.2));
	return (angle / 57.2);
}

void first_display()
{
	
	angle += 1;
	glutPostRedisplay();

	GLfloat temp[3] = { 40,40,40 };
	GLfloat m[16];
	for (int i = 0; i < 16; i++)
	{
		m[i] = 0;
	}
	m[0] = m[5] = m[10] = 1.0;
	m[7] = -1.0 / temp[1];
	glClearColor(1, 1, 1, 1.0);			
	glClear(GL_COLOR_BUFFER_BIT);		
	glMatrixMode(GL_MODELVIEW);			
	glLoadIdentity();
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0, 5, 0);
	glRotatef(angle, 0, 1, 0);
	glutWireTeapot(5);
	glPopMatrix();

	/*本節重點*/
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(temp[0], temp[1], temp[2]);
	glMultMatrixf(m);
	glTranslatef(-temp[0], -temp[1], -temp[2]);
	glColor3f(0.2, 0.2, 0.2);
	glTranslatef(0, -7, 0);
	glRotatef(angle, 0, 1, 0);
	glutSolidTeapot(5);
	glPopMatrix();
	/*重點結束*/

	glFlush();
}

void init_render()
{
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	glOrtho(-15.0, 25.0, -25.0, 15.0, -20.0, 20.0);
	gluLookAt(1, 1, 1, 0, 0,0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

}
void idle()
{


	angle+=1;
	glutPostRedisplay();

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("HW7");
	glutDisplayFunc(first_display);
	glutIdleFunc(idle);
	init_render();
	glutMainLoop();
}