#include<GL/glut.h>
#include<iostream>

using namespace std;

void defaultDisplay();
void triangle();
void point();

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(200,50);
   glutCreateWindow("Activity - Group 5");
   glutDisplayFunc(defaultDisplay);
   glutMainLoop();
   
   return 0;
}


void triangle(){
	GLfloat trianglevertex[] = {
		0.0f, 0.80f, 0.0f,
		-0.25f, 0.55f, 0.0f,
		0.25f, 0.55f, 0.0f,
		
		0.0f, 0.55f, 0.0f,
		-0.25f, 0.30f, 0.0f,
		0.25f, 0.30f, 0.0f,
		
		0.0f, 0.30f, 0.0f,
		-0.25f, 0.05f, 0.0f,
		0.25f, 0.05f, 0.0f,
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, trianglevertex);
	
	glDrawArrays(GL_TRIANGLES,0,9);
	
	glDisableClientState(GL_VERTEX_ARRAY);
}


void point(){ 
    glPointSize(20.0);
    
    GLfloat pointvertex[] = { 
        -0.75f, -0.75f, 0.0f,
        -0.75f, 0.75f, 0.0f,
        0.75f, 0.75f, 0.0f,
        0.75f, -0.75f, 0.0f
    };
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, pointvertex);
    glDrawArrays(GL_POINTS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}


void defaultDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(220,20,60);
	point();
	triangle();
	glFlush();
}
