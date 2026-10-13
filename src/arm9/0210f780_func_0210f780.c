/* Decompiled C draft; module arm9; ROM address 0210f780. No matching claim. */
#include "types.h"
#include "deps/0210f780_func_0210f780.h"

void func_0210f780(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  
  iVar1 = iRam0210f804;
  iVar6 = 0;
  psVar5 = psRam0210f800;
  do {
    uVar2 = iVar1 + iVar6 * 4;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) &&
       (iVar3 = func_0212c400(param_1,(char)psVar5[4],psVar5), iVar3 != 0)) {
      if (psVar5[1] == *psVar5) {
        uVar2 = (uint)(psVar5 + 2) & 3;
        uVar4 = *(uint *)((uint)(psVar5 + 2) & 0xfffffffc);
        uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
        if (-1 < (int)uVar2) {
          *(uint *)(psVar5 + 2) = uVar2 + 1;
        }
      }
      else {
        psVar5[2] = 0;
        psVar5[3] = 0;
      }
      psVar5[1] = *psVar5;
    }
    iVar6 = iVar6 + 1;
    psVar5 = psVar5 + 6;
  } while (iVar6 < 2);
  return;
}

