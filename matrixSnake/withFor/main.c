#define SIZE ( 13 )

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mas[ SIZE * SIZE ];

    rec_put( mas, SIZE, SIZE, 1 );
    out( mas, SIZE );

}

void rec_put( int *mas, int size, int size_MAX, int digit )
{
    int i;
    int pos, line;

    if( size == 1 )
    {
        mas[ 0 ] = digit;
        return 0;
    }
    if( size == 2 )
    {
        mas[ 0 ] = digit++;
        mas[ 1 ] = digit++;
        mas[ 1 + size_MAX ] = digit++;
        mas[ size_MAX ] = digit;
        return 0;
    }
    putTop( mas, size, size_MAX, &digit );//filling the top side of the square
    putRight( mas, size, size_MAX, &digit );//filling the right side of the square
    putBottom( mas, size, size_MAX, &digit );//filling the bottom side of the square
    putLeft( mas, size, size_MAX, &digit );//filling the left side of the square

    rec_put( mas + size_MAX + 1, size - 2, size_MAX, digit );
}

void out( int *mas, int size )
{
    int i = 0;

    for( i = 0; i < size * size; i++ )
    {
        printf( "%6i", mas[ i ] );
        if( ( i + 1 ) % size == 0 )
            printf( "\n" );
    }
}

void putRight( int *mas, int size, int size_MAX, int *digit )
{
    int i;
    int line, pos;

    for( i = 0; i < size - 1; i++ )//filling the right side of the square
    {
        line = i + 2;
        pos = size - 1 + size_MAX * ( line - 1 );
        mas[ pos ] = *digit;
        ( *digit )++;
    }
}

void putLeft( int *mas, int size, int size_MAX, int *digit )
{
    int i;
    int line, pos;

    for( i = 0; i < size - 2; i++ )//filling the left side of the square
    {
        line = size - i - 1;
        pos = ( line - 1 ) * size_MAX ;
        mas[ pos ] = *digit;
        ( *digit )++;
    }
}

void putTop( int *mas, int size, int size_MAX, int *digit )
{
    int i;
    int pos;

    for( i = 0; i < size; i++ )//filling the top side of the square
    {
        pos = i;
        mas[ pos ] = *digit;
        ( *digit )++;
    }
}

void putBottom( int *mas, int size, int size_MAX, int *digit )
{
    int i;
    int pos;

    for( i = 0; i < size - 1; i++ )//filling the bottom side of the square
    {
        pos = ( size_MAX + 1 )* ( size - 1) - 1 - i ;
        mas[ pos ] = *digit;
        ( *digit )++;
    }
}
