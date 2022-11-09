#include <iostream>
#include <GL\glut.h>
using namespace std;
void defaultDisplay();
void point();
void triangle();
int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitWindowSize(1024,768);
glutInitWindowPosition(200,50);
glutCreateWindow("My First OpenGL");
glutDisplayFunc(defaultDisplay);
glutMainLoop();
return 0;
}
void triangle(){
glBegin(GL_TRIANGLES);
glVertex2f(0.0f, .75f);
glVertex2f(-0.75f,  0.0f);
glVertex2f(0.75f, 0.0f);
glEnd();
}
void point(){
glPointSize(20.0);
glBegin(GL_POINTS);
glVertex2f(-0.75f,  -0.75f);
glVertex2f(-0.75f,  0.75f);
glVertex2f(0.75f,  0.75f);
glVertex2f(0.75f,  -0.75f);
glEnd();
}
void defaultDisplay(){
glClear(GL_COLOR_BUFFER_BIT);
glColor4f(.16f, .72f, .08f, 1.0f);
point();
triangle();
glFlush();
}
