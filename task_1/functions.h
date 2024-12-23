#include <vector>
#include <string>

typedef struct {
    std::string date;
    std::string cityCode;
    std::string cityName;
    int duration;
    double rate;
    std::string phoneNumber;
} Call;

// Функции
void addCall(std::vector<Call>& calls);
void viewCalls(const std::vector<Call>& calls);
void searchCallsByCity(const std::vector<Call>& calls, const std::string& cityName);
void deleteCall(std::vector<Call>& calls, const std::string& phoneNumber);
void updateCall(std::vector<Call>& calls, const std::string& phoneNumber);
void sortCallsByDuration(std::vector<Call>& calls);
void calculateCityStats(const std::vector<Call>& calls, const std::string& cityName);
void menu();
