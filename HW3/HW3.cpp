#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
int j = 0;
void display()
{



	glClearColor(1, 1, 1, 1.0);		//背景顏色
	glClear(GL_COLOR_BUFFER_BIT);	//將緩衝區清除成預設值

	glMatrixMode(GL_MODELVIEW);		//指定哪一個是當前的矩陣
	/*
	GL_MODELVIEW,對模型視圖矩陣應用接下來的矩陣操作，執行該命令後，輸出繪製的圖形。
	GL_PROJECTION,對投影矩陣堆棧進行矩陣操作，執行該命令後，為場景增加透視效果。
	GL_TEXTURE,對紋理矩陣堆棧進行矩陣操作，執行該命令後，可以為圖形增加紋理貼圖。
	*/
	glLoadIdentity();				//取代之前的矩陣 變成單位矩陣
	//gluLookAt(1, 1, 0, 0, 0, 0, 0, 1, 0);
	//定義觀看的角度()
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
	//glFrustum(-20, 20.0, -20.0, 20.0, -20.0, 20.0); //(x最左直,x最右值,y最左值,y最右值,z最左值,z最右值)
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
	glutInitWindowSize(500, 500);			//windowsize 寬500,高400
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

