#include <stdio.h>

char Tboard[3][3];

void init_Tboard (){
  int i, j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      Tboard[i][j] = ' ';
    }
  }
}

void display_Tboard(){
  int i, j;
  for(i = 0; i < 3; i++){
     printf(" ---  ---  ---\n");
    for(j = 0; j < 3; j++)
      printf("| %c |",Tboard[i][j]);
    printf("\n");
  }
  printf(" ---  ---  ---\n");
}

void get_P_move(char P_key){
  int x, y;
  printf("Enter coordinates of your move: ");
  scanf("%d %d", &x, &y);
  if(x > 3 || y > 3 || Tboard[x][y] != ' '){
    printf("Invalid move. Please Try Again\n");
    get_P_move(P_key);
  }
  else{
    Tboard[x][y] = P_key;
  }
}

char win_checker(){
  int i = 0;
  for(i = 0; i < 3; i++){
    if(Tboard[i][0] == Tboard[i][1] && Tboard[i][0] == Tboard[i][2])
      return Tboard[i][0];
    if(Tboard[0][i] == Tboard[1][i] && Tboard[0][i] == Tboard[2][i])
      return Tboard[0][i];
  }
  if(Tboard[0][0]==Tboard[1][1] && Tboard[0][0]==Tboard[2][2])
      return Tboard[0][0];

  if(Tboard[0][2]==Tboard[1][1] && Tboard[0][2]==Tboard[2][0])
      return Tboard[0][2];
  return ' ';
}

int main(){
  int x = 0, y = 0, moveCounter = 0;
  int P1_turn = 1, P2_turn = 0, game_over = 0;
  char X_key = 'X', O_key = 'O';
  char winning_move;
  
  printf("T I C - T A C - T O E\n");
  init_Tboard();
  display_Tboard();
  printf("INSTRUCTIONS: Enter coordinates separated by space (' ')\n");

  while (game_over  == 0){
    if (P1_turn == 1 && P2_turn == 0){ //USE X_key
      get_P_move(X_key);
      P1_turn = 0;
      P2_turn = 1;
      winning_move = win_checker();
      moveCounter++;
    }
      
    else if (P2_turn == 1 && P1_turn == 0){ //USE O_key
      get_P_move(O_key);
      P1_turn = 1;
      P2_turn = 0;
      moveCounter++;
    }
    display_Tboard();
    
    if(winning_move != ' '){
      game_over = 1;
      break;
    }
    if(moveCounter == 9){
      game_over = 1;
      break;
    }
  }

  if(game_over == 1 && winning_move == 'X')
    printf("\nPLAYER 1 - X WINS!\n");
  else if(game_over == 1 && winning_move == 'O')
    printf("\nPLAYER 2 - O WINS!\n");
  else if(moveCounter == 9 && game_over == 1)
    printf("\nGAME OVER PLAYER 1 & PLAYER 2 TIED!\n");
}