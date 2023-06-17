#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <list>
using namespace std;

// Stack --> LIFO --> El ultimo es el primero en salir
    // metodo top()
// Queue --> FIFO --: El primero es el primero el salir
    // metodo front()
    // metodo back()

// Priority Queue
//    Basado en un criterio de orden que los podemos definir

void ejemplo_pq1() {
    stack<int> s1;               // Contenedor interno (deque)
    stack<int, list<int>> s2;    // Contenedor interno (lista)
    queue<int> q1;               // Contenedor interno (deque)
    queue<int, vector<int>> q2;  // No permite realizar un pop
    queue<int, list<int>> q3;    // No permite realizar un pop
}

void ejemplo_pq2() {
    priority_queue<int> pq1;        // Contenedor interno (vector)
    priority_queue<int, deque<int>> pq2;
    priority_queue<int, vector<int>, less<>> pq3; // less --> Descendente

}

template<typename T, typename ...Params>
void ppq(priority_queue<T, Params...>& pq) {
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    cout << endl;
}

void ejemplo_pq3() {
    priority_queue<int> pq1;        // Contenedor interno (vector)
    pq1.emplace(10);
    pq1.emplace(1);
    pq1.emplace(20);
    pq1.emplace(100);
    pq1.emplace(3);
    ppq(pq1);       // Descendente

    priority_queue<int, vector<int>, greater<>> pq2; // greater --> Ascendente

    // Crear un vector
    vector<int> v = {11, 22, 31, 14, 51, 32, 15, 55};
    stack<int, vector<int>> s1(v);
    priority_queue<int, vector<int>, greater<>> pq3(greater<>(), std::move(v)); // greater --> Ascendente
    cout << size(v) << endl;
    ppq(pq3); // Ascendente
}

struct Persona {
    string nombre;
    string apellido;
    friend ostream& operator<<(ostream& out, const Persona& p) {
        out << p.nombre << " " << p.apellido;
        return out;
    }
//    bool operator<(Persona other) const {
//        return nombre < other.nombre;
//    }
//    bool operator>(Persona other) const {
//        return nombre > other.nombre;
//    }
};

void ejemplo_pq4() {
    vector v = {Persona{"Alicia", "Zapata"},
                Persona{"Victor", "Alva"},
                Persona{"Pedros", "Perez"},
                Persona{"Maria", "Lopez"},
                Persona{"Alejandra", "Adrianzen"},
    };

//    priority_queue pq1(less<>(), v);
//    ppq(pq1);
//    cout << string(20, '-') << endl;
//    priority_queue pq2(greater<>(), std::move(v));
//    ppq(pq2);
}

void ejemplo_comparar_constantes() {
    Persona a {"AAA", "BBB"};
    Persona b {"ZZZ", "NNN"};
    const Persona c {"ZZZ", "NNN"};
//    cout << boolalpha << (a < b) << endl;
//    cout << boolalpha << (a < c) << endl;
}
// priority queue --> utiliza internamente una estructura de datos: heap (arbol binario)
// map --> utiliza internamente una estructura de datos: (arbol binario)
// tiene un criterio de ordenamiento (Compare)
// unordered_map --> utiliza internamente una estructura de datos: (hash tables)
// Por default del heap: max-heap

void ejemplo_pq5() {
    vector v = {Persona{"Alicia", "Zapata"},
                Persona{"Victor", "Alva"},
                Persona{"Pedros", "Perez"},
                Persona{"Maria", "Lopez"},
                Persona{"Alejandra", "Adrianzen"},
    };

    auto lambda_less = [](auto a, auto b) {
        return a.nombre < b.nombre;
    };
    auto lambda_greater = [](auto a, auto b) {
        return a.nombre > b.nombre;
    };

    auto lambda_less_last_name = [](auto a, auto b) {
        return a.apellido < b.apellido;
    };
    auto lambda_greater_last_name = [](auto a, auto b) {
        return a.apellido > b.apellido;
    };

    priority_queue pq1(lambda_less_last_name, v);
    ppq(pq1);
    cout << string(20, '-') << endl;
    priority_queue pq2(lambda_greater_last_name, std::move(v));
    ppq(pq2);
}


int main() {
//    ejemplo_pq3();
//    ejemplo_pq4();
    ejemplo_pq5();


    return 0;
}
