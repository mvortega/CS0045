#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
void display();

//GLfloat polygonvertices[] = {
//-0.5f,0.5f,0.0f, //first vertex
//0.5f,0.5f,0.0f, //second vertex
//1.0f,0.0f,0.0f, //third vertex
//0.5f,-0.5f,0.0f, //fourth vertex
//-0.5f,-0.5f,0.0f, //fifth vertex
//-1.0f,0.0f,0.0f //sixth vertex
//};
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
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.5f,0.5f,0.0f);
	glLineWidth(6);
	glEnd();
//GLuint VBOid;
//glGenBuffers(1, &VBOid);
//glBindBuffer(GL_ARRAY_BUFFER, VBOid);
//glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*18, polygonvertices, GL_STATIC_DRAW);
//glEnableClientState(GL_VERTEX_ARRAY);
//glVertexPointer(3, GL_FLOAT, 0, 0);
//glDrawArrays(GL_POLYGON,0,18);
//glDisableClientState(GL_VERTEX_ARRAY);
//// bind with 0, so, switch back to normal pointer operation
//glBindBuffer(GL_ARRAY_BUFFER, 0);
//glDeleteBuffers(1, &VBOid);
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor4f(.20f,.25f,.08f,.09f);
polygon();
glFlush();
}
