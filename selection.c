#include <stdio.h>
#define LEN 7
int main(){
  int v [LEN] = {471,336,1218,630,1001,1346,790};
  int menor,selecionado;
      for(int i = 0; i < LEN; i++){
  	 printf(" %d ", v[i]);
      }
  for(int i= 0; i< LEN-1; i++){
    selecionado = v[i];
    menor = i+1;
    for(int j=i+1; j< LEN; j++)
     	if(v[menor] > v[j])
       	menor = j;
	  if(selecionado > v[menor]){
  	  v[i] = v[menor];
  	  v[menor] = selecionado;
	  }

  }
  printf("\n\n");
  for(int i = 0; i < LEN; i++){
  	 printf(" %d ", v[i]);
  }
}   	