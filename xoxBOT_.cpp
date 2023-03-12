//
//  main.c
//  TIC-TAC-TOE
//
//  Created by Batuhan Toraman, Kasim Taha Karagoz, Metin Eren Oktay
//  Copyright © 2020. All rights reserved.
//

// Included libraries and defined arrays:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
char SQUARE[10] = { 'q', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

//Function Prototypes
void DrawBoard (void);
int CheckX (void);
int CheckO (void);
int AIplay (char SQUARE[10], int level, int start);
bool LegalMoveCheck (char SQUARE[10]);
int GiveScore (char SQUARE[10], int start);
int minimax (char SQUARE[10], int Depth, bool MAX, int start);
int MakeBestMove (char SQUARE[10], int start);

// Main Function
int main ()
{
    setlocale( LC_ALL, "Turkish");
    int lang = 0;
    printf ("Enter 1 for English\nTürkçe için 2 giriniz\n");
    scanf ("%d", &lang);
    fflush (stdin);
    int Play = 1;
    while (Play == 1)
    {
        Play = 0;
        unsigned int opponent = 0, level = 0, result = 0, turn = 1, number1 = 0 , number2 = 0;
        int start = 0;
        char X = X;
        char O = O;
        SQUARE[1] = '1';
        SQUARE[2] = '2';
        SQUARE[3] = '3';
        SQUARE[4] = '4';
        SQUARE[5] = '5';
        SQUARE[6] = '6';
        SQUARE[7] = '7';
        SQUARE[8] = '8';
        SQUARE[9] = '9';
        
        if (lang == 1)
        {
            printf ("\n\n\nWelcome to Tic-Tac-Toe The Game...\nTic-Tac-Toe, aka noughts and crosses, is a dual-player 3x3 board game\nin which players take turns and aim to complete a row , a column, or a diagonal\nwith either three O's or three X's in the spaces of a grid of nine squares.\n\n");
            printf ("INSTRUCTIONS:\nThe first player is known as X and the second is O.\nThe two players alternate placing X's and O's on the game board until either has three in a row, a column or a diagonal or all nine squares are filled.\nX always goes first. In the event that no one has three in a row, it is a tie.\n\n\n");
            printf("Whom do you want to play with? Enter 1 for vs another player, 2 for vs computer\n");
        }
        else if (lang == 2)
        {
            printf("\n\n\nXOX Oyununa Hoş Geldiniz...\nXOX 2 kişilik, 3x3 bir tahtada oynanan tur bazlı bir oyundur.\n\n TALİMATLAR:\nBirinci oyuncu X, ikinci oyuncu O karakterini kullanır.\nOyuncular; dokuz karelik bir tahtada, sırayla, bir satırı, bir sütunu veya çapraz bir sırayı aynı karakterlerle doldurmaya çalışırlar.\nEğer her iki oyuncu da bir sıra, sütün veya çapraz sıra oluşturmayı başaramazsa oyun beraberlikle sonlanır.\nKiminle oynamak istersiniz? Başka bir oyuncu ile oynamak için 1, bilgisayara karşı oynamak için 2 giriniz.\n");
        }
        
        while (opponent == 0)
        {
            scanf ("%d", &opponent);
            fflush (stdin);
            if (opponent > 2)
            {
                opponent = 0;
                if (lang == 1)
                {
                    printf ("Please insert a valid choice\n");
                }
                else if (lang == 2)
                {
                    printf("Lütfen geçerli bir karakter giriniz\n");
                }
            }
            else if (opponent == 0)
            {
                if (lang == 1)
                {
                    printf ("Please insert a valid choice\n");
                }
                else if (lang == 2)
                {
                    printf("Lütfen geçerli bir karakter giriniz\n");
                }
            }
        }
        
        if (opponent==1)
        {
            DrawBoard ();
            while (result == 0)
            {
                while (turn == 1)
                {
                    if (lang == 1)
                    {
                        printf("Player 1, enter the number of a square to place your X.\n");
                    }
                    else if (lang == 2)
                    {
                        printf("Oyuncu 1, X yerleştirmek istediğiniz karenin numarasını giriniz.\n");
                    }
                    
                    scanf("%d", &number1);
                    fflush(stdin);
                    if (number1 == 1 && SQUARE[1] == '1')
                        SQUARE[1] = 'X';
                    else if (number1 == 2 && SQUARE[2] == '2')
                        SQUARE[2] = 'X';
                    else if (number1 == 3 && SQUARE[3] == '3')
                        SQUARE[3] = 'X';
                    else if (number1 == 4 && SQUARE[4] == '4')
                        SQUARE[4] = 'X';
                    else if (number1 == 5 && SQUARE[5] == '5')
                        SQUARE[5] = 'X';
                    else if (number1 == 6 && SQUARE[6] == '6')
                        SQUARE[6] = 'X';
                    else if (number1 == 7 && SQUARE[7] == '7')
                        SQUARE[7] = 'X';
                    else if (number1 == 8 && SQUARE[8] == '8')
                        SQUARE[8] = 'X';
                    else if (number1 == 9 && SQUARE[9] == '9')
                        SQUARE[9] = 'X';
                    else
                    {
                        if (lang == 1)
                        {
                            printf ("Please make a valid move.\n");
                        }
                        else if (lang == 2)
                        {
                            printf("Lütfen geçerli bir hamle yapınız.\n");
                        }
                        break;
                    }
                    DrawBoard ();
                    result = CheckX ();
                    if (result != 0)
                    {
                        break;
                    }
                    turn++;
                }
                
                while (turn==2)
                {
                    if (lang == 1)
                    {
                        printf("Player 2, enter the number of a square to place your O.\n");
                    }
                    else if (lang == 2)
                    {
                        printf("Oyuncu 2, O yerleştirmek istediğiniz karenin numarasını giriniz.\n");
                    }
                    scanf ("%d", &number2);
                    fflush (stdin);
                    if (number2 == 1 && SQUARE[1] == '1')
                        SQUARE[1] = 'O';
                    else if (number2 == 2 && SQUARE[2] == '2')
                        SQUARE[2] = 'O';
                    else if (number2 == 3 && SQUARE[3] == '3')
                        SQUARE[3] = 'O';
                    else if (number2 == 4 && SQUARE[4] == '4')
                        SQUARE[4] = 'O';
                    else if (number2 == 5 && SQUARE[5] == '5')
                        SQUARE[5] = 'O';
                    else if (number2 == 6 && SQUARE[6] == '6')
                        SQUARE[6] = 'O';
                    else if (number2 == 7 && SQUARE[7] == '7')
                        SQUARE[7] = 'O';
                    else if (number2 == 8 && SQUARE[8] == '8')
                        SQUARE[8] = 'O';
                    else if (number2 == 9 && SQUARE[9] == '9')
                        SQUARE[9] = 'O';
                    else
                    {
                        if (lang == 1)
                        {
                            printf ("Please make a valid move.\n");
                        }
                        else if (lang == 2)
                        {
                            printf("Lütfen geçerli bir hamle yapınız.\n");
                        }

                        break;
                    }
                    DrawBoard ();
                    result = CheckO ();
                    if (result != 0)
                    {
                        break;
                    }
                    turn--;
                }
            }
            
            if (result == 1)
            {
                if (lang == 1)
                {
                    printf ("PLAYER 1 WINS!!!\n");
                }
                else if (lang == 2)
                {
                    printf("OYUNCU 1 KAZANDI!!!\n");
                }
            }
            else if (result == 2)
            {
                if (lang == 1)
                {
                    printf ("PLAYER 2 WINS!!!\n");
                }
                else if (lang == 2)
                {
                    printf("OYUNCU 2 KAZANDI!!!\n");
                }
            }

            else if (result == 3)
            {
                if (lang == 1)
                {
                    printf ("IT IS A TIE!!!\n");
                }
                else if (lang == 2)
                {
                    printf("SONUÇ BERABERE!!!\n");
                }
            }
        }
        else if (opponent == 2)
        {
            if (lang == 1)
            {
                printf ("Select a difficulty\nEnter 1 for Easy, 2 for Medium, 3 for Expert\n");
            }
            else if (lang == 2)
            {
                printf("Bir zorluk derecesi seçiniz\nKolay için 1, Orta için 2, Uzman için 3 giriniz\n");
            }
            
            while (level == 0)
            {
                scanf ("%d", &level);
                fflush (stdin);
                if (level > 3)
                {
                    level = 0;
                    
                }
                else if (level == 0)
                {
                    if (lang == 1)
                    {
                        printf ("Please make a valid move.\n");
                    }
                    else if (lang == 2)
                    {
                        printf("Lütfen geçerli bir hamle yapınız.\n");
                    }
                }
            }
            if (level == 1)
            {
                if (lang == 1)
                {
                    printf("You chose easy\n\n");
                }
                else if (lang == 2)
                {
                    printf("Kolay seçtiniz\n\n");
                }
            }
            if (level == 2)
            {
                if (lang == 1)
                {
                    printf("You chose medium\n\n");
                }
                else if (lang == 2)
                {
                    printf("Orta seçtiniz\n\n");
                }
            }
            if (level == 3)
            {
                if (lang == 1)
                {
                    printf("You chose expert\n\n");
                }
                else if (lang == 2)
                {
                    printf("Uzman seçtiniz\n\n");
                }
            }
                       
            if (lang == 1)
            {
                 printf ("Choose the character you want to play by entering 1 for X and 2 for O\n");
            }
            else if (lang == 2)
            {
                 printf ("Oynamak istediğiniz karakteri seçiniz. X için 1, O için 2 giriniz\n");
            }
           
            while (start == 0 )
            {
                scanf ("%d", &start );
                fflush (stdin);
                if (start > 2)
                {
                    start = 0;
                    if (lang == 1)
                    {
                        printf ("Please insert a valid choice\n");
                    }
                    else if (lang == 2)
                    {
                        printf("Lütfen geçerli bir karakter giriniz\n");
                    }
                }
                else if (start == 0)
                {
                    if (lang == 1)
                    {
                        printf ("Please insert a valid choice\n");
                    }
                    else if (lang == 2)
                    {
                        printf("Lütfen geçerli bir karakter giriniz\n");
                    }
                }
            }
            DrawBoard ();
                       
            while (result == 0 && start == 1)
            {
                while (turn == 1)
                {
                    if (lang == 1)
                    {
                        printf("Player 1, enter the number of a square to place your X.\n");
                    }
                    else if (lang == 2)
                    {
                        printf("Oyuncu 1, X yerleştirmek istediğiniz karenin numarasını giriniz.\n");
                    }
                    scanf("%d", &number1);
                    fflush(stdin);
                    if (number1 == 1 && SQUARE[1] == '1')
                        SQUARE[1] = 'X';
                    else if (number1 == 2 && SQUARE[2] == '2')
                        SQUARE[2] = 'X';
                    else if (number1 == 3 && SQUARE[3] == '3')
                        SQUARE[3] = 'X';
                    else if (number1 == 4 && SQUARE[4] == '4')
                        SQUARE[4] = 'X';
                    else if (number1 == 5 && SQUARE[5] == '5')
                        SQUARE[5] = 'X';
                    else if (number1 == 6 && SQUARE[6] == '6')
                        SQUARE[6] = 'X';
                    else if (number1 == 7 && SQUARE[7] == '7')
                        SQUARE[7] = 'X';
                    else if (number1 == 8 && SQUARE[8] == '8')
                        SQUARE[8] = 'X';
                    else if (number1 == 9 && SQUARE[9] == '9')
                        SQUARE[9] = 'X';
                    else
                    {
                        if (lang == 1)
                        {
                            printf ("Please make a valid move.\n");
                        }
                        else if (lang == 2)
                        {
                            printf("Lütfen geçerli bir hamle yapınız.\n");
                        }
                        break;
                    }
                    DrawBoard ();
                    result = CheckX ();
                    if (result != 0)
                    {
                        break;
                    }
                    turn++;
                               
                }
                while (turn == 2)
                {
                    number2 = AIplay (SQUARE, level, start);
                    if (number2 == 1 && SQUARE[1] == '1')
                        SQUARE[1] = 'O';
                    else if (number2 == 2 && SQUARE[2] == '2')
                        SQUARE[2] = 'O';
                    else if (number2 == 3 && SQUARE[3] == '3')
                        SQUARE[3] = 'O';
                    else if (number2 == 4 && SQUARE[4] == '4')
                        SQUARE[4] = 'O';
                    else if (number2 == 5 && SQUARE[5] == '5')
                        SQUARE[5] = 'O';
                    else if (number2 == 6 && SQUARE[6] == '6')
                        SQUARE[6] = 'O';
                    else if (number2 == 7 && SQUARE[7] == '7')
                        SQUARE[7] = 'O';
                    else if (number2 == 8 && SQUARE[8] == '8')
                        SQUARE[8] = 'O';
                    else if (number2 == 9 && SQUARE[9] == '9')
                        SQUARE[9] = 'O';
                    else
                        break;
                    DrawBoard ();
                    result = CheckO ();
                    if (result != 0)
                    {
                        break;
                    }
                    turn--;
                }
            }
            if (result == 1 && start == 1)
                {
                    if (lang == 1)
                    {
                        printf ("CONGRATULATIONS YOU WIN!!!\n");
                    }
                    else if (lang == 2)
                    {
                        printf("TEBRİKLER KAZANDINIZ!!!\n");
                    }
                }
            else if (result == 2 && start ==1 )
                {
                    if (lang == 1)
                    {
                        printf ("SORRY YOU LOSE:(\n");
                    }
                    else if (lang == 2)
                    {
                        printf("MAALESEF KAYBETTİNİZ:(\n");
                    }
                }
            else if (result == 3 && start == 1)
                {
                    if (lang == 1)
                    {
                        printf ("IT IS A TIE!!!\n");
                    }
                    else if (lang == 2)
                    {
                        printf("SONUÇ BERABERE!!!\n");
                    }
                }
            
            while (result == 0 && start == 2)
            {
                while (turn == 1)
                {
                    number1 = AIplay (SQUARE, level, start);
                    if (number1 == 1 && SQUARE[1] == '1')
                        SQUARE[1] = 'X';
                    else if (number1 == 2 && SQUARE[2] == '2')
                        SQUARE[2] = 'X';
                    else if (number1 == 3 && SQUARE[3] == '3')
                        SQUARE[3] = 'X';
                    else if (number1 == 4 && SQUARE[4] == '4')
                        SQUARE[4] = 'X';
                    else if (number1 == 5 && SQUARE[5] == '5')
                        SQUARE[5] = 'X';
                    else if (number1 == 6 && SQUARE[6] == '6')
                        SQUARE[6] = 'X';
                    else if (number1 == 7 && SQUARE[7] == '7')
                        SQUARE[7] = 'X';
                    else if (number1 == 8 && SQUARE[8] == '8')
                        SQUARE[8] = 'X';
                    else if (number1 == 9 && SQUARE[9] == '9')
                        SQUARE[9] = 'X';
                    else
                        break;
                    DrawBoard ();
                    result = CheckX();
                    if (result != 0)
                    {
                        break;
                    }
                    turn++;
                }
                while (turn==2)
                {
                    if (lang == 1)
                    {
                        printf("Enter the number of a square to place your O.\n");
                    }
                    else if (lang == 2)
                    {
                        printf("O yerleştirmek istediğiniz karenin numarasını giriniz.\n");
                    }
                    scanf ("%d", &number2);
                    fflush (stdin);
                    if (number2 == 1 && SQUARE[1] == '1')
                        SQUARE[1] = 'O';
                    else if (number2 == 2 && SQUARE[2] == '2')
                        SQUARE[2] = 'O';
                    else if (number2 == 3 && SQUARE[3] == '3')
                        SQUARE[3] = 'O';
                    else if (number2 == 4 && SQUARE[4] == '4')
                        SQUARE[4] = 'O';
                    else if (number2 == 5 && SQUARE[5] == '5')
                        SQUARE[5] = 'O';
                    else if (number2 == 6 && SQUARE[6] == '6')
                        SQUARE[6] = 'O';
                    else if (number2 == 7 && SQUARE[7] == '7')
                        SQUARE[7] = 'O';
                    else if (number2 == 8 && SQUARE[8] == '8')
                        SQUARE[8] = 'O';
                    else if (number2 == 9 && SQUARE[9] == '9')
                        SQUARE[9] = 'O';
                    else
                    {
                        if (lang == 1)
                        {
                            printf ("Please make a valid move.\n");
                        }
                        else if (lang == 2)
                        {
                            printf("Lütfen geçerli bir hamle yapınız.\n");
                        }
                        break;
                    }
                    DrawBoard ();
                    result = CheckO ();
                    if (result != 0)
                    {
                        break;
                    }
                    turn--;
                }
            }
            if (result == 2 && start == 2)
            {
                if (lang == 1)
                {
                    printf ("CONGRATULATIONS YOU WIN!!!\n");
                }
                else if (lang == 2)
                {
                    printf("TEBRİKLER KAZANDINIZ!!!\n");
                }
            }
            else if (result == 1 && start == 2)
            {
                if (lang == 1)
                {
                    printf ("SORRY YOU LOSE:(\n");
                }
                else if (lang == 2)
                {
                    printf("MAALESEF KAYBETTİNİZ:(\n");
                }
            }
            else if (result == 3 && start == 2)
            {
                if (lang == 1)
                {
                    printf ("IT IS A TIE!!!\n");
                }
                else if (lang == 2)
                {
                    printf("SONUÇ BERABERE!!!\n");
                }
            }
        }
    
        while (Play == 0)
        {
            if (lang == 1)
            {
                printf ("Do you want to play again?\nEnter 1 to restart, 2 to exit\n");
            }
            else if (lang == 2)
            {
                printf ("Tekrar oynamak ister misiniz?\nYeniden başlatmak için 1, çıkış yapmak için 2 giriniz\n");
            }
            
            scanf ("%d", &Play);
            fflush (stdin);
            if (Play > 2)
            {
                Play = 0;
                if (lang == 1)
                {
                    printf ("Please insert a valid choice\n");
                }
                else if (lang == 2)
                {
                    printf("Lütfen geçerli bir karakter giriniz\n");
                }
            }
            else if (Play == 0)
            {
                if (lang == 1)
                {
                    printf ("Please insert a valid choice\n");
                }
                else if (lang == 2)
                {
                    printf("Lütfen geçerli bir karakter giriniz\n");
                }
            }
        }
        
    }
    exit(0);
    return 0;
}


//Defined functions
void DrawBoard ()
{
    printf(" _________________\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", SQUARE[1], SQUARE[2], SQUARE[3]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", SQUARE[4], SQUARE[5], SQUARE[6]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", SQUARE[7], SQUARE[8], SQUARE[9]);
    printf("|_____|_____|_____|\n");
}
int CheckX ()
{
    if (SQUARE[1] == SQUARE[2] && SQUARE[2] == SQUARE[3])
        return 1;
        
    else if (SQUARE[4] == SQUARE[5] && SQUARE[5] == SQUARE[6])
        return 1;
        
    else if (SQUARE[7] == SQUARE[8] && SQUARE[8] == SQUARE[9])
        return 1;
        
    else if (SQUARE[1] == SQUARE[4] && SQUARE[4] == SQUARE[7])
        return 1;
        
    else if (SQUARE[2] == SQUARE[5] && SQUARE[5] == SQUARE[8])
        return 1;
        
    else if (SQUARE[3] == SQUARE[6] && SQUARE[6] == SQUARE[9])
        return 1;
        
    else if (SQUARE[1] == SQUARE[5] && SQUARE[5] == SQUARE[9])
        return 1;
        
    else if (SQUARE[3] == SQUARE[5] && SQUARE[5] == SQUARE[7])
        return 1;
        
    else if (SQUARE[1] != '1' && SQUARE[2] != '2' && SQUARE[3] != '3'
             && SQUARE[4] != '4' && SQUARE[5] != '5' && SQUARE[6] != '6'
             && SQUARE[7] != '7' && SQUARE[8] != '8' && SQUARE[9] != '9')
        return 3;
    else
        return 0;
}
int CheckO ()
{
    if (SQUARE[1] == SQUARE[2] && SQUARE[2] == SQUARE[3])
        return 2;
        
    else if (SQUARE[4] == SQUARE[5] && SQUARE[5] == SQUARE[6])
        return 2;
        
    else if (SQUARE[7] == SQUARE[8] && SQUARE[8] == SQUARE[9])
        return 2;
        
    else if (SQUARE[1] == SQUARE[4] && SQUARE[4] == SQUARE[7])
        return 2;
        
    else if (SQUARE[2] == SQUARE[5] && SQUARE[5] == SQUARE[8])
        return 2;
        
    else if (SQUARE[3] == SQUARE[6] && SQUARE[6] == SQUARE[9])
        return 2;
        
    else if (SQUARE[1] == SQUARE[5] && SQUARE[5] == SQUARE[9])
        return 2;
        
    else if (SQUARE[3] == SQUARE[5] && SQUARE[5] == SQUARE[7])
        return 2;
        
    else if (SQUARE[1] != '1' && SQUARE[2] != '2' && SQUARE[3] != '3'
             && SQUARE[4] != '4' && SQUARE[5] != '5' && SQUARE[6] != '6'
             && SQUARE[7] != '7' && SQUARE[8] != '8' && SQUARE[9] != '9')
        return 3;
    else
        return 0;
}
int AIplay (char SQUARE[10], int level, int start)
{
    
    if (level == 1)
    {
        int x;
        srand (time (0));
        x = (rand () % 9 + 1);
        return x;
    }
    if (level == 2)
    {
        char AI = (start == 1) ? 'O' : 'X';
        int z = 0;
        if(SQUARE[5] == '5')
            z = 5;
        else if(SQUARE[1] == SQUARE[2] && SQUARE[2] == AI && SQUARE[3] == '3')
            z = 3;
        else if(SQUARE[1] == SQUARE[3] && SQUARE[3] == AI && SQUARE[2] == '2')
            z = 2;
        else if(SQUARE[2] == SQUARE[3] && SQUARE[3] == AI && SQUARE[1] == '1')
            z = 1;
        else if(SQUARE[4] == SQUARE[5] && SQUARE[5] == AI && SQUARE[6] == '6')
            z = 6;
        else if(SQUARE[4] == SQUARE[6] && SQUARE[6] == AI && SQUARE[5] == '5')
            z = 5;
        else if(SQUARE[5] == SQUARE[6] && SQUARE[6] == AI && SQUARE[4] == '4')
            z = 4;
        else if(SQUARE[7] == SQUARE[8] && SQUARE[8] == AI && SQUARE[9] == '9')
            z = 9;
        else if(SQUARE[7] == SQUARE[9] && SQUARE[9] == AI && SQUARE[8] == '9')
            z = 8;
        else if(SQUARE[8] == SQUARE[9] && SQUARE[9] == AI && SQUARE[7] == '7')
            z = 7;
        else if(SQUARE[1] == SQUARE[4] && SQUARE[4] == AI && SQUARE[7] == '7')
            z = 7;
        else if(SQUARE[1] == SQUARE[7] && SQUARE[7] == AI && SQUARE[4] == '4')
            z = 4;
        else if(SQUARE[4] == SQUARE[7] && SQUARE[7] == AI && SQUARE[1] == '1')
            z = 1;
        else if(SQUARE[2] == SQUARE[5] && SQUARE[5] == AI && SQUARE[8] == '8')
            z = 8;
        else if(SQUARE[2] == SQUARE[8] && SQUARE[8] == AI && SQUARE[5] == '5')
            z = 5;
        else if(SQUARE[5] == SQUARE[8] && SQUARE[8] == AI && SQUARE[2] == '2')
            z = 2;
        else if(SQUARE[3] == SQUARE[6] && SQUARE[6] == AI && SQUARE[9] == '9')
            z = 9;
        else if(SQUARE[3] == SQUARE[9] && SQUARE[9] == AI && SQUARE[6] == '6')
            z = 6;
        else if(SQUARE[6] == SQUARE[9] && SQUARE[9] == AI && SQUARE[3] == '3')
            z = 3;
        else if(SQUARE[1] == SQUARE[5] && SQUARE[5] == AI && SQUARE[9] == '9')
            z = 9;
        else if(SQUARE[1] == SQUARE[9] && SQUARE[9] == AI && SQUARE[5] == '5')
            z = 5;
        else if(SQUARE[5] == SQUARE[9] && SQUARE[9] == AI && SQUARE[1] == '1')
            z = 1;
        else if(SQUARE[3] == SQUARE[5] && SQUARE[5] == AI && SQUARE[7] == '7')
            z = 7;
        else if(SQUARE[3] == SQUARE[7] && SQUARE[7] == AI && SQUARE[5] == '5')
            z = 5;
        else if(SQUARE[5] == SQUARE[7] && SQUARE[7] == AI && SQUARE[3] == '3')
            z = 3;
        else
        {
            srand (time (0));
            z = (rand () % 9 + 1);
        }
        return z;
    }
    if (level == 3 )
    {
        int y;
        y = MakeBestMove (SQUARE, start);
        return y;
    }
    return 0;
}
bool LegalMoveCheck (char SQUARE[10])
{
    for (int i = 1; i < 10; i++)
    {
        if (SQUARE[i] == i + '0')
        return true;
    }
    return false;
}
int GiveScore (char SQUARE[10], int start)
{
    char AI = (start == 1) ? 'O' : 'X';
    char Player = (start == 1) ? 'X' : 'O';

    if (SQUARE[1] == SQUARE[2] && SQUARE[2] == SQUARE[3] && SQUARE[3] == AI)
         return 10;
         
    else if (SQUARE[4] == SQUARE[5] && SQUARE[5] == SQUARE[6] && SQUARE[6] == AI)
        return 10;
        
    else if (SQUARE[7] == SQUARE[8] && SQUARE[8] == SQUARE[9] && SQUARE[9] == AI)
        return 10;
        
    else if (SQUARE[1] == SQUARE[4] && SQUARE[4] == SQUARE[7] && SQUARE[7] == AI)
        return 10;
        
    else if (SQUARE[2] == SQUARE[5] && SQUARE[5] == SQUARE[8] && SQUARE[8] == AI)
        return 10;
        
    else if (SQUARE[3] == SQUARE[6] && SQUARE[6] == SQUARE[9] && SQUARE[9] == AI)
        return 10;
        
    else if (SQUARE[1] == SQUARE[5] && SQUARE[5] == SQUARE[9] && SQUARE[9] == AI)
        return 10;
        
    else if (SQUARE[3] == SQUARE[5] && SQUARE[5] == SQUARE[7] && SQUARE[7] == AI)
        return 10;
        
    else if (SQUARE[1] == SQUARE[2] && SQUARE[2] == SQUARE[3] && SQUARE[3] == Player)
         return -10;
        
    else if (SQUARE[4] == SQUARE[5] && SQUARE[5] == SQUARE[6] && SQUARE[6] == Player)
        return -10;
        
    else if (SQUARE[7] == SQUARE[8] && SQUARE[8] == SQUARE[9] && SQUARE[9] == Player)
        return -10;
        
    else if (SQUARE[1] == SQUARE[4] && SQUARE[4] == SQUARE[7] && SQUARE[7] == Player)
        return -10;
        
    else if (SQUARE[2] == SQUARE[5] && SQUARE[5] == SQUARE[8] && SQUARE[8] == Player)
        return -10;
        
    else if (SQUARE[3] == SQUARE[6] && SQUARE[6] == SQUARE[9]&& SQUARE[9] == Player)
        return -10;
        
    else if (SQUARE[1] == SQUARE[5] && SQUARE[5] == SQUARE[9] && SQUARE[9] == Player)
        return -10;
        
    else if (SQUARE[3] == SQUARE[5] && SQUARE[5] == SQUARE[7] && SQUARE[7] == Player)
        return -10;
             
    else return 0;
}
int minimax (char SQUARE[10], int Depth, bool Maximizer, int start)
{
    char AI = (start == 1) ? 'O' : 'X';
    char Player = (start == 1) ? 'X' : 'O';


    int score = GiveScore (SQUARE, start);
    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (LegalMoveCheck (SQUARE) == false)
        return 0;
    if (Maximizer)
    {
        int Best = -1000;
        for (int i = 1; i < 10 ; i++)
        {
            if (SQUARE[i] == i + '0')
            {
                SQUARE[i] = AI;
                Best = MAX (Best, minimax (SQUARE, Depth+1, !Maximizer, start));
                SQUARE[i] = i + '0';
            }
        }
        return Best;
    }
    else
    {
        int Best = 1000;
        for(int i = 1; i < 10; i++)
        {
            if (SQUARE[i] == i + '0')
            {
                SQUARE[i] = Player;
                Best = MIN( Best, minimax(SQUARE, Depth+1, !Maximizer, start));
                SQUARE[i] = i + '0';
            }
        }
    return Best;
    }
}
int MakeBestMove (char SQUARE[10], int start)
{
    char AI = (start == 1) ? 'O' : 'X';
    int BestValue = -1000;
    int OptimalMove = -1;
    for (int i = 1; i < 10; i++)
    {
        if (SQUARE[i] == i + '0')
        {
            SQUARE[i] = AI;
            int MoveValue = minimax (SQUARE, 0, false, start);
            SQUARE[i] = i + '0';
            if (MoveValue > BestValue)
            {
                OptimalMove = i;
                BestValue = MoveValue;
            }
        }
    }
    return OptimalMove;
}
