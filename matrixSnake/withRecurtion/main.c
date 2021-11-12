#define MAX_SIZE ( 5 )

#include <stdio.h>
#include <stdlib.h>

int main()
{
    rec_out( MAX_SIZE, 1, 1 );
}

int per( int size )
{
    return size * 4 - 4;
}

void rec_out( int size, int digit, int line )
{
    if( size > MAX_SIZE )//выход из рекурентной функции
        return 0;

    if( line <= MAX_SIZE / 2 + 1 )//если линия не ниже середины
        printTOP( digit, size );//заполнять линию как верхнюю половину
    else
        printBOTTOM( digit, size );//заполнять линию как нижнюю половину

    if( size == 1 )
        size++;
    if( line < MAX_SIZE / 2 + 1 )//если линия выше середины   ПЕРЕХОД К СЛЕДУЮЩЕМУ УРОВНЮ РЕКУРСИИ
    {
        if( size == MAX_SIZE )//если это первая линия
            rec_out( size - 1, digit + per( size ) - 1, line + 1 );//переход к заполнению верхней части с первой линии
        else
            rec_out( size - 2, digit + per( size - 1 ), line + 1 );//переход к заполнению верхней части
    }
    else if( MAX_SIZE % 2 && line == MAX_SIZE / 2 + 1 )//если у матрицы нечетный размер и линия - средняя
        rec_out( size + 1, digit - 1, line + 1 );//переход к заполнению нижней части со средней линии
    else
        rec_out( size + 2, digit - per( size ) - 2, line + 1 );//переход к заполнению нижней части
}

void rec_lineTOP( int startDigit, int endDigit )
{
    if( endDigit == startDigit )
    {
        printf( "%5i", endDigit );
        return 0;
    }

    rec_lineTOP( startDigit, endDigit - 1 );
    printf( "%5i", endDigit );
}

void rec_beforeTOP( int digit, int size )
{
    if( MAX_SIZE - size < 2 )
        return 0;

    digit -= per( size + 1 ) + 1;

    rec_beforeTOP( digit, size + 2 );
    printf( "%5i", digit );
}

void rec_afterTOP( int digit, int size )
{
    if( digit >= MAX_SIZE && digit <= 2 * MAX_SIZE - 1 )
        printf( "\n" );

    if( MAX_SIZE <= size )
        return 0;

    digit -= per( size ) + 1;
    printf( "%5i", digit );

    rec_afterTOP( digit, size + 2);
}

void rec_lineBOTTOM( int startDigit, int endDigit )
{
    if( endDigit == startDigit )
    {
        printf( "%5i", endDigit );
        return 0;
    }

    printf( "%5i", startDigit );
    rec_lineBOTTOM( startDigit - 1, endDigit );
}

void rec_beforeBOTTOM( int digit, int size )
{
    if( MAX_SIZE - size < 2 )
        return 0;

    digit -= per( size ) + 1;

    rec_beforeBOTTOM( digit, size + 2 );
    printf( "%5i", digit );
}

void rec_afterBOTTOM( int digit, int size )
{
    if( digit >= MAX_SIZE && digit <= 2 * MAX_SIZE - 1 )
        printf( "\n" );

    if( MAX_SIZE <= size )
        return 0;

    digit -= per( size + 1 ) + 1;
    printf( "%5i", digit );

    rec_afterBOTTOM( digit, size + 2);
}

void printTOP( int digit, int size )
{
    rec_beforeTOP( digit, size );
    rec_lineTOP( digit, digit + size - 1 );
    rec_afterTOP( digit + size - 1, size );
}

void printBOTTOM( int digit, int size )
{
    rec_beforeBOTTOM( digit, size );
    rec_lineBOTTOM( digit, digit - size + 1 );
    rec_afterBOTTOM( digit - size + 1, size );
}



