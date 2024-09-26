#include "AccountCreationTracker.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <winevt.h>

#pragma comment(lib, "wevtapi.lib")

void AccountCreationTracker::TrackEvent() {
    HANDLE hEventLog = OpenEventLog(NULL, L"Security");
    if (hEventLog == NULL) {
        std::cerr << "Olay günlüðü açýlamadý." << std::endl;
        return;
    }

    EVENTLOGRECORD* pBuffer = (EVENTLOGRECORD*)malloc(0x10000);
    DWORD dwBytesRead = 0, dwMinBytesNeeded = 0;

    while (ReadEventLog(hEventLog, EVENTLOG_SEQUENTIAL_READ | EVENTLOG_FORWARDS_READ,
        0, pBuffer, 0x10000, &dwBytesRead, &dwMinBytesNeeded)) {
        EVENTLOGRECORD* pRecord = pBuffer;

        while ((BYTE*)pRecord < (BYTE*)pBuffer + dwBytesRead) {
            // Olay ID'sini kontrol et (hesap oluþturma ID'si: 4720)
            if (pRecord->EventID == 4720) {
                std::string eventName = GetEventName(pRecord->EventID); // Olay ismi alýnýyor

                // Unix timestamp'i okunabilir bir tarihe çevir
                std::string readableTime = ConvertUnixTimeToReadableTime(pRecord->TimeGenerated);

                std::string eventData = "Event ID: " + std::to_string(pRecord->EventID) + " (" + eventName + ") occurred at: " + std::to_string(pRecord->TimeGenerated);
                std::cout << eventData << std::endl;
                WriteToFile(eventData);
            }

            pRecord = (EVENTLOGRECORD*)((BYTE*)pRecord + pRecord->Length);
        }
    }

    free(pBuffer);
    CloseEventLog(hEventLog);
}
