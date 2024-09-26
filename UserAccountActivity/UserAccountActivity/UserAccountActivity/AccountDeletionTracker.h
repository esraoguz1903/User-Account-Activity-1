#ifndef ACCOUNTDELETIONTRACKER_H
#define ACCOUNTDELETIONTRACKER_H

#include "EventTracker.h"

class AccountDeletionTracker : public EventTracker {
public:
    void TrackEvent() override;
};

#endif // ACCOUNTDELETIONTRACKER_H
