#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void manual_user(){
  fprintf(stdout, "\n [*] Parameters: \n");
  fprintf(stdout, "\n\t --checker   --update\n");
}

void note_checker(){
  fprintf(stdout, "\n\n\t\t [*] UP...\n");
  system("cd $up && git status");

  fprintf(stdout, "\n\n\t\t [*] BLACKBOX...\n");
  system("cd $box && git status");

  fprintf(stdout, "\n\n\t\t [*] BRAIN...\n");
  system("cd $brain && git status");
  
  fprintf(stdout, "\n\n\t\t [*] BORED...\n");
  system("cd $bored && git status");

  fprintf(stdout, "\n\tChecker Ready...\n");
}

void note_update(){
  fprintf(stdout, "\n\n\t\t [*] UP...\n");
  system("cd $up && git pull origin master");

  fprintf(stdout, "\n\n\t\t [*] BLACKBOX...\n");
  system("cd $box && git pull origin master");

  fprintf(stdout, "\n\n\t\t [*] BRAIN...\n");
  system("cd $brain && git pull origin master");
  
  fprintf(stdout, "\n\n\t\t [*] BORED...\n");
  system("cd $bored && git pull origin master");

  fprintf(stdout, "\n\tUpdate Ready...\n");
}


int main(int argc, char *argv[]){
  if(argc != 2){
    manual_user();
    return 69;
  }
  if( strcmp(argv[1], "--checker") == 0 ){
    note_checker();
  }else if( strcmp(argv[1], "--update") == 0 ){
    note_update();
  }else{
    manual_user();
    return 69;
  }

  return 0;
}
