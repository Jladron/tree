#include <iostream>

using namespace std;

//Arboles generales

template <class T>
struct info_nodo{
    T et;
    info_nodo<T>* padre, *hijoizq, *hermanodcha;
    info_nodo(){
        padre=
        hijoizq=
        hermanodcha = 0;
    }
    info_nodo(const T & e){
        et = e;
        padre = 
        hijoizq = 
        hermanodcha = 0;
    }
}

template <class T>
info_nodo<T>* CrearRaiz(const T &e){
    info_nodo<T> * n = new info_nodo<T>(e);
}

template <class T>
int Altura(info_nodo<T>* n){
    if(n == nullptr){
        return -1;
    }else{
        info_nodo<T>*aux;
        int max = -1;
        for(aux = n->hijoizq; aux != nullptr;
            aux = aux->hermanodcha){
                int h = Altura(aux);
                if(h > max){
                    max = h;
                }
        }
        return max + 1;
    }
}

template <class T>
void Copiar(info_nodo<T>*s, info_nodo<T>* &d){
    if(s == nullptr){
        d = nullptr;
    }else{
        d = CrearRaiz(s->et);
        Copiar(s->hijoizq, d->hijoizq);
        Copiar(s->hermanodcha, d->hermanodcha);
        if(d->hijoizq != 0){
            d->hijoizq->padre = d;
        }

        if(d->hermanodcha != 0){
            d->hermanodcha->padre = d->padre;
        }
    }
}


template <class T>
void Borrar(info_nodo<T>*s){
    if(s != nullptr){
        Borrar(s->hijoizq);
        Borrar(s->hermanodcha);
        delete s;
    }
}

template <class T>
void InsertarHijoIzq(info_nodo<T>*n, info_nodo<T>* & T2){
    if(T2 != nullptr){
        T2->hermanodcha = n->hijoizq;
        T2->padre = n;
        n->hijoizq = T2;
        T2 = nullptr;
    }
}


template<class T>
void InsertarHermanoDrcha(info_nodo<T>*n, info_nodo<T>* & T2){
    if(T2 != nullptr){
        T2->hermanodcha = n->hermanodcha;
        T2->padre = n->padre;
        n->hermanodcha = T2;
        T2 = nullptr;
    }
}

template<class T>
info_nodo<T>* PodarHijoIzq(info_nodo<T>* n){
    

    if(n->hijoizq != nullptr){
        info_nodo<T> * res = n->hijoizq;
        n->hizq = n->hijoizq->hermanodcha;
        res->padre = nullptr;
        res->hermanodcha = nullptr;
        return res;
    }
    return nullptr;
}

template<class T>
info_nodo<T>* PodarHermanoDrcha(info_nodo<T>* n){
    info_nodo<T> * res = 0;
    if(n->hermanodcha){
        res = n->hermanodcha;
        n->hermanodcha =  res->hermanodcha;
        res->hermanodcha = nullptr;
        res->padre = nullptr;
    }
    return res;
}

int main(){

    return 0;
}