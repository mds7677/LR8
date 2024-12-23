 #include "../task_1/functions.h" 
 #include "functions.cpp"
 void Menu(){
    std::cout << "\nМеню:\n"
                  << "1. Добавить запись\n"
                  << "2. Просмотреть записи\n"
                  << "3. Поиск по городу\n"
                  << "4. Удалить запись\n"
                  << "5. Обновить запись\n"
                  << "6. Сортировка по длительности\n"
                  << "7. Расчеты для города\n"
                  << "0. Выход\n"
                  << "Ваш выбор: ";
}
int main(){
     std::vector<Call> calls;
    int choice;
    
    do {
        Menu();
    std::cin >> choice;
    

        switch (choice) {
            case 1:
                addCall(calls);
                break;
            case 2:
                viewCalls(calls);
                break;
            case 3: {
                std::string cityName;
                std::cout << "Введите название города: ";
                std::cin >> cityName;
                searchCallsByCity(calls, cityName);
                break;
            }
            case 4: {
                std::string phoneNumber;
                std::cout << "Введите номер телефона для удаления: ";
                std::cin >> phoneNumber;
                deleteCall(calls, phoneNumber);
                break;
            }
            case 5: {
                std::string phoneNumber;
                std::cout << "Введите номер телефона для обновления: ";
                std::cin >> phoneNumber;
                updateCall(calls, phoneNumber);
                break;
            }
            case 6:
                sortCallsByDuration(calls);
                break;
            case 7: {
                std::string cityName;
                std::cout << "Введите название города: ";
                std::cin >> cityName;
                calculateCityStats(calls, cityName);
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
    return 0;
}