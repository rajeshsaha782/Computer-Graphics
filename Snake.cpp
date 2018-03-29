#include<windows.h>
#include <stdlib.h>
#include<iostream>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>

using namespace std;

string direction="right";
GLint  positionX=0,positionY=0,speed=10;
int snake_size[10],Rx,Ry;
bool visited=false;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(0.0, 600.0, 0.0, 600.0, -1.0, 1.0);
}

int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

void RandomPoints()
{
     Rx=random(0,600);
     Ry=random(0,600);
     Rx=Rx-(Rx%10);
     Ry=Ry-(Ry%10);
}

void RandomBox()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(Rx,Ry);
    glVertex2f(Rx+10,Ry);
    glVertex2f(Rx+10,Ry+10);
    glVertex2f(Rx,Ry+10);
    glEnd();
   // cout<<"X:"<<Rx<<"Y:"<<Ry<<endl;
}

void update(int value)
{

    if( positionX >= 700)
         positionX = 0;
    else if( positionX <=-110)
         positionX = 600;

    else if( positionY >= 700)
         positionY = 0;
    else if( positionY <= -110)
         positionY = 600;

    if(direction=="right")
    {
         positionX += speed;
    }
    else if(direction=="left")
    {
         positionX -= speed;
    }
    else if(direction=="top")
    {
         positionY += speed;
    }
    else if(direction=="bottom")
    {
         positionY -= speed;
    }


    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}

void SpecialFunc(int key, int x, int y)
{
    if(direction=="right" || direction=="left")
    {
        if(key == GLUT_KEY_UP)
        {
            direction="top";
        }
        else if(key == GLUT_KEY_DOWN)
        {
            direction="bottom";
        }
    }
    else if(direction=="top" || direction=="bottom")
    {
        if(key == GLUT_KEY_RIGHT)
        {
            direction="right";
        }
        else if(key == GLUT_KEY_LEFT)
        {
            direction="left";
        }
    }


}

void Check()
{
    if(positionX>=590 || positionY>=590)
    {
        speed =0;
    }
}

void Right(int a)
{
    //Check();

   glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0-a,100);
    glVertex2f(10-a,100);
    glVertex2f(10-a,110);
    glVertex2f(0-a,110);
    glEnd();
    cout<<"X:"<<10-a<<" Y:"<<100<<endl;
}
void Left(int a)
{
   glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0+a,100);
    glVertex2f(10+a,100);
    glVertex2f(10+a,110);
    glVertex2f(0+a,110);
    glEnd();
    //cout<<"X:"<<0<<"Y:"<<0+a<<endl;
}
void Top(int a)
{
   glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0,100-a);
    glVertex2f(10,100-a);
    glVertex2f(10,110-a);
    glVertex2f(0,110-a);
    glEnd();
    //cout<<"X:"<<0<<"Y:"<<0+a<<endl;
}
void Bottom(int a)
{
   glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0,100+a);
    glVertex2f(10,100+a);
    glVertex2f(10,110+a);
    glVertex2f(0,110+a);
    glEnd();

    //cout<<"X:"<<0<<"Y:"<<0+a<<endl;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(!visited)
    {
      RandomPoints();
      visited=true;
    }
    RandomBox();

      glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(10,590);
    glVertex2f(590,590);
    glVertex2f(10,590);
    glVertex2f(10,10);
     glVertex2f(10,10);
    glVertex2f(590,10);
     glVertex2f(590,10);
    glVertex2f(590,590);
    glEnd();

    int a=0;
    for(int i=0;i<=10;i++)
    {

       glPushMatrix();
        glTranslatef( positionX,positionY, 0.0f);
        if(direction=="right")
        {
            Right(a);
        }
        else if(direction=="left")
        {
            Left(a);
        }
        else if(direction=="top")
        {
            Top(a);
        }
        else if(direction=="bottom")
        {
            Bottom(a);
        }

        glPopMatrix();
        a=a+12;
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

    glutSpecialFunc(SpecialFunc);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
