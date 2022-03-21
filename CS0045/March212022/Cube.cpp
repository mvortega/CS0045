#include <iostream>
#include <cstdlib>
#include <GL/glut.h>

using namespace std;

void display();
void view();

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  view();
  glFlush();
}

void view(){
  	// glBegin(GL_POLYGON);//cube base
  	// glColor3f(1.0,1.0,1.0);
	  //   glVertex2f(-0.3, -0.3);
	  //   glVertex2f(-0.3, 0.3);
	  //   glVertex2f(0.3, 0.3);
	  //   glVertex2f(0.3, -0.3);
  	// glEnd();
  	

  	glLineWidth(3);//cube line
		glColor3f(2.0,2.0,2.0);
	glBegin(GL_LINE_STRIP);
	glColor3f(21.0, 0.0, 1.0);
	     glVertex2f(0.3, -0.3);
	     glVertex2f(-0.3, -0.3);
	     glVertex2f(-0.3, 0.3);
	     glVertex2f(0.3, 0.3);
	     glVertex2f(0.3, -0.3);
	glEnd();
  
  	glLineWidth(3);//top left line
		glColor3f(2.0,2.0,2.0);
	glBegin(GL_LINE_STRIP);
	glColor3f(21.0, 0.0, 1.0);
	     glVertex2f(-0.3, 0.3);
			 glVertex2f(0.3, 0.7);
			 glVertex2f(0.7,0.7);
			 glVertex2f(0.3,0.3);
	glEnd();	

	  	glLineWidth(3);//bottom right line
		glColor3f(2.0,2.0,2.0);
	glBegin(GL_LINE_STRIP);
	glColor3f(21.0, 0.0, 1.0);
			 glVertex2f(0.7,0.7);
			 glVertex2f(0.7, 0.3);
			 glVertex2f(0.3, -0.3);
			 
	glEnd();	

}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(600,400);
   glutCreateWindow("Cube");
   glutDisplayFunc(display);
   glutMainLoop();
}
