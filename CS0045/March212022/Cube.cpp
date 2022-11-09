#define GLEW_STATIC
#define BUFFER_OFFSET(i) ((void*)(i))
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#define  STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

using namespace std;

/*void display();
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

}*/ //part of orig code

void displayObject(); 
void init();

void GLAPIENTRY 
MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity, GLsizei length,
    const GLchar* message, 
    const void* userParam);


int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitWindowSize(1024,768);
   glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH); 
   glutCreateWindow("Cube");
   init(); 
   
   glutDisplayFunc(displayObject);
   GLenum err = glewInit(); 
   if(err == GLEW_OK){
    glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(MessageCallback, 0);
        printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
        printf("OpenGL vendor (%s): \n", glGetString(GL_VENDOR)); 
        glutMainLoop();
    } 
}

GLfloat cubevertices[] = {
//---------------------- CUBE
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f,  1.0f,
    
    1.0f, 1.0f,  1.0f,
    1.0f, -1.0f,  1.0f, 
    -1.0f, -1.0f,  1.0f,
    
    -1.0f, -1.0f, -1.0f, 
    1.0f, -1.0f, -1.0f,
    1.0f,  1.0f, 1.0f, 
    
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f, 
    1.0f, -1.0f, 1.0f,
    
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
    1.0f, -1.0f, -1.0f
};

GLfloat texturecoord[] = {
//---------------------- CUBE
    1.0f,  1.0f, 1.0f, 
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f, 
    1.0f, -1.0f, 1.0f,
    
    1.0f,  1.0f, 1.0f, 
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f, 
    1.0f, -1.0f, 1.0f,
    
    1.0f,  1.0f, 1.0f, 
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f, 
    1.0f, -1.0f, 1.0f,
    
    1.0f,  1.0f, 1.0f, 
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f, 
    1.0f, -1.0f, 1.0f,
    
    1.0f,  1.0f, 1.0f, 
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f, 
    1.0f, -1.0f, 1.0f,
    
    1.0f,  1.0f, 1.0f, 
    -1.0f,  1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f, 
    1.0f, -1.0f, 1.0f,
};


void displayObject(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW ); 
    glLoadIdentity();
    gluLookAt(2.0,2.0,4.0,0.0,0.0,0.0,0.0,1.0,0.0); 
    
   //General Light
    GLfloat lmodelambient [] = {.2,.2,.2,1.0}; 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodelambient);
    
    //Material
    GLfloat math_ambient[] = {0.0f,0.0f,1.0f,1.0f}; //Blue 
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, math_ambient);
    
    //Directional Light
    GLfloat lightposition0[] = {1.0f, 0.0f,2.0f, 1.0f}; 
    GLfloat lightcolor0[] = {0.5f, 0.2f, 0.2f, 1.0f}; 
    glLightfv(GL_LIGHT0,GL_DIFFUSE, lightcolor0); 
    glLightfv(GL_LIGHT0,GL_POSITION,lightposition0);
    
    //Spotlight
    GLfloat lightposition1[] = {0.0f, 4.0f,0.0f, 1.0f};
    GLfloat lightcolor1[] = {1.0f, 0.2f, 1.0f, 0.2f};
    GLfloat spotdirection[] = {0.0f, -1.0f, 0.0f}; 
    glLightfv(GL_LIGHT1,GL_DIFFUSE, lightcolor1);
    glLightfv(GL_LIGHT1,GL_POSITION,lightposition1); 
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotdirection); 
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF, 15.0);
    glutSolidCube(1.0);
    
    //Generate Texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("cubetexture.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        cout << width << " " << height << " " << nrChannels << endl;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        cout << "Failed to load texture" << std::endl;
        exit(0);
    }
    stbi_image_free(data);
    
    //Display Cube
    GLuint VBOid;
    glGenBuffers(1, &VBOid);
    glBindBuffer(GL_ARRAY_BUFFER, VBOid);
    glBufferData(GL_ARRAY_BUFFER,  ((12*6) * 3 ) * sizeof(GLfloat), cubevertices, GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, (((12*6)*2) * sizeof(GLfloat)),((12*6) * sizeof(GLfloat)), texturecoord);
    
    glEnableClientState(GL_VERTEX_ARRAY);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glTexCoordPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(((12*6)*2)*sizeof(GLfloat) ));
    
    
    glBegin(GL_QUADS);
    
        for(int i=0; i < 24; i++){
            glArrayElement(i);
        }
        
    glEnd();
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &VBOid);
    
    glFlush();
}

void GLAPIENTRY MessageCallback(GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam ){
        fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR**" : "" ),type, severity, message); 
        }

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1024.0/768.0, 1.0, 10.0);
    glEnable(GL_DEPTH_TEST);
    
   
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
}
