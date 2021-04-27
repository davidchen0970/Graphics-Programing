#include <GL/glut.h>

void mydisplay() //繪圖函數
{

	glClearColor(1, 1, 1, 1.0);			//背景顏色
	glClear(GL_COLOR_BUFFER_BIT);		//將緩衝區清除成預設值

	glMatrixMode(GL_MODELVIEW);			//指定哪一個是當前的矩陣
	/*
	GL_MODELVIEW,對模型視圖矩陣應用接下來的矩陣操作，執行該命令後，輸出繪製的圖形。
	GL_PROJECTION,對投影矩陣堆棧進行矩陣操作，執行該命令後，為場景增加透視效果。
	GL_TEXTURE,對紋理矩陣堆棧進行矩陣操作，執行該命令後，可以為圖形增加紋理貼圖。
	*/
	glLoadIdentity();					//取代之前的矩陣 變成單位矩陣
										//gluLookAt(0, 0, 0, 0, 0, 0, 0, 0, 0);
										//定義觀看的角度()
	glColor3f(1, 0, 0);
	glTranslatef(-10, 10, 0);			//平移函數
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
	//指定哪一個是當前的矩陣
	/*
	GL_MODELVIEW,對模型視圖矩陣應用接下來的矩陣操作，執行該命令後，輸出繪製的圖形。
	GL_PROJECTION,對投影矩陣堆棧進行矩陣操作，執行該命令後，為場景增加透視效果。
	GL_TEXTURE,對紋理矩陣堆棧進行矩陣操作，執行該命令後，可以為圖形增加紋理貼圖。
	*/
	glLoadIdentity();
	glOrtho(-15.0, 25.0, -25.0, 15.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv) 
{
	
	glutInitWindowSize(500, 500);		//設置寬度 高度
	glutInitWindowPosition(400, 40);	//設置window 在screen的位置
	glutCreateWindow("simple");			//建立視窗
	glutDisplayFunc(mydisplay);			

	init();

	glutMainLoop();
}