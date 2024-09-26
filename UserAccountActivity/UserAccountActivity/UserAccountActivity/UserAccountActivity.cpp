#include "AccountCreationTracker.h"
#include "AccountModificationTracker.h"
#include "AccountDeletionTracker.h"
#include "LoginLogoutTracker.h"

int main() {
    // Hesap oluşturma olaylarını izler
    AccountCreationTracker creationTracker;
    creationTracker.TrackEvent();

    // Hesap değiştirme olaylarını izler
    AccountModificationTracker modificationTracker;
    modificationTracker.TrackEvent();

    // Hesap silme olaylarını izler
    AccountDeletionTracker deletionTracker;
    deletionTracker.TrackEvent();

    // Giriş/çıkış olaylarını izler
    LoginLogoutTracker loginTracker;
    loginTracker.TrackEvent();

    return 0;
}
