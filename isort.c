#include <stdio.h>

void shift_element(int *arr,int i){
    while(i!=0){
        *(arr+i+1)=*(arr+i);
            i--;
    }
}
void insertion_sort(int *arr,int len){
    for(int j=1;j<=len-1;j++){
        int tmp=*(arr+j);
        int i=j-1;
        while(i>=0&&*(arr+i)>tmp){
            *(arr+i+1)=*(arr+i);
            i--;
            *(arr+i+1)=tmp;
        }
    }
}
void my_print(int *arr,int len){
    for(int i=0;i<len;i++){
        if(i==len-1){
           printf("%d\n",*(arr+i));  
        }
        else{
             printf("%d,",*(arr+i));
        }
    }
}

