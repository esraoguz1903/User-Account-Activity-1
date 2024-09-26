#ifndef ACCOUNTMODIFICATIONTRACKER_H
#define ACCOUNTMODIFICATIONTRACKER_H

#include "EventTracker.h"

class AccountModificationTracker : public EventTracker {
public:
    void TrackEvent() override;
};

#endif // ACCOUNTMODIFICATIONTRACKER_H
