#pragma once

#include "types.h"

void wlmenu_init(void);
BOOL savc_decryptBlock(u32 *cursor, u32 byteCount, u32 expectedFirstWord);
void savc_encryptBlock(u32 *cursor, u32 byteCount);
s32 savc_findEncryptionSeed(u32 value, u32 expected);
BOOL savc_handleBlockFooter(u8 *bytes, u32 byteCount, u32 skipTickBytes);
void savc_generateBlockFooter(u8 *bytes, u32 byteCount, u32 skipTickBytes);
u16 savc_calculateChecksum(u8 *cursor, u32 byteCount);
void savc_handleError(s32 errorCode);
BOOL savc_lockCardBackup(void);
void savc_unlockCardBackup(void);
