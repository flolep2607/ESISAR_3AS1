#include <stdio.h>
#include <stdlib.h>

int notesV1(){
    char note;
    printf("Quelle est la note ? Merci de rentrer A, B, C, D ou E.\n");
    scanf("%s", &note);
    if (note == 'A'){
        printf("Très bien\n");
    }
    else if (note == 'B'){
        printf("Bien\n");
    }
    else if (note == 'C'){
        printf("Assez bien\n");
    }
    else if (note == 'D'){
        printf("Passable\n");
    }
    else if (note == 'E'){
        printf("Insuffisant\n");
    }
    else{
        printf("Note invalide, merci de rentrer A, B, C, D ou E.\n");
    }
    return 0;
}

int notesV2(){
    char note;
    printf("Quelle est la note ? Merci de rentrer A, B, C, D ou E.\n");
    scanf("%s", &note);
    switch (note){
        case 'A':
        printf("Très bien\n");
        break;
        case 'B':
        printf("Bien\n");
        break;
        case 'C':
        printf("Assez bien\n");
        break;
        case 'D':
        printf("Passable\n");
        break;
        case 'E':
        printf("Insuffisant\n");
        break;
        default:
        printf("Note invalide, merci de rentrer A, B, C, D ou E.\n");
    }
    return 0;
}

int main(){
    notesV1();
    notesV2();
}