/* Decompiled C draft; module arm9; ROM address 020607b0. No matching claim. */
#include "types.h"
#include "deps/020607b0_func_020607b0.h"

bool func_020607b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_30 [34];
  byte local_e;
  
  GlobalZ_GetOI(param_1,auStack_30);
  uVar2 = (uint)local_e;
  Mem_CpuFill8(auStack_30,0,0x24);
  local_e = local_e & 0xfe;
  GlobalZ_SetOI(param_1,auStack_30);
  if (*(short *)((*(uint *)(uRam02060874 & 0xfffffffc) >> (uRam02060874 & 3) * 8 |
                 *(uint *)(uRam02060874 & 0xfffffffc) << (uRam02060874 & 3) * -8 + 0x20) + 0x16) ==
      0) {
    uVar3 = (*(uint *)(uRam02060878 & 0xfffffffc) >> (uRam02060878 & 3) * 8 |
            *(uint *)(uRam02060878 & 0xfffffffc) << (uRam02060878 & 3) * -8 + 0x20) + 0x20;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Mem_CpuFill8(param_1 * 0xc + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iRam0206087c,0)
    ;
  }
  else {
    uVar3 = (*(uint *)(uRam02060878 & 0xfffffffc) >> (uRam02060878 & 3) * 8 |
            *(uint *)(uRam02060878 & 0xfffffffc) << (uRam02060878 & 3) * -8 + 0x20) + 0x20;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    func_0x0219d948(param_1 * 0xc + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iRam0206087c
                   );
  }
  WriteFriendListSaveDataSection();
  return (int)(uVar2 << 0x1f) < 0;
}

