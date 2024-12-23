#include <iostream>
#include "func.h"
#include "func.cpp"

void menu() {
    std::vector<Flight> flights;
    int choice;

    do {
        std::cout << "\nМеню:\n"
                  << "1. Инициализировать данные\n"
                  << "2. Добавить рейс\n"
                  << "3. Удалить рейс\n"
                  << "4. Обновить рейс\n"
                  << "5. Просмотреть все рейсы\n"
                  << "6. Найти рейсы по пункту назначения\n"
                  << "7. Сохранить данные в файл\n"
                  << "8. Загрузить данные из файла\n"
                  << "0. Выход\n"
                  << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                initializeData(flights);
                break;
            case 2:
                addFlight(flights);
                break;
            case 3: {
                int flightNumber;
                std::cout << "Введите номер рейса для удаления: ";
                std::cin >> flightNumber;
                deleteFlight(flights, flightNumber);
                break;
            }
            case 4: {
                int flightNumber;
                std::cout << "Введите номер рейса для обновления: ";
                std::cin >> flightNumber;
                updateFlight(flights, flightNumber);
                break;
            }
            case 5:
                viewFlights(flights);
                break;
            case 6: {
                std::string destination;
                std::cout << "Введите пункт назначения: ";
                std::cin.ignore();
                std::getline(std::cin, destination);
                listFlightsByDestination(flights, destination);
                break;
            }
            case 7:
                saveToFile(flights, "flights.txt");
                break;
            case 8:
                loadFromFile(flights, "flights.txt");
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}