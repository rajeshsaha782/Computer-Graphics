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
int Rx,Ry,snake_size=1,score=0;
bool visited=false,status=false;



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

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(0.0, 600.0, 0.0, 600.0, -1.0, 1.0);
    Rx=random(30,550);
    Ry=random(30,550);
    Rx=Rx-(Rx%10);
    Ry=Ry-(Ry%10);
}

void RandomPoints()
{
     Rx=random(30,550);
     Ry=random(30,550);
     Rx=Rx-(Rx%10);
     Ry=Ry-(Ry%10);
     visited=false;
}

void RandomBox()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(Rx,Ry);
    glVertex2f(Rx+10,Ry);
    glVertex2f(Rx+10,Ry+10);
    glVertex2f(Rx,Ry+10);
    glEnd();


      if(positionX==Rx && positionY+10==Ry)
        {
           cout<<"X:"<<Rx<<" positionX:"<<positionX<<endl;
           cout<<"Y:"<<Ry<<" positionY:"<<positionY<<endl;
           visited=true;snake_size++;score++;
           //speed=0;
        }

    //cout<<"X:"<<Rx<<"Y:"<<Ry<<endl;
}

void update(int value)
{

    /*if( positionX >= 700)
         positionX = 0;
    else if( positionX <=-110)
         positionX = 600;

    else if( positionY >= 700)
         positionY = 0;
    else if( positionY <= -110)
         positionY = 600;*/

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

void Check_border()
{
    if(positionX>=590 || positionX<10|| positionY>=580 ||positionY<=-10)
    {
        speed =0;
        if(!status)
        {
            cout<<"Check->"<<positionX<<","<<positionY<<endl;
            cout<<"***********GAME OVER************"<<endl;
            cout<<"**************Your Score:"<<score<<"**************"<<endl;
            status=true;
        }


    }

}

void Right(int a)
{
   glBegin(GL_QUADS);

    glVertex2f(0-a,10);
    glVertex2f(10-a,10);
    glVertex2f(10-a,20);
    glVertex2f(0-a,20);
    glEnd();
    //cout<<"X:"<<10-a<<" Y:"<<100<<endl;
}
void Left(int a)
{
   glBegin(GL_QUADS);

    glVertex2f(0+a,10);
    glVertex2f(10+a,10);
    glVertex2f(10+a,20);
    glVertex2f(0+a,20);
    glEnd();
    //cout<<"X:"<<0<<"Y:"<<0+a<<endl;
}
void Top(int a)
{
   glBegin(GL_QUADS);

    glVertex2f(0,10-a);
    glVertex2f(10,10-a);
    glVertex2f(10,20-a);
    glVertex2f(0,20-a);
    glEnd();
    //cout<<"X:"<<0<<"Y:"<<0+a<<endl;
}
void Bottom(int a)
{
   glBegin(GL_QUADS);

    glVertex2f(0,10+a);
    glVertex2f(10,10+a);
    glVertex2f(10,20+a);
    glVertex2f(0,20+a);
    glEnd();

    //cout<<"X:"<<0<<"Y:"<<0+a<<endl;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(visited)
    {
      RandomPoints();
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
    for(int i=0;i<snake_size;i++)
    {
        if(i==0)
        {
            Check_border();

        }
        if(i%2==0)
        {
            glColor3f(1.0f, 1.0f, 0.0f);
        }
        else
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }

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
        a=a+10;
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(350, 50);
    glutCreateWindow("Snake");
    glutDisplayFunc(display);
    init();

    glutSpecialFunc(SpecialFunc);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
