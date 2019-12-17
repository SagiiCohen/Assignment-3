#include <stdio.h>
#define LINE 256
#define WORD 30

int getLine(char s[]){
   int len=0;
   char c;
   char *pointer=s;
    do{
     if(scanf("%c",&c)==EOF){return 0; }
    else{
    *(pointer++)=c;
        len++;
    }    
    }while(c!='\n');
    return len-1;
}

void printString(char c[],int len){
    char *pointer=c;
    for(int i=0;i<len;i++){
        printf("%c",*(pointer++));
        
    }
    printf("\n");
}

int getword(char w[]){
    int lenword=0;
    char cw;
    char *pointerW=w;
    do{
    if(scanf("%c",&cw)==EOF){return 0;}
    else{
    *(pointerW++)=cw;
        lenword++;
    }    
    }while(cw!='\n'&&cw!='\t'&&cw!=' ');
    return lenword-1;
}
int getlength(char* c){
    int i=0;
    while(*(c+i)!='\n'&&*(c+i)!=' ')i++;
    return i;
}

int substring(char* str1,char* str2){
   int i=0;
   
    while(*(str1+i)!='\n'){
        if(*(str1+i)==*(str2)){
           int counter=1;int j=0;
          while(counter>0){
                if(*(str2+j)==' '||*(str2+j)=='\n'||*(str1+i+j)=='\n'){
                    if(counter-1==getlength(str2)){return 1;}
                    else{counter=0;}
                }
                 else if(*(str1+i+j)==*(str2+j)){counter++;}
                 else if(*(str1+i+j)=='\t'||*(str1+i+j)==' '){counter =0;}
                 else{counter=0;}    
                j++; 
          }
        }
        i++;
    }
   return 0;
}
 int similar(char* s,char* t,int n){
  if(getlength(s)<getlength(t))return 0;
   else{
   int maximumdifferent=0;int i=0;int j=0;
        while(*(s+i)!='\n'&&*(s+i)!=' '){
            if(*(s+i)!=*(t+j)){maximumdifferent++;i++;}
            else{i++;j++;}
  }
    if(maximumdifferent<=n)return 1;
   }
   return 0; 
 }  

void print_lines(char* str){
     char possibleline[LINE];
     char* pointerline=possibleline;
   int lengthline=0;
  do{
       
        lengthline=getLine(possibleline);
       if(substring(possibleline,str)!=0){
           printString(pointerline ,lengthline);     
       }
    }while(lengthline!=0);
}
void print_similar_words(char* str){
     char possibleword[WORD];
     char* pointerword=possibleword;
   int lengthword=0;
  do{
       
        lengthword=getword(possibleword);
       if(similar(possibleword,str,1)!=0){
           printString(pointerword ,lengthword);     
       }
    }while(lengthword!=0);
}
