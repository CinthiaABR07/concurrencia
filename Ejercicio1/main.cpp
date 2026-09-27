#include 
#include 
#include 
#include 

void tarea_hilo(int id, const std::string& mensaje) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 500); 

    for (int i = 1; i <= 5; ++i) {
        std::cout << "[Hilo ID: " << std::this_thread::get_id() 
                  << " | " << mensaje << "] Iteración " << i << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
    }
}

int main() {
    std::cout << "--- Inicio del programa principal ---" << std::endl;

    std::thread h1(tarea_hilo, 1, "Proceso A");
    std::thread h2(tarea_hilo, 2, "Proceso B");
    std::thread h3(tarea_hilo, 3, "Proceso C");

    h1.join();
    h2.join();
    h3.join();

    std::cout << "--- Todos los hilos han terminado ---" << std::endl;
    return 0;
}
