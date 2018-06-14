#include "nodo.cpp"
void merged(lista<int>&l1,lista<int>&l2){
  nodo<int>*p=l1.H;
  nodo<int>*q=l2.H;
  nodo<int>*r=NULL;
  nodo<int>*h=NULL;
  bool b;
  if(p && q){
    if((p->valor)<(q->valor)){
      h=p;
      p=p->next;
    }
    else{
      h=q;
      q=q->next;
    }
    r=h;
  }
  while(p || q){
    if(p && q){
     if((p->valor)<(q->valor)){
       r->next=p;
       r=p;
       p=p->next;
     }
      else{
        r->next=q;
        r=q;
        q=q->next;
      }
    }
    else if(p){
      r->next=p;
      r=p;
      p=p->next;
    }
    else{
      r->next=q;
      r=q;
      q=q->next;
    }
  }
  l2.H=NULL;
  l1.H=NULL;
  l1.H=h;
}
int main() {
  lista<int>l1,l2;
  l1.add(1);
  l1.add(2);
  l1.add(3);
  l1.add(5);
  l1.add(7);
  l2.add(100);
  l2.add(6);
  l2.add(8);
  l2.add(9);
  l2.add(-1);
  cout<<"lista 1"<<endl;
  l1.print();
  cout<<"lista 2"<<endl;
  l2.print();
  cout<<"lista mergeada"<<endl;
  merged(l1,l2);
  l1.print();
  l2.print();
}