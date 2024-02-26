#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<cmath>
void women(){
    //int t;
    

    //man
     for(int t=5;t<30;t=t+5){
   cleardevice();
circle(380,170,20);
int l[]={ 370,184,320+t+t,260,350+t+t,260,370,184 };
drawpoly(4,l);
//line(350,214,416+t,265);
line(350+t+t,260,375+t+t,260);
line(375+t+t,260,375+t+t,253);
line(375+t+t,253,353+t+t,253);
arc(376+t+t,256.5,270,450,6.5);
arc(335+t+t,260,180,360,15);
line(330+t+t,275,345+t+t,360);
line(340+t+t,275,385+t+t,360);
     
circle(500,300,20);
int p[]={ 480,300,400+t,240,400+t,280,480,300};
drawpoly(4,p);
//360-340/2  //200-160/2
//10 , 20
arc(400+t, 260,90,270,20);
//line((430+12),(457.5-21),440,280);
//line((430+21),(457.5-12),400,300);
line(t+(400-(20*cos(30))),(300+(20*sin(30))),420,340);
line(t+(400-20*cos(30)),(300+20*sin(30)),460,340);



delay(1);
}
     for(int t=30;t>5;t=t-5){
        cleardevice();
        circle(380,170,20);
int l[]={ 370,184,320+t+t,260,350+t+t,260,370,184 };
drawpoly(4,l);
//line(350,214,416+t,265);
line(350+t+t,260,375+t+t,260);
line(375+t+t,260,375+t+t,253);
line(375+t+t,253,353+t+t,253);
arc(376+t+t,256.5,270,450,6.5);
arc(335+t+t,260,180,360,15);
line(330+t+t,275,345+t+t,360);
line(340+t+t,275,385+t+t,360);
circle(500,300,20);
int p[]={ 480,300,400+t,240,400+t,280,480,300};
drawpoly(4,p);
//360-340/2  //200-160/2
//10 , 20
arc(400+t, 260,90,270,20);
//line((430+12),(457.5-21),440,280);
//line((430+21),(457.5-12),400,300);
line(t+(400-(20*cos(30))),(300+(20*sin(30))),420,340);
line(t+(400-20*cos(30)),(300+20*sin(30)),460,340);



delay(1);

}
} 
void man(){
        
circle(420,260,20);
int l[]={ 420,240, 360,220,380,220,420,240};
drawpoly(4,l);

}
//arc(430,450,430);
//line(400-20*cos(30),260+20*sin(30),400,240);
//line(400-20*cos(60),260+20*sin(60),400,240);

   



using namespace std;     
int main(int argc, char const *argv[]){
//int i,j,k;
   int gd=DETECT,gm; 
 
     initgraph(&gd,&gm,(char*)"");
       
 int t,dir;
     initgraph(&gd,&gm,(char*)"");
       
   // setbkcolor(RED);
  for(dir=1;dir<3;dir++){
  if(dir==1){
   for(int i=0;i<534;i++){
    women();
    dir=dir-1;
   }
  }
   else{
   man();
   dir=dir+1;
   }
   delay(100);

  }


      getch();
    closegraph();
return 0;
}