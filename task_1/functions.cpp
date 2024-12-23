#include "functions.h"
#include <iostream>
#include <algorithm>

void addCall(std::vector<Call>& calls) {
    Call newCall;
    std::cout << "Введите дату (ДД.ММ.ГГГГ): ";
    std::cin >> newCall.date;
    std::cout << "Введите код города: ";
    std::cin >> newCall.cityCode;
    std::cout << "Введите название города: ";
    std::cin >> newCall.cityName;
    std::cout << "Введите длительность разговора (в минутах): ";
    std::cin >> newCall.duration;
    std::cout << "Введите тариф (стоимость за минуту): ";
    std::cin >> newCall.rate;
    std::cout << "Введите номер телефона: ";
    std::cin >> newCall.phoneNumber;
    calls.push_back(newCall);
    std::cout << "Разговор добавлен.\n";
}

void viewCalls(const std::vector<Call>& calls) {
    for (const auto& call : calls) {
        std::cout << "Дата: " << call.date << ", Код города: " << call.cityCode
                  << ", Город: " << call.cityName << ", Длительность: " << call.duration
                  << " мин, Тариф: " << call.rate << ", Телефон: " << call.phoneNumber << "\n";
    }
}

void searchCallsByCity(const std::vector<Call>& calls, const std::string& cityName) {
    for (const auto& call : calls) {
        if (call.cityName == cityName) {
            std::cout << "Дата: " << call.date << ", Телефон: " << call.phoneNumber
                      << ", Длительность: " << call.duration << " мин\n";
        }
    }
}

void deleteCall(std::vector<Call>& calls, const std::string& phoneNumber) {
    auto it = std::remove_if(calls.begin(), calls.end(), [&](const Call& call) {
        return call.phoneNumber == phoneNumber;
    });
    if (it != calls.end()) {
        calls.erase(it, calls.end());
        std::cout << "Запись удалена.\n";
    } else {
        std::cout << "Запись не найдена.\n";
    }
}

void updateCall(std::vector<Call>& calls, const std::string& phoneNumber) {
    for (auto& call : calls) {
        if (call.phoneNumber == phoneNumber) {
            std::cout << "Введите новую длительность разговора (мин): ";
            std::cin >> call.duration;
            std::cout << "Данные обновлены.\n";
            return;
        }
    }
    std::cout << "Запись не найдена.\n";
}

void sortCallsByDuration(std::vector<Call>& calls) {
    std::sort(calls.begin(), calls.end(), [](const Call& a, const Call& b) {
        return a.duration > b.duration;
    });
    std::cout << "Сортировка выполнена.\n";
}

void calculateCityStats(const std::vector<Call>& calls, const std::string& cityName) {
    int totalDuration = 0;
    double totalCost = 0.0;

    for (const auto& call : calls) {
        if (call.cityName == cityName) {
            totalDuration += call.duration;
            totalCost += call.duration * call.rate;
        }
    }

    std::cout << "Город: " << cityName << ", Общее время: " << totalDuration
              << " мин, Общая стоимость: " << totalCost << " у.е.\n";
}