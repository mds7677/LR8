#include "func.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Инициализация данных
void initializeData(std::vector<Flight>& flights) {
    flights.push_back({101, "Boeing 737", "New York", "08:30", .passengers = 180});
    flights.push_back({202, "Airbus A320", "London", "10:15", .cargoWeight = 1200.5});
    flights.push_back({303, "Embraer 190", "Paris", "13:45", .passengers = 100});
    flights.push_back({404, "Boeing 747", "New York", "16:00", .passengers = 300});
    std::cout << "Данные успешно инициализированы.\n";
}

// Добавление рейса
void addFlight(std::vector<Flight>& flights) {
    Flight newFlight;
    std::cout << "Введите номер рейса: ";
    std::cin >> newFlight.flightNumber;
    std::cout << "Введите тип самолета: ";
    std::cin.ignore();
    std::getline(std::cin, newFlight.aircraftType);
    std::cout << "Введите пункт назначения: ";
    std::getline(std::cin, newFlight.destination);
    std::cout << "Введите время вылета (чч:мм): ";
    std::cin >> newFlight.departureTime;

    char cargoOrPassengers;
    std::cout << "Рейс грузовой или пассажирский? (g/p): ";
    std::cin >> cargoOrPassengers;
    if (cargoOrPassengers == 'p') {
        std::cout << "Введите количество пассажиров: ";
        std::cin >> newFlight.passengers;
    } else {
        std::cout << "Введите вес груза: ";
        std::cin >> newFlight.cargoWeight;
    }

    flights.push_back(newFlight);
    std::cout << "Рейс добавлен.\n";
}

// Удаление рейса
void deleteFlight(std::vector<Flight>& flights, int flightNumber) {
    auto it = std::remove_if(flights.begin(), flights.end(), [flightNumber](const Flight& flight) {
        return flight.flightNumber == flightNumber;
    });
    if (it != flights.end()) {
        flights.erase(it, flights.end());
        std::cout << "Рейс удален.\n";
    } else {
        std::cout << "Рейс с указанным номером не найден.\n";
    }
}

// Обновление рейса
void updateFlight(std::vector<Flight>& flights, int flightNumber) {
    for (auto& flight : flights) {
        if (flight.flightNumber == flightNumber) {
            std::cout << "Введите новый пункт назначения: ";
            std::cin.ignore();
            std::getline(std::cin, flight.destination);
            std::cout << "Введите новое время вылета (чч:мм): ";
            std::cin >> flight.departureTime;
            std::cout << "Данные рейса обновлены.\n";
            return;
        }
    }
    std::cout << "Рейс с указанным номером не найден.\n";
}

// Просмотр всех рейсов
void viewFlights(const std::vector<Flight>& flights) {
    for (const auto& flight : flights) {
        std::cout << "Рейс №" << flight.flightNumber << ", Самолет: " << flight.aircraftType
                  << ", Пункт назначения: " << flight.destination
                  << ", Время вылета: " << flight.departureTime << "\n";
    }
}

// Список рейсов по пункту назначения
void listFlightsByDestination(const std::vector<Flight>& flights, const std::string& destination) {
    std::vector<Flight> filteredFlights;
    for (const auto& flight : flights) {
        if (flight.destination == destination) {
            filteredFlights.push_back(flight);
        }
    }

    std::sort(filteredFlights.begin(), filteredFlights.end(), [](const Flight& a, const Flight& b) {
        return a.departureTime < b.departureTime;
    });

    std::cout << "Рейсы в пункт \"" << destination << "\":\n";
    for (const auto& flight : filteredFlights) {
        std::cout << "Рейс №" << flight.flightNumber << ", Самолет: " << flight.aircraftType
                  << ", Время вылета: " << flight.departureTime << "\n";
    }
}

// Сохранение данных в файл
void saveToFile(const std::vector<Flight>& flights, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& flight : flights) {
        file << flight.flightNumber << ";" << flight.aircraftType << ";"
             << flight.destination << ";" << flight.departureTime << "\n";
    }file.close();
    std::cout << "Данные сохранены в файл.\n";
}

// Загрузка данных из файла
void loadFromFile(std::vector<Flight>& flights, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл.\n";
        return;
    }

    Flight flight;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        flight.flightNumber = std::stoi(line.substr(0, (pos = line.find(';'))));
        line.erase(0, pos + 1);
        flight.aircraftType = line.substr(0, (pos = line.find(';')));
        line.erase(0, pos + 1);
        flight.destination = line.substr(0, (pos = line.find(';')));
        line.erase(0, pos + 1);
        flight.departureTime = line;
        flights.push_back(flight);
    }
    file.close();
    std::cout << "Данные загружены из файла.\n";
}