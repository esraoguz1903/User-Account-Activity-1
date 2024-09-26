#ifndef ACCOUNTCREATIONTRACKER_H
#define ACCOUNTCREATIONTRACKER_H

#include "EventTracker.h"

class AccountCreationTracker : public EventTracker {
public:
    void TrackEvent() override;
};

#endif // ACCOUNTCREATIONTRACKER_H
