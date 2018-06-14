#include<iostream>
using namespace std;
template <class T>
class nodo{
  public:
  T valor;
  nodo* next;
  nodo (T,nodo<T>*p=NULL);
};
template <class T>
class lista{
  public:
  nodo<T>* H;
  lista();
  bool buscar(T,nodo <T> * &);
  void add(T);
  void out(T);
  void imprimir(nodo<T>*p);
  void print();
  void eraser(nodo<T>*p);
  void eliminar_lista();
  ~lista();
};