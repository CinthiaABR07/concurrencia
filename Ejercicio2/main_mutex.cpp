#include 
#include 
#include 
#include 

long long contador_global = 0;
std::mutex mtx; // Mutex 

const int NUM_HILOS = 5;
const int INCREMENTOS_POR_HILO = 1000000;

void incrementar_seguro() {
    for (int i = 0; i < INCREMENTOS_POR_HILO; ++i) {
        std::lock_guard lock(mtx);
        contador_global++; 
    }
}

int main() {
    std::cout << "Ejecutando con std::mutex..." << std::endl;
    std::vector hilos;

    // Crear 5 hilos
    for (int i = 0; i < NUM_HILOS; ++i) {
        hilos.push_back(std::thread(incrementar_seguro));
    }

    // Esperar a que todos terminen
    for (auto& h : hilos) {
        h.join();
    }

    std::cout << "Valor esperado del contador: " << (NUM_HILOS * INCREMENTOS_POR_HILO) << std::endl;
    std::cout << "Valor real obtenido:          " << contador_global << std::endl;

    return 0;
}
