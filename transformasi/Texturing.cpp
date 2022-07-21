
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <Windows.h>
#include "loadimage.h"

GLuint gambar1;
GLuint gambar2;
GLuint gambar3;
GLuint gambar4;
GLuint gambar5;

bool animasi = false;
float angle = 0.0f;

float xrot = 20.0f;
float yrot = 0.0f;
float scale = 1.0f;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

float xdiff = 0;
float ydiff = 0;

bool mousedown = false;

void transformasi() {
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f); 
	glScalef(scale, scale, scale); 
	glTranslatef(xmov, ymov, zmov);
	
}

void sgitga() {

	
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, gambar4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-0.5,0.0, 0.5);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5,0.0,0.5);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0.0,0.0,-0.5);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, gambar5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0.0, 0.5, -0.5);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, gambar1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glColor3f(1.5, 1.5, 1.5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.5, 0.0, 0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5, 0.0, 0.5);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, gambar2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-0.5, 0.0, 0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.0, 0.0, -0.5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.5, -0.5);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, gambar3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5, 0.0, 0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.0, 0.0, -0.5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 0.5,-0.5);
	glEnd();



	glDisable(GL_TEXTURE_2D);

	
}

void display() {

	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	
	transformasi();
	sgitga();

	


	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}



void myinit() {
	glClearColor(0.0f, 1.0f, 0.906f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	gambar1 = loadjpg_custom("C:/Users/asus/Documents/TUGAS4_672019154_transformasi_Texturing/transformasi/a.bmp");
	gambar2 = loadjpg_custom("C:/Users/asus/Documents/TUGAS4_672019154_transformasi_Texturing/transformasi/b.bmp");
	gambar3 = loadjpg_custom("C:/Users/asus/Documents/TUGAS4_672019154_transformasi_Texturing/transformasi/c.bmp");
	gambar4 = loadjpg_custom("C:/Users/asus/Documents/TUGAS4_672019154_transformasi_Texturing/transformasi/d.bmp");
	gambar5 = loadjpg_custom("C:/Users/asus/Documents/TUGAS4_672019154_transformasi_Texturing/transformasi/f.bmp");

	
	
}

void resize(int width, int height)
{
	if (height == 0) height = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(18.0, width / height, 0.1, 100.0);
	glTranslatef(0.0f, -0.5f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
}

void mouseMove(int x, int y) {
	if (mousedown) {
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mousedown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else {
		mousedown = false;
	}
	glutPostRedisplay();
}
void keyboardSpecial(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
		xmov -= 0.01f;
		break;
	case GLUT_KEY_UP:
		ymov += 0.01f;
		break;
	case GLUT_KEY_RIGHT:
		xmov += 0.01f;
		break;
	case GLUT_KEY_DOWN:
		ymov -= 0.01f;
		break;
	}
	
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
	case 'A':
		yrot -= 3.0f;
		break;
	case 'd':
	case 'D':
		yrot += 3.0f;
		break;
	case 'w':
	case 'W':
		xrot += 3.0f;
		break;
	case 's':
	case 'S':
		xrot -= 3.0f;
		break;

	case 'z':
	case 'Z':
		scale += 0.3f;
		break;
	case 'x':
	case 'X':
		scale -= 0.3f;
		break;

	
	case 'q':
	case 'Q':
		if (animasi) {
			animasi = false;
			printf("Stop\n");
		}
		else {
			printf("Play\n");
			animasi = true;
		}
		break;


	}
	glutPostRedisplay();
}
void timer(int) {
	glutTimerFunc(10, timer, 0);

	if (animasi)
		xrot -= 3.0f;
	else
		xrot = xrot;

	glutPostRedisplay();
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutReshapeFunc(resize);
	glutCreateWindow("TEGUH RIYADI - 672019154");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutTimerFunc(0, timer, 0);
	

	myinit();
	glutMainLoop();

	return 0;
}
