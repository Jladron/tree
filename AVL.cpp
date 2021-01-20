#include <iostream>

using namespace std;

//Arbol AVL (andelson, Velskii y Landis) se trata de un arbol auto balanceado en el que la diferencia de alturas de dos subarboles
//no pueden ser mayor a 1

template <class T>
struct info_nodo_AVL{
    T et;
    info_nodo_AVL<T>*padre,*hizq, *hder;
    int altura;
};

template <class T>
info_nodo_AVL<T>* Busqueda(info_nodo<T>*n, const T &x){
    if(n == nullptr){
        return nullptr;
    }else{
        if(n->et == x){
            return n;
        }else{
            if(n->et < X){
                return Busqueda(n->hder, x);
            }else{
                return Busqueda(n->hizq, x);
            }
        }
    }
}

int main(){

    return 0;
}