#pragma once

#include "types.h"

u32 ComputeProfileInfoCrc(const u32 *table, const void *data, u32 length);
u16 Crc16(const u16 *table, const u8 *data, u32 length);
u8 ComputeFriendCrc(const u8 *table, const void *data, u32 length);
void ComputeProfileInfoCrcImpl(const u32 *table, u32 *crc, const u8 *data, u32 length);
void GenerateProfileInfoCrcLookupTable(u32 *table, u32 polynomial);
void Crc16Continue(const u16 *table, u16 *crc, const u8 *data, u32 length);
void SomeHashing(u16 *table, u32 polynomial);
void Friend_ComputeCrcImpl(const u8 *table, u8 *crc, const u8 *data, u32 length);
void GenerateFriendCrcLookupTable(u8 *table, u32 polynomial);
