#include <GL/glut.h>

void mydisplay() //ø�Ϩ��
{

	glClearColor(1, 1, 1, 1.0);			//�I���C��
	glClear(GL_COLOR_BUFFER_BIT);		//�N�w�İϲM�����w�]��

	glMatrixMode(GL_MODELVIEW);			//���w���@�ӬO��e���x�}
	/*
	GL_MODELVIEW,��ҫ����ϯx�}���α��U�Ӫ��x�}�ާ@�A����өR�O��A��Xø�s���ϧΡC
	GL_PROJECTION,���v�x�}��̶i��x�}�ާ@�A����өR�O��A�������W�[�z���ĪG�C
	GL_TEXTURE,�ﯾ�z�x�}��̶i��x�}�ާ@�A����өR�O��A�i�H���ϧμW�[���z�K�ϡC
	*/
	glLoadIdentity();					//���N���e���x�} �ܦ����x�}
										//gluLookAt(0, 0, 0, 0, 0, 0, 0, 0, 0);
										//�w�q�[�ݪ�����()
	glColor3f(1, 0, 0);
	glTranslatef(-10, 10, 0);			//�������
	/*
	void glTranslated(GLdouble x, GLdouble y, GLdouble z);
	void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
	*/
	glutWireTeapot(3);
	glTranslatef(25, -25, 0);
	glutWireTeapot(3);
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	//���w���@�ӬO��e���x�}
	/*
	GL_MODELVIEW,��ҫ����ϯx�}���α��U�Ӫ��x�}�ާ@�A����өR�O��A��Xø�s���ϧΡC
	GL_PROJECTION,���v�x�}��̶i��x�}�ާ@�A����өR�O��A�������W�[�z���ĪG�C
	GL_TEXTURE,�ﯾ�z�x�}��̶i��x�}�ާ@�A����өR�O��A�i�H���ϧμW�[���z�K�ϡC
	*/
	glLoadIdentity();
	glOrtho(-15.0, 25.0, -25.0, 15.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv) 
{
	
	glutInitWindowSize(500, 500);		//�]�m�e�� ����
	glutInitWindowPosition(400, 40);	//�]�mwindow �bscreen����m
	glutCreateWindow("simple");			//�إߵ���
	glutDisplayFunc(mydisplay);			

	init();

	glutMainLoop();
}