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
};


//En un AVL en la inserción debemos mantener las alturas de los nodos 
//Se distinguen 4 casos
//Caso A: ROTACIÓN SIMPLE a DERECHA (RSD) sucede cuando se inserta un 
// nuevo nodo como hijo a la izquierda

template <class T>
void SimpleDerecha(info_nodo_AVL<T> * & n){
    info_nodo_AVL<T> * aux = n->hizq;
    info_nodo_AVL<T> * padre = n->padre;
    n->hizq = n->hder;
    if(n->hizq != nullptr){
        n->hizq->padre = n;
    }
    n->padre = aux;
    aux->padre = padre;
    aux->hder = n;
    n = aux;
    ActualizarAltura(n->hder);
};

template <class T>
void ActualizarAltura(info_nodo_AVL<T>* &n){
    if(n != 0){
        n->altura = std::max(Altura(n->hizq),
                    Altura(n->hder)) + 1;
        ActualizarAltura(n->padre);    
    }
};


// Caso D_ ROTACIÓN SIMPLE a IZQUIERDA(RSI) sucede cunado insertamos un 
// nuevo nodo a la derecha 

template <class T>
void SimpleIzquierda(info_nodo_AVL<T>* &n){
    info_nodo_AVL<T> * aux = n->hder;
    info_nodo_AVL<T> * padre = n->padre;
    n->hder = n->hizq;
    if(n->hder != nullptr){
        n->hder->padre = n;
    }
    n->padre = aux;
    aux->padre = padre;
    aux->hizq = n;
    n = aux;
    ActualizarAltura(n->hizq);
};

// Caso B debemos realizar una rotación simple a la izquierda
// sobre el hizq del nodo donde se produce el desequilibrio y luego 
// realizamos una rotación simple a la derecha sobre el nodo donde se produce 
// el desquilibrio

template <class T>
void Doble_IzquierdaDerecha(info_nodo_AVL<T>* & n){
    SimpleIzquierda(n->hizq);
    SimpleDerecha(n);
};

// Caso C: debemos realizar primero una rotacion simple a la derecha 
// sobre el hijo a la derecha del nodo donde se produce el desequilibrio
// y luego una rotación simple a la izquierda en el nodo 

template <class T>
void Doble_DerechaIzquierda(info_nodo_AVL<T>* & n){
    SimpleDerecha(n->hder);
    SimpleIzquierda(n);
}

//Ahora que tenemos todos los posibles desequilibrios en mente procedemos
// con el método de inserción

template<class T>
bool InsertarAVL(info_nodo_AVL<T>* &raiz, T x){
    if(raiz == nullptr){
        raiz = new info_nodo_AVL<T>(x);
        raiz->altura = 0;
        return true;
    }else{
        if(x < raiz->et){
            if(InsertarAVL(raiz->hizq, x)){
                raiz->hizq->padre = raiz;
            }
            switch (Altura(raiz->hizq) - Altura(raiz->padre)){
                case 0: return false;
                case 1:
                    raiz->altura++;
                    return true;
                case 2:
                    //CASO A
                if(Altura(raiz->hizq->hizq) > Altura(raiz->hizq->hder)){
                    SimpleDerecha(raiz);
                }else{
                    //CASO B
                    Doble_IzquierdaDerecha(raiz);
                }
                return false;
            }
        }else{ //x es mayor que la etiqueta de la raiz
            if(InsertarAVL(raiz->hder, x){
                if(raiz->hder != nullptr){
                    raiz->hder->padre = raiz;
                }

                switch (Altura(raiz->heder) - Altura(raiz->hizq)){
                    case 0: 
                        return false;
                    case 1: 
                        raiz->altura++;
                        return true;
                    case 2:
                        //CASO D
                        if(Altura(raiz->hder->hder) > Altura(raiz->hder->hizq)){
                            SimpleIzquierda(raiz);
                        }else{
                            //CASO C
                            Doble_DerechaIzquierda(raiz);
                        }
                        return false;
                }
            }
        }
    }

}


int main(){

    return 0;
}