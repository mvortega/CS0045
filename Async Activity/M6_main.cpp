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

//Geronimo Dayos III, Aje Evangelista, Jeremiah Habana
void triangle(){
	GLfloat trianglevertex[] = {
		0.0f,.75f,0.0f, 
		-0.75f,0.0f,0.0f,
		0.75f,0.0f,0.0f
};
	
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, trianglevertex);
        glDrawArrays(GL_TRIANGLE,0,3);
        glEnableClientState(GL_VERTEX_ARRAY);
}


// Darla David and Miciella Decano
void point(){
	// Darla David
	GLfloat pointvertex[] = {
		-0.75f, -0.75f, 0.0f,
		-0.75f, 0.75f, 0.0f,
		0.75f, 0.75f, 0.0f,
		0.75f, -0.75f, 0.0f,
	};
    
    //Miciella Decano
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, pointvertex);
    glDrawArrays(GL_POINTS,0,4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void defaultDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(.16f, .72f, .08f, 1.0f);
	point();
	triangle();
	glFlush();
}
