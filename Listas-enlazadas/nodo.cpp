#include "nodo.h"
template <class T>
nodo<T>::nodo(T a,nodo <T>*p){
  next=p;
  valor=a;
}
template <class T>
lista<T>::lista(){
  H=NULL;
}
template <class T>
bool lista<T>::buscar(T a,nodo<T> * & p){
  nodo<T> *i=H;
  nodo<T> *y=i;
  while(i && i->valor<a){
    y=i;
    i=i->next;
  }
  p=y;
  return i && (i->valor)==a;
}
template <class T>
void lista<T>::add(T a){
  nodo<T> *p;
  if(!buscar(a,p)){
    if(p==H && !p){
      H=new nodo<T>(a);
    }
    else if(p==H & (p->valor)>a){
      H=new nodo<T>(a,H);
    }
    else{
      p->next=new nodo<T>(a,p->next);
    }
  }
}
template <class T>
void lista<T>::out(T a){
  nodo<T>*p;
  if(buscar(a,p)){
    cout<<"hola"<<endl;
    nodo<T>*u;
    if(p==H && H->valor==a){
        u=H->next;
        delete(H);
        H=u;
    }
    else{
      u=p->next->next;
      delete(p->next);
      p->next=u;
    }
  }
}
template <class T>
void lista<T>::imprimir(nodo<T>*p){
  if(p){
    cout<<"Direccion: ";
    //printf("%d",&p);
    cout<<p;
    cout<<" Valor: "<<p->valor;
    if(p->next)cout<<" ";
    else cout<<endl<<endl;
    imprimir(p->next);
  }
}
template <class T>
void lista<T>::print(){
  imprimir(H);
}
template <class T>
void lista<T>::eraser(nodo<T>*p){
  if(p){
    eraser(p->next);
    delete p;
  }
}
template <class T>
void lista<T>::eliminar_lista(){
  eraser(H);
  H=NULL;
}
template <class T>
lista<T>::~lista(){
  eraser(H);
  H=NULL;
}
