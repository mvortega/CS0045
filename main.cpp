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
glutCreateWindow("Green Triangle");
glutDisplayFunc(defaultDisplay);
glutMainLoop();
return 0;
}
void triangle(){
GLfloat trianglevertex[] = 
{
   0.0f, 0.45f, 0.0f,
  -0.45f, 0.0f, 0.0f,
   0.45f, 0.0f, 0.0f
};
glEnableClientState(GL_VERTEX_ARRAY);
}
void point(){
	glPointSize(20.0);
	
	GLfloat pointvertex[] = {
	-0.45f, -0.45f,
	-0.45f, 0.45f,
	0.45f, 0.45f,
	0.45f, -0.45f
	};
	
}
void defaultDisplay(){
glClear(GL_COLOR_BUFFER_BIT);
glColor4f(.16f, .72f, .08f, 1.0f);
point();
triangle();
glFlush();
}
