#pragma once

#include "types.h"

// Waits for the DMA channel, returns the kept mask to the bank group and clears the mask and address.
void GX_EndLoadClearImage(void);
// Copies size bytes from src to the colour image address + 0x20000 (the depth image).
void GX_LoadClearImageDepth(const void *src, u32 size);
// Copies size bytes from src to the colour image address.
void GX_LoadClearImageColor(const void *src, u32 size);
// Keeps the clear-image bank mask and sets the colour image address (0x6800000 for masks 2 and 3, 0x6840000 for 8 and
// 12, 0x67e0000 for 1, 0x6820000 for 4).
void GX_BeginLoadClearImage(void);
// Waits for the DMA channel, returns the kept mask to the bank group and clears the mask and base.
void GX_EndLoadTexPltt(void);
// Copies size bytes from src to the texture palette base + offset; DMA channel when in use, else Mem_CpuCopy32.
void SomeDmaCopy_0(const void *src, u32 offset, u32 size);
// Keeps the texture-palette bank mask and sets the load base from the 8-entry table, indexed by mask >> 4.
void GX_BeginLoadTexPltt(void);
// Waits for the DMA channel, returns the kept mask to the bank group and clears the four state words.
void GX_EndLoadTex(void);
// Copies size bytes from src to the texture banks at offset; a copy that crosses the first run's size is split there,
// the rest goes to the second run base.
void GX_LoadTex(const void *src, u32 offset, u32 size);
// Keeps the texture bank mask and loads that mask's row of the block table: first run base, second run base, first run
// size.
void GX_BeginLoadTex(void);

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gClearImageLoadBankMask;

// Start of the first run of texture banks.
extern u32 gTextureLoadFirstBase;

// Address the texture palette load starts from, from gTexturePaletteBaseTable.
extern u8 *gTexturePaletteLoadBase;

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern s32 gTexturePaletteLoadBankMask;

// Address of the colour slot; the depth slot is 0x20000 above it. For a single bank it lies below that bank.
extern u8 *gClearImageLoadBase;

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gTextureLoadBankMask;

// Start of the second run (0 when the mask is one run).
extern u32 gTextureLoadSecondBase;

// Byte size of the first run.
extern u32 gTextureLoadFirstSize;

// Base address >> 12 of the first bank of each texture palette mask, indexed by mask >> 4 (8 halfwords).
extern const u16 gTexturePaletteBaseTable[];

// 16 rows of 3 halfwords per texture bank mask: first run base >> 12, second run base >> 12, first run size >> 12.
extern const u16 gTextureBlockTable[16][3];
