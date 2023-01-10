#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void reshape(int,int);
void timer(int);
void init()
{
    glClearColor(0.173,0.216,0.230,1.0); //red green blue alpha
}
int main(int argc,char**argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
   glutInitWindowPosition(200,0); //position
   glutInitWindowSize(1200,800); //size
   glutCreateWindow("16101256");

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutTimerFunc(0,timer,0);
   init();

   glutMainLoop();
}
   float x_position = -10;
   int state = 1; //1 y3ny right -1 y3ny left

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //the flag to clear the frame buffer
    glLoadIdentity(); //to reset any coordinates
    glBegin(GL_POLYGON);
    glColor3f(0.196,0.164,0.132);
    glVertex2f(-0.9,-20);
    glVertex2f(30,-20);
    glVertex2f(30,8.5);
    glVertex2f(7.6,8.5);

    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(4,-2);
    glVertex2f(4.5,-2.5);
    glVertex2f(30,-2);

    glVertex2f(30,10.5);
    glVertex2f(7.6,10.5);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.0,0.2,0.2);
    glVertex2f(-30,6.9);
    glVertex2f(30,6.9);

    glVertex2f(30,7.2);
    glVertex2f(-30,7.2);

    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.2,0.2,0.2);
    glVertex2f(x_position,6.0);
    glVertex2f(x_position,6.0);

    glVertex2f(x_position,-4.0);
    glVertex2f(x_position+4.0,-4.0);
    glVertex2f(x_position+4.0,6.0);
    glVertex2f(x_position+2,7.0);

    glEnd();
    glBegin(GL_POLYGON);

    glColor3f(0.8,0.2,0.2);
    glVertex2f(x_position+2.3,6.5);
    glVertex2f(x_position+1.7,6.5);

    glVertex2f(x_position+1.3,7.5);
    glVertex2f(x_position+2.7,7.5);

    glEnd();


    glutSwapBuffers();

}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h); //view port
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int)
{
  glutPostRedisplay();
  glutTimerFunc(1000/60,timer,0);
  switch(state)
  {
  case 1 :
    if(x_position<16)
        x_position+=0.10;
    else
        state = -1;
    break;
  case -1 :
    if(x_position>-16)
        x_position-=0.10;
    else
        state=1;
    break;

  }
}
