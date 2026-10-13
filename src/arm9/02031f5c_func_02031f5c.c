/* Decompiled C draft; module arm9; ROM address 02031f5c. No matching claim. */
#include "types.h"
#include "deps/02031f5c_func_02031f5c.h"

void func_02031f5c(void)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_2a [20];
  undefined2 local_16;
  
  iVar3 = *piRam02031ff8;
  uVar5 = 1;
  iVar4 = 0xc;
  psVar2 = psRam02031ffc;
  do {
    Mem_CpuFill16(0,(int)(uintptr_t)(auStack_2a),0x16);
    iVar1 = func_0204fcec(uVar5 & 0xffff,(int)(uintptr_t)(auStack_2a));
    if (iVar1 == 0) {
      func_021241c0(1,(int)*psVar2,*(undefined4 *)(iVar3 + 0x54),*(undefined4 *)(iVar3 + 0x4c),
                    *(undefined4 *)(iVar3 + 0x58));
      *(undefined4 *)(*piRam02031ff8 + iVar4 + 0xe0) = 0;
    }
    else {
      local_16 = 0;
      func_0212426c(1,(int)*psVar2,*(undefined4 *)(iVar3 + 0x54),auStack_2a,
                    *(undefined4 *)(iVar3 + 0x4c),*(undefined4 *)(iVar3 + 0x58));
      if (*(int *)(*piRam02031ff8 + iVar4 + 0xe0) != 2) {
        *(undefined4 *)(*piRam02031ff8 + iVar4 + 0xe0) = 1;
      }
    }
    psVar2 = psVar2 + 6;
    iVar4 = iVar4 + 0xc;
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 8);
  return;
}

