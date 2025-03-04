#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct mail {
    char subj[50] ;
    char name[50] ;
    char adre[50] ;
    char room[50] ;
}   mail ;
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
int main() {

    mail out  ;
    int oe = 0 ;
    //////////////////////// - open files with error handling - /////////////
    FILE *f_in  = fopen("IN.txt" , "r");
    FILE *f_out = fopen("OUT.txt", "w");
    FILE *f_bin1 = fopen("INBINA.bin", "wb+");
    //
    if ( f_in == NULL ) {
        fprintf( f_out , "IN.txt is empty");
        return 1;
    }
    //////////////////////////////////////////////////////////////////////////
    while ( fgets( out.subj , sizeof(out.subj) , f_in ) != NULL ) {
        out.subj[strlen(out.subj)-1] = '\0' ;
        //
        fgets( out.name , sizeof(out.name) , f_in ) ;
        out.name[strlen(out.name)-1] = '\0' ;
        //
        fgets( out.adre , sizeof(out.adre) , f_in ) ;
        out.adre[strlen(out.adre)-1] = '\0' ;
        //
        fgets( out.room , sizeof(out.room) , f_in ) ;
        out.room[strlen(out.room)-1] = '\0' ;
        //
        fwrite(&out , 1 , sizeof(mail) , f_bin1 ) ;
    }
    
    //////////////////////// - close 1 - /////////////
    fclose(f_in);
    fclose(f_bin1);

    // Print from bin to out.text
    FILE *f_bin2 = fopen("INBINA.bin", "rb");
    // 
    while (fread(&out, sizeof(mail), 1, f_bin2) == 1) {  
        fprintf( f_out , "Subject: %s\nName: %s\nAddress: %s\nRoom: %s\n\n",
               out.subj, out.name, out.adre, out.room);
    }

    //////////////////////// - close 2 - /////////////
    fclose(f_bin2);
    fclose(f_out);
    return 0;
}




       