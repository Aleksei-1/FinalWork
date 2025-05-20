#include "stdio.h"
#include "conio.h"

unsigned char a, c, d, e, h;  
signed char b;                
unsigned char num, j;

struct troyka {
    short func;              
    signed char arg;         
    unsigned char i;          
};

troyka mass[5];  

void main() {
    a = 10;                   
    b = 2;                    
    c = 3;
    d = 4;
    e = 2;
    h = 2;                    
    num = 1;                   

    _asm {
        push eax;
        push ecx;
        push ebx;
        push edx;

        mov cx, 5;     
        lea edx, mass  

            for_begin :
      
        mov al, a    
            imul ax, ax    
            imul ax, 36    
            add ax, bx     

            mov word ptr[edx], ax  
            mov word ptr[edx], ax  
            mov byte ptr[edx + 2], al  

            inc num

            mov al, h      
            add a, al      

            add edx, 4     

            loop for_begin; 

        pop edx;
        pop eax;
        pop ecx;
        pop ebx;
    }

    printf(" +-------+-------+----------------+\n");
    for (j = 0; j < 5; j++) {
        printf(" |   %3hd   |   %3d    |    %3d    |\n", mass[j].func, mass[j].arg, mass[j].i);
        printf(" +-------+-------+----------------+\n");
    }

    _getch();
}