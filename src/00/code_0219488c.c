#include "00/code_0219488c.h"
#include "00/code_02194840.h"
#include "00/code_021948bc.h"

s32 gpiFindProfileByUser(GpConnection *connection, const char *nick, const char *email, void **profile) {
    GPIFindProfileByUserData data;

    data.mNick = nick;
    data.mEmail = email;
    data.mProfile = profile;
    data.mFound = FALSE;
    GpiForEachProfileWhileNonZero(connection, gpiCheckProfileForUser, &data);
    if (data.mFound == FALSE) {
        *profile = NULL;
    }
    return 0;
}
