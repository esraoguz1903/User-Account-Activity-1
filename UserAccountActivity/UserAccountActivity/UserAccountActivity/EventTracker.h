#ifndef EVENTTRACKER_H
#define EVENTTRACKER_H

#include <string>
#include <wtypes.h>
//#include <Windows.h>
class EventTracker {
public:
    virtual void TrackEvent() = 0; // Tüm alt sýnýflar bu fonksiyonu tanýmlamalýdýr
    void WriteToFile(const std::string& eventData);
    std::string GetEventName(int eventId); // Event ID'ye göre açýklama getiren fonksiyon
    std::string ConvertUnixTimeToReadableTime(DWORD unixTime); // Unix zaman damgasýný insan tarafýndan okunabilir tarihe çevirir
    
   
};

#endif // EVENTTRACKER_H
