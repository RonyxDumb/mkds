/* Decompiled C draft; module arm9; ROM address 020cb51c. No matching claim. */
#include "types.h"
#include "deps/020cb51c_func_020cb51c.h"

void func_020cb51c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_02049b6c();
  if (iVar1 == 0) {
    iVar1 = GetPMaybeState_1();
    if ((iVar1 == 1) || (iVar1 = GetPMaybeState_1(), iVar1 == 2)) {
      if (*(int *)(*piRam020cb5e8 + iRam020cb5ec) == 0) {
        iVar1 = func_020546d8();
        if (iVar1 != 1) {
          return;
        }
        *(undefined4 *)(*piRam020cb5e8 + iRam020cb5ec) = 1;
      }
      if (*(int *)(*piRam020cb5e8 + iRam020cb5f0) == 0) {
        iVar1 = func_02054754();
        if (iVar1 != 1) {
          return;
        }
        *(undefined4 *)(*piRam020cb5e8 + iRam020cb5f0) = 1;
      }
    }
    OamBuffer_ResetValues16_from_thumb(*piRam020cb5e8 + iRam020cb5f4,*piRam020cb5e8 + iRam020cb5f8);
    iVar1 = *piRam020cb5e8;
    if (*(int *)(iVar1 + iRam020cb5fc) == 0) {
      (**(code **)(iVar1 + *(int *)(iVar1 + 0xc) * 8 + 0x18))(param_1);
      if (*(int *)(*piRam020cb5e8 + 4) != 0) {
        func_020cb618();
        func_020cb6c0();
      }
    }
    else {
      *(int *)(iVar1 + iRam020cb5fc) = 0;
      func_020cb6c0();
      (**(code **)(*piRam020cb5e8 + *(int *)(*piRam020cb5e8 + 0xc) * 8 + 0x18))(param_1);
    }
    NavigationContext_OnSceneUpdate_from_thumb();
    func_0212a920();
    iVar1 = Bright_IsBothScreensFadedIn();
    if (iVar1 != 0) {
      func_020cb600(*piRam020cb5e8);
    }
  }
  return;
}

