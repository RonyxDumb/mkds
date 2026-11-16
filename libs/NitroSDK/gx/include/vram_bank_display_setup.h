#pragma once

#include "types.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "fixed_point_graphics_setup.h"

// Sets the display mode of the NtrMain screen (DISPCNT bits 16-17) and its background mode (bits 0-3), and saves the
// display mode. While the display is off the mode written is 0.
void ConfigureDispcntDisplay(u16 dispMode, u32 bgMode, s32 bg0As);
// Turns the NtrMain display on again with the saved display mode (graphics mode if none was saved).
void GX_DispOn(void);
// Saves the display mode of the NtrMain screen and turns its display off.
void SomeDispcntInit(void);
// Enables (enable != 0) or disables the V-blank interrupt flag in DISPSTAT; returns its previous value.
u32 GX_VBlankIntr(s32 enable);
// Powers the graphics hardware, clears the VRAM bank state, takes the VRAM lock id, clears both display register
// blocks (by DMA fill when a DMA channel is set) and sets the background matrices to identity.
void Gfx_Initialize(void);
// Clears the bank masks of every VRAM group and the bank control registers.
void Gfx_InitializeState(void);
// Returns the byte size of the banks given to the sub screen sprites.
u32 GX_GetSizeOfSubOBJ(void);
// Returns the byte size of the banks given to the NtrMain screen sprites.
u32 GX_GetSizeOfOBJ(void);
// Releases the banks listed in the mask at group: stores 0 there, turns the banks off and frees their locks.
// Returns the
// mask.
u32 GX_disableBankForX_(u16 *group);
// Clears bit 31 of DISPCNT (0x4001000) first. Turns off and unlocks the banks of the sub screen sprite extended
// palette group; returns the former bank mask.
u32 GX_DisableBankForOBJExtPltt(void);
// Clears bit 30 of DISPCNT (0x4001000) first. Turns off and unlocks the banks of the sub screen background extended
// palette group; returns the former bank mask.
u32 GX_DisableBankForBGExtPltt(void);
// Turns off and unlocks the banks of the sub screen sprite group; returns the former bank mask.
u32 GX_DisableBankForSubOBJ(void);
// Turns off and unlocks the banks of the sub screen background group; returns the former bank mask.
u32 GX_DisableBankForSubBG(void);
// Turns off and unlocks the banks of the direct access group; returns the former bank mask.
u32 GX_DisableBankForLCDC(void);
// Turns off and unlocks the banks of the second processor group; returns the former bank mask.
u32 GX_DisableBankForARM7(void);
// Turns off and unlocks the banks of the clear image group; returns the former bank mask.
u32 GX_DisableBankForClearImage(void);
// Turns off and unlocks the banks of the texture palette group; returns the former bank mask.
u32 GX_DisableBankForTexPltt(void);
// Turns off and unlocks the banks of the texture group; returns the former bank mask.
u32 GX_DisableBankForTex(void);
// Clears bit 31 of DISPCNT (0x4000000) first. Turns off and unlocks the banks of the sprite extended palette group;
// returns the former bank mask.
u32 GX_DisableBankForOBJExtPltt(void);
// Clears bit 30 of DISPCNT (0x4000000) first. Turns off and unlocks the banks of the background extended palette
// group; returns the former bank mask.
u32 GX_DisableBankForBGExtPltt(void);
// Turns off and unlocks the banks of the sprite group; returns the former bank mask.
u32 GX_DisableBankForOBJ(void);
// Turns off and unlocks the banks of the background group; returns the former bank mask.
u32 GX_DisableBankForBG(void);
// Moves the banks listed in the mask at group back to the direct access group, enabled in mode 0; returns the mask.
u16 resetBankForX_(u16 *group);
// Clears bit 31 of DISPCNT (0x4001000) first. Gives the banks of the sub screen sprite extended palette group back
// to direct access; returns the former bank mask.
u16 GX_ResetBankForSubOBJExtPltt(void);
// Clears bit 30 of DISPCNT (0x4001000) first. Gives the banks of the sub screen background extended palette group
// back to direct access; returns the former bank mask.
u16 GX_ResetBankForSubBGExtPltt(void);
// Gives the banks of the sub screen sprite group back to direct access; returns the former bank mask.
u16 GX_ResetBankForSubOBJ(void);
// Gives the banks of the sub screen background group back to direct access; returns the former bank mask.
u16 GX_ResetBankForSubBG(void);
// Gives the banks of the clear image group back to direct access; returns the former bank mask.
u16 GX_ResetBankForClearImage(void);
// Gives the banks of the texture palette group back to direct access; returns the former bank mask.
u16 GX_ResetBankForTexPltt(void);
// Gives the banks of the texture group back to direct access; returns the former bank mask.
u16 GX_ResetBankForTex(void);
// Clears bit 31 of DISPCNT (0x4000000) first. Gives the banks of the sprite extended palette group back to direct
// access; returns the former bank mask.
u16 GX_ResetBankForOBJExtPltt(void);
// Clears bit 30 of DISPCNT (0x4000000) first. Gives the banks of the background extended palette group back to
// direct access; returns the former bank mask.
u16 GX_ResetBankForBGExtPltt(void);
// Assigns the banks in the mask to the sub screen sprite extended palette group and writes their bank control
// registers. Sets bit 31 of DISPCNT (0x4001000) for a non-empty mask and clears it for 0.
void GX_SetBankForSubOBJExtPltt(u32 subObjExtPltt);
// Assigns the banks in the mask to the sub screen background extended palette group and writes their bank control
// registers. Sets bit 30 of DISPCNT (0x4001000) for a non-empty mask and clears it for 0.
void GX_SetBankForSubBGExtPltt(u32 subBgExtPltt);
// Assigns the banks in the mask to the sub screen sprite group and writes their bank control registers.
void GX_SetBankForSubOBJ(u32 subObj);
// Assigns the banks in the mask to the sub screen background group and writes their bank control registers.
void GX_SetBankForSubBG(s32 subBg);
// Adds the banks to the direct access group and enables them for it.
void GX_SetBankForLCDC(u32 lcdc);
// Assigns the banks in the mask to the second processor group and writes their bank control registers.
void GX_SetBankForARM7(s32 arm7);
// Assigns the banks in the mask to the clear image group and writes their bank control registers.
void GX_SetBankForClearImage(u32 clrImg);
// Assigns the banks in the mask to the texture palette group and writes their bank control registers.
void GX_SetBankForTexPltt(s32 texPltt);
// Assigns the banks in the mask to the texture group and writes their bank control registers.
void GX_SetBankForTex(u32 tex);
// Assigns the banks in the mask to the sprite extended palette group and writes their bank control registers. Sets
// bit 31 of DISPCNT (0x4000000) for a non-empty mask and clears it for 0.
void GX_SetBankForOBJExtPltt(u32 objExtPltt);
// Assigns the banks in the mask to the background extended palette group and writes their bank control registers.
// Sets bit 30 of DISPCNT (0x4000000) for a non-empty mask and clears it for 0.
void GX_SetBankForBGExtPltt(s32 bgExtPltt);
// Assigns the banks in the mask to the sprite group and writes their bank control registers.
void GX_SetBankForOBJ(s32 obj);
// Assigns the banks in the mask to the background group and writes their bank control registers.
void GX_SetBankForBG(s32 bg);
// Enables the banks listed in the mask for direct access (mode 0).
void GX_VRAMCNT_SetLCDC_(u32 lcdc);

// Returns the total byte size of the banks whose bits (0 to 8) are set in bits.
u32 GX_GetSizeOfX_(u32 bits);

// Returns the texture group's bank mask.
u32 GX_GetBankForTex(void);

// 1 while the NtrMain display is on; SomeDispcntInit clears it, GX_DispOn sets it, ConfigureDispcntDisplay writes mode 0 while it is
// 0 and clears it when its first argument is 0. Initial value 1.
extern u16 gDispOn[];

// Id from Os_AllocateLockId, taken in Gfx_Initialize; GX_disableBankForX_ hands it to the lock-table release.
extern u16 g_Gfx_VramLockId;

// Display mode value (the bits at 16 and up of the NtrMain display word) kept while the display is off and by
// ConfigureDispcntDisplay; GX_DispOn writes it back.
extern u16 g_CurrentDisplayMode;

// 13 bank-mask halfwords: [0] banks that are directly accessible, then the banks given to the background, sprites,
// second processor, texture, texture palette, clear image, background and sprite extended palettes, sub background, sub
// sprites, sub background and sub sprite extended palettes.
extern u16 g_Gfx_State[];

extern u32 g_GfxDmaChannel;
extern s32 sDayOfYear[12];
