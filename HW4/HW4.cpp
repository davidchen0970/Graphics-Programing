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
void first_display()
{

	angle += 1;
	glutPostRedisplay();

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//第一個圓柱體
	{
		glColor3f(0.5, 0.7, 0.0);
		glPushMatrix();
		glTranslatef(0, base, 0);
		glRotatef(angle, 0, 1, 0);
		glRotatef(90, 2, 0, 0);								//(0,0,0)到(x,y,z)的向量,右手拇指指向向量，四指環繞是旋轉方向
		GLUquadricObj* quadricPtr;							//新建一個物體(未定義)
		quadricPtr = gluNewQuadric();						//新建一個二次的物體
		gluQuadricDrawStyle(quadricPtr, GLU_LINE);			//指定二次曲面所需的法線類型
		gluQuadricNormals(quadricPtr, GLU_NONE);
		gluQuadricTexture(quadricPtr, GL_FALSE);
		gluCylinder(quadricPtr, 5, 10, 5, 15, 10);
		glTranslatef(0, 0, 0);
		glPopMatrix();
	}
	//第二個圓柱體
	{
		glColor3f(0.7, 0.5, 0.0);
		glPushMatrix();
		glTranslatef(0, base + 15, 0);
		glRotatef(angle, 0, 1, 0);
		glRotatef(90, 2, 0, 0);								//(0,0,0)到(x,y,z)的向量,右手拇指指向向量，四指環繞是旋轉方向
		GLUquadricObj* quadricPtr;							//新建一個物體(未定義)
		quadricPtr = gluNewQuadric();						//新建一個二次的物體
		gluQuadricDrawStyle(quadricPtr, GLU_LINE);			//指定二次曲面所需的法線類型
		gluQuadricNormals(quadricPtr, GLU_NONE);
		gluQuadricTexture(quadricPtr, GL_FALSE);
		gluCylinder(quadricPtr, 5, 5, 15, 15, 10);
		glTranslatef(0, 0, 0);
		glPopMatrix();
	}
	//第三個圓柱體
	{
		glColor3f(0.7, 0.5, 0.0);
		glPushMatrix();
		glTranslatef(0, base + 15 + 30, 0);
		glRotatef(angle, 0, 1, 0);
		glRotatef(90, 2, 0, 0);								//(0,0,0)到(x,y,z)的向量,右手拇指指向向量，四指環繞是旋轉方向
		GLUquadricObj* quadricPtr;							//新建一個物體(未定義)
		quadricPtr = gluNewQuadric();						//新建一個二次的物體
		gluQuadricDrawStyle(quadricPtr, GLU_LINE);			//指定二次曲面所需的法線類型
		gluQuadricNormals(quadricPtr, GLU_NONE);
		gluQuadricTexture(quadricPtr, GL_FALSE);
		gluCylinder(quadricPtr, 3, 3, 30, 15, 10);
		glTranslatef(0, 0, 0);
		glPopMatrix();
	}
	//第一個球體
	{
		glColor3f(0.1, 0.3, 0.5);
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);
		glTranslatef(0, base + 15 + 30, 0);
		GLUquadricObj* quadricPtr8;
		quadricPtr8 = gluNewQuadric();
		gluQuadricDrawStyle(quadricPtr8, GLU_LINE);
		gluQuadricNormals(quadricPtr8, GLU_NONE);
		gluQuadricTexture(quadricPtr8, GL_FALSE);
		gluSphere(quadricPtr8, 3, 50, 15);
		glPopMatrix();
	}
	//下手臂
	{
		glColor3f(0, 0.5, 0.3);
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);

		glTranslatef(0, base + 15 + 30, 0);
		GLfloat temp = tan(arm_first_angle);
		glRotatef(90, -1.0 * temp, 1, 0);		//第一個是angle,第二個後是(0,0,0)到(x,y,z)的向量,右手拇指指向向量，四指環繞是旋轉方向
		GLUquadricObj* quadricPtr;							//新建一個物體(未定義)
		quadricPtr = gluNewQuadric();						//新建一個二次的物體
		gluQuadricDrawStyle(quadricPtr, GLU_LINE);			//指定二次曲面所需的法線類型
		gluQuadricNormals(quadricPtr, GLU_NONE);
		gluQuadricTexture(quadricPtr, GL_FALSE);
		gluCylinder(quadricPtr, 3, 3, 30, 15, 10);
		glTranslatef(0, 0, 0);
		glPopMatrix();
	}
	//第二顆球體
	{
		glColor3f(0.1, 0.3, 0.5);
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);

		glTranslatef(30 * cos(arm_first_angle), base + 15 + 30 + 30 * sin(arm_first_angle), 0);
		GLUquadricObj* quadricPtr8;
		quadricPtr8 = gluNewQuadric();
		gluQuadricDrawStyle(quadricPtr8, GLU_LINE);
		gluQuadricNormals(quadricPtr8, GLU_NONE);
		gluQuadricTexture(quadricPtr8, GL_FALSE);
		gluSphere(quadricPtr8, 3, 50, 15);
		glPopMatrix();
	}
	//上手臂
	{
		glColor3f(0, 0.5, 0.3);
		glPushMatrix();
		glRotatef(angle, 0, 1, 0);

		GLfloat temp = tan(arm_second_angle);
		glTranslatef(30 * cos(arm_first_angle), base + 15 + 30 + 30 * sin(arm_first_angle), 0);
		glRotatef(90, 1, temp, 0);							//第一個是angle,第二個後是(0,0,0)到(x,y,z)的向量,右手拇指指向向量，四指環繞是旋轉方向
		GLUquadricObj* quadricPtr;							//新建一個物體(未定義)
		quadricPtr = gluNewQuadric();						//新建一個二次的物體
		gluQuadricDrawStyle(quadricPtr, GLU_LINE);			//指定二次曲面所需的法線類型
		gluQuadricNormals(quadricPtr, GLU_NONE);
		gluQuadricTexture(quadricPtr, GL_FALSE);
		gluCylinder(quadricPtr, 3, 1, 30, 15, 10);
		glTranslatef(0, 0, 0);
		glPopMatrix();
	}


	glFlush();

}

void init_render()
{
	glMatrixMode(GL_PROJECTION);			//要用GL_PROJECTION模式才可以改視窗
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -50, 50);
	//glFrustum(-50, 50, -50, 50, -50, 50);	//(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far)
	//gluLookAt(1, 1, 1, 0, 0, 0, 0, 0, 0);
	//gluLookAt(0.1, 0.1, 0.1, 0, 0, 0, 1, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}



void mouseFunc(int button, int state, int x, int y)
{
	;
}

void keyboardFunc(unsigned char key, int x, int y)
{
	//printf("%d", int(key));
	switch (int(key))
	{
	case 115:
		if (arm_first_angle > -0.9)	arm_first_angle -= 0.01727;
		break;
	case 119:
		if (arm_first_angle < 1.39626)	arm_first_angle += 0.01727;
		break;
	case 100:
		angle += 1;
		glutPostRedisplay();
		break;
	case 97:
		angle -= 1;
		glutPostRedisplay();

		break;
	case 113:
		if (arm_second_angle > 0.1)	arm_second_angle -= 0.01727;
		break;
	case 101:
		if (arm_second_angle < 1.39626)	arm_second_angle += 0.01727;
		break;
	case 120:
		glLoadIdentity();
		gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
		break;
	case 122:
		glLoadIdentity();
		gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, -1);
		break;
	}
	glutPostRedisplay();

}

void ChangeSize(GLsizei weigth, GLsizei heigth)
{
	GLfloat aspectRatio;
	if (heigth == 0)
	{
		heigth = 1;
	}

	glViewport(0, 0, weigth, heigth);	//將可視範圍設為視窗大小

	glMatrixMode(GL_PROJECTION);		//重設座標系統為投影模式
	glLoadIdentity();

	aspectRatio = (GLfloat)weigth / (GLfloat)heigth;	//建立剪裁區域

	if (weigth <= heigth)
	{
		glOrtho(-50, 50, -50 / aspectRatio, 50 / aspectRatio, 50, -50);
	}
	else
	{
		glOrtho(-50.0 * aspectRatio, 50.0 * aspectRatio, -50, 50, 50, -50);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("homework 4");
	glutDisplayFunc(first_display);

	init_render();
	glutMouseFunc(mouseFunc);
	glutKeyboardFunc(keyboardFunc);
	glutReshapeFunc(ChangeSize);


	glutMainLoop();
}