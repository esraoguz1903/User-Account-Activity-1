#ifndef EVENTTRACKER_H
#define EVENTTRACKER_H

#include <string>
#include <wtypes.h>
//#include <Windows.h>
class EventTracker {
public:
    virtual void TrackEvent() = 0; // T�m alt s�n�flar bu fonksiyonu tan�mlamal�d�r
    void WriteToFile(const std::string& eventData);
    std::string GetEventName(int eventId); // Event ID'ye g�re a��klama getiren fonksiyon
    std::string ConvertUnixTimeToReadableTime(DWORD unixTime); // Unix zaman damgas�n� insan taraf�ndan okunabilir tarihe �evirir
    
   
};

#endif // EVENTTRACKER_H
