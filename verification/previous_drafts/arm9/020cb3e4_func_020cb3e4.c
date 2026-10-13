/* Decompiled C draft; module arm9; ROM address 020cb3e4. No matching claim. */
#include "types.h"
#include "deps/020cb3e4_func_020cb3e4.h"

void func_020cb3e4(void)

{
  int iVar1;
  
  iVar1 = func_020cccc0();
  if (iVar1 != 0) {
    func_020cb4a8(0x18);
    ConfigureDispcntDisplay(1,0,0);
    CopySomePaletteData(*(undefined4 *)(*(int *)(*piRam020cb470 + iRam020cb474) + 0xc),0,
                        uRam020cb478);
    CopySomePaletteData(*(int *)(*(int *)(*piRam020cb470 + iRam020cb474) + 0xc) + iRam020cb47c,
                        iRam020cb47c,0x40);
    CopyTileDataTop_0(*(undefined4 *)(*(int *)(*piRam020cb470 + iRam020cb480) + 0x14),0,
                      *(undefined4 *)(*(int *)(*piRam020cb470 + iRam020cb480) + 0x10));
    GXS_SetGraphicsMode__mkds_cb48c(0x16);
    SetDispcntSubBgMode(0);
    TEQSub_Fn30Impl(*(undefined4 *)(*(int *)(*piRam020cb470 + iRam020cb484) + 0xc),0,
                    *(undefined4 *)(*(int *)(*piRam020cb470 + iRam020cb484) + 8));
    TEQSub_Fn35Impl(*(undefined4 *)(*(int *)(*piRam020cb470 + iRam020cb488) + 0x14),0,
                    *(undefined4 *)(*(int *)(*piRam020cb470 + iRam020cb488) + 0x10));
  }
  return;
}

