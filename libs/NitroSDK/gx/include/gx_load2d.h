#pragma once

#include "types.h"

void GXS_EndLoadOBJExtPltt(void);
// Copies size bytes from src to 0x68a0000 + offset (sub OBJ extended palette, bank I); DMA channel when in use, else
// MIi_CpuCopy32.
void GXS_LoadOBJExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the sub-screen OBJ extended palette (bank I): keeps the mask the bank group returns.
void GXS_BeginLoadOBJExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears it.
void GXS_EndLoadBGExtPltt(void);
// Copies size bytes from src to 0x6898000 + offset (sub BG extended palette, bank H); DMA channel when in use, else
// MIi_CpuCopy32.
void GXS_LoadBGExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the sub-screen BG extended palette (bank H): keeps the mask the bank group returns.
void GXS_BeginLoadBGExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears the state.
void GX_EndLoadOBJExtPltt(void);
// Copies size bytes from src to the main OBJ extended palette at offset from the base set by the begin call.
void GX_LoadOBJExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the main-screen OBJ extended palette: keeps the bank mask and sets the base (0x6890000 for bank F,
// 0x6894000 for G).
void GX_BeginLoadOBJExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears the load state.
void GX_EndLoadBGExtPltt(void);
// Copies size bytes from src to the main BG extended palette at offset (relative to the base set by the begin call);
// uses the DMA channel when one is in use, else MIi_CpuCopy32.
void GX_LoadBGExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the main-screen BG extended palette: asks the bank group for its mask, keeps it, and sets the load
// base (0x6880000 for bank E, 0x6894000 with a 0x4000 offset for G alone, 0x6890000 for F or F and G).
void GX_BeginLoadBGExtPltt(void);

void GXS_LoadBG3Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG3 character data at offset.
void GX_LoadBG3Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG2 character data at offset.
void GXS_LoadBG2Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG2 character data at offset.
void GX_LoadBG2Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG1 character data at offset.
void GXS_LoadBG1Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG1 character data at offset.
void GX_LoadBG1Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG0 character data at offset.
void GXS_LoadBG0Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG0 character data at offset.
void GX_LoadBG0Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG3 screen data at offset.
void GXS_LoadBG3Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG3 screen data at offset.
void GX_LoadBG3Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG2 screen data at offset.
void GXS_LoadBG2Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG2 screen data at offset.
void GX_LoadBG2Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG1 screen data at offset.
void GXS_LoadBG1Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG1 screen data at offset.
void GX_LoadBG1Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG0 screen data at offset.
void GXS_LoadBG0Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG0 screen data at offset.
void GX_LoadBG0Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to sub OBJ character memory at 0x6600000 + offset; DMA for more than 0x30 bytes, else
// MIi_CpuCopy32.
void GXS_LoadOBJ(const void *src, u32 offset, u32 size);
// Copies size bytes from src to main OBJ character memory at 0x6400000 + offset; DMA for more than 0x30 bytes, else
// MIi_CpuCopy32.
void GX_LoadOBJ(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub OAM at 0x7000400 + offset; same cut-over.
void GXS_LoadOAM(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main OAM at 0x7000000 + offset; DMA for more than 0x30 bytes, else MIi_CpuCopy32.
void GX_LoadOAM(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub OBJ palette at 0x5000600 + offset; same cut-over.
void GXS_LoadOBJPltt(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main OBJ palette at 0x5000200 + offset; same cut-over.
void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub BG palette at 0x5000400 + offset; same cut-over.
void GXS_LoadBGPltt(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main BG palette at 0x5000000 + offset; DMA for more than 0x1c bytes, else
// MIi_CpuCopy16.
void GX_LoadBGPltt(const void *src, u32 offset, u32 size);
