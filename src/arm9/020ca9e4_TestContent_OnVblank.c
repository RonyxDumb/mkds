/* Decompiled C draft; module arm9; ROM address 020ca9e4. No matching claim. */
#include "types.h"
#include "deps/020ca9e4_TestContent_OnVblank.h"

void TestContent_OnVblank(void)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(*piRam020caa9c + 8) != 0) {
    CopyPaletteBottom(*(int *)(*(int *)(*piRam020caa9c + 0x60) + 0xc) + iRam020caaa0,iRam020caaa0,
                      0x40);
    CopyBgData_Bg0_Bottom(*(undefined4 *)(*(int *)(*piRam020caa9c + 100) + 0x14),0,uRam020caaa4);
    *(undefined4 *)(*piRam020caa9c + 8) = 0;
  }
  if (*(int *)*piRam020caa9c != 0) {
    TEQSub_Fn24Impl(((int *)*piRam020caa9c)[0x1a] + 0xc,0,uRam020caaa8);
  }
  iVar2 = *(int *)*piRam020caa9c;
  if (iVar2 != ((int *)*piRam020caa9c)[1]) {
    if (iVar2 == 0) {
      uVar1 = func_020cab74();
      GXS_SetGraphicsMode__mkds_cab58(uVar1 & 0xfffffffe);
      if (*(code **)(*piRam020caa9c + 0xc) == (code *)0x0) {
        func_020caaac(0,0,6,10);
      }
      else {
        (**(code **)(*piRam020caa9c + 0xc))();
      }
    }
    else {
      uVar1 = func_020cab74();
      GXS_SetGraphicsMode__mkds_cab58(uVar1 | 1);
      func_020cab2c(0,0);
      UpdateBldcntBldalphaBldy_Sub(0x3e,0x3f,8,8,0xfffffff9);
    }
  }
  ((undefined4 *)*piRam020caa9c)[1] = *(undefined4 *)*piRam020caa9c;
  return;
}

