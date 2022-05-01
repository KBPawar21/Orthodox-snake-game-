//    S N A K E    G A M E



#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

#include<process.h>

void main()
{

    int lenth=3,ten=10,round=0,temp=1,LEVEL=1,speed=150;

    int gd=DETECT,gm;
    int j,k,y,x,i=0,dif=-5,dif2=5,score=0,str[1100];
    int R[1000],T[1000],L[1100],B[1000],ch,pos=1,db[1100];

    initgraph ( &gd,&gm, "c:\\TC\\BGI");


    R[0]=10,T[0]=30,L[0]=20,B[0]=20;
    R[1]=20,T[1]=30,L[1]=30,B[1]=20;
    R[2]=30,T[2]=30,L[2]=40,B[2]=20;

     for(i=0;i<lenth;i++)
	 db[i]=pos;



						 srand(time(0));
						 x=rand()%60;
						 x=x*10;
						  x=x+5;

						 srand(time(0));
						 y=rand()%40;
						 y=y*10;
						  y=y+5;




	 while(1)
	 {






		       if(kbhit())
			 {

			   ch=getch();


			   switch(ch)
			    {
				   case 50:
					  if(pos==1 || pos==3)
					  {
					    pos=0;
					    db[lenth-1]=pos;
					    round=0;
					    break;
					  }
					  else
					   break;

				   case 52:
					   if(pos==2 || pos==0)
					   {
					     pos=3;
					     db[lenth-1]=pos;
					     round=0;
					     break;
					   }
					   else
					    break;


				   case 54:
					   if(pos==2 || pos==0)
					   {
					     pos=1;
					     db[lenth-1]=pos;
					     round=0;
					     break;
					   }

					   else
					     break;

				   case 56:
					  if(pos==1 || pos==3)
					  {
					    pos=2;
					    db[lenth-1]=pos;
					   round=0;
					   break;
					  }
					  else
					    break;

				       case 27:
					      exit(0);

				  }//swtch

			      }  //ifkbhit





			       switch(db[lenth-1])
				    {
				       case 0: dif=5,dif2=-5;  break;
				       case 1: dif=-5,dif2=5;  break;
				       case 2: dif=5,dif2=15;  break;
				       case 3: dif=15,dif2=5;  break;
				    }




			      for(i=0;i<lenth;i++)
			      {
				   if( db[i]== 0 || db[i]==1)
				       ten=10;
				   else
				       ten= -10;


				 if(db[i]==3 || db[i]==1)
				  {
					R[i]=R[i]+ten;
					L[i]=L[i]+ten;
				  }
				  else
				   {
					B[i]=B[i]+ten;
					T[i]=T[i]+ten;
				  }
			       }





					       if(temp==1)
					       {
						  setcolor(15);
						  sprintf(str ,"%d" ,LEVEL);
						  outtextxy(260,185," L E V E L  ");
						  outtextxy(370,186,str);
						  sleep(3);
						  temp=0;
					       }

			      /*	for(k=0;k<12;k++)
				      {
				       setcolor(4);
				       rectangle (628+k,12-k,11-k,388+k);       // Boundry lines
				      }
				      //sleep(3);
			       */





			       clrscr();


			      for(j=0;j<lenth;j++)
			       {

				  for(k=0;k<5;k++)
				      {
				       setcolor(4);
				       rectangle (R[j]+k,T[j]-k,L[j]-k,B[j]+k);
				      }

				}            //snake


			   //food

				    setcolor(0);
				    setfillstyle(1,0);
				    circle(x,y,6);
				    floodfill(x,y,0);



		// when Snake touches it self

				     for(i=0;i<lenth-2;i++)
				       {
					  if(L[lenth-1] == L[i] && T[lenth-1]==T[i])
					   {

					      temp=3;   //code goes to snake & boundry loop

					   }
				       }



		// Snake & boundry

				    if(L[lenth-1]==650 || L[lenth-1]==0 || T[lenth-1]==0 || T[lenth-1]==410 || temp==3)
				    {
				      sleep(1);
				      clrscr();
				       setcolor(4);
				       i=0;
				      while(i<10)
					rectangle(375+i,217-i,213-i,155+i),i++;
				       setcolor(4);
				       sprintf(str ,"%d" ,score);            // Final Score
				      outtextxy(230,185," YOUR SCORE : ");
				      outtextxy(340,186,str);
				      sleep(3);
				      exit(0);
				    }







	// Snake & food touch

				     if(x==L[lenth-1]-5 && y==T[lenth-1]-5)
				     {
					temp=2;
				     }

				    if(x+dif==L[lenth-1] && y+dif2==T[lenth-1] || temp==2)
				    {

					 score++;
					 temp=0;

					  //printf("\n\n\n\n\t\t %d %d %d %d",x, y,L[lenth-1],T[lenth-1]);


						 srand(time(0));
						 x=rand()%60;
						  x=x*10;
						  x=x+5;

						 srand(time(0));
						 y=rand()%40;
						 y=y*10;
						 y=y+5;
						 temp=0;


					  lenth++;
					  i=lenth-1;
					  db[i]=db[i-1];




					   if( db[i]== 0 || db[i]==1)
					     ten=10;
					   else
					     ten= -10;


					   if(db[i]==1 || db[i]==3)
					   {
						R[i]=R[i-1]+ten;
						//printf("%d %d %d %d", R[i],R[i-1],R[i-2],R[i-3]);
						//getch();
						L[i]=L[i-1]+ten;
						B[i]=B[i-1];
						T[i]=T[i-1];
					   }
					  else
					   {
						B[i]=B[i-1]+ten;
						//printf("%d %d %d %d 2", B[i],B[i-1],B[i-2],B[i-3]);
					   //	getch();
						T[i]=T[i-1]+ten;
						L[i]=L[i-1];
						R[i]=R[i-1];
					    }

					  i=0;



						if(score%20==0)
						{
						 speed=speed-0;
							LEVEL++;
						  clrscr();
						  setcolor(0);
						  sprintf(str ,"%d" ,LEVEL);
						  outtextxy(230,185," L E V E L  ");
						      outtextxy(340,186,str);
						  sleep(3);
						}

				      } //if



				      if(round<lenth-1)
					   round++;




				       setcolor(0);
				       sprintf(str ,"%d" ,score);            // Score board
				       outtextxy(14,15,"SCORE :");
				       outtextxy(70,15,str);




				delay(speed);



				 for(i=0;i<lenth-1;i++)
				 {
				    db[i]=db[i+1];

				  }
			       if(round==1)
				 db[lenth-2]=db[lenth-1];



			  } //while a



		    } //final







