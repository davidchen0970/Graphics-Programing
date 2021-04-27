#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
GLint Size = 10;
GLfloat angle = 0.0f;
GLint X = 1, Y = 1, Z = 0;
int base = -40;
GLfloat arm_first_angle = 0.79, arm_second_angle = 0.79;
int rotating = 0;

int ii = 0;
void first_display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 1);
	
	GLUquadricObj* quadricPtr;							//新建一個物體(未定義)
	quadricPtr = gluNewQuadric();						//新建一個二次的物體
	gluQuadricDrawStyle(quadricPtr, GLU_LINE);			//指定二次曲面所需的法線類型
	gluQuadricNormals(quadricPtr, GLU_NONE);
	gluQuadricTexture(quadricPtr, GL_FALSE);
	glTranslatef(-10, -10, -10);
	glTranslatef(10, 10, 10);
		if (ii == 2)
		{
		float m[16];
		for (int i = 0; i < 16; i++)
		{
			m[i] = 0;
		}
		m[0] = m[5] = m[10] = m[15] = 1;
		m[4] = 1.0 / tan(60 / 180.0 * 3.14159);
		glMultMatrixf(m);
		}
		if (ii == 1)
		{
			glTranslatef(10, 10, 10);
		}
		glRotatef(angle, 0, 1, 0);
	gluSphere(quadricPtr, 10, 20, 40);
	glLoadIdentity();
	glFlush();
}

void init_render()
{
	glMatrixMode(GL_PROJECTION);			//要用GL_PROJECTION模式才可以改視窗
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -50, 50);
	glMatrixMode(GL_MODELVIEW);
}

void MENU(int in)
{
	glMatrixMode(GL_MODELVIEW);
	if (in == 1)
	{
		ii = 2;
	}
	else if (in == 2)
	{
		ii = 1;
	}
	else if (in == 3)
	{
		ii = 0;
	}
	
}

void idle()
{
	angle += 1;
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("homework 6");
	glutDisplayFunc(first_display);
	
	init_render();
	
	glutCreateMenu(MENU);
	glutAddMenuEntry("歪斜", 1);
	glutAddMenuEntry("任意點旋轉", 2);
	glutAddMenuEntry("BACK", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutIdleFunc(idle);
	glutMainLoop();
}