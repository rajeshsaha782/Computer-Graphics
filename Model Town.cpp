#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

GLint y=0;
GLint position =0,positioncar2=300;
GLint speed = 10;
int carx=300,suny=0;
int environmentMode=0;

void update(int value)
{
    if(position>460)
    {
        position =-370;
    }
    else if(position<-370)
    {
        position =460;
    }

    if(positioncar2>460)
    {
        positioncar2 =-370;
    }
    else if(positioncar2<-370)
    {
        positioncar2 =460;
    }

    positioncar2 -= speed;
    position += speed;
    carx=position;

    //printf("%d\n",position);

    glutPostRedisplay();

    glutTimerFunc(100, update, 0);
}

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


void drawLampPostLight(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * 3.1416;

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    glColor4f(1.000, 0.980, 0.980, 1.0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

}
void drawCarCircle(GLfloat x, GLfloat y, GLfloat radius)
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


void drawCloud(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 1000;
    GLfloat twicePi = 3.0f * 3.1416;

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    glColor4f(1.0, 1.0, 1.0, 1.0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void drawTree(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * 3.1416;

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
    glColor4f(0.196, 0.804, 0.196, 1.0);
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
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

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
    glColor3f(1,1,1);
    glVertex2f(0,110);
    glVertex2f(760,110);
    glEnd();

    ///road middle line

    GLfloat x1=0,y1=30;
    for(int i=0; i<20; i++)
    {
        glBegin(GL_LINES);
        glColor3f(0,1,1);
        glVertex2f(x1,150);
        glVertex2f(y1,150);
        x1+=50;
        y1+=50;

        glEnd();
    }

    ///middle road - delete   zerbra cossing face a "----" line this portion delete
    glBegin(GL_QUADS);
    glColor3f(0,0,0);

    glVertex2f(555,115);
    glVertex2f(575,115);
    glVertex2f(575,170);
    glVertex2f(555,170);
    glEnd();

    ///Road up Line

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(0,190);
    glVertex2f(760,190);
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
    for(int i=0; i<7; i++)
    {
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex2f(555,x);
        glVertex2f(575,y);
        x+=10;
        y+=10;
        glEnd();
    }

    /// Car
    glPushMatrix();
    glTranslatef(position,0,0);

    glBegin(GL_POLYGON);
    glColor3f(.52,.76,.91);

    glVertex2f(300,120);   ///carx=300;
    glVertex2f(370,120);  ///carx=370;
    glVertex2f(370,130);    ///carx=370;
    glVertex2f(355,130);    ///carx=355;
    glVertex2f(340,140);    ///carx=340;
    glVertex2f(320,140);    ///carx=320;
    glVertex2f(310,130);    ///carx=310;
    glVertex2f(300,130);    ///carx=300;
    glEnd();

    drawCarCircle(320,120,5);    ///carx=320;
    drawCarCircle(350,120,5);    ///carx=350;

    glPopMatrix();


    glPushMatrix();
    glTranslatef(position,0,0);

    glBegin(GL_POLYGON);
    glColor3f(.52,.76,.91);

    glVertex2f(300+100,120);   ///carx=300;
    glVertex2f(370+100,120);  ///carx=370;
    glVertex2f(370+100,130);    ///carx=370;
    glVertex2f(355+100,130);    ///carx=355;
    glVertex2f(340+100,140);    ///carx=340;
    glVertex2f(320+100,140);    ///carx=320;
    glVertex2f(310+100,130);    ///carx=310;
    glVertex2f(300+100,130);    ///carx=300;
    glEnd();

    drawCarCircle(320+100,120,5);    ///carx=320;
    drawCarCircle(350+100,120,5);    ///carx=350;

    glPopMatrix();


    ///upper car

    glPushMatrix();
    glTranslatef(positioncar2,0,0);

    glBegin(GL_POLYGON);
    glColor3f(.52,.76,.91);

    glVertex2f(300,160);
    glVertex2f(370,160);
    glVertex2f(370,170);
    glVertex2f(360,170);
    glVertex2f(350,180);
    glVertex2f(330,180);
    glVertex2f(315,170);
    glVertex2f(300,170);
    glEnd();

    drawCarCircle(320,160,5);
    drawCarCircle(350,160,5);

    glPopMatrix();


    ///Town Starts

    glBegin(GL_QUADS);
    glColor3f(.52,.76,.91);

    glVertex2f(0,200);
    glVertex2f(760,200);
    glVertex2f(760,380);
    glVertex2f(0,380);
    glEnd();

    ///Building

    glBegin(GL_QUADS);
    if(environmentMode==0)
    {
         glColor3f(.5,.5,.5);
    }
    else
    {
         glColor3f(0,0,0);
    }

    glVertex2f(0,200);
    glVertex2f(50,200);
    glVertex2f(50,300);
    glVertex2f(0,300);
    glEnd();

    int m=5,n=15,l=210,k=220;
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<3; j++)
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
    for(int i=0; i<13; i++)
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
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<3; j++)
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
    glPushMatrix();
    glTranslatef(0,suny,0);
    drawSun(100,360,10);
    glEnd();
    glPopMatrix();

    ///cloud1
    drawCloud(200,330,15);
    drawCloud(230,330,15);
    drawCloud(215,340,15);
    drawCloud(215,320,15);

    ///cloud2
    drawCloud(200+400,340,20);
    drawCloud(230+400,340,20);
    drawCloud(215+400,350,20);
    drawCloud(215+400,330,20);


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


///building with hill
    glBegin(GL_QUADS);
    glColor3f(0,1,1);

    glVertex2f(465,200);
    glVertex2f(510,200);
    glVertex2f(510,330);
    glVertex2f(465,330);
    glEnd();

    m=465,n=510,l=205,k=330;
    for(int i=0; i<5; i++)
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
    for(int i=0; i<7; i++)
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
    for(int i=0; i<7; i++)
    {
        glBegin(GL_LINES);
        glColor3f(.5,1,.5);
        glVertex2f(500,l);
        glVertex2f(560,l);
        l+=15;
        glEnd();

    }


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


///lamp post down
    ///1st lamp
    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(50,100);
    glVertex2f(50,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(50,130);
    glVertex2f(60,140);
    glEnd();

    drawLampPostLight(60,135,3);
    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(200,100);
    glVertex2f(200,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(200,130);
    glVertex2f(210,140);
    glEnd();

    drawLampPostLight(210,135,3);

    ///3rd lamp

    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(400,100);
    glVertex2f(400,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(400,130);
    glVertex2f(410,140);
    glEnd();

    drawLampPostLight(410,135,3);

     ///4th lamp
    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(620,100);
    glVertex2f(620,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(620,130);
    glVertex2f(630,140);
    glEnd();

    drawLampPostLight(630,135,3);

///upper lamp post
    ///1st lamp
    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(50+20,100+95);
    glVertex2f(50+20,130+95);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(50+20,130+95);
    glVertex2f(60+20,140+95);
    glEnd();

    drawLampPostLight(80,230,3);

    ///2nd lamp

    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(200+20,100+95);
    glVertex2f(200+20,130+95);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(200+20,130+95);
    glVertex2f(210+20,140+95);
    glEnd();

    drawLampPostLight(230,230,3);

    ///3rd lamp

    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(400+20,100+95);
    glVertex2f(400+20,130+95);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(400+20,130+95);
    glVertex2f(410+20,140+95);
    glEnd();

    drawLampPostLight(430,230,3);

    ///4th lamp

    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(620+20,100+95);
    glVertex2f(620+20,130+95);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(620+20,130+95);
    glVertex2f(630+20,140+95);
    glEnd();

    drawLampPostLight(650,230,3);

///draw tree1

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53,10);
    glVertex2f(57,10);
    glVertex2f(57,40);
    glVertex2f(53,40);
    glEnd();

    drawTree(50,50,12);  ///red fruit
    drawTree(60,50,12);
    drawTree(55,60,12);
    drawTree(55,40,12);

    ///drawTree 2

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53+250,10+10);
    glVertex2f(57+250,10+10);
    glVertex2f(57+250,40+10);
    glVertex2f(53+250,40+10);
    glEnd();

    drawTree(50+250,50+10,12);  ///red fruit
    drawTree(60+250,50+10,12);
    drawTree(55+250,60+10,12);
    drawTree(55+250,40+10,12);

    ///drawTree 3

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53+250+150,10);
    glVertex2f(57+250+150,10);
    glVertex2f(57+250+150,40);
    glVertex2f(53+250+150,40);
    glEnd();

    drawTree(50+250+150,50,12);  ///red fruit
    drawTree(60+250+150,50,12);
    drawTree(55+250+150,60,12);
    drawTree(55+250+150,40,12);

    ///drawTree 4

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53+250+320,10);
    glVertex2f(57+250+320,10);
    glVertex2f(57+250+320,40);
    glVertex2f(53+250+320,40);
    glEnd();

    drawTree(50+250+320,50,12);  ///red fruit
    drawTree(60+250+320,50,12);
    drawTree(55+250+320,60,12);
    drawTree(55+250+320,40,12);

 ///upper Draw Tree  1

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53,10+180);
    glVertex2f(57,10+180);
    glVertex2f(57,40+180);
    glVertex2f(53,40+180);
    glEnd();

    drawTree(50,50+180,12);  ///red fruit
    drawTree(60,50+180,12);
    drawTree(55,60+180,12);
    drawTree(55,40+180,12);

    ///upper Draw Tree 2

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53+250,10+180);
    glVertex2f(57+250,10+180);
    glVertex2f(57+250,40+180);
    glVertex2f(53+250,40+180);
    glEnd();

    drawTree(50+250,50+10+180,12);  ///red fruit
    drawTree(60+250,50+10+180,12);
    drawTree(55+250,60+10+180,12);
    drawTree(55+250,40+10+180,12);

    ///upper Draw Tree 3

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53+250+150,10+180);
    glVertex2f(57+250+150,10+180);
    glVertex2f(57+250+150,40+180);
    glVertex2f(53+250+150,40+180);
    glEnd();

    drawTree(50+250+150,50+180,12);  ///red fruit
    drawTree(60+250+150,50+180,12);
    drawTree(55+250+150,60+180,12);
    drawTree(55+250+150,40+180,12);

    ///upper Draw Tree 4

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(53+250+400,10+180);
    glVertex2f(57+250+400,10+180);
    glVertex2f(57+250+400,40+180);
    glVertex2f(53+250+400,40+180);
    glEnd();

    drawTree(50+250+400,50+180,12);  ///red fruit
    drawTree(60+250+400,50+180,12);
    drawTree(55+250+400,60+180,12);
    drawTree(55+250+400,40+180,12);

    glFlush();
}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'o':
        speed = 0;
        break;
    case 's':
        speed = 10;
        break;
    case 'd':
        if(suny>35)
        {
            suny =-40;
        }
        else if(suny<-40)
        {
            suny =35;
        }

    if(suny>=35)
    {
       environmentMode=1;
    }
    else
    {
        environmentMode=0;
    }
    /*if(position>460)
    {
        position =-370;
    }
    else if(position<-370)
    {
        position =460;
    }
    */
        printf("%d\n",suny);
        suny -= 5;

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1400,650);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Model Town");
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutKeyboardFunc(handleKeypress);
    init();
    glutMainLoop();
    return 0;
}
