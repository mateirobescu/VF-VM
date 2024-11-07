#include <stdio.h>

int byte[8];

void print_byte()
{
    for(int i = 0; i < 8; i++)
        printf("%d", byte[i]);
}

int main(int argc, const char * argv[])
{
    printf("=====MENIU=====\n");
    printf("  1 --> VF: CD, CI, CC\n");
    printf("  2 --> VM: SP\n");
    printf("$>");
    
    
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        printf("Introduceti un numar intreg din intervalul [-127, 127]: ");
        int nr;
        scanf("%d", &nr);
        int cpy = nr;
        
        
        if (nr >= 0)
            byte[0] = 0;
        else
        {
            byte[0] = 1;
            cpy *= -1;
        }
        
        int i = 7;
        while (cpy)
        {
            byte[i] = cpy % 2;
            cpy /= 2;
            i--;
        }
        
        printf(" B10 |    CD    |    CI    |    CC    \n");
        if(nr >= 0)
            printf(" ");
        printf("%d", nr);
        if(nr / 100 == 0)
            printf(" ");
        if(nr / 10 == 0)
            printf(" ");
        
        printf(" | ");
        print_byte();
        printf(" | ");
        
        if(nr < 0)
            for(int i = 1; i < 8; i++)
                byte[i] = byte[i] ^ 1;
        
        print_byte();
        
        printf(" | ");
        
        if(nr < 0)
        {
            int k = 7;
            while (byte[k] == 1)
            {
                byte[k] = 0;
                k--;
            }
            byte[k] = 1;
        }
        
        print_byte();
        
        printf("\n");
        
    }
    else if(choice == 2)
    {
        
    }
    else
        printf("Optiunea nu exista!");
    
    
    return 0;
}

