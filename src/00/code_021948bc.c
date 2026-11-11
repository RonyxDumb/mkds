#include "00/code_021948bc.h"
#include "code_02139f70.h"

u32 gpiCheckProfileForUser(u32 connection, int profile, GPIFindProfileByUserData *data) {
    int difference;
    u32 *cache;
    cache = *(u32 **) (profile + 0xc);
    if (((cache != NULL) && (difference = strcmp(data->mUnk_00, (const char *) (*cache)), difference == 0)) &&
        (difference = strcmp(data->mUnk_04, (const char *) (cache[2])), difference == 0)) {
        *data->mUnk_08 = (void *) profile;
        data->mUnk_0c = TRUE;
        return 0;
    }
    return 1;
}
