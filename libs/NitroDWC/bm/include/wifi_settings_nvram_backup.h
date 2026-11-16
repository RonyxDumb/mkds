#pragma once

#include "types.h"

typedef struct DWCWiFiInfo {
    /* 00 */ u64 mAttestedUserId;
    /* 08 */ u64 mNotAttestedId;
    /* 10 */ u16 mPass;
    /* 12 */ u16 mRandomHistory;
} DWCWiFiInfo;

// States of NVRAMm_ExecuteCommand. READ and WRITE_ENABLE are the two commands the callers pass. After the write enable
// word the machine checks that the chip took it (CHECK_WRITE_ENABLED, bit 1 of the status byte), sends the page
// (PAGE_WRITE) and polls the status until its bit 0 clears (WAIT_WRITE_DONE). A status error bit or more than 4000 ms
// of waiting goes to WRITE_FAILED. FINISH only sends a word and is never entered by this code.
#define NVRAM_STATE_READ 1
#define NVRAM_STATE_WRITE_ENABLE 2
#define NVRAM_STATE_PAGE_WRITE 3
#define NVRAM_STATE_CHECK_WRITE_ENABLED 4
#define NVRAM_STATE_WAIT_WRITE_DONE 5
#define NVRAM_STATE_WRITE_FAILED 6
#define NVRAM_STATE_FINISH 7

extern u16 nv_result;
extern u8 Work[32];
extern u32 nv_cb_occurred;

u8 *StructDW_SomeFn_2_from_thumb(const DWCWiFiInfo *info);
u16 FifoHandler_4_from_thumb(u32 tag, u32 data, u32 err);
BOOL writeDisable(void);
BOOL StructDC_SomeFn_5_from_thumb(const u8 *src, u32 address, u32 size, const u8 *work);
void writeNvram(u32 address, u16 size, void *data);
BOOL readNvram(u32 address, u32 size, void *buf);
BOOL NVRAMm_ExecuteCommand(u32 state, u32 addr, u16 size, u8 *srcp);
BOOL DWC_BACKUPlCheckAddress(const u8 *address);
BOOL DWC_BACKUPlCheckIp(const u8 *ip, const u8 *mask);
BOOL StructDCInner_HasAnyUnk_from_thumb(const u8 *ssid);
void DWCi_BACKUPlConvMaskAddr(u32 mask, u8 *buf);
u8 DWCi_BACKUPlConvMaskCidr(const u8 *mask);

void WritePackedWiFiInfo(const u8 *packedWiFiInfo);

typedef struct DWCWiFiInfo DWCWiFiInfo;

void StructDW_MaybeCreate_from_thumb(DWCWiFiInfo *info);
BOOL StructDW_SomeFn_0_from_thumb(const DWCWiFiInfo *info, u8 *work);

u32 StructDC_SomeFn_0_from_thumb(u8 *data);
u32 WriteFlaggedNvramEntries(void *data, int *flags, void *verifyBuffer);
u32 StructDC_SomeFn_1_from_thumb(void *buffer);
u32 StructDC_SomeFn_3_from_thumb(u16 *buffer);
