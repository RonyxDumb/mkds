#include "00/Lib/DWC/shop_access_point_key.h"

#include "00/Lib/DWC/ssid_wep_decode.h"
#include "00/Lib/GameSpy/stream_cipher.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "cpu_copy_fill.h"

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
