#pragma once

#include "types.h"

u32 Crc32(const u32 *table, const void *data, u32 length);
u16 Crc16(const u16 *table, const u8 *data, u32 length);
u8 Crc8(const u8 *table, const void *data, u32 length);
void Crc32Continue(const u32 *table, u32 *crc, const u8 *data, u32 length);
void Crc32InitTable(u32 *table, u32 polynomial);
void Crc16Continue(const u16 *table, u16 *crc, const u8 *data, u32 length);
void Crc16InitTable(u16 *table, u32 polynomial);
void Crc8Continue(const u8 *table, u8 *crc, const u8 *data, u32 length);
void Crc8InitTable(u8 *table, u32 polynomial);
