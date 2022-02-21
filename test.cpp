#include <iostream>
#include <windows.h>
#include <GL\glut.h>
#include <GL\freeglut_ext.h>
using namespace std;

void defaultDisplay();
void keyboardMonitor(unsigned char key, int x, int y);
void mouseMonitor(int button, int state, int x, int y);
void detectMotion(int x, int y);
void detectPassiveMotion(int x, int y);
void mouseEntryDetector(int state);
void specialMonitor(int key, int x, int y);

void animateString(int value);
float t1x1 = -0.6, t1x2 = -0.4, t1x3 = -0.2,
 t2x1 = 0.6, t2x2 = 0.4, t2x3 = 0.2 ,
 y1 = 0.6, y2 = 0.8, 
 lx1 = 0.2, lx2 = -0.2, ly = 0.3;

int r1 = 0, g1 = 0, b1 = 255,
r2 = 0, g2 = 0 , b2 = 255;



int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(200,50);
	glutCreateWindow("My First OpenGL");
	//glutFullScreen();
	
	glutDisplayFunc(defaultDisplay);
	glutKeyboardFunc(keyboardMonitor);
	glutMouseFunc(mouseMonitor);
	glutMotionFunc(detectMotion);
	glutPassiveMotionFunc(detectPassiveMotion);
	glutEntryFunc(mouseEntryDetector);
	glutSpecialFunc(specialMonitor);
	
	//glutIdleFunc(animateText );
	
	glutMainLoop();
return 0;
}

void mouseEntryDetector(int state){
	if(state == GLUT_LEFT){
		cout << "Mouse has left the application " <<endl;
	}
	else{
		cout << "Mouse has re-entered the application " << endl;
	}
}

void animateString(int value){
	int i = 1;
	if(value==1){
		t1x1 += .02f;
		t1x2 += .02f;
		t1x3 += .02f;
		t2x1 += .02f;
		t2x2 += .02f;
		t2x3 += .02f;
		lx1 += .02f;
		lx2 += .02f;
		i++;
	}
	else{
		t1x1 += .02f;
		t1x2 += .02f;
		t1x3 += .02f;
		t2x1 += .02f;
		t2x2 += .02f;
		t2x3 += .02f;
		lx1 += .02f;
		lx2 += .02f;
	}
	glutPostRedisplay();
	if(i == 5){
		glutLeaveMainLoop();
	}
	
	
}


void detectMotion(int x, int y){
	cout << x << " " << y << endl;
}

void detectPassiveMotion(int x, int y){
	cout << x << "P " << y << endl;
}

void mouseMonitor(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		if( state == GLUT_DOWN){
			cout << "Left button was clicked..." << endl;
			if(b1 == 255){
				b1 -= 255;
				g1 += 255;
			}
			else if(g1 == 255){
				b1 += 255;
				g1 -= 255;
			}
			
		}
			
		else
			cout << "Left button was released..." << endl;
	}
	else if(button == GLUT_RIGHT_BUTTON){
		if( state == GLUT_DOWN){
			cout << "Right button was clicked..." << endl;
			if(b2 == 255){
				b2 -= 255;
				g2 += 255;
			}
			else if(g2 == 255){
				b2 += 255;
				g2 -= 255;
			}
		}
		
	}
	else{
		cout << "Middle button was clicked..." << endl;
		}
	cout << x << " " << y << endl;
	//cout << button << endl;
}

void keyboardMonitor(unsigned char key, int x, int y){
	cout << key << endl;
	switch(key){
		case 'a':
			t1x1 -= .02f;
			t1x2 -= .02f;
			t1x3 -= .02f;
			t2x1 -= .02f;
			t2x2 -= .02f;
			t2x3 -= .02f;
			lx1 -= .02f;
			lx2 -= .02f;
			break;
		case  'd':
			t1x1 += .02f;
			t1x2 += .02f;
			t1x3 += .02f;
			t2x1 += .02f;
			t2x2 += .02f;
			t2x3 += .02f;
			lx1 += .02f;
			lx2 += .02f;
			break;
		case 's':
			y1 -= .02f;
			y2 -= .02f;	
			ly -= .02f;	
			break;
		case 'w':
			y1 += .02f;
			y2 += .02f;
			ly += .02f;
			break;
		case 27:
			glutTimerFunc(1000,animateString,1);			
			break;
		default:
			x=0.0f;
	}
	glutPostRedisplay();
}
void specialMonitor(int key, int x, int y){
	cout << key << endl;
	if(key == GLUT_KEY_LEFT){
		if(b1 == 255){
				b1 -= 255;
				g1 += 255;
			}
		else if(g1 == 255){
			b1 += 255;
			g1 -= 255;
			}
	}
	else if(key == GLUT_KEY_RIGHT){
		if(b2 == 255){
				b2 -= 255;
				g2 += 255;
			}
		else if(g2 == 255){
			b2 += 255;
			g2 -= 255;
			}
	}
	glutPostRedisplay();
}

void defaultDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);
    glLineStipple(4, 0xAAAA);

    glBegin(GL_POLYGON);
        glColor3f(255, 255, 0);
        glVertex2f(-1, -1);
        glVertex2f(-1, 1);
        glVertex2f(1, 1);
        glVertex2f(1, -1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(r1, g1, b1);
        glVertex2f(t1x1, y1);
        glVertex2f(t1x2, y2);
        glVertex2f(t1x3, y1);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(r2, g2, b2);
        glVertex2f(t2x1, y1);
        glVertex2f(t2x2, y2);
        glVertex2f(t2x3, y1);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3f(0, 0, 255);
        glVertex2f(lx1, ly);
        glVertex2f(lx2, ly);
    glEnd();
	glFlush();
	
}
