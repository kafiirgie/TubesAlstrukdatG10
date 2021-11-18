#include "boolean.h"
#include "stack.h"
#include <stdlib.h>


void CreateEmpty (Stack *S){
    Top(*S) = Nil;
    
}

boolean IsEmpty (Stack S){
   return Top(S) == Nil;
}
boolean IsFull (Stack S){
    return Top(S) == MaxEl;
}


void Push (Stack * S, infotype X){
    Top(*S)=Top(*S)+1;
    InfoTop(*S)=X;
}


void Pop (Stack * S, infotype* X){
    *X = InfoTop(*S);
    Top(*S)=Top(*S)-1;
}