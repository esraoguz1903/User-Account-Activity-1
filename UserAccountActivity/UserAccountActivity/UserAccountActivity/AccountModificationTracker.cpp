/*#include "AccountModificationTracker.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <winevt.h>

#pragma comment(lib, "wevtapi.lib")

void AccountModificationTracker::TrackEvent() {
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
            // Olay ID'sini kontrol et (hesap etkinleþtirme ID'si: 4722)
            if (pRecord->EventID == 4722) {
                std::string eventName = GetEventName(pRecord->EventID); // Olay ismi alýnýyor
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
*/
#include "AccountModificationTracker.h"
#include <iostream>
#include <windows.h>
#include <winevt.h>

#pragma comment(lib, "wevtapi.lib")

void AccountModificationTracker::TrackEvent() {
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
            // Sadece þifre ve kullanýcý adý deðiþikliklerini logla
            if (pRecord->EventID == 4723 || pRecord->EventID == 4724 || pRecord->EventID == 4781) {
                std::string eventName = GetEventName(pRecord->EventID);

                // Unix timestamp'i okunabilir bir tarihe çevir
                std::string readableTime = ConvertUnixTimeToReadableTime(pRecord->TimeGenerated);

                std::string eventData = "Event ID: " + std::to_string(pRecord->EventID) + " (" + eventName + ") occurred at: " + std::to_string(pRecord->TimeGenerated);
                std::cout << eventData << std::endl;
                WriteToFile(eventData); // EventTracker sýnýfýndaki metodu çaðýrýyoruz
            }

            pRecord = (EVENTLOGRECORD*)((BYTE*)pRecord + pRecord->Length);
        }
    }

    free(pBuffer);
    CloseEventLog(hEventLog);
}
