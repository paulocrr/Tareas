#include <stdio.h>
int Len(char s[]);
void strcat(char *t,char *f);
char Lower(char *s);
int strend(char *s,char *t);
void reverse(char *s,int n);
void strncpy(char *s,char *t,int n);
main(){
    char a[100]="Hola";
    char b[50]="que_tal";
    char c ='A';
    char d[]="hola";
    char e[]="a";
    char f[100]="";
    char g[100]="Hola";
    char h[] = "Adios";
    strcat(&a,&b);
    strncpy(&g,&f,2);
    reverse(h,5);
    printf("%s%s\n","Strcat: ",a);
    printf("%s%c\n","Lower: ",Lower(&c));
    printf("%s%d\n","Strend: ",strend(&d,&e));
    printf("%s%s\n","Copia: ",f);
    printf("%s%s\n","Reverse: ",h);
}
char Lower(char *s){
    return *s+32;
}
void strcat(char *t,char *f){
    int i = Len(t);
    t=t+i;
    while(*t++ = *f++);
}
int strend(char *s,char *t){
    int c = 0;
    int i = Len(s)-1;
    int j = Len(t);

    while(c<i){
        *s++;
        ++c;
    }
    c=0;
    if(j>1){
        while(c<j){
            *t++;
            ++c;
        }
        c=0;
    }
    while(c<j){
        if(*s !=*t ){
            return 0;
        }
        *s--;
        *t--;
        ++c;
    }
    return 1;
}
void strncpy(char *s,char *t,int n){
    int i = 0;
    while(i<n){
        *t++ = *s++;
        ++i;
    }
}
void reverse(char *s,int n){
    char temp;
	if(n>1){
		temp = s[n-1];
		s[n-1] = s[0];
		s[0] = temp;
		reverse(s+1,n-2);
	}
}
int Len(char s[]){
    int i = 0;
    while(s[i]!= '\0'){
        ++i;
    }
    return i;
}
