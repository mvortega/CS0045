#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
void display();

int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitWindowSize(800, 600);
glutCreateWindow("simple");
glutDisplayFunc(display);
GLenum err = glewInit();
if(err == GLEW_OK){
glutMainLoop();
}
}
void polygon(){
	//glBegin(GL_LINE_LOOP);
	//glVertex3f(-0.5f,0.5f,0.0f);
	//glVertex3f(0.5f,0.5f,0.0f);
	//glVertex3f(1.0f,0.0f,0.0f,);
	//insert vertex here
	GLfloat polygonvertices[] = {
	       -0.5f,0.5f,0.0f, //first vertex
		0.5f,0.5f,0.0f, //second vertex
		1.0f,0.0f,0.0f, //third vertex
		0.5f,-0.5f,0.0f, //fourth vertex
	       -0.5f,-0.5f,0.0f, //fifth vertex
	      -1.0f,0.0f,0.0f //sixth vertex
};
	
GLuint VBOid;
glGenBuffers(1, &VBOid);
glBindBuffer(GL_ARRAY_BUFFER, VBOid);
glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*18, polygonvertices, GL_STATIC_DRAW);
glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3, GL_FLOAT, 0, 0);
glDrawArrays(GL_LINE_LOOP,0,6);
glDisableClientState(GL_VERTEX_ARRAY);
//bind with 0, so, switch back to normal pointer operation
glBindBuffer(GL_ARRAY_BUFFER, 0);
glDeleteBuffers(1, &VBOid);
}
void display(){
glClearColor(0,0,1,0);
glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(6);
glColor4f(1.0f,0.0f,1.0f,0.0f);
polygon();
glFlush();
}
