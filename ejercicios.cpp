#include <queue>
// Dado un arbol binario de búsqueda, impplementa una funcion
// para imprimir las etiquetas de los nodos en orden de mayor a menor 
// profundidad. Si tiene las misma profundidad el orden da igual 

typedef pair<int, bintree<int>::nodo> myinfo;

void ListarProfundidad(bintree<int> &ab){
    
    list<int> salida;
    priority_queue<myinfo> pq;

    pq.emplace(0, ab.getRaiz());

    while(!pq.empty()){
        myinfo aux = pq.top();
        pq.pop();
        salida.push_back(*(aux.second));

        if(!aux.second.hizq().null()){
            pq.emplace(aux.first + 1, aux.second.hizq());
        }

        if(!aux.second.hdcha().null()){
            pq.emplace(aux.first + 1, aux.second.hdcha());
        }
    }
    salida.reverse();

};

int main(){
    return 0;
}