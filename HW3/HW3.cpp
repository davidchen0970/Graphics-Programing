#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
int j = 0;
void display()
{



	glClearColor(1, 1, 1, 1.0);		//�I���C��
	glClear(GL_COLOR_BUFFER_BIT);	//�N�w�İϲM�����w�]��

	glMatrixMode(GL_MODELVIEW);		//���w���@�ӬO��e���x�}
	/*
	GL_MODELVIEW,��ҫ����ϯx�}���α��U�Ӫ��x�}�ާ@�A����өR�O��A��Xø�s���ϧΡC
	GL_PROJECTION,���v�x�}��̶i��x�}�ާ@�A����өR�O��A�������W�[�z���ĪG�C
	GL_TEXTURE,�ﯾ�z�x�}��̶i��x�}�ާ@�A����өR�O��A�i�H���ϧμW�[���z�K�ϡC
	*/
	glLoadIdentity();				//���N���e���x�} �ܦ����x�}
	//gluLookAt(1, 1, 0, 0, 0, 0, 0, 1, 0);
	//�w�q�[�ݪ�����()
//glPushMatrix();
	glColor3f(0, 0, 0);
	//glTranslatef(-20, -20, 0);
	glutWireCube(1);
	//glPopMatrix();
	//glColor3f(1, 0, 0);
	//glTranslatef(15, 15, 0);
	//glutWireTeapot(3);
	glFlush();

}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	//glFrustum(-20, 20.0, -20.0, 20.0, -20.0, 20.0); //(x�̥���,x�̥k��,y�̥���,y�̥k��,z�̥���,z�̥k��)
	glMatrixMode(GL_MODELVIEW);
}

void mouseFunc(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glClearColor(1, 1, 1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		printf("%d %d ", x, y);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//gluLookAt(1, 1, 0, 0, 0, 0, 0, 1, 0);
		glColor3f(0, 0, 0);
		glTranslatef((-250+x)/25, (250-y)/25, 0);
		glutWireCube(1);
		glFlush();
	}
}

void main(int argc, char** argv)
{
	glutInitWindowSize(500, 500);			//windowsize �e500,��400
	glutCreateWindow("simple");
	j++;
	glutDisplayFunc(display);
	init();
	glutMouseFunc(mouseFunc);
	glutMainLoop();

}





/*

	void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far)

*/

