#include <stdio.h>

int byte[8];
int vmbytes[32];

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
        printf("Introduceti un numar real: ");
        float nr;
        scanf("%f", &nr);
        
        int pi = (int)nr;
        float pf = nr - pi;
        int exp = 404;
        int ex_exp = 0;
        
        int mantissa[23] = {0};
        int len_m = 0;
        
        
        int cpi = pi;
        if(cpi < 0)
            cpi *= -1;
        
        while(cpi != 1)
        {
            mantissa[len_m++] = cpi % 2;
            cpi /= 2;
        }
        if(len_m > 0)
            exp = len_m;
        
        for(int i = 0; i < len_m / 2; i++)
        {
            mantissa[i] += mantissa[len_m - i - 1];
            mantissa[len_m - i - 1] = mantissa[i] - mantissa[len_m - i - 1];
            mantissa[i] -= mantissa[len_m - i - 1];
        }
        
        for(int i = 0; i < 23; i++)
            printf("%d", mantissa[i]);
        
        printf("\n");
        
        if(pf < 0)
            pf *= -1;
        for(int i = 0; i < 5 && pf; i++)
        {
            pf *= 2;
            mantissa[len_m++] = (int)pf;
            pf -= (int)pf;
        }
        
        if(nr >= 0)
            vmbytes[0] = 0;
        else
            vmbytes[0] = 1;
        
        exp = 127 + exp;
        
        int k = 8;
        while(exp)
        {
            vmbytes[k--] = exp % 2;
            exp /= 2;
        }
        
        for(int i = 0; i < 23; i++)
            vmbytes[i + 9] = mantissa[i];
        
        for(int i = 0; i < 32; i++)
            printf("%d", vmbytes[i]);
        
        
    }
    else
        printf("Optiunea nu exista!");
    
    
    
    return 0;
}

