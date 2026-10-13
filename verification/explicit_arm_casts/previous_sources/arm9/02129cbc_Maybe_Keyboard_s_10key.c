/* Decompiled C draft; module arm9; ROM address 02129cbc. No matching claim. */
#include "types.h"
#include "deps/02129cbc_Maybe_Keyboard_s_10key.h"

void Maybe_Keyboard_s_10key(void)

{
  undefined4 uVar1;
  int local_10;
  int local_c [3];
  
  uVar1 = find_buf_fn_from_thumb(uRam02129e38);
  *(undefined4 *)(*piRam02129e3c + 0xa4) = uVar1;
  uVar1 = find_buf_fn_from_thumb(uRam02129e40);
  *(undefined4 *)(*piRam02129e3c + 0x9c) = uVar1;
  uVar1 = find_buf_fn_from_thumb(uRam02129e44);
  *(undefined4 *)(*piRam02129e3c + 0xac) = uVar1;
  uVar1 = find_buf_fn_from_thumb(uRam02129e48);
  *(undefined4 *)(*piRam02129e3c + 0xa8) = uVar1;
  uVar1 = find_buf_fn_from_thumb(uRam02129e4c);
  *(undefined4 *)(*piRam02129e3c + 0xa0) = uVar1;
  uVar1 = find_buf_fn_from_thumb(uRam02129e50);
  *(undefined4 *)(*piRam02129e3c + 0xb0) = uVar1;
  uVar1 = find_buf_fn_from_thumb(uRam02129e54);
  Gfx_ReadCharGraphics(*piRam02129e3c + 0x94,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02129e58);
  LoadCellBankFrom(*piRam02129e3c + 0x90,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02129e5c);
  Gfx_ReadPalette(*piRam02129e3c + 0x98,uVar1);
  Arm_FlushRange(*(undefined4 *)(*(int *)(*piRam02129e3c + 0x94) + 0x14),
                 *(undefined4 *)(*(int *)(*piRam02129e3c + 0x94) + 0x10));
  CopyTileDataTop_0(*(undefined4 *)(*(int *)(*piRam02129e3c + 0x94) + 0x14),0,
                    *(undefined4 *)(*(int *)(*piRam02129e3c + 0x94) + 0x10));
  TEQSub_Fn35Impl(*(undefined4 *)(*(int *)(*piRam02129e3c + 0x94) + 0x14),0,
                  *(undefined4 *)(*(int *)(*piRam02129e3c + 0x94) + 0x10));
  Arm_FlushRange(*(undefined4 *)(*(int *)(*piRam02129e3c + 0x98) + 0xc),
                 *(undefined4 *)(*(int *)(*piRam02129e3c + 0x98) + 8));
  CopySomePaletteData(*(undefined4 *)(*(int *)(*piRam02129e3c + 0x98) + 0xc),0,uRam02129e60);
  CopySomePaletteData(*(int *)(*(int *)(*piRam02129e3c + 0x98) + 0xc) + iRam02129e64,iRam02129e64,
                      0x40);
  TEQSub_Fn30Impl(*(undefined4 *)(*(int *)(*piRam02129e3c + 0x98) + 0xc),0,
                  *(undefined4 *)(*(int *)(*piRam02129e3c + 0x98) + 8));
  uVar1 = find_buf_fn_from_thumb(uRam02129e68);
  Gfx_ReadCharGraphicsV2(&local_10,uVar1);
  Arm_FlushRange(*(undefined4 *)(local_10 + 0x14),*(undefined4 *)(local_10 + 0x10));
  CopyBgData_Bg3_Bottom(*(undefined4 *)(local_10 + 0x14),0,*(undefined4 *)(local_10 + 0x10));
  uVar1 = find_buf_fn_from_thumb(uRam02129e6c);
  MaybeReadScreenBlock_0(*piRam02129e3c + 0xb4,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02129e70);
  MaybeReadScreenBlock_0(*piRam02129e3c + 0xb8,uVar1);
  uVar1 = find_buf_fn_from_thumb(uRam02129e74);
  Gfx_ReadPalette(local_c,uVar1);
  Arm_FlushRange(*(undefined4 *)(local_c[0] + 0xc),0x80);
  CopyPaletteBottom(*(undefined4 *)(local_c[0] + 0xc),0,0x80);
  return;
}

