#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    clock_t start,end;
    srand( time( 0 ) );
    
    start=clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 100 );
      system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
      
   }
   end=clock();
   
   if(hare==70) cout<<"Hare wins. Yuch."<<endl;
   if(tortoise==70) cout<<"TORTOISE WINS!!! YAY!!!"<<endl;
   cout<<"TIME ELAPSED = "<<(end-start)/1000<<" seconds"<<endl;
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int j=0;j<7;j++)
		cout<<"---------|";
	cout<<endl;
	cout<<setw(*bunnyPtr)<<"H"<<endl;
	cout<<setw(*snapperPtr)<<"T"<<endl;
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int tt=1+rand()%10;
	if(tt>=1&&tt<=5) *turtlePtr+=3;
	else if(tt>=6&&tt<=8) *turtlePtr-=6;
	else *turtlePtr+=1;
	
	if(*turtlePtr>70)*turtlePtr=70;
	if(*turtlePtr<1)*turtlePtr=1;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
  	int rr=1+rand()%10;
	if(rr>=1&&rr<=2) *rabbitPtr+=0;
	else if(rr>=3&&rr<=4) *rabbitPtr+=9;
	else if(rr==5) *rabbitPtr-=12;
	else if(rr>=6&&rr<=8) *rabbitPtr+=1;
	else *rabbitPtr-=2;
	
	if(*rabbitPtr>70)*rabbitPtr=70;
	if(*rabbitPtr<1)*rabbitPtr=1;
}
