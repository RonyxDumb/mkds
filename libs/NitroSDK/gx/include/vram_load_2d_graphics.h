#pragma once

#include "types.h"

void GXS_EndLoadOBJExtPltt(void);
// Copies size bytes from src to 0x68a0000 + offset (sub OBJ extended palette, bank I); DMA channel when in use, else
// Mem_CpuCopy32.
void GXS_LoadOBJExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the sub-screen OBJ extended palette (bank I): keeps the mask the bank group returns.
void GXS_BeginLoadOBJExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears it.
void GXS_EndLoadBGExtPltt(void);
// Copies size bytes from src to 0x6898000 + offset (sub BG extended palette, bank H); DMA channel when in use, else
// Mem_CpuCopy32.
void GXS_LoadBGExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the sub-screen BG extended palette (bank H): keeps the mask the bank group returns.
void GXS_BeginLoadBGExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears the state.
void GX_EndLoadOBJExtPltt(void);
// Copies size bytes from src to the NtrMain OBJ extended palette at offset from the base set by the begin call.
void GX_LoadOBJExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the NtrMain-screen OBJ extended palette: keeps the bank mask and sets the base (0x6890000 for bank F,
// 0x6894000 for G).
void GX_BeginLoadOBJExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears the load state.
void GX_EndLoadBGExtPltt(void);
// Copies size bytes from src to the NtrMain BG extended palette at offset (relative to the base set by the begin call);
// uses the DMA channel when one is in use, else Mem_CpuCopy32.
void GX_LoadBGExtPltt(const void *src, u32 offset, u32 size);
// Starts a load into the NtrMain-screen BG extended palette: asks the bank group for its mask, keeps it, and sets the load
// base (0x6880000 for bank E, 0x6894000 with a 0x4000 offset for G alone, 0x6890000 for F or F and G).
void GX_BeginLoadBGExtPltt(void);

void CopyBgData_Bg3_Bottom(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG3 character data at offset.
void CopyBgData_Bg3_Top(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG2 character data at offset.
void CopyBgData_Bg2_Bottom(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG2 character data at offset.
void CopyBgData_Bg2_Top(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG1 character data at offset.
void CopyBgData_Bg1_Bottom(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG1 character data at offset.
void CopyBgData_Bg1_Top(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG0 character data at offset.
void CopyBgData_Bg0_Bottom(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG0 character data at offset.
void CopyBgData_Bg0_Top(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG3 screen data at offset.
void TEQSub_Fn27Impl_Fn29Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG3 screen data at offset.
void TEQSub_Fn11Impl_Fn13Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG2 screen data at offset.
void TEQSub_Fn26Impl_Fn28Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG2 screen data at offset.
void TEQSub_Fn10Impl_Fn12Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG1 screen data at offset.
void TEQSub_Fn25Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG1 screen data at offset.
void TEQSub_Fn9Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG0 screen data at offset.
void TEQSub_Fn24Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain engine BG0 screen data at offset.
void TEQSub_Fn8Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to sub OBJ character memory at 0x6600000 + offset; DMA for more than 0x30 bytes, else
// Mem_CpuCopy32.
void TEQSub_Fn35Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to NtrMain OBJ character memory at 0x6400000 + offset; DMA for more than 0x30 bytes, else
// Mem_CpuCopy32.
void CopyTileDataTop_0(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub OAM at 0x7000400 + offset; same cut-over.
void CopyToOamB(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain OAM at 0x7000000 + offset; DMA for more than 0x30 bytes, else Mem_CpuCopy32.
void CopyToOamA(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub OBJ palette at 0x5000600 + offset; same cut-over.
void TEQSub_Fn30Impl(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain OBJ palette at 0x5000200 + offset; same cut-over.
void CopySomePaletteData(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub BG palette at 0x5000400 + offset; same cut-over.
void CopyPaletteBottom(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the NtrMain BG palette at 0x5000000 + offset; DMA for more than 0x1c bytes, else
// CopyMemory16.
void CopyPaletteTop(const void *src, u32 offset, u32 size);

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 g_SomeSubBgExtPlt;

// Address the OBJ extended palette load starts from; 0 when idle.
extern u32 g_SomeObjExtPltLcdcBlock;

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 g_SomeObjExtPlt;

// Subtracted from the load offset: 0x4000 when only bank G is mapped, else 0.
extern u32 gBgExtPaletteLoadBaseOffset;

// Address the BG extended palette load starts from; set by the begin call, 0 when idle.
extern u32 gBgExtPaletteLoadBase;

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gBgExtPaletteLoadBankMask;

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 g_SomeSubObjExtPlt;
