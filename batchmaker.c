#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

FILE *fileOUT;
char dev[50] = "dev";
char test[50] = "test";
char prod[50] = "prod";
char ans[50] = "";
char ansStr[50] = "";
char d[50] = "3";
char t[50] = "2";
char p[50] = "1";
char defaultUN[50] = "";
char un[50] = "";
char filename[50] = "";
char fullname[50] = "";
char dip[50] = "000.000.000.000"; // insert server IP address here
char tip[50] = "000.000.000.000"; // insert server IP address here
char pip[50] = "000.000.000.000"; // insert server IP address here
char yes[50] = "y";
char no[50] = "n";
char yn[50] = "";
char dfn[50] = "";
char finishText[256] = "\n...The batch file has been saved to the desktop\n\n";

int main()
{
  strcat(defaultUN, getenv("USERNAME"));
  printf("\nPlease select from the server options below.\n\t1) dev\n\t2) test\n\t3) prod\n\nThe server you choose will be the one we connect to with the batch file (1/2/3): ");
  scanf("%s", &ans);
  
  if(!strcmp(ans, dev)) strcat(ansStr, dev);
  if(!strcmp(ans, test)) strcat(ansStr, test);
  if(!strcmp(ans, prod)) strcat(ansStr, prod);
  else{ printf("\nPlease choose 1, 2, or 3."\n\n); return 0;}
  
  printf("Your username is %s. Do you want to connect using this username (y/n)?: ", defaultUN);
  scanf("%s", &yn);
  
  if(!strcmp(yn, yes)){
    strcat(un, defaultUN);
  }
  else if(!strcmp(yn, no)){
    printf("Please enter the username you want to connect with (Ex: %s): ", defaultUN);
    scanf("%s", &un);
  }
  else{
    printf("\nPlease only use \"y\" or \"n\"\n\n");
    return 0;
  }
  
  strcat(dfn, ansStr);
  strcat(dfn, "_SSH");
  printf("The file name will be %s. Do you want to keep it (y/n)?: ", &dfn);
  scanf("%s", &yn);
  
  if(!strcmp(yn, yes)){
    strcat(filename, dfn);
  }
  else if(!strcmp(yn, no)){
    printf("Please enter the filename you want to use (without the extension - Ex: '%s_SSH'): ", &ansStr);
    scanf("%s", &filename);
  }
  else{
    printf("\nPlease only use \"y\" or \"n\"\n\n");
    return 0;
  }
  
  strcat(filename, ".bat");
  strcat(fullname, getenv("USERPROFILE");
  strcat(fullname, "\\Desktop\\");
  strcat(fullname, filename);
  
  if(!strcmp(ansStr, dev)){
    fileOUT = fopen(fullname, "w+");
    fprintf(fileOUT, "@echo off \nd: \ncd D:\\TTERMPRO \nstart ttermpro ssh://%s /user=%s \nexit", dip, un);
    printf(finishTEXT);
  }
  else if(!strcmp(ansStr, test)){
    fileOUT = fopen(fullname, "w+");
    fprintf(fileOUT, "@echo off \nd: \ncd D:\\TTERMPRO \nstart ttermpro ssh://%s /user=%s \nexit", tip, un);
    printf(finishTEXT);
  }
  else if(!strcmp(ansStr, prod)){
    fileOUT = fopen(fullname, "w+");
    fprintf(fileOUT, "@echo off \nd: \ncd D:\\TTERMPRO \nstart ttermpro ssh://%s /user=%s \nexit", pip, un);
    printf(finishTEXT);
  }
  else{
    return 0;
  }
  
  printf("Do you want to make another batch file (y/n)?: ");
  scanf("%s", &yn);
  
  if(!strcmp(yn, yes)){
    strcpy(defaultUN, "");
    strcpy(un, "");
    strcpy(filename, "");
    strcpy(fullname, "");
    strcpy(dfn, "");
    strcpy(yn, "");
    strcpy(ans, "");
    strcpy(ansStr, "");
    fclose(fileOUT);
    main();
  }
  else if(!strcmp(yn, no)){
    system("PAUSE");
  }
  else{
    printf("\nPlease only enter yes or no\n\n");
    return 0;
  }
  
  if(fileOUT != NULL){
    fclose(fileOUT);
  }
  
  return 0;

}
