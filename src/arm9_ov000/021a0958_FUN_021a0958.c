/* Decompiled C draft; module arm9_ov000; ROM address 021a0958. No matching claim. */
#include "types.h"
#include "deps/021a0958_FUN_021a0958.h"

int FUN_021a0958(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x02139ffc(param_2,0);
  iVar2 = 0;
  if (0 < param_3) {
    do {
      param_2 = func_0x02139ffc(param_2,0x2f);
      if (param_2 == 0) {
        return -1;
      }
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  iVar2 = func_0x02139ffc(param_2,0x2f);
  if (iVar2 == 0) {
    iVar2 = iVar1;
  }
  if (param_2 != iVar2) {
    iVar2 = iVar2 - param_2;
    func_0x0214d1fc((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(param_1),iVar2);
    *(undefined1 *)(param_1 + iVar2) = 0;
    return iVar2;
  }
  return -1;
}

