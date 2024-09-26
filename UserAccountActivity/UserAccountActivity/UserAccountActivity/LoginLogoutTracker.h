#ifndef LOGINLOGOUTTRACKER_H
#define LOGINLOGOUTTRACKER_H

#include "EventTracker.h"

class LoginLogoutTracker : public EventTracker {
public:
    void TrackEvent() override;
};

#endif // LOGINLOGOUTTRACKER_H
