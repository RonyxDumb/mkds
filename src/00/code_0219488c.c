#include "00/code_0219488c.h"
#include "00/code_02194840.h"
#include "00/code_021948bc.h"

s32 gpiFindProfileByUser(GpConnection *connection, const char *nick, const char *email, void **profile) {
    GPIFindProfileByUserData data;

    data.mUnk_00 = nick;
    data.mUnk_04 = email;
    data.mUnk_08 = profile;
    data.mUnk_0c = FALSE;
    GpiForEachProfileWhileNonZero(connection, gpiCheckProfileForUser, &data);
    if (data.mUnk_0c == FALSE) {
        *profile = NULL;
    }
    return 0;
}
