#include "EventTracker.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <wtypes.h>


// Olay� dosyaya yazd�ran fonksiyon
void EventTracker::WriteToFile(const std::string& eventData) {
    std::ofstream outFile;
    outFile.open("C:\\Users\\Esra\\Desktop\\user_activity_log.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << eventData << std::endl;
        outFile.close();
    }
    else {
        std::cerr << "Dosya a��lamad�!" << std::endl;
    }
}


/*std::string EventTracker::ConvertUnixTimeToReadableTime(DWORD unixTime) {
    // Unix zaman damgas�n� time_t'ye �evir
    std::time_t time = static_cast<std::time_t>(unixTime);

    // Yerel zaman format�nda saat ve tarihi string'e �evir
    char buffer[80];
    std::tm* localTime = std::localtime(&time);
    if (localTime != nullptr) {
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return std::string(buffer);
    }
    else {
        return "Invalid Time";
    }
}*/

std::string EventTracker::ConvertUnixTimeToReadableTime(DWORD unixTime) {
    // Unix zaman damgas�n� time_t'ye �evir
    time_t rawTime = static_cast<time_t>(unixTime);

    // G�venli bir �ekilde yerel saat �evrimi
    std::tm localTime;
    localtime_s(&localTime, &rawTime);

    // Yerel zaman format�nda saat ve tarihi string'e �evir
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);

    return std::string(buffer);
}


// Event ID'ye g�re a��klama d�nd�ren fonksiyon
std::string EventTracker::GetEventName(int eventId) {
    switch (eventId) {
    case 4624: return "Login (Giris Yapildi)";
    case 4634: return "Logout (Cikis Yapildi)";
    case 4720: return "Account Created (Hesap Olusturuldu)";
    case 4722: return "Account Enabled (Hesap Etkinlestirildi)";
    case 4726: return "Account Deleted (Hesap Silindi)";
    case 4781: return "Account Renamed (Kullanici Adi Degistirildi)";
    case 4723: return "Password Change Attempt (Sifre Degisikligi Denemesi)";
    case 4724: return "Password Changed (Sifre Degistirildi)";
    default: return "Unknown Event";
    }
}
