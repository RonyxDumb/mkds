/* Decompiled C draft; module arm9; ROM address 02012f58. No matching claim. */
#include "types.h"
#include "deps/02012f58_func_02012f58.h"

void func_02012f58(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_50 [64];
  
  func_01ff9234();
  puVar1 = puRam02012ff0;
  *puRam02012fec = 0;
  puVar2 = puRam02012ff4;
  *puVar1 = 0;
  *puVar2 = 0;
  if (param_1 != 0) {
    do {
      iVar3 = G3X_GetClipMtx(auStack_50);
    } while (iVar3 != 0);
    func_02147980(auStack_50,param_1);
  }
  if (param_2 != 0) {
    do {
      iVar3 = G3X_GetVectorMtx(param_2);
    } while (iVar3 != 0);
  }
  puVar1 = puRam02012fec;
  *puRam02012ff8 = 1;
  *puVar1 = 2;
  return;
}

