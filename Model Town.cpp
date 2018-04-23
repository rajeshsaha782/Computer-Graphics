#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<MMsystem.h>
using namespace std;
GLint y=0;
GLint lowerCar1 =0,lowerCar2 =300,lowerCar3 =100,upperCar1=300,upperCar2=100,upperCar3=500,cloud1=0,cloud2=0,cloud3=0,SignalTime=0;
GLfloat day_night=0;
GLint lowerCar1_speed = 8,lowerCar2_speed = 12,lowerCar3_speed = 5,upperCar1_speed = 8,upperCar2_speed = 12,upperCar3_speed = 15;
int carx=300,suny=0;
bool stop=false,play=false;


string day="up",Signal="red",VIPsignal="null";

void update(int value)
{
    if(lowerCar1>460)
    {
        lowerCar1 =-370;
    }
    if(lowerCar2>400)
    {
        lowerCar2 =-470;
    }
    if(lowerCar3>500)
    {
        lowerCar3 =-470;
    }

    if(upperCar1<-370)
    {
        upperCar1 =460;
    }

    if(upperCar2<-300)
    {
        upperCar2 =660;
    }
    if(upperCar3<-350)
    {
        upperCar3 =660;
    }

    if(cloud1<-300)
    {
        cloud1 =660;
    }
    if(cloud2<-600)
    {
        cloud2 =300;
    }
    if(cloud3>200)
    {
        cloud3 =-700;
    }

    if(day=="up")
    {
        day_night+=.001;
        if(day_night>=.9)
        {
            day="down";play=false;
        }
    }
    else if(day=="down")
    {
        day_night-=.001;
        if(day_night<=0.0)
        {
            day="up";
        }
    }



    cloud1 -= 2;cloud2 -= 5;cloud3 += 3;
    if((Signal=="red"||Signal=="yellow") && (upperCar3<=305 && upperCar3>=285))
    {
        upperCar3_speed=0;
    }
    else
    {
        upperCar3 -= upperCar3_speed;
    }
    if((Signal=="red"||Signal=="yellow") && (upperCar2<=504 && upperCar2>=460))
    {
        upperCar2_speed=0;
    }
    else
    {
        upperCar2 -= upperCar2_speed;
    }
    if((Signal=="red"||Signal=="yellow") && (upperCar1<=316 && upperCar1>=300))
    {
        upperCar1_speed=0;
    }
    else
    {
        upperCar1 -= upperCar1_speed;
    }

    if((Signal=="red"||Signal=="yellow") && (lowerCar1>=160 && lowerCar1<=176))
    {
        lowerCar1_speed=0;
    }
    else
    {
        lowerCar1 += lowerCar1_speed;
    }

    if((Signal=="red"||Signal=="yellow") && (lowerCar2>=58 && lowerCar2<=82))
    {
        lowerCar2_speed=0;
    }
    else
    {
        lowerCar2 += lowerCar2_speed;
    }

    if((Signal=="red"||Signal=="yellow") && (lowerCar3>=170 && lowerCar3<=180))
    {
        lowerCar3_speed=0;
    }
    else
    {
        lowerCar3 += lowerCar3_speed;
    }

    SignalTime++;
    if(SignalTime>10)
    {
        if(Signal=="red")
        {
            if(SignalTime>50 && VIPsignal=="null")
            {
                Signal="yellow";
                SignalTime=0;
            }

        }
        else if(Signal=="green")
        {
            if(SignalTime>40)
            {
                Signal="red";
                SignalTime=0;
            }
        }
        else if(Signal=="yellow")
        {
            Signal="green";VIPsignal="null";SignalTime=0;
            if(stop==false)
            {
                lowerCar1_speed = 8;
                lowerCar2_speed = 12;
                lowerCar3_speed = 5;
                upperCar1_speed = 8;
                upperCar2_speed = 12;
                upperCar3_speed = 15;
            }

        }

    }



    //printf("%d\n",lowerCar1);
   //cout<<cloud3<<endl;

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
   // glColor4f(1.0, 0.0, 0.0, 1.0);
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
    //glColor4f(1.000, 0.980, 0.980, 1.0);
    glColor4f(1.0, 1.0, 1.0-day_night, 1.0);
        if(day=="day")
        {
           glColor4f(1.0, 1.0, 1.0, 1.0);
        }
        else if(day=="night")
        {
            glColor4f(1.0, 1.0, 0.00, 1.0);
        }

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
    glColor3f(1.0, 1.0, 0.0+day_night);

    if(day=="day")
    {
       glColor3f(1,1,0);
    }
    else if(day=="night")
    {
        glColor3f(1,1,1);
    }

    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
}

void Star()
{
    int x,y;
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glVertex2f(384,362.5);
            glVertex2f(387,360);
            glVertex2f(386,364);
            glVertex2f(389,366);
            glVertex2f(385,366);
            glVertex2f(384,369+1);
            glVertex2f(383,366);
            glVertex2f(380-.5,366);
            glVertex2f(382,364);
            glVertex2f(381,360);
        glEnd();
        glBegin(GL_POLYGON);
        x=30;y=-10;
            glVertex2f(384+x,362.5+y);
            glVertex2f(387+x,360+y);
            glVertex2f(386+x,364+y);
            glVertex2f(389+x,366+y);
            glVertex2f(385+x,366+y);
            glVertex2f(384+x,369+1+y);
            glVertex2f(383+x,366+y);
            glVertex2f(380-.5+x,366+y);
            glVertex2f(382+x,364+y);
            glVertex2f(381+x,360+y);
        glEnd();
        x=0;y=0;
        for(int i=1;i<=3;i++)
        {
            x=x-(30*i);
            if(i%2==0)
            {
                y=y-10;
            }
            else
                y=y+5;
            glBegin(GL_POLYGON);
            glVertex2f(384+x,362.5+y);
            glVertex2f(387+x,360+y);
            glVertex2f(386+x,364+y);
            glVertex2f(389+x,366+y);
            glVertex2f(385+x,366+y);
            glVertex2f(384+x,369+1+y);
            glVertex2f(383+x,366+y);
            glVertex2f(380-.5+x,366+y);
            glVertex2f(382+x,364+y);
            glVertex2f(381+x,360+y);
            glEnd();
            y=0;
        }


        glBegin(GL_POLYGON);
        x=-230;y=-5;
            glVertex2f(384+x,362.5+y);
            glVertex2f(387+x,360+y);
            glVertex2f(386+x,364+y);
            glVertex2f(389+x,366+y);
            glVertex2f(385+x,366+y);
            glVertex2f(384+x,369+1+y);
            glVertex2f(383+x,366+y);
            glVertex2f(380-.5+x,366+y);
            glVertex2f(382+x,364+y);
            glVertex2f(381+x,360+y);
        glEnd();
        glBegin(GL_POLYGON);
        x=90;y=-10;
            glVertex2f(384+x,362.5+y);
            glVertex2f(387+x,360+y);
            glVertex2f(386+x,364+y);
            glVertex2f(389+x,366+y);
            glVertex2f(385+x,366+y);
            glVertex2f(384+x,369+1+y);
            glVertex2f(383+x,366+y);
            glVertex2f(380-.5+x,366+y);
            glVertex2f(382+x,364+y);
            glVertex2f(381+x,360+y);
        glEnd();
        glBegin(GL_POLYGON);
        x=130;y=5;
            glVertex2f(384+x,362.5+y);
            glVertex2f(387+x,360+y);
            glVertex2f(386+x,364+y);
            glVertex2f(389+x,366+y);
            glVertex2f(385+x,366+y);
            glVertex2f(384+x,369+1+y);
            glVertex2f(383+x,366+y);
            glVertex2f(380-.5+x,366+y);
            glVertex2f(382+x,364+y);
            glVertex2f(381+x,360+y);
        glEnd();
        glBegin(GL_POLYGON);
        x=230;y=5;
            glVertex2f(384+x,362.5+y);
            glVertex2f(387+x,360+y);
            glVertex2f(386+x,364+y);
            glVertex2f(389+x,366+y);
            glVertex2f(385+x,366+y);
            glVertex2f(384+x,369+1+y);
            glVertex2f(383+x,366+y);
            glVertex2f(380-.5+x,366+y);
            glVertex2f(382+x,364+y);
            glVertex2f(381+x,360+y);
        glEnd();
        glBegin(GL_POLYGON);
        x=270;y=-5;
            glVertex2f(384+x,362.5+y);
            glVertex2f(387+x,360+y);
            glVertex2f(386+x,364+y);
            glVertex2f(389+x,366+y);
            glVertex2f(385+x,366+y);
            glVertex2f(384+x,369+1+y);
            glVertex2f(383+x,366+y);
            glVertex2f(380-.5+x,366+y);
            glVertex2f(382+x,364+y);
            glVertex2f(381+x,360+y);
        glEnd();
}

void Lamposts()
{
    ///lamp post down
    ///1st lamp

    drawLampPostLight(60,135,3);
    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(200,100);
    glVertex2f(200,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(50,130);
    glVertex2f(60,140);
    glEnd();


    ///2nd lamp

    drawLampPostLight(210,135,3);
    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(50,100);
    glVertex2f(50,130);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.184, 0.310, 0.310);
    glVertex2f(200,130);
    glVertex2f(210,140);
    glEnd();



    ///3rd lamp
    drawLampPostLight(410,135,3);
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



     ///4th lamp
     drawLampPostLight(630,135,3);
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




///upper lamp post
    ///1st lamp
    drawLampPostLight(80,230,3);
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



    ///2nd lamp
    drawLampPostLight(230,230,3);
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



    ///3rd lamp
    drawLampPostLight(430,230,3);
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



    ///4th lamp
 drawLampPostLight(650,230,3);
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


}

void LowerCar1()
{
    glPushMatrix();
    glTranslatef(lowerCar1,0,0);

    glBegin(GL_POLYGON);
    glColor3f(.52,.76,.91);

    glVertex2f(300,120+10);   ///carx=300;
    glVertex2f(370,120+10);  ///carx=370;
    glVertex2f(370,130+10);    ///carx=370;
    glVertex2f(355,130+10);    ///carx=355;
    glVertex2f(340,140+10);    ///carx=340;
    glVertex2f(320,140+10);    ///carx=320;
    glVertex2f(310,130+10);    ///carx=310;
    glVertex2f(300,130+10);    ///carx=300;
    glEnd();

     glColor3f(.52,.76,.91);
    drawCircle(302,125+10,4);
    drawCircle(368,125+10,4);


    glBegin(GL_POLYGON);///glass
    glColor3f(0,0,0);

    glVertex2f(352,130+10);
    glVertex2f(340,138+10);
    glVertex2f(322,138+10);
    glVertex2f(313,130+10);

    glEnd();

    glColor4f(1.0, 1.0, 1.0, 1.0);
    drawCarCircle(320,120+10,5);    ///carx=320;
    drawCarCircle(350,120+10,5);    ///carx=350;

    glPopMatrix();
}

void LowerCar2()
{
     glPushMatrix();
    glTranslatef(lowerCar2,0,0);

    glBegin(GL_POLYGON);
    glColor3f(.32,.36,.91);

    glVertex2f(300+100,120);   ///carx=300;
    glVertex2f(370+100,120);  ///carx=370;
    glVertex2f(370+100,130);    ///carx=370;
    glVertex2f(355+100,130);    ///carx=355;
    glVertex2f(340+100,140);    ///carx=340;
    glVertex2f(320+100,140);    ///carx=320;
    glVertex2f(310+100,130);    ///carx=310;
    glVertex2f(300+100,130);    ///carx=300;
    glEnd();

    glColor3f(.32,.36,.91);
    drawCircle(402,125,4);
    drawCircle(468,125,4);


    glBegin(GL_POLYGON);///glass
    glColor3f(0,0,0);

    glVertex2f(452,130);
    glVertex2f(440,138);
    glVertex2f(422,138);
    glVertex2f(413,130);
    glEnd();

    glColor4f(0.7, 0.6, 0.7, 1.0);
    drawCarCircle(320+100,120,5);
    drawCarCircle(350+100,120,5);

    glColor4f(0, 0, 0, 1.0);
    drawCarCircle(320+100,120,2);
    drawCarCircle(350+100,120,2);

    glPopMatrix();

}

void LowerCar3()
{
    glPushMatrix();
    glTranslatef(lowerCar3,0,0);
    glBegin(GL_POLYGON);
    glColor3f(.32,.76,0);

    glVertex2f(280,120);
    glVertex2f(370,120);
    glVertex2f(370,150);
    glVertex2f(280,150);

    glEnd();

    glColor3f(.32,.76,0);
    drawCircle(367,127.5,7);

    glColor3f(0.4,0.4,0.9);
    glBegin(GL_QUADS);
    int r=285,c=145;
    for(int i=0;i<4;i++)
    {
        glVertex2f(r,c);
        glVertex2f(r,c-12);
        glVertex2f(r+12,c-12);
        glVertex2f(r+12,c);

        r+=18;
    }
    glColor3f(0.4,0.4,0.5);
     glVertex2f(355,122);
     glVertex2f(366,122);
     glVertex2f(366,146);
     glVertex2f(355,146);

    glEnd();


    glColor4f(0.5, 0.5, 0.5, 1.0);
    drawCarCircle(300,120,7);
    drawCarCircle(348,120,7);

    glColor4f(0, 0, 0, 1.0);
    drawCarCircle(300,120,4);
    drawCarCircle(348,120,4);
    glPopMatrix();

}
void UpperCar1()
{
    glPushMatrix();
    glTranslatef(upperCar1,0,0);

    glBegin(GL_POLYGON);
    //glColor3f(.52,.76,.91);
    glColor3f(.92,.36,.31);

    glVertex2f(300,160);
    glVertex2f(370,160);
    glVertex2f(370,170);
    glVertex2f(364,170);//4
    glVertex2f(350,180);
    glVertex2f(330,180);
    glVertex2f(310,170);
    glVertex2f(300,170);
    glEnd();

    glColor3f(.92,.36,.31);
    drawCircle(302,165,4);
    drawCircle(368,165,4);

    glBegin(GL_POLYGON);///glass
    glColor3f(0,0,0);

    glVertex2f(359,170);
    glVertex2f(346,179);
    glVertex2f(332,179);
    glVertex2f(316,170);

    glEnd();

    glColor4f(0.5, 0.7, 0.6, 1.0);
    drawCarCircle(320,160,5);
    drawCarCircle(350,160,5);

    glColor4f(0, 0, 0, 1.0);
    drawCarCircle(320,160,2);
    drawCarCircle(350,160,2);

    glPopMatrix();
}

void UpperCar2()
{
    ///upper car 2

    glPushMatrix();
    glTranslatef(upperCar2,0,0);

    glBegin(GL_POLYGON);
    //glColor3f(.52,.76,.91);
    glColor3f(.02,.06,.91);

    glVertex2f(300-200,160);
    glVertex2f(370-200,160);
    glVertex2f(370-200,170);
    glVertex2f(364-200,170);//4
    glVertex2f(350-200,180);
    glVertex2f(330-200,180);
    glVertex2f(310-200,170);
    glVertex2f(300-200,170);
    glEnd();

    glColor3f(.02,.06,.91);
    drawCircle(302-200,165,4);
    drawCircle(368-200,165,4);

    glBegin(GL_POLYGON);///glass
    glColor3f(0,0,0);

    glVertex2f(359-200,170);
    glVertex2f(346-200,179);
    glVertex2f(332-200,179);
    glVertex2f(316-200,170);

    glEnd();

    glColor4f(0.5, 0.7, 0.6, 1.0);
    drawCarCircle(320-200,160,5);
    drawCarCircle(350-200,160,5);

    glPopMatrix();


}
void UpperCar3()
{
    ///upper car 3

    glPushMatrix();
    glTranslatef(upperCar3,0,0);

    glBegin(GL_POLYGON);
    //glColor3f(.52,.76,.91);
    glColor3f(.92,.06,.11);

    glVertex2f(300,160+10);
    glVertex2f(370,160+10);
    glVertex2f(370,170+10);
    glVertex2f(364,170+10);//4
    glVertex2f(350,180+10);
    glVertex2f(330,180+10);
    glVertex2f(310,170+10);
    glVertex2f(300,170+10);
    glEnd();

    glColor3f(.92,.06,.11);
    drawCircle(302,165+10,4);
    drawCircle(368,165+10,4);

    glBegin(GL_POLYGON);///glass
    glColor3f(0,0,0);

    glVertex2f(359,170+10);
    glVertex2f(346,179+10);
    glVertex2f(332,179+10);
    glVertex2f(316,170+10);

    glEnd();

    glColor4f(0.8, 0.6, 0.2, 1.0);
    drawCarCircle(320,160+10,5);
    drawCarCircle(350,160+10,5);

    glPopMatrix();


}

void FirstBuilding()
{
    glBegin(GL_QUADS);
    glColor3f(.5,.5,.5);

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
            glColor3f(.92,.96,1-day_night);

            if(day=="day")
            {
               glColor3f(0.92,0.96,1);
            }
            else if(day=="night")
            {
                glColor3f(.92,.96,0);
            }

            glVertex2f(m,l);
            glVertex2f(n,l);
            glVertex2f(n,k);
            glVertex2f(m,k);
            m+=10;
            n+=10;


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
}

void SecondBuilding()
{
     ///2nd Building

    glBegin(GL_QUADS);
    glColor3f(.5,.5,.5);

    glVertex2f(50,200);
    glVertex2f(110,200);
    glVertex2f(110,330);
    glVertex2f(50,330);
    glEnd();

    int m=55,n=65,l=205,k=330;
    for(int i=0; i<13; i++)
    {
        glBegin(GL_LINES);
        glColor3f(.5,1,.5);
        glVertex2f(50,l);
        glVertex2f(110,l);
        l+=10;
        glEnd();
    }

}

void ThirdBuilding()
{
  ///3rd Building

    glBegin(GL_QUADS);
    glColor3f(0.565, 0.633, 0.865);

    glVertex2f(90,200);
    glVertex2f(155,200);
    glVertex2f(155,300);
    glVertex2f(90,300);
    glEnd();

    int r=97,c=296;
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<3; j++)
        {
            glBegin(GL_QUADS);
            glColor3f(.92,.96,1-day_night);
            if(day=="day")
            {
               glColor3f(0.92,0.96,1);
            }
            else if(day=="night")
            {
                glColor3f(.92,.96,0);
            }

            glVertex2f(r,c);
            glVertex2f(r,c-10);
            glVertex2f(r+10,c-10);
            glVertex2f(r+10,c);

            glEnd();

            r+=20;


        }
        r=97;
        c=296-i*15;

    }
    glBegin(GL_QUADS);
    glColor3f(.8,.8,.8);

    glVertex2f(115,200);
    glVertex2f(135,200);
    glVertex2f(135,225);
    glVertex2f(115,225);
    glEnd();
}

void FourthBuilding()
{
    ///4th building

    glBegin(GL_QUADS);
    glColor3f(.5,.7,.5);

    glVertex2f(620,200);
    glVertex2f(710,200);
    glVertex2f(710,350);
    glVertex2f(620,350);
    glEnd();

    int r=630,c=340;
    for(int i=1; i<7; i++)
    {
        for(int j=0; j<4; j++)
        {
            glBegin(GL_QUADS);
            glColor3f(.92,.96,1-day_night);
            if(day=="day")
            {
               glColor3f(0.92,0.96,1);
            }
            else if(day=="night")
            {
                glColor3f(.92,.96,0);
            }

            glVertex2f(r,c);
            glVertex2f(r,c-10);
            glVertex2f(r+10,c-10);
            glVertex2f(r+10,c);

            glEnd();

            r+=20;
        }
        r=630;
        c=340-i*20;
    }
    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(655,200);
    glVertex2f(675,200);
    glVertex2f(675,225);
    glVertex2f(655,225);
    glEnd();
}

void FifthBuilding()
{
     ///5th building

    glBegin(GL_QUADS);
    glColor3f(.5,.7,.5);

    glVertex2f(150,200);
    glVertex2f(220,200);
    glVertex2f(220,350);
    glVertex2f(150,350);
    glEnd();

    int r1=160,c1=340;
    for(int i=1; i<7; i++)
    {
        for(int j=0; j<3; j++)
        {
            glBegin(GL_QUADS);
            glColor3f(.92,.96,1-day_night);
            if(day=="day")
            {
               glColor3f(0.92,0.96,1);
            }
            else if(day=="night")
            {
                glColor3f(.92,.96,0);
            }

            glVertex2f(r1,c1);
            glVertex2f(r1,c1-10);
            glVertex2f(r1+10,c1-10);
            glVertex2f(r1+10,c1);

            glEnd();

            r1+=20;
        }
        r1=160;
        c1=340-i*20;
    }

    glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex2f(175,200);
    glVertex2f(195,200);
    glVertex2f(195,225);
    glVertex2f(175,225);
    glEnd();
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
        glColor3f(1,1,0.3);
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

    ///Lower Car
    LowerCar1();
    LowerCar2();
    LowerCar3();

    ///upper car
    UpperCar3();
    UpperCar1();
    UpperCar2();



    ///Town Starts

///background
    glBegin(GL_QUADS);

    glColor3f(0.52-day_night,0.76-day_night,1-(day_night));
    if(day=="day")
    {
       glColor3f(0.62,0.76,1);
    }
    else if(day=="night")
    {
        glColor3f(0.52-.9,0.76-.9,1-.9);
    }

    //glColor3f(.52,.76,.91);
    //glColor4f(0.5, 0.7, 0.6, 1.0);

    glVertex2f(0,200);
    glVertex2f(760,200);
    glVertex2f(760,380);
    glVertex2f(0,380);
    glEnd();



     ///sun
    glPushMatrix();
    glTranslatef(0,suny,0);
    drawSun(100,360,10);
    glEnd();
    glPopMatrix();


     ///cloud1
    glPushMatrix();
    glTranslatef(cloud1,0,0);
    drawCloud(200,330,15);
    drawCloud(230,330,15);
    drawCloud(215,340,15);
    drawCloud(215,320,15);
    glPopMatrix();

    ///cloud2
    glPushMatrix();
    glTranslatef(cloud2,0,0);
    drawCloud(200+400,340,20);
    drawCloud(230+400,340,20);
    drawCloud(215+400,350,20);
    drawCloud(215+400,330,20);
    glPopMatrix();

    ///cloud3
    glPushMatrix();
    glTranslatef(cloud3,0,0);
    drawCloud(200+400,340,23);
    drawCloud(230+400,340,23);
    drawCloud(215+400,350,20);
    drawCloud(215+400,330,20);
    glPopMatrix();






    ///Hill

    glBegin(GL_POLYGON);
    glColor3f(.12-day_night,.96-day_night,1-day_night);
    if(day=="day")
    {
       glColor3f(.12,.96,1);
    }
    else if(day=="night")
    {
        glColor3f(.12-.9,.96-.9,1-.9);
    }

    glVertex2f(170,200);
    glVertex2f(430,200);
    glVertex2f(330,270);
    glVertex2f(320,260);
    glVertex2f(270,300);
    glVertex2f(240,260);
    glVertex2f(230,270);
    glEnd();

    ///star

    if(day=="night" || day_night>=.7)
    {
        Star();
    }

    ///big tree
    glBegin(GL_QUADS);
    glColor3f(0.6,0.2,0.1);

    glVertex2f(373,200);
    glVertex2f(380,200);
    glVertex2f(380,270);
    glVertex2f(373,270);
    glEnd();

    drawTree(373,50+70+180,19);  ///top
    drawTree(359,50+50+180,19);  ///left
    drawTree(377,60+20+180,19);  ///bottom
    drawTree(390,40+60+180,19);  ///right

    ///Hill 2

    glBegin(GL_POLYGON);
    glColor3f(.9-day_night,.8-day_night,.5-day_night);

    if(day=="day")
    {
       glColor3f(.9,.8,.5);
    }
    else if(day=="night")
    {
        glColor3f(.9-.7,.8-.7,.5-.7);
    }

    glVertex2f(350,200);
    glVertex2f(590,200);
    glVertex2f(530,270);
    glVertex2f(520,260);
    glVertex2f(470,300);
    glVertex2f(430,260);
    glVertex2f(420,270);
    glEnd();





    ///Buildings
    FifthBuilding();
    FirstBuilding();
    SecondBuilding();
    ThirdBuilding();
    FourthBuilding();

    ///Flag
    if(day_night<=.5 && day!="night")
    {
        glBegin(GL_QUADS);
        glColor3f(0,1,0);

        glVertex2f(600,230);
        glVertex2f(630,230);
        glVertex2f(630,245);
        glVertex2f(600,245);
        glEnd();
        glColor3f(1,0,0);
        drawCircle(615,237,5);
    }


    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(630,200);
    glVertex2f(630,245);
    glEnd();



///building with hill
    glBegin(GL_QUADS);
    glColor3f(0,1-day_night,1-day_night);
    if(day=="day")
    {
       glColor3f(0,1,1);
    }
    else if(day=="night")
    {
        glColor3f(0,1-.7,1-.7);
    }

    glVertex2f(465,200);
    glVertex2f(510,200);
    glVertex2f(510,330);
    glVertex2f(465,330);
    glEnd();

int m=465,n=510,l=205,k=330;
    for(int i=0; i<5; i++)
    {
        glBegin(GL_LINES);
        glColor3f(0.0, 0.502+day_night, 0.502);

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

///All lamposts here
    Lamposts();

///Signal Light Down road

     glBegin(GL_LINES);
    glColor3f(0.763, 0.763, 0.763);
    glVertex2f(540,100);
    glVertex2f(540,120);
    glEnd();

    glColor3f(0.763, 0.763, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(535,120);
    glVertex2f(545,120);
    glVertex2f(545,150);
    glVertex2f(535,150);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    drawCircle(540,145,3);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(540,135,3);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(540,125,3);

    if(Signal=="red")
    {
        glColor3f(1.0, 0.0, 0.0);
        drawCircle(540,145,3);
    }
    else if(Signal=="green")
    {
        glColor3f(0.0, 1.0, 0.0);
        drawCircle(540,135,3);
    }
    else if(Signal=="yellow")
    {
        glColor3f(1.0, 1.0, 0.0);
        drawCircle(540,125,3);
    }




///Signal Light up road

    glBegin(GL_LINES);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2f(580,190);
    glVertex2f(580,210);
    glEnd();

    glColor3f(0.763, 0.763, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(575,210);
    glVertex2f(585,210);
    glVertex2f(585,240);
    glVertex2f(575,240);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    drawCircle(580,235,3);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(580,225,3);
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(580,215,3);

    if(Signal=="red")
    {
        glColor3f(1.0, 0.0, 0.0);
    drawCircle(580,235,3);
    }
    else if(Signal=="green")
    {
        glColor3f(0.0, 1.0, 0.0);
    drawCircle(580,225,3);
    }
    else if(Signal=="yellow")
    {
        glColor3f(1.0, 1.0, 0.0);
    drawCircle(580,215,3);
    }

///draw tree1

    glBegin(GL_QUADS);
    glColor3f(0.6,0.2,0.1);

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
    glColor3f(0.6,0.2,0.1);

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
    glColor3f(0.6,0.2,0.1);

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
    glColor3f(0.6,0.2,0.1);

    glVertex2f(53+250+320,10);
    glVertex2f(57+250+320,10);
    glVertex2f(57+250+320,40);
    glVertex2f(53+250+320,40);
    glEnd();

    drawTree(50+250+320,50,12);  ///red fruit
    drawTree(60+250+320,50,12);
    drawTree(55+250+320,60,12);
    drawTree(55+250+320,40,12);


    ///drawTree 5

    glBegin(GL_QUADS);
    glColor3f(0.6,0.2,0.1);

    glVertex2f(53+100,10+10);
    glVertex2f(57+100,10+10);
    glVertex2f(57+100,40+10);
    glVertex2f(53+100,40+10);
    glEnd();

    drawTree(50+100,50+10,14);  ///red fruit
    drawTree(60+100,50+10,14);
    drawTree(55+100,60+10,14);
    drawTree(55+100,40+10,14);

    ///drawTree 6

    glBegin(GL_QUADS);
    glColor3f(0.6,0.2,0.1);

    glVertex2f(53+250+420,10+20);
    glVertex2f(57+250+420,10+20);
    glVertex2f(57+250+420,40+20);
    glVertex2f(53+250+420,40+20);
    glEnd();

    drawTree(50+250+420,50+20,15);  ///red fruit
    drawTree(60+250+420,50+20,15);
    drawTree(55+250+420,60+20,15);
    drawTree(55+250+420,40+20,15);

 ///upper Draw Tree  1

    glBegin(GL_QUADS);
    glColor3f(0.6,0.2,0.1);

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
    glColor3f(0.6,0.2,0.1);

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
    glColor3f(0.6,0.2,0.1);

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
    glColor3f(0.6,0.2,0.1);

    glVertex2f(53+250+400,10+180);
    glVertex2f(57+250+400,10+180);
    glVertex2f(57+250+400,40+180);
    glVertex2f(53+250+400,40+180);
    glEnd();

    drawTree(50+250+400,50+180,12);  ///red fruit
    drawTree(60+250+400,50+180,12);
    drawTree(55+250+400,60+180,12);
    drawTree(55+250+400,40+180,12);

    if(day_night>=.71&&play==false)
    {
         PlaySound("tara.wav", NULL, SND_FILENAME);
         play=true;
    }

    glFlush();
}


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':           ///stop all cars
        if(stop==false)
        {
            lowerCar1_speed=0;
            lowerCar2_speed=0;
            lowerCar3_speed=0;
            upperCar1_speed=0;
            upperCar2_speed=0;
            upperCar3_speed=0;
            stop=true;
        }
        else
        {
            lowerCar1_speed = 8;
            lowerCar2_speed = 12;
            lowerCar3_speed = 5;
            upperCar1_speed = 8;
            upperCar2_speed = 12;
            upperCar3_speed = 15;
            stop=false;
        }

        break;
    case 'n':           ///signal deactivated
        Signal="null";VIPsignal="null";
        SignalTime=0;
        if(stop==false)
        {
           lowerCar1_speed = 8;
            lowerCar2_speed = 12;
            lowerCar3_speed = 5;
            upperCar1_speed = 8;
            upperCar2_speed = 12;
            upperCar3_speed = 15;
        }

        break;
    case 'r':           ///red signal activate
        Signal="red";
        SignalTime=0;
        break;
    case 'g':           ///green signal activate
        Signal="green";VIPsignal="null";SignalTime=0;
        if(stop==false)
        {
           lowerCar1_speed = 8;
            lowerCar2_speed = 12;
            lowerCar3_speed = 5;
            upperCar1_speed = 8;
            upperCar2_speed = 12;
            upperCar3_speed = 15;
        }
        break;
    case 'v':
        if(VIPsignal=="null")
        {
            Signal="red";
            SignalTime=0;
            VIPsignal="vip";
        }
        else
            VIPsignal="null";
        break;
    case 'd':           ///activate day view
        day="day";
        break;
    case 't':           ///activate night view
        day="night";
        break;
    case 'a':           ///activate auto day-night view
        day="up";

        glutPostRedisplay();
    }
}
void SpecialFunc(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)///to increase car speed
    {
        lowerCar1_speed+=10;
        lowerCar2_speed+=10;
        lowerCar3_speed+=5;
        upperCar1_speed+=6;
        upperCar2_speed+=6;
        upperCar3_speed+=8;
    }
    else if(key == GLUT_KEY_DOWN)///to decrease car speed
    {
        lowerCar1_speed-=5;
        lowerCar2_speed-=5;
        lowerCar3_speed-=4;
        upperCar1_speed-=5;
        upperCar2_speed-=5;
        upperCar3_speed-=5;
    }
    else if(key==GLUT_KEY_RIGHT)///To increase day_night speed
    {
        if(day=="up")
        {
            day_night+=.009;
            if(day_night>=.9)
            {
                day="down";play=false;
            }
        }
        else if(day=="down")
        {
            day_night-=.009;
            if(day_night<=0.0)
            {
                day="up";
            }
        }
    }


}
void MENU(int x)
{
    if(x==0)    ///Stop
    {
        lowerCar1_speed=0;
        lowerCar2_speed=0;
        lowerCar3_speed=0;
        upperCar1_speed=0;
        upperCar2_speed=0;
        upperCar3_speed=0;
        stop=true;
	}
	else if(x==1)     ///Run
	{
        lowerCar1_speed = 8;
        lowerCar2_speed = 12;
        lowerCar3_speed = 5;
        upperCar1_speed = 8;
        upperCar2_speed = 12;
        upperCar3_speed = 15;
        stop=false;
	}
	else if(x==2)   ///Day View
	{
        day="day";
	}
	else if(x==3)   ///Night View
	{
        day="night";
	}
	else if(x==4)   ///Auto Day-Night View
	{
        day="up";
	}
	else if(x==5)   ///Red Signal Activate
	{
        Signal="red";
        SignalTime=0;
	}
	else if(x==6)   ///Green Signal Activate
	{
        Signal="green";VIPsignal="null";SignalTime=0;
        if(stop==false)
        {
           lowerCar1_speed = 8;
            lowerCar2_speed = 12;
            lowerCar3_speed = 5;
            upperCar1_speed = 8;
            upperCar2_speed = 12;
            upperCar3_speed = 15;
        }
	}
	else if(x==7)   ///VIP Signal Activate
	{
         Signal="red";
        SignalTime=0;
        VIPsignal="vip";
	}
	else if(x==8)   ///VIP Signal Deactivate
	{
        VIPsignal="null";
	}
	else if(x==9)   ///Signal Deactivate
	{
        Signal="null";VIPsignal="null";
        SignalTime=0;
        if(stop==false)
        {
           lowerCar1_speed = 8;
            lowerCar2_speed = 12;
            lowerCar3_speed = 5;
            upperCar1_speed = 8;
            upperCar2_speed = 12;
            upperCar3_speed = 15;
        }

	}
	else if(x==10)   ///Increase Car Speed
	{
        lowerCar1_speed+=10;
        lowerCar2_speed+=10;
        lowerCar3_speed+=5;
        upperCar1_speed+=6;
        upperCar2_speed+=6;
        upperCar3_speed+=8;
	}
	else if(x==11)  ///Decrease Car Speed
	{
        lowerCar1_speed-=5;
        lowerCar2_speed-=5;
        lowerCar3_speed-=4;
        upperCar1_speed-=5;
        upperCar2_speed-=5;
        upperCar3_speed-=5;
	}

    glutPostRedisplay();
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
    glutSpecialFunc(SpecialFunc);
    glutCreateMenu(MENU);
    glutAddMenuEntry("Stop",0);
    glutAddMenuEntry("Run",1);
    glutAddMenuEntry("Day View",2);
    glutAddMenuEntry("Night View",3);
    glutAddMenuEntry("Auto Day-Night View",4);
    glutAddMenuEntry("Red Signal Activate",5);
    glutAddMenuEntry("Green Signal Activate",6);
    glutAddMenuEntry("VIP Signal Activate",7);
    glutAddMenuEntry("VIP Signal Deactivate",8);
    glutAddMenuEntry("Signal Deactivate",9);
    glutAddMenuEntry("Increase Car Speed",10);
    glutAddMenuEntry("Decrease Car Speed",11);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    init();
    glutMainLoop();
    return 0;
}
