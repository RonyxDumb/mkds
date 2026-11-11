#include "00/code_0218f7f8.h"

u32 gpiResetProfile(u32 connection, u32 profile) {
    u32 result;
    u32 profileAddress = profile;
    result = 0u;
    *(u32 *) ((profileAddress) + 8u) = result;
    *(u32 *) ((profileAddress) + 16u) = result;
    *(u32 *) ((profileAddress) + 20u) = result;
    *(u32 *) ((profileAddress) + 24u) = result;
    result = 1u;
    return result;
}
