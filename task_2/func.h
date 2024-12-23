#include <string>
#include <vector>

typedef struct {
    int flightNumber;         // Номер рейса
    std::string aircraftType; // Тип самолета
    std::string destination;  // Пункт назначения
    std::string departureTime; // Время вылета
    union {
        int passengers;        // Количество пассажиров
        double cargoWeight;    // Вес груза
    };
} Flight;

// Объявление функций
void initializeData(std::vector<Flight>& flights);
void addFlight(std::vector<Flight>& flights);
void deleteFlight(std::vector<Flight>& flights, int flightNumber);
void updateFlight(std::vector<Flight>& flights, int flightNumber);
void viewFlights(const std::vector<Flight>& flights);
void listFlightsByDestination(const std::vector<Flight>& flights, const std::string& destination);
void saveToFile(const std::vector<Flight>& flights, const std::string& filename);
void loadFromFile(std::vector<Flight>& flights, const std::string& filename);