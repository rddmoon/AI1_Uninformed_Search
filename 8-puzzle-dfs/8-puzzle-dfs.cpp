#include <iostream>
#include <cstring>

using namespace std;

void DFS(int game[9], int X, string path);

int node = 0;
int goal[9];
int solution = 0;
int state[9][9][9][9][9][9][9][9][9];

int main(){
    
    int game[9];
    int X;
    goal[0] = 1;
    goal[1] = 2;
    goal[2] = 3;
    goal[3] = 4;
    goal[4] = 5;
    goal[5] = 6;
    goal[6] = 7;
    goal[7] = 0;
    goal[8] = 8;
    
    printf("Goal State:\n");
	  for(int i = 0;i < 3; i++){
        printf("%d ",goal[i]);
    }
    printf("\n");
    for(int i = 3;i < 6; i++){
        printf("%d ",goal[i]);
    }
    printf("\n");
    for(int i = 6;i < 9; i++){
        printf("%d ",goal[i]);
    }
    printf("\n");
    first:
    printf("\nInput initial state:\n");
    
    for(int i = 0;i < 9; i++){
        scanf("%d",&game[i]);
        if(game[i]==0){
            X = i;
        }
        if(game[i] > 9 || game[i] < 0){
        	printf("Input should be numbers from 0 to 8\n");
        	game[9] = {0};
        	goto first;
		}
    }
    memset(state, 0, sizeof(state[0][0][0][0][0][0][0][0][0])*9*9*9*9*9*9*9*9*9);
    DFS(game, X, "\nPath:\n");
    printf("\nNode: %d\n", node);
}
void DFS(int game[9], int X, string path){
	if(solution == 1){
		return;
	}
    if(state[game[0]][game[1]][game[2]][game[3]][game[4]][game[5]][game[6]][game[7]][game[8]]==0){
        node++;
        state[game[0]][game[1]][game[2]][game[3]][game[4]][game[5]][game[6]][game[7]][game[8]]=1;
    }else{
        return;
    }

    int find = 0;
    for(int i=0;i < 9;i++){   
        if(game[i] != goal[i] ){
            find = 1;
            break;
        }
    }
    if(find == 0){
        	solution = 1;
            printf("%s", path.c_str());
            return;
        }
    if(X < (3 * 2)){
        game[X] = game[X+3];
        game[X+3] = 0;
        DFS(game, X+3, path+"Up\n");
        game[X+3] = game[X];
        game[X] = 0;
    }
    if((X+1) % 3 !=1 ){
        game[X] = game[X-1];
        game[X-1] = 0;
        DFS(game, X-1, path+"Right\n");
        game[X-1] = game[X];
        game[X] = 0;
    }
    if((X+1) % 3 !=0 ){
        game[X] = game[X+1];
        game[X+1] = 0;
        DFS(game, X+1, path+"Left\n");
        game[X+1] = game[X];
        game[X] = 0;
    }
    if(X > 2){
        game[X] = game[X-3];
        game[X-3] = 0;
        DFS(game, X-3, path+"Down\n");
        game[X-3] = game[X];
        game[X] = 0;   
    }
}
