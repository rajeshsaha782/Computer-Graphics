#include<windows.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>
#include<MMsystem.h>
using namespace std;

string direction="right";
GLint  positionX=0,positionY=0,speed=10;
int Rx,Ry,snake_size=3,score=0,Highscore=0,bonusPoint=50;
bool visited=false,status=false;
int winSize=290;


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
string int_to_str(int num)
{
    stringstream ss;

    ss << num;

    return ss.str();
}
void File_write()
{
    ofstream outfile;
   outfile.open("Highscore.txt");
   outfile <<Highscore<< endl;
   outfile.close();
}
void File_read()
{
    ifstream infile;
   infile.open("Highscore.txt");
   int data;
   infile >> data;
   Highscore=data;
   infile.close();
}

void init()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glOrtho(0.0, 300.0, 0.0, 300.0, -1.0, 1.0);
    Rx=random(20,winSize-10);
    Ry=random(20,winSize-10);
    Rx=Rx-(Rx%10);
    Ry=Ry-(Ry%10);
    File_read();
    cout<<"\t\tSCORE:"<<score<<endl;
}

void RandomPoints()
{
     Rx=random(20,winSize-10);
     Ry=random(20,winSize-10);
     Rx=Rx-(Rx%10);
     Ry=Ry-(Ry%10);
     visited=false;
     bonusPoint=50;
}

void RandomBox()
{

    if(bonusPoint%2==0 && status==false)
    {
        glColor3f(0.0f, 1.0f, 0.0f);
    }
    else
    {
        glColor3f(0.0f, 0.5f, 0.5f);
    }

    glBegin(GL_QUADS);
    glVertex2f(Rx,Ry);
    glVertex2f(Rx+10,Ry);
    glVertex2f(Rx+10,Ry+10);
    glVertex2f(Rx,Ry+10);
    glEnd();


      if(positionX==Rx && positionY+10==Ry)
        {
            //PlaySound("Tick.wav", NULL, SND_FILENAME);
            PlaySound("drip.wav", NULL, SND_FILENAME);
           //cout<<"X:"<<Rx<<" positionX:"<<positionX<<endl;
           //cout<<"Y:"<<Ry<<" positionY:"<<positionY<<endl;
           visited=true;snake_size++;
           if(bonusPoint>0)
           {
               score=score+bonusPoint;
           }
           else
           {
              score++;
           }

            system("cls");
            cout<<"\t\tSCORE:"<<score<<" +"<<bonusPoint<<endl;

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

    if(bonusPoint!=0)
    {
        bonusPoint--;
    }

    //cout<<bonusPoint<<endl;
    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}



void Check_border()
{
    if(positionX>=winSize || positionX<10|| positionY>=winSize-10 ||positionY<=-10)
    {
        speed =0;
        if(!status)
        {
            system("cls");
            cout<<"\n\t\t***********GAME OVER************"<<endl;
            if(score>Highscore)
            {
                File_write();
                Highscore=score;
                cout<<"**************Congratulation!!!Your make a new High score.**************"<<endl;
            }
            cout<<"\t**************Your Score:"<<score<<"**************"<<endl;
            cout<<"Check Point->"<<positionX<<","<<positionY<<endl;
            status=true;

            PlaySound("noooh_2.wav", NULL, SND_SYNC);
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

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glVertex2f(10,winSize);
    glVertex2f(winSize,winSize);
    glVertex2f(10,winSize);
    glVertex2f(10,10);
     glVertex2f(10,10);
    glVertex2f(winSize,10);
     glVertex2f(winSize,10);
    glVertex2f(winSize,winSize);
    glEnd();



    int a=0;
    for(int i=0;i<snake_size;i++)
    {
        if(i%2==0)
        {
            glColor3f(1.0f, 1.0f, 0.0f);
        }
        else
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }

        if(i==0)//Head
        {
            Check_border();
            glColor3f(0.0f, 0.0f, 1.0f);//head color
        }


       glPushMatrix();
        glTranslatef(positionX,positionY, 0.0f);
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
void MENU(int x)
{
    if(x==1)//play
    {
       speed=10;
       PlaySound("unpause.wav", NULL, SND_SYNC);
	}
	else if(x==0)//pause
	{
	    speed=0;
	    PlaySound("pause.wav", NULL, SND_SYNC);
	}
	else if(x==2)//restart
	{
	    direction="right";
        positionX=10,positionY=10,speed=10;
        snake_size=3,score=0;
        visited=false,status=false;
        bonusPoint=50;File_read();

        Rx=random(20,winSize-10);
        Ry=random(20,winSize-10);
        Rx=Rx-(Rx%10);
        Ry=Ry-(Ry%10);

        system("cls");
        cout<<"\t\tSCORE:"<<score<<endl;
	}
	else if(x==3)//high score
    {
        cout<<"\n*****HighScore:"<<Highscore<<"*****"<<endl;
        speed=0;
    }

    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(400, 50);
    glutCreateWindow("Snake");
    glutDisplayFunc(display);
    init();

    glutSpecialFunc(SpecialFunc);

    glutCreateMenu(MENU);
    glutAddMenuEntry("Pause",0);
    glutAddMenuEntry("Play",1);
    glutAddMenuEntry("Restart",2);
    glutAddMenuEntry("High score",3);
    //glutAddMenuEntry("Stop",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutTimerFunc(0, update, 100);
    glutMainLoop();
    return 0;
}
