/* Decompiled C draft; module arm9; ROM address 020cb9b8. No matching claim. */
#include "types.h"
#include "deps/020cb9b8_func_020cb9b8.h"

void func_020cb9b8(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam020cba28;
  iVar2 = *piRam020cba28;
  if (*(int *)(iVar2 + iRam020cba2c) == 0) {
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0xc);
    *(undefined4 *)(*piVar1 + 0xc) = 0x1f;
    func_020cb618();
  }
  iVar2 = func_020cbad0();
  if (iVar2 == 0) {
    ResetGlobalB4A4_from_thumb();
    ResetGlobalPK_from_thumb();
  }
  DisposeNavigationContext_from_thumb();
  ResetGlobalNN_from_thumb();
  ResetGlobalKTB_from_thumb();
  DisposeAllModelResources();
  SetSinglePlayerMenuTarget(0);
  SetB488_B5(0);
  EnableAlphaSetBldcntBldalphaTop(0,0x3f,6,10);
  EnableAlphaSetBldcntBldalphaSub(0,0x3f,6,10);
  *piRam020cba28 = 0;
  return;
}

