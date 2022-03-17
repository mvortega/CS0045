#define GLEW_STATIC
#define BUFFER_OFFSET(i) ((void*)(i))
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;

void displayObject();
void displayCube();
void GLAPIENTRY MessageCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam );
GLuint VBOid;
void keyMonitor(unsigned char key, int x, int y);
bool initCube = true;
float angle = 1.0f;
void init();

GLfloat vertices[] = {
		//------------------- Cube

	  1.0f, 1.0f, -1.0f,
	 -1.0f, 1.0f, -1.0f,
	 -1.0f, 1.0f,  1.0f,
	  1.0f, 1.0f,  1.0f,
 
      1.0f, -1.0f,  1.0f,
     -1.0f, -1.0f,  1.0f,
     -1.0f, -1.0f, -1.0f,
      1.0f, -1.0f, -1.0f,
 
      1.0f,  1.0f,  1.0f,
     -1.0f,  1.0f,  1.0f,
     -1.0f, -1.0f,  1.0f,
      1.0f, -1.0f,  1.0f,
 
    
      1.0f, -1.0f, -1.0f, 
     -1.0f, -1.0f, -1.0f,
     -1.0f,  1.0f, -1.0f,
      1.0f,  1.0f, -1.0f,
 
     -1.0f,  1.0f,  1.0f,
     -1.0f,  1.0f, -1.0f,
     -1.0f, -1.0f, -1.0f,
     -1.0f, -1.0f,  1.0f,
 
      1.0f,  1.0f, -1.0f,
      1.0f,  1.0f,  1.0f,
      1.0f, -1.0f,  1.0f,
      1.0f, -1.0f, -1.0f,

};

GLfloat colorscube[] = {
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
};

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutCreateWindow("03-17-22");
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	init();
	glutInitWindowSize(800,600);
	glutDisplayFunc(displayObject);
	glutKeyboardFunc(keyMonitor);
	GLenum err = glewInit();
	
	if(err == GLEW_OK){
		glEnable ( GL_DEBUG_OUTPUT );
		glDebugMessageCallback( MessageCallback, 0 );
		printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
		printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR));
		glutMainLoop();
	}
}

void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 800.0/600.0, 1.0, 10.0);
}

void displayCube(){
	if(initCube){
		glGenBuffers(1, &VBOid);
		glBindBuffer(GL_ARRAY_BUFFER, VBOid);
		glBufferData(GL_ARRAY_BUFFER, ((12*6) + (12*6)) * sizeof(GLfloat), vertices, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, (12*6) * sizeof(GLfloat),(12*6) * sizeof(GLfloat), colorscube);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, 0);
		glColorPointer(3, GL_FLOAT,0,BUFFER_OFFSET((12*6)*sizeof(GLfloat) ));
		initCube = false;
	}
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,4.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glPushMatrix();
	glRotatef(angle,0.0f,1.0f,0.0f);
	glBegin(GL_QUADS); 
	
	for(int i=0; i < 24; i++){
		glArrayElement(i);
	}
	
	glEnd(); 
	glFlush();
	glPopMatrix();
}

void animateCube(int value){
	if(angle>360)
	angle=0;
	angle++;
	glutPostRedisplay();
}

void keyMonitor(unsigned char key, int x, int y){
	if(key=='x'){
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &VBOid);
		exit(0);
	}
}

void displayObject(){
	glClear(GL_COLOR_BUFFER_BIT);
	displayCube();
	glutTimerFunc(50,animateCube,1);
	glFlush();
}

void GLAPIENTRY MessageCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam ){
	fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", type == GL_DEBUG_TYPE_ERROR ? "* GL ERROR *" : "" ,type, severity, message );
}


