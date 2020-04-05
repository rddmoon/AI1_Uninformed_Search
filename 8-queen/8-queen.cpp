#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int check(int queen[], int col){
	int i;
	for(i = 0; i < col; i++){
		if((queen[i] == queen[col]) || (abs(queen[col] - queen[i]) == (col - i))){
			return 0;
        }
    }
    return 1;
}

void back(int &col){
    col--;
    if(col==-1){
    	exit(0);
	}
}

void print(int queen[]){
	static int count =0;
    count++;
    int i, j, board[8][8]={0};
    printf("Solusi %d\n", count);
    for(i = 0; i < 8; i++){
        board[queen[i]][i] = 1;           
    }
     //print  
    for(i = 0; i < 8; i++){ 
		for(j = 0; j < 8; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
    }
}

int main(){
	int queen[8]; queen[0]=0;
    int c=1; 
	bool fromback = false;
    while(1){
		while( c < 8){
        	if( !fromback ){
        		queen[c]=-1;
			}
            fromback = false;
            while( queen[c] < 8){
            	queen[c]++;
                while(queen[c]==8){
					back(c);
                    queen[c]++;              
                }
                if(check(queen, c) == 1){
					break;
				}                   
            }
        	c++;
     	}
	    print(queen);
	    cin.get();
	    back(c);
	    fromback = true;
    }
}
