#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(0.0, 760.0, 0.0, 380.0, -1.0, 1.0);
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * 3.1416;

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 1.0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void drawSun(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * 3.1416;

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    glColor3f(1.0, .84, 0.0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();

    ///Green Field With Tree
    glBegin(GL_QUADS);
    glColor3f(0,.5,0);

    glVertex2f(0,0);
    glVertex2f(760,0);
    glVertex2f(760,80);
    glVertex2f(0,80);
    glEnd();


    ///border Between Road and Field


    GLfloat x=0,y=30;
    for(int i=0; i<20; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.545, 0.271, 0.075);

        glVertex2f(x,80);
        glVertex2f(y,80);
        glVertex2f(y,100);
        glVertex2f(x,100);
        glEnd();
        x+=30;
        y+=30;
        glBegin(GL_QUADS);
        glColor3f(0.753, 0.753, 0.753);

        glVertex2f(x,80);
        glVertex2f(y,80);
        glVertex2f(y,100);
        glVertex2f(x,100);
        glEnd();
        x+=30;
        y+=30;
        //printf("%d\n",&x);

    }


    ///Road

    glBegin(GL_QUADS);
    glColor3f(0,0,0);

    glVertex2f(0,100);
    glVertex2f(760,100);
    glVertex2f(760,200);
    glVertex2f(0,200);
    glEnd();

    ///Road Down Line

    glBegin(GL_LINES);
    //glLineWidth(5.0);
    glColor3f(1,1,1);
    glVertex2f(0,110);
    glVertex2f(760,110);
    glEnd();


    ///road middle line

    GLfloat x1=0,y1=30;
    for(int i=0; i<20; i++)
    {
        glBegin(GL_LINES);
        //glLineWidth(5.0);
        glColor3f(0,1,1);
        glVertex2f(x1,150);
        glVertex2f(y1,150);
        x1+=50;
        y1+=50;

        glEnd();
    }

    ///Road up Line

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0,190);
    glVertex2f(760,190);
    glEnd();

///lamp post down
    glBegin(GL_LINES);
    //glLineWidth(5.0);
    glColor3f(1,1,1);
    glVertex2f(50,100);
    glVertex2f(50,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(50,130);
    glVertex2f(60,140);
    glEnd();



    glBegin(GL_LINES);
    //glLineWidth(5.0);
    glColor3f(1,1,1);
    glVertex2f(200,100);
    glVertex2f(200,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(200,130);
    glVertex2f(210,140);
    glEnd();



    glBegin(GL_LINES);
    //glLineWidth(5.0);
    glColor3f(1,1,1);
    glVertex2f(400,100);
    glVertex2f(400,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(400,130);
    glVertex2f(410,140);
    glEnd();



    glBegin(GL_LINES);
    //glLineWidth(5.0);
    glColor3f(1,1,1);
    glVertex2f(620,100);
    glVertex2f(620,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(620,130);
    glVertex2f(630,140);
    glEnd();


    ///Town Starts

    glBegin(GL_QUADS);
    glColor3f(.52,.76,.91);

    glVertex2f(0,200);
    glVertex2f(760,200);
    glVertex2f(760,380);
    glVertex2f(0,380);
    glEnd();

    ///Flag
    glBegin(GL_QUADS);
    glColor3f(0,1,0);

    glVertex2f(600,230);
    glVertex2f(630,230);
    glVertex2f(630,245);
    glVertex2f(600,245);
    glEnd();

    drawCircle(615,237,5);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(630,200);
    glVertex2f(630,245);
    glEnd();


    ///sun
    drawSun(100,360,10);


///building with hill
    glBegin(GL_QUADS);
    glColor3f(0,1,1);

    glVertex2f(465,200);
    glVertex2f(510,200);
    glVertex2f(510,330);
    glVertex2f(465,330);
    glEnd();

    int m=465,n=510,l=205,k=330;
    for(int i=0;i<5;i++)
    {
       glBegin(GL_LINES);
       glColor3f(0.000, 0.502, 0.502);
       glVertex2f(m,l);
       glVertex2f(m,k);
       m+=10;
       glEnd();

    }

///hill 3rd Building

glBegin(GL_QUADS);
    glColor3f(0.545, 0.000, 0.545);

    glVertex2f(550,200);
    glVertex2f(600,200);
    glVertex2f(600,310);
    glVertex2f(550,310);
    glEnd();

    m=55,n=65,l=205,k=330;
    for(int i=0;i<7;i++)
    {
       glBegin(GL_LINES);
       glColor3f(1,1,1);
       glVertex2f(550,l);
       glVertex2f(600,l);
       l+=15;
       glEnd();

    }



///hill 2nd building

glBegin(GL_QUADS);
    glColor3f(0.184, 0.310, 0.310);

    glVertex2f(500,205);
    glVertex2f(560,205);
    glVertex2f(560,300);
    glVertex2f(500,300);
    glEnd();

    m=55,n=65,l=205,k=330;
    for(int i=0;i<7;i++)
    {
       glBegin(GL_LINES);
       glColor3f(.5,1,.5);
       glVertex2f(500,l);
       glVertex2f(560,l);
       l+=15;
       glEnd();

    }





    ///Hill

    glBegin(GL_POLYGON);
    glColor3f(.12,.96,1);

    glVertex2f(170,200);
    glVertex2f(430,200);
    glVertex2f(330,270);
    glVertex2f(320,260);
    glVertex2f(270,300);
    glVertex2f(240,260);
    glVertex2f(230,270);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(.5,.5,.5);

    glVertex2f(350,200);
    glVertex2f(590,200);
    glVertex2f(530,270);
    glVertex2f(520,260);
    glVertex2f(470,300);
    glVertex2f(430,260);
    glVertex2f(420,270);
    glEnd();


///Tool Box
    glBegin(GL_QUADS);
    glColor3f(.12,.96,1);

    glVertex2f(520,195);
    glVertex2f(540,195);
    glVertex2f(540,210);
    glVertex2f(520,210);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(.69,.93,.93);

    glVertex2f(510,215);
    glVertex2f(550,215);
    glVertex2f(530,230);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(.12,.96,1);
    glVertex2f(520,195);
    glVertex2f(520,215);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(.12,.96,1);
    glVertex2f(540,195);
    glVertex2f(540,215);
    glEnd();


///middle road - delete
    glBegin(GL_QUADS);
    glColor3f(0,0,0);

    glVertex2f(540,115);
    glVertex2f(590,115);
    glVertex2f(590,150);
    glVertex2f(540,150);
    glEnd();

   ///Zebra Crosss

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(555,110);
    glVertex2f(555,190);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(575,110);
    glVertex2f(575,190);
    glEnd();

   x=115;
   y=125;
   for(int i=0;i<7;i++)
   {
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(555,x);
    glVertex2f(575,y);
    x+=10;
    y+=10;
    glEnd();
   }


///Building

    glBegin(GL_QUADS);
    glColor3f(.5,.5,.5);

    glVertex2f(0,200);
    glVertex2f(50,200);
    glVertex2f(50,300);
    glVertex2f(0,300);
    glEnd();

    m=5,n=15,l=210,k=220;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            glBegin(GL_QUADS);
            glColor3f(.12,.96,1);

            glVertex2f(m,l);
            glVertex2f(n,l);
            glVertex2f(n,k);
            glVertex2f(m,k);
            m+=10;
            n+=10;

            glBegin(GL_QUADS);
            glColor3f(.5,.5,.5);

            glVertex2f(m,l);
            glVertex2f(n,l);
            glVertex2f(n,k);
            glVertex2f(m,k);
            m+=5;
            n+=5;


            glEnd();
        }
        k+=15;
        l+=15;
        m=5,n=15;
    }

    ///2nd Building

    glBegin(GL_QUADS);
    glColor3f(.5,.5,.5);

    glVertex2f(50,200);
    glVertex2f(110,200);
    glVertex2f(110,330);
    glVertex2f(50,330);
    glEnd();

    m=55,n=65,l=205,k=330;
    for(int i=0;i<13;i++)
    {
       glBegin(GL_LINES);
       glColor3f(.5,1,.5);
       glVertex2f(50,l);
       glVertex2f(110,l);
       l+=10;
       glEnd();

    }


  ///3rd Building

    glBegin(GL_QUADS);
    glColor3f(0.565, 0.933, 0.565);

    glVertex2f(90,200);
    glVertex2f(155,200);
    glVertex2f(155,300);
    glVertex2f(90,300);
    glEnd();

    m=95,n=105,l=210,k=220;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            glBegin(GL_QUADS);
            glColor3f(.12,.96,1);

            glVertex2f(m,l);
            glVertex2f(n,l);
            glVertex2f(n,k);
            glVertex2f(m,k);
            m+=10;
            n+=10;

            glBegin(GL_QUADS);
            glColor3f(0.565, 0.933, 0.565);

            glVertex2f(m,l);
            glVertex2f(n,l);
            glVertex2f(n,k);
            glVertex2f(m,k);
            m+=10;
            n+=10;


            glEnd();
        }
        k+=15;
        l+=15;
        m=95,n=105;
    }


    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1400,650);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Basic Animation");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
