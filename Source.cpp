#include <stdlib.h>
#include <GL/glut.h> 	// ����������� ���������:
#include <GL/gl.h>

#include <iostream>
float Angle = 90;
GLfloat rx=0, ry=0, rz=0;
GLdouble sx=1, sy=1, sz=1;
GLfloat tx=0, ty=0, tz=0;
int size =  10;



void display()
{
	
	glutWireTeapot(10);
	
	glFlush();



}


void myMouse(int button, int state, int x, int y)

{
	
	glPopMatrix();
	
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		sx = sx * 1.5;
		sy = sy * 1.5;
		sz = sz * 1.5;
		
	}

	
	else 
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{	
			sx = sx / (1.5);
			sy = sy / (1.5);
			sz = sz / (1.5);
			
	}

	glPushMatrix();
	glScaled(sx, sy, sz);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glutPostRedisplay();
	
}



void SpecialKey(int spec_key, int x, int y)
{
	int CTRL; 
	//glPopMatrix();
	CTRL = glutGetModifiers();
		
		if (CTRL == GLUT_ACTIVE_CTRL)
		{
			if (spec_key == GLUT_KEY_DOWN)
			{
				tx = 0;
				ty = 0;
				tz = -3;
			}


			if (spec_key == GLUT_KEY_UP)
			{
				tx = 0;
				tz = 3;
				ty = 0;
			}
		}


		if(CTRL!=GLUT_ACTIVE_CTRL) {
			if (spec_key == GLUT_KEY_DOWN)
			{
				ty = -3;
				tx = 0;
				tz = 0;
			}
			if (spec_key == GLUT_KEY_UP)
			{
				ty = 3;
				tx = 0;
				tz = 0;
			}

			if (spec_key == GLUT_KEY_RIGHT)
			{
				ty = 0;
				tx = 3;
				tz = 0;
			}
			if (spec_key == GLUT_KEY_LEFT)
			{
				ty = 0;
				tx = -3;
				tz = 0;
			}

		}
	
		
	glTranslatef(tx, ty, tz);
	//glPopMatrix();
	glClear(GL_COLOR_BUFFER_BIT);
	glutPostRedisplay();


}
void myKeyboard(unsigned char key, int x, int y)
{
	
	//glPopMatrix();
	switch (key)
	{
	case 'y':
		
		ry = 1, rz = 0, rx = 0;

		
		break;

	case 'x':
		rx = 1, ry = 0, rz = 0;
		
		break;
	case 'z':
		rz = 1, ry = 0, rx = 0;	
		break;

	default:
		break;
	};
	
	
	glRotatef(Angle,rx, ry, rz);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glutPostRedisplay();

}



int main(int argc, char** argv)
{
	
	setlocale(LC_ALL, "Russian");
	glutInit(&argc, argv); 		// �������������� OpenGL Utility Toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // �������������� ������� (GLUT_SINGLE - ���� ���������� �����, GLUT_RGB - ������� ����� ��� ��������� ��������, �������� � ������
	glutInitWindowSize(640, 480); 	// ������ ������ � ������ ���� ��� ��� �������������
	glutInitWindowPosition(0, 0); // ������ ���������� �������� ������ ���� ���� ������������ �������� ������ ���� ������
	glutCreateWindow("���� ���������"); // ��������� � ���������� ���� � ��������� ���������
	glClearColor(1, 1, 1, 0); // ������ ���� ���� (�������, �������, �����, ������������)
	glColor3ub(0, 0, 0); 		// ���� ��������� (�������, �������, ����� �� 0 �� 255 - unsigned byte)
	// glColor3f(1.0,1.0,1.0) // ��� ����� ������ ���� �� 0 �� 1 (float)
	glPointSize(2);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -1, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(0, 0, 20, 0, 1, 0, 0, 1, 0);
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(SpecialKey);
	glutMouseFunc(myMouse);
	
	
		
	

	
	
	// ����������� (���� �������� �����) �������, ������� ����� �������� �� ��������� ��� ������������� ������� ���������� ����
	glutMainLoop(); 		// ������ � ����������� ������� ����
	return 0;

}
