#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdptArray.h"
typedef struct AdptArray_{
    int size;
    PElement *arrElemens;
    COPY_FUNC cf;
    DEL_FUNC df;
    PRINT_FUNC pf;

}AdptArray;
//A function that initializes an empty array (that is, without members).

PAdptArray CreateAdptArray(COPY_FUNC cf, DEL_FUNC df,PRINT_FUNC pf)
{
    PAdptArray newADPt=(PAdptArray)malloc(sizeof(AdptArray));
    if(newADPt==NULL){
        return NULL;
    }
    newADPt->size=0;
    newADPt->cf=cf;
    newADPt->df=df;
    newADPt->pf=pf;
    newADPt->arrElemens=NULL;
    return newADPt;

}
//A function that frees the object's memory (including its members).
void DeleteAdptArray(PAdptArray pAdptArray){
    for (int i = 0; i < pAdptArray->size; i++)
    {
        if (pAdptArray->arrElemens[i]!=NULL)
        {
            pAdptArray->df(pAdptArray->arrElemens[i]);
        }
        
    }
    free(pAdptArray->arrElemens);
    free(pAdptArray);

}

//A function that receives an index and a member and saves a copy of the member in the requested location.
  //Frees the old member if it exists.
Result SetAdptArrayAt(PAdptArray pAdptArray, int n, PElement pElement){
    if(n<pAdptArray->size){
        if (pAdptArray->arrElemens[n]==NULL)
        {
            
            pAdptArray->arrElemens[n]=pAdptArray->cf(pElement);
            return SUCCESS;
        }else{
            if(pAdptArray->arrElemens[n]!=NULL){
                pAdptArray->df(pAdptArray->arrElemens[n]);
                pAdptArray->arrElemens[n]=pAdptArray->cf(pElement);
                return SUCCESS;
            }
        }
    }
    
    if (n>pAdptArray->size)
    {
        PElement *newPEelemnt =(PElement*)calloc(n+1,sizeof(PElement));
        if (newPEelemnt==NULL)
        {
            return FAIL;
        }
        memcpy(newPEelemnt,pAdptArray->arrElemens,pAdptArray->size*sizeof(PElement));
        free(pAdptArray->arrElemens);
        pAdptArray->arrElemens=newPEelemnt;
        pAdptArray->size=n+1;
        pAdptArray->arrElemens[n]=pAdptArray->cf(pElement);

         return SUCCESS;

    }
    return FAIL;
    
}

//A function that receives an index and returns a copy of the member at this location.
PElement GetAdptArrayAt(PAdptArray pAdptArray, int n){
    if (pAdptArray->arrElemens[n]==NULL||n<0)
    {
        return NULL;
    }
    PElement curr=pAdptArray->cf(pAdptArray->arrElemens[n]);
    return curr;
     
    
}

//A function that returns the size of the array.
int GetAdptArraySize(PAdptArray pAdptArray){
    if (pAdptArray==NULL)
    {
        return -1;
    }
    return pAdptArray->size;

}
//A function that prints the elements in the array.
void PrintDB(PAdptArray pAdptArray){
    for (int i = 0; i < pAdptArray->size; i++)
    {
        if (pAdptArray->arrElemens[i]!=NULL)
        {
            pAdptArray->pf(pAdptArray->arrElemens[i]);
        }
        
        
    }
    

}