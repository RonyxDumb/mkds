#include "00/Lib/DWC/code_0218a67c.h"
#include "00/code_0218a000.h"

#include "00/Lib/DWC/code_0218a350.h"
#include "00/Lib/GameSpy/code_0218a71c.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"

u8 gShopSsidPrefix[9] = {0x4e, 0x44, 0x57, 0x43, 0x53, 0x48, 0x41, 0x50, 0};

void GOADecrypt(GOACryptState *state, u8 *data, int length) {
    u8 decrypted;
    int index;
    index = 0;
    if (0 < length) {
        do {
            decrypted = GOADecryptByte(state, data[index]);
            data[index] = decrypted;
            index = index + 1;
        } while (index < length);
    }
}

BOOL DWCi_AC_CheckNintendoShopAP(const u8 *ssid) {
    int compare;
    u8 decoded[24];
    DecodeSsid(ssid, decoded);
    compare = memcmp((const u8 *) ((u32) decoded), gShopSsidPrefix, 8);
    if (compare == 0) {
        return 1;
    }
    return 0;
}

void DWCi_AC_GetNintendoShopWepKey(const u8 *ssid, u8 *wepKey) {
    u8 decoded[24];
    DecodeSsid(ssid, decoded);
    MakeShopWepKey(decoded, wepKey);
}

void DWCi_AC_GetPostalCode(const u8 *ssid, char *postalCode) {
    u8 decoded[24];
    DecodeSsid(ssid, decoded);
    if (memcmp(decoded, gShopSsidPrefix, 8) == 0) {
        MI_CpuCopy8(decoded + 8, postalCode, 10);
    }
}
