#define GLEW_STATIC // <----- define GLEW_STATIC
#include<iostream>
#include <GL/glew.h> // <---- additional header files
#include <GL/glut.h>
using namespace std;
void display();
void triangle();
void init();
void keyBoardMonitor(unsigned char key, int x, int y);
GLuint VBOid;
bool initTriangle = true;
float angle = 1.0f;
GLfloat trianglevertices[] = {
0.0f, .75f, 0.0f,
-0.75f, 0.0f, 0.0f,
0.75f, 0.0f, 0.0f
};
int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitWindowSize(800,600);
glutInitWindowPosition(100,100);
glutCreateWindow("simple");
glutKeyboardFunc(keyBoardMonitor);
glutDisplayFunc(display);
GLenum err = glewInit(); 
if (err == GLEW_OK) {
glutMainLoop(); 
}
}
void triangle(){
if(initTriangle){
glGenBuffers(1, &VBOid);
glBindBuffer(GL_ARRAY_BUFFER, VBOid);
glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, trianglevertices, GL_STATIC_DRAW);
glEnableClientState(GL_VERTEX_ARRAY);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0f, -0.5f, 0.0f);
glScalef(.75f,.75f,0.0f);
initTriangle= false;
}
glPushMatrix();
glRotatef(angle,0.0f,0.0f,-1.0); //altered from counter-clockwise to clockwise
glVertexPointer(3, GL_FLOAT, 0, 0);
glDrawArrays(GL_TRIANGLES,0,6);
glPopMatrix();
}
void animateTriangle(int value){
angle++;
glutPostRedisplay();
}
void display(){
glClear(GL_COLOR_BUFFER_BIT);
glColor4f(.16f,.72f,.08f,1.0f);
triangle();
glFlush();
glutTimerFunc(200,animateTriangle,1);
}
void keyBoardMonitor(unsigned char key, int x, int y){
if(key == 'x'){
glDisableClientState(GL_VERTEX_ARRAY);
glBindBuffer(GL_ARRAY_BUFFER, 0);
glDeleteBuffers(1, &VBOid);
exit(0);
}
}
