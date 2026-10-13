/* Decompiled C draft; module arm9; ROM address 0211ca8c. No matching claim. */
#include "types.h"
#include "deps/0211ca8c_func_0211ca8c.h"

void func_0211ca8c(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  iVar2 = *piRam0211caf4;
  if (*(int *)(iVar2 + 0x60) == 3) {
    if (*(int *)(iVar2 + 0x74) == 0) {
      func_0211d910((*(short *)(iVar2 + 0x88) + -1) * 0x10000 >> 0x10);
      *(undefined2 *)(*piRam0211caf4 + 0x50) = 6;
      bVar1 = true;
    }
    else if (*(int *)(iVar2 + 0x74) == 1) {
      func_0211d844((*(short *)(iVar2 + 0x8a) + -1) * 0x10000 >> 0x10);
      *(undefined2 *)(*piRam0211caf4 + 0x50) = 6;
      bVar1 = true;
    }
    if (bVar1) {
      NNSi_MaybeSndPlayerStartSeq(uRam0211caf8,0,0x17);
    }
  }
  return;
}

