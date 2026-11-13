// I/O register addresses.
#pragma once

#include "types.h"

#define reg_GX_DISPCNT (*(vu32 *) 0x04000000)
#define reg_GX_DISPSTAT (*(vu16 *) 0x04000004)
#define reg_GX_VCOUNT (*(vu16 *) 0x04000006)
#define reg_G2_BG0CNT (*(vu16 *) 0x04000008)
#define reg_G2_BG1CNT (*(vu16 *) 0x0400000a)
#define reg_G2_BG2CNT (*(vu16 *) 0x0400000c)
#define reg_G2_BG3CNT (*(vu16 *) 0x0400000e)
#define reg_G2_BG0OFS (*(vu32 *) 0x04000010)
#define reg_G2_BG1OFS (*(vu32 *) 0x04000014)
#define reg_G2_BG2OFS (*(vu32 *) 0x04000018)
#define reg_G2_BG3OFS (*(vu32 *) 0x0400001c)
#define reg_G2_BG2PA (*(vu16 *) 0x04000020)
#define reg_G2_BG2PD (*(vu16 *) 0x04000026)
#define reg_G2_BG3PA (*(vu16 *) 0x04000030)
#define reg_G2_BG3PD (*(vu16 *) 0x04000036)
#define reg_G2_WIN0H (*(vu16 *) 0x04000040)
#define reg_G2_WIN1H (*(vu16 *) 0x04000042)
#define reg_G2_WIN0V (*(vu16 *) 0x04000044)
#define reg_G2_WIN1V (*(vu16 *) 0x04000046)
#define reg_G2_WININ (*(vu16 *) 0x04000048)
#define reg_G2_WINOUT (*(vu16 *) 0x0400004a)
#define reg_G2_BLDCNT (*(vu16 *) 0x04000050)
#define reg_G3X_DISP3DCNT (*(vu16 *) 0x04000060)
#define reg_GX_DISPCAPCNT (*(vu32 *) 0x04000064)
#define reg_GX_MASTER_BRIGHT (*(vu16 *) 0x0400006c)
#define reg_OS_TM0CNT_L (*(vu16 *) 0x04000100)
#define reg_PAD_KEYINPUT (*(vu16 *) 0x04000130)
#define reg_PXI_SUBPINTF (*(vu16 *) 0x04000180)
#define reg_PXI_SUBP_FIFO_CNT (*(vu16 *) 0x04000184)
#define reg_PXI_SEND_FIFO (*(vu32 *) 0x04000188)
#define reg_MI_MCCNT0 (*(vu16 *) 0x040001a0)
#define reg_MI_MCCNT1 (*(vu32 *) 0x040001a4)
#define reg_MI_MCCNT0_HI (*(vu8 *) 0x040001a1)
#define reg_MI_MCCMD0 (*(vu8 *) 0x040001a8)
#define reg_MI_MCCMD1 (*(vu8 *) 0x040001a9)
#define reg_MI_MCCMD2 (*(vu8 *) 0x040001aa)
#define reg_MI_MCCMD3 (*(vu8 *) 0x040001ab)
#define reg_MI_MCCMD4 (*(vu8 *) 0x040001ac)
#define reg_MI_MCCMD5 (*(vu8 *) 0x040001ad)
#define reg_MI_MCCMD6 (*(vu8 *) 0x040001ae)
#define reg_MI_MCCMD7 (*(vu8 *) 0x040001af)
#define reg_MI_EXMEMCNT (*(vu16 *) 0x04000204)
#define reg_OS_IME (*(vu16 *) 0x04000208)
#define reg_OS_IE (*(vu32 *) 0x04000210)
#define reg_OS_IF (*(vu32 *) 0x04000214)
#define reg_GX_VRAMCNT_A (*(vu8 *) 0x04000240)
#define reg_GX_VRAMCNT_B (*(vu8 *) 0x04000241)
#define reg_GX_VRAMCNT_C (*(vu8 *) 0x04000242)
#define reg_GX_VRAMCNT_D (*(vu8 *) 0x04000243)
#define reg_GX_VRAMCNT_E (*(vu8 *) 0x04000244)
#define reg_GX_VRAMCNT_F (*(vu8 *) 0x04000245)
#define reg_GX_VRAMCNT_G (*(vu8 *) 0x04000246)
#define reg_GX_VRAMCNT_H (*(vu8 *) 0x04000248)
#define reg_GX_VRAMCNT_I (*(vu8 *) 0x04000249)
#define reg_CP_DIVCNT (*(vu16 *) 0x04000280)
#define reg_CP_DIV_NUMER (*(vu64 *) 0x04000290)
#define reg_CP_DIV_DENOM (*(vu64 *) 0x04000298)
#define reg_CP_DIV_RESULT (*(vu64 *) 0x040002a0)
#define reg_CP_DIVREM_RESULT (*(vu64 *) 0x040002a8)
#define reg_CP_DIV_NUMER_LO (*(vu32 *) 0x04000290)
#define reg_CP_DIV_RESULT_LO (*(vu32 *) 0x040002a0)
#define reg_CP_DIVREM_RESULT_LO (*(vu32 *) 0x040002a8)
#define reg_CP_SQRTCNT (*(vu16 *) 0x040002b0)
#define reg_CP_SQRT_RESULT (*(vu32 *) 0x040002b4)
#define reg_CP_SQRT_PARAM (*(vu64 *) 0x040002b8)
#define reg_GX_POSTFLG (*(vu16 *) 0x04000300)
#define reg_GX_POWCNT (*(vu16 *) 0x04000304)
#define reg_G3X_ALPHA_TEST_REF (*(vu16 *) 0x04000340)
#define reg_G3X_CLEAR_COLOR (*(vu32 *) 0x04000350)
#define reg_G3X_CLEAR_DEPTH (*(vu16 *) 0x04000354)
#define reg_G3X_CLRIMAGE_OFFSET (*(vu16 *) 0x04000356)
#define reg_G3X_FOG_COLOR (*(vu32 *) 0x04000358)
#define reg_G3X_FOG_OFFSET (*(vu16 *) 0x0400035c)
#define reg_G3X_GXFIFO (*(vu32 *) 0x04000400)
#define reg_G3_MTX_MODE (*(vu32 *) 0x04000440)
#define reg_G3_MTX_PUSH (*(vu32 *) 0x04000444)
#define reg_G3_MTX_POP (*(vu32 *) 0x04000448)
#define reg_G3_MTX_STORE (*(vu32 *) 0x0400044c)
#define reg_G3_MTX_RESTORE (*(vu32 *) 0x04000450)
#define reg_G3_MTX_IDENTITY (*(vu32 *) 0x04000454)
#define reg_G3_MTX_LOAD_4x4 (*(vu32 *) 0x04000458)
#define reg_G3_MTX_LOAD_4x3 (*(vu32 *) 0x0400045c)
#define reg_G3_MTX_SCALE (*(vu32 *) 0x0400046c)
#define reg_G3_MTX_TRANS (*(vu32 *) 0x04000470)
#define reg_G3_COLOR (*(vu32 *) 0x04000480)
#define reg_G3_TEXCOORD (*(vu32 *) 0x04000488)
#define reg_G3_VTX_16 (*(vu32 *) 0x0400048c)
#define reg_G3_VTX_10 (*(vu32 *) 0x04000490)
#define reg_G3_VTX_DIFF (*(vu32 *) 0x04000494)
#define reg_G3_POLYGON_ATTR (*(vu32 *) 0x040004a4)
#define reg_G3_TEXIMAGE_PARAM (*(vu32 *) 0x040004a8)
#define reg_G3_PLTT_BASE (*(vu32 *) 0x040004ac)
#define reg_G3_DIF_AMB (*(vu32 *) 0x040004c0)
#define reg_G3_SPE_EMI (*(vu32 *) 0x040004c4)
#define reg_G3_BEGIN_VTXS (*(vu32 *) 0x04000500)
#define reg_G3_END_VTXS (*(vu32 *) 0x04000504)
#define reg_G3_SWAP_BUFFERS (*(vu32 *) 0x04000540)
#define reg_G3X_GXSTAT (*(vu32 *) 0x04000600)
#define reg_GXS_DB_DISPCNT (*(vu32 *) 0x04001000)
#define reg_G2S_DB_BG0CNT (*(vu16 *) 0x04001008)
#define reg_G2S_DB_BG1CNT (*(vu16 *) 0x0400100a)
#define reg_G2S_DB_BG2CNT (*(vu16 *) 0x0400100c)
#define reg_G2S_DB_BG3CNT (*(vu16 *) 0x0400100e)
#define reg_G2S_DB_BG0OFS (*(vu32 *) 0x04001010)
#define reg_G2S_DB_BG1OFS (*(vu32 *) 0x04001014)
#define reg_G2S_DB_BG2OFS (*(vu32 *) 0x04001018)
#define reg_G2S_DB_BG3OFS (*(vu32 *) 0x0400101c)
#define reg_G2S_DB_BG2PA (*(vu16 *) 0x04001020)
#define reg_G2S_DB_BG2PD (*(vu16 *) 0x04001026)
#define reg_G2S_DB_BG3PA (*(vu16 *) 0x04001030)
#define reg_G2S_DB_BG3PD (*(vu16 *) 0x04001036)
#define reg_G2S_DB_WIN0H (*(vu16 *) 0x04001040)
#define reg_G2S_DB_WIN0V (*(vu16 *) 0x04001044)
#define reg_G2S_DB_WININ (*(vu16 *) 0x04001048)
#define reg_G2S_DB_WINOUT (*(vu16 *) 0x0400104a)
#define reg_G2S_DB_BLDCNT (*(vu16 *) 0x04001050)
#define reg_GXS_DB_MASTER_BRIGHT (*(vu16 *) 0x0400106c)
#define reg_CP_SQRT_PARAM_LO (*(vu32 *) 0x040002b8)
#define reg_EMU_PORT (*(vu32 *) 0x04fff200)
#define reg_PXI_RECV_FIFO (*(vu32 *) 0x04100000)
#define reg_MI_MCD1 (*(vu32 *) 0x04100010)

// Bits of the background control registers.
#define REG_G2_BG0CNT_PRIORITY_MASK 0x0003
#define REG_G2_BG1CNT_PRIORITY_MASK 0x0003
#define REG_G2_BG2CNT_PRIORITY_MASK 0x0003
#define REG_G2_BG3CNT_PRIORITY_MASK 0x0003
#define REG_G2S_DB_BG0CNT_PRIORITY_MASK 0x0003
#define REG_G2S_DB_BG1CNT_PRIORITY_MASK 0x0003
#define REG_G2S_DB_BG2CNT_PRIORITY_MASK 0x0003
#define REG_G2S_DB_BG3CNT_PRIORITY_MASK 0x0003
#define REG_G2_BG0CNT_MOSAIC_MASK 0x0040
#define REG_G2_BG1CNT_MOSAIC_MASK 0x0040
#define REG_G2_BG2CNT_MOSAIC_MASK 0x0040
#define REG_G2_BG3CNT_MOSAIC_MASK 0x0040
#define REG_G2S_DB_BG0CNT_MOSAIC_MASK 0x0040
#define REG_G2S_DB_BG1CNT_MOSAIC_MASK 0x0040
#define REG_G2S_DB_BG2CNT_MOSAIC_MASK 0x0040
#define REG_G2S_DB_BG3CNT_MOSAIC_MASK 0x0040

// Memory map addresses.
#define HW_BG_PLTT ((u16 *) 0x05000000)
#define HW_DB_BG_PLTT ((u16 *) 0x05000400)
#define HW_OAM ((u16 *) 0x07000000)
#define HW_DB_OAM ((u16 *) 0x07000400)
#define HW_THREADINFO_MAIN 0x027fffa0
#define HW_BUTTON_XY_BUF ((vu16 *) 0x27fffa8)
#define HW_REAL_TIME_CLOCK_BUF 0x027ffde8
#define PAD_DETECT_FOLD_MASK 0x8000
#define REG_CP_DIVCNT_BUSY_MASK 0x8000
#define REG_CP_SQRTCNT_BUSY_MASK 0x8000
#define REG_GX_DISPCNT_DISPLAY_MASK 0x1f00
#define REG_GXS_DB_DISPCNT_DISPLAY_MASK 0x1f00
