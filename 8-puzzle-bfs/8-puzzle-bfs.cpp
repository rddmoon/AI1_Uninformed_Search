#include<bits/stdc++.h>
using namespace std;

int n = 9;
vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 0, 8};
map<vector<int>, bool> visit;

struct node {
    vector<int> state;
    node* parent;
    
    node(){
        parent = NULL;
    }
};

void printState(vector<int> state){
    for(int i = 0; i < 9; ){
        for(int j = 0; j < 3; ++j, ++i){
        	printf("%d ", state[i]);
		}
        printf("\n");
    }
    printf("\n");
}

void printPath(node* state){
	int i;
    vector<node*> path;
    while(state){
        path.push_back(state);
        state = state->parent;
    }
    printf("\nMoves: %lu\n", path.size()-1);
    for(i = path.size()-1; i >= 0; --i){
    	printState(path[i]->state);
	}
}

node* createNewState(node* state, int x, int y){
    node* new_state = new node();
    new_state->state = state->state;
    swap(new_state->state[x], new_state->state[y]);
    
    return new_state;
}

void BFS(node* initial){
    visit[initial->state] = 1;
    
    int pos, row, col;
    
    node *curr = new node(), *child = new node();
    queue<node*> q;    
    q.push(initial);
    
    while(!q.empty()){
        curr = q.front();
        q.pop();
        
        if(curr->state == goal){
            printPath(curr);
            return;
        }
        int i;
        for(i = 0; i < n; ++i){
            if(curr->state[i] == 0){
                pos = i;
                break;
            }
        }
        row = pos / 3;
        col = pos % 3;

        if(col != 0){
            child = createNewState(curr, pos, pos-1);
            
            if(visit[child->state] == 0){
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }

        if(col != 2){
            child = createNewState(curr, pos, pos+1);
            
            if(visit[child->state] == 0){
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }

        if(row != 0){
            child = createNewState(curr, pos, pos-3);
            
            if(visit[child->state] == 0){
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }

        if(row != 2){
            child = createNewState(curr, pos, pos+3);
            
            if(visit[child->state] == 0)
            {
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }
    }
}

int main(){
    int i, x;
    node* initial = new node();
    printf("Goal state:\n");
    for(i = 0; i < 3; i ++){
    	printf("%d ", goal[i]);
	}
	printf("\n");
	for(i = 3; i < 6; i ++){
    	printf("%d ", goal[i]);
	}
	printf("\n");
	for(i = 6; i < 9; i ++){
    	printf("%d ", goal[i]);
	}
	printf("\n");
    first:
    printf("\nInput initial state:\n");
    for(i = 0; i < n; ++i){
        scanf("%d", &x);
        if(x > 8 || x < 0){
        	printf("\nInput should be numbers from 0 to 8\n");
        	goto first;
		}
        initial->state.push_back(x);
    }
    
    BFS(initial);
    
    return 0;
}
