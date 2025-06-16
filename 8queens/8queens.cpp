#include <iostream>
#include <math.h>



bool ok(int &c, int board []){

    //check if there is already a queen in that row
    for(int i = 0; i < c; i++){
        if(board[i] == board[c]) return false;
    }

    //check diagonals using absolute value
    for(int i = 0; i < c; i++){
        if(abs(c - i) == abs(board[c] - board[i])) return false;
    }

    return true;
}

void backtrack(int &c){
    c--;
    if(c < 0){
        exit(0);
    }

}

void print(int board[]){
    static int solutions = 0;
    std::cout<<"Solution #"<<++solutions<<"\n";

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[j] == i){
                std::cout<<"1";
            }else{
                std::cout<<"0";
            }
        }
        std::cout<<"\n";
    }
    std::cout<<"----------\n";
}

int main(){

    int board [8];
    int c = 0; 
    board[c] = 0;

    while( c >= 0){
        c++;
        if(c >= 8){
            print(board);
            backtrack(c);
        }else{
            board[c] = -1;
        }

        while(c >= 0){
            board[c]++;

            if(board[c] >= 8){
                backtrack(c);
            }else{
                if(ok(c,board)){
                    break;
                }
            }
        }
    }




}