#include<windows.h>
#include<iostream>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<string.h>

using namespace std;
string direction="right";
GLint position=0,speed=10;
int snake_size[10];


void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-600.0, 600.0, -600.0, 600.0, -1.0, 1.0);
}
void update(int value)
{

    if(position >= 650)
        position = -600;

    position += speed;

    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}
void SpecialFunc(int key, int x, int y)
{
    if(direction=="right")
    {
        if(key == GLUT_KEY_UP)
        {
            direction="";
        }
        else if(key == GLUT_KEY_DOWN)
        {
            direction="bottom";
        }
    }

}
void Right(int a)
{
   glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0-a,0);
    glVertex2f(20-a,0);
    glVertex2f(20-a,20);
    glVertex2f(0-a,20);
    glEnd();
}
void Bottom(int a)
{
   glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0,0-a);
    glVertex2f(20,0-a);
    glVertex2f(20,20-a);
    glVertex2f(0,20-a);
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int a=0;
    for(int i=0;i<=10;i++)
    {

       glPushMatrix();
        glTranslatef(position,0.0f, 0.0f);
        if(direction=="right")
        {
          Right(a);
        }
        else if(direction=="bottom")
        {
            Bottom(a);
        }

        glPopMatrix();
        a=a+25;
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Snake");
    glutDisplayFunc(display);
    init();
    //glutKeyboardFunc(handleKeypress);
    //glutMouseFunc(handleMouse);
    glutSpecialFunc(SpecialFunc);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
