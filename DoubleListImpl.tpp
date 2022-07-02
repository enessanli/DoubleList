#pragma once

#include "DoubleList.tpp"

template <typename T>
DoubleList<T>::DoubleList(T *a, unsigned n) {
if(n!=0){
Node *current1,*current2;

mHead[0]= mHead[1]=new Node;
current1=mHead[0];
current2=mHead[1];
mHead[0]->mValue=*a;

for(unsigned i=0;i<(n-1);i++){
mHead[0]->mNext[0]= mHead[1]->mNext[1]= new Node;
mHead[0]=mHead[0]->mNext[0];
mHead[1]=mHead[1]->mNext[1];
mHead[0]->mValue=*++a;

}
mHead[1]->mNext[1]=NULL;
mHead[0]->mNext[0]=NULL;
mHead[0]=current1;
mHead[1]=current2;

}
else{
mHead[0]=NULL;
mHead[1]=NULL;
}
}










template <typename T>
DoubleList<T>::DoubleList(const DoubleList<T> &dl) {
Node *current[5];
unsigned i=1,sayi=1;
current[0]=dl.mHead[0];
current[1]=dl.mHead[1];


if(current[0]!=NULL){
mHead[0]=new Node;
current[2]=mHead[0];
mHead[0]->mValue=current[0]->mValue;
current[2]=mHead[0];
current[4]=mHead[0];


while(current[0]->mNext[0]!=NULL){
mHead[0]->mNext[0]=new Node;
mHead[0]=mHead[0]->mNext[0];
current[0]=current[0]->mNext[0];
mHead[0]->mValue=current[0]->mValue;
sayi++;
}}
mHead[0]->mNext[0]=NULL;
mHead[0]=current[2];




if(current[2]!=NULL){
while(current[2]->mNext[0]!=NULL){
if(current[2]->mValue==current[1]->mValue)
{
mHead[1]=current[2];
current[3]=mHead[1];
current[1]=current[1]->mNext[1];
current[2]=mHead[0];
break;
}
else{current[2]=current[2]->mNext[0];  }
}

}



for(;i<(sayi);i++){

while(1){
if(current[2]->mValue==current[1]->mValue){

mHead[1]->mNext[1]=current[2];
mHead[1]=mHead[1]->mNext[1];
current[2]=mHead[0];
break;
}
else{current[2]=current[2]->mNext[0];}
}

current[1]=current[1]->mNext[1];






}


mHead[1]->mNext[1]=NULL;

mHead[1]=current[3];



}























template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::get(unsigned index,
                                                 Color color) const {

unsigned i=0;
Node *current[2];
current[color]=mHead[color];
while(i<index){
if(current[color]->mNext[color]==nullptr){
throw InvalidIndexException();
}
else{current[color]=current[color]->mNext[color];
i++;


}
}

return current[color];
  return nullptr;
}



template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::insert(T value, unsigned redIndex,
                                                    unsigned blueIndex) {
Node *current[4],*a;
unsigned i=1,j=1,k=0,l=0;
a= new Node;
a->mNext[0]=NULL;
a->mNext[1]=NULL;

a->mValue=value;
current[0]=mHead[0];
current[1]=mHead[1];
current[2]=mHead[0];
current[3]=mHead[1];
while(current[2]!=NULL){
k++;
current[2]=current[2]->mNext[0];
}
while(current[3]!=NULL){
l++;
current[3]=current[3]->mNext[1];
}
if(redIndex>(k) || blueIndex>(l)){
delete a;
throw InvalidIndexException();

}


if(redIndex==0){

a->mNext[0]=mHead[0];
mHead[0]=a;

}

if(redIndex>0){

while((i<redIndex)&&(current[0]->mNext[0])!=NULL){
current[0]=current[0]->mNext[0];
i++;
}


a->mNext[0]=current[0]->mNext[0];
current[0]->mNext[0]=a;

}

if(blueIndex==0){
a->mNext[1]=mHead[1];
mHead[1]=a;
}

if(blueIndex>0){
while((j<blueIndex)&&(current[1]->mNext[1])!=NULL){
current[1]=current[1]->mNext[1];
j++;
}

a->mNext[1]=current[1]->mNext[1];
current[1]->mNext[1]=a;

}


  return nullptr;
}















template <typename T>
void DoubleList<T>::remove(unsigned index, Color color) {
Node *current[4],*temp1,*prev1,*temp2,*prev2;
unsigned a=0,b=0;
current[0]=mHead[color];
current[2]=mHead[color];
current[3]=mHead[color];
temp1=mHead[0];
prev1=NULL;
temp2=mHead[1];
prev2=NULL;

while(current[3]!=NULL){
a++;
current[3]=current[3]->mNext[color];
}

if(index>a){
throw InvalidIndexException();
}

while(b!=index){
b++;
current[2]=current[2]->mNext[color];
}


 if (temp1 != NULL && temp1->mValue == current[2]->mValue)
    {
        mHead[0] = temp1->mNext[0]; // Changed head
                   // free old head
      
    }
 else
    {
    while (temp1 != NULL && temp1->mValue != current[2]->mValue)
    {
        prev1 = temp1;
        temp1 = temp1->mNext[0];
    }
 prev1->mNext[0] = temp1->mNext[0];

}




 if (temp2 != NULL && temp2->mValue == current[2]->mValue)
    {
        mHead[1] = temp2->mNext[1]; // Changed head
                 delete temp2;  // free old head
       
    }
 else
    {
    while (temp2 != NULL && temp2->mValue != current[2]->mValue)
    {
        prev2 = temp2;
        temp2 = temp2->mNext[1];
    }
 prev2->mNext[1] = temp2->mNext[1];
delete temp2;

}











}















template <typename T>
void DoubleList<T>::append(DoubleList<T> &dl) {
Node *current[2];
current[0]=mHead[0];
current[1]=mHead[1];
if(mHead[0]==NULL){mHead[0]=dl.mHead[0];}
else{while(mHead[0]!=NULL){
if(mHead[0]->mNext[0]==NULL){
mHead[0]->mNext[0]=dl.mHead[0];
mHead[0]=current[0];

break;
}
mHead[0]=mHead[0]->mNext[0];
}}
dl.mHead[0]=NULL;
if(mHead[1]==NULL){mHead[1]=dl.mHead[1];}
else{while(mHead[1]!=NULL){
if(mHead[1]->mNext[1]==NULL){
mHead[1]->mNext[1]=dl.mHead[1];
mHead[1]=current[1];

break;
}
mHead[1]=mHead[1]->mNext[1];
}}


dl.mHead[1]=NULL;
}

template <typename T>
DoubleList<T>::~DoubleList() {
Node *temp1;
while(mHead[0]!=NULL){
temp1=mHead[0];
mHead[0]=mHead[0]->mNext[0];
delete temp1;
}

}