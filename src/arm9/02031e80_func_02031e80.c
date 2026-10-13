/* Decompiled C draft; module arm9; ROM address 02031e80. No matching claim. */
#include "types.h"
#include "deps/02031e80_func_02031e80.h"

void func_02031e80(void)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_48;
  short local_2a [11];
  
  local_48 = 0;
  iVar4 = *piRam02031f48;
  uVar6 = 1;
  iVar5 = 0xc;
  psVar3 = psRam02031f4c;
  do {
    Mem_CpuFill16(0,(int)(uintptr_t)(local_2a),0x16);
    iVar2 = *piRam02031f50 + iRam02031f54 + iRam02031f58 * (uVar6 & 0xffff);
    if (iVar2 != 0) {
      CopyMemory16(iVar2,(int)(uintptr_t)(local_2a),0x14);
      if (local_2a[0] == 0) {
        func_021241c0(1,(int)*psVar3,*(undefined4 *)(iVar4 + 0x54),*(undefined4 *)(iVar4 + 0x4c),
                      *(undefined4 *)(iVar4 + 0x58));
        *(undefined4 *)(*piRam02031f48 + iVar5 + 0xe0) = 0;
      }
      else {
        func_0212426c(1,(int)*psVar3,*(undefined4 *)(iVar4 + 0x54),local_2a,
                      *(undefined4 *)(iVar4 + 0x4c),*(undefined4 *)(iVar4 + 0x58));
        *(undefined4 *)(*piRam02031f48 + iVar5 + 0xe0) = 2;
        local_48 = local_48 + 1;
      }
    }
    piVar1 = piRam02031f48;
    psVar3 = psVar3 + 6;
    iVar5 = iVar5 + 0xc;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < 8);
  *(int *)(*piRam02031f48 + 0x74) = local_48;
  *(undefined4 *)(*piVar1 + 0x8c) = 1;
  return;
}

