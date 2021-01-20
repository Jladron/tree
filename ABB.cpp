#include <iostream>

using namespace std;
// Arbol Binario de búsqueda{5,7,13,20,80,1,3,0,12}
//    5
//   / \
//  1   7 
// / \  / \
// 0 3    13
//        / \
//       12  20
//           / \
//             80

template <class T>
struct info_nodo{
    T et;
    info_nodo<T> * Padre;
    info_nodo<T> * hizq;
    info_nodo<T> * hder;
};

//Tenemos una eficiencia promedio (log2(n)) y O(n) para buscar una etiqueta
//búsqueda recursiva
template <class T>
info_nodo<T> * Buscar(info_nodo<T>*n, const T &x){
    if(n == nullptr){
        return nullptr;
    }else{
        if(x == n->et){
            return n;
        }else if(x < n->et){
            Buscar(n->hizq, x);
        }else{
            Buscar(n->hder, x);
        }
    }
}

//busqueda iterativa

template <class T>
info_nodo<T> * Buscar(info_nodo<T>*n, const T &x){
    bool encontrado = false;
    while( n !=  nullptr && !encontrado){
        if(n->et == x){
            encontrado = true;
        }else{
            if(x < n->et){
                n = n->hizq;
            }else{
                n = n->hder;
            }
        }
    }

    return n;
}


//inserción recursiva

template <class T>
bool Insertar(info_nodo<T>* &n, const T &x){
    bool resultado = false;
    if(n == nullptr){
        n = new info_nodo(x);
        return true;
    }else if(x <n->et){
        resultado = Insertar(n->hizq, x);
        if(resultado){
            n->hizq->Padre = n;    
        }
        return resultado;
    }else{
        resultado = Insertar(n->hder, x);
        if(resultado){
            n->hder->Padre = n;
        }
        return resultado;
    }

    return resultado;
}

//insercion iterativa
template <class T>
bool Insertar(info_nodo<T>* &n, const T &x){
    bool insertado = false;
    while( n !=  nullptr){
        if(n->et == x){
            return false;//si ya existe una etiqueta no se inserta nada
        }else{
            if(x < n->et){
                n = n->hizq;
            }else{
                n = n->hder;
            }
        }
    }
    if(n == nullptr){
        n = new info_nodo(x);//en caso de que no esté la etiqueta se inserta el elemento donde corresponda
        insertado = true;
    }
    return insertado;
};

//Borrado

void Borrar(info_nodo<T>*n, int x){
    if(n != nullptr){
        if(n->et == x){
            EliminarRaiz(n);
        }else{
            if(n->et < x){
                Borrar(n->hder, x);
            }else{
                Borrar(n->hizq, x);
            }
        }
    }
};

void PutPadre(info_nodo<T>*n, info_nodo<T>*nuevo){
    info_nodo<T>*padre = n->Padre;
    if(padre != nullptr){
        if(padre->hder == n){
            padre->hder = nuevo;
        }else{
            padre->hizq = nuevo;
        }
        nuevo->Padre = padre;
    }
};

void EliminarRaiz(info_nodo<T>*n, int x){
    //CASO 0 el nodo que queremos borrar es una hoja
    if(n->hizq == nullptr && n->hder == nullptr){
        PutPadre(n,nullptr);
        delete n;
    }else{
        if(n->hizq == nullptr && n->hder != nullptr){
            //CASO 1 el nodo que queremos borrar solo tiene hijo a la derecha
            PutPadre(n, n->hder);
            info_nodo<T>*aux = n;
            n = n->hder;
            delete aux;
        }else{
            if(n->hizq != nullptr && n->hder == nullptr){
                //CASO 2 el nodo que queremos borrar solo tiene hijo a la izquierda
                PutPadre(n, n->hizq);
                info_nodo<T>* aux = n;
                n = n->hizq;
                delete aux;
            }else{
                //CASO 3 el nodo tiene hijo tanto a la derecha como a la izquierda
                info_nodo<T>*aux = n->hder;
                while(aux->hizq != nullptr){
                    aux = aux->hizq;    //buscamos el valor sustituto que será el último hijo a la izquierda del hijo a la derecha
                }
                n->et = aux->et;
                Borrar(aux, aux->et);

            }
        }
    }
}

int main(){

    return 0;
}