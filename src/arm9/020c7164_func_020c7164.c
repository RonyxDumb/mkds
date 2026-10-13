/* Decompiled C draft; module arm9; ROM address 020c7164. No matching claim. */
#include "types.h"
#include "deps/020c7164_func_020c7164.h"

void func_020c7164(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  byte bStack_20;
  byte bStack_1f;
  char cStack_1e;
  char cStack_1d;
  ushort uStack_1c;
  short asStack_1a [3];
  
  uVar5 = *(uint *)(uRam020c72e8 & 0xfffffffc) >> (uRam020c72e8 & 3) * 8 |
          *(uint *)(uRam020c72e8 & 0xfffffffc) << (uRam020c72e8 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != 1) {
    return;
  }
  if (*(uint *)(uRam020c72ec & 0xfffffffc) >> (uRam020c72ec & 3) * 8 == 0 &&
      *(uint *)(uRam020c72ec & 0xfffffffc) << (uRam020c72ec & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar5 = uVar5 + 0xc;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar3 * 8 == 0 && uVar5 << uVar3 * -8 + 0x20 == 0) {
    uVar4 = CheckHandleSaveTimeTrialRecord2(0);
    *(undefined4 *)
     ((*(uint *)(uRam020c72ec & 0xfffffffc) >> (uRam020c72ec & 3) * 8 |
      *(uint *)(uRam020c72ec & 0xfffffffc) << (uRam020c72ec & 3) * -8 + 0x20) + 8) = uVar4;
    uVar4 = CheckHandleSaveTimeTrialRecord_LeastLap(0);
    *(undefined4 *)
     ((*(uint *)(uRam020c72ec & 0xfffffffc) >> (uRam020c72ec & 3) * 8 |
      *(uint *)(uRam020c72ec & 0xfffffffc) << (uRam020c72ec & 3) * -8 + 0x20) + 0x10) = uVar4;
    return;
  }
  uVar4 = GetCurrentPlayerRacerId();
  GetPlayerTotalTime(uVar4,&bStack_20,&bStack_1f,&uStack_1c);
  uVar3 = uRam020c72ec;
  uVar5 = *(uint *)(uRam020c72ec & 0xfffffffc) >> (uRam020c72ec & 3) * 8 |
          *(uint *)(uRam020c72ec & 0xfffffffc) << (uRam020c72ec & 3) * -8 + 0x20;
  puVar6 = (ushort *)(uVar5 + 0x9c);
  iVar7 = 4;
  while (((char)puVar6[0xc] == '\0' ||
         ((uint)uStack_1c + (uint)bStack_1f * 1000 + (uint)bStack_20 * iRam020c72f0 !=
          (uint)*puVar6 +
          (uint)*(byte *)((int)puVar6 + 3) * 1000 + (uint)(byte)puVar6[1] * iRam020c72f0))) {
    puVar6 = puVar6 + -0x10;
    iVar7 = iVar7 + -1;
    if (iVar7 < 0) {
      uVar4 = 0;
LAB_020c7268:
      *(undefined4 *)(uVar5 + 8) = uVar4;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar4 = GetCurrentPlayerRacerId();
      uVar2 = GetLeastTimeLap(uVar4,&cStack_1e,&cStack_1d,asStack_1a);
      *(undefined2 *)
       ((*(uint *)(uRam020c72ec & 0xfffffffc) >> (uRam020c72ec & 3) * 8 |
        *(uint *)(uRam020c72ec & 0xfffffffc) << (uRam020c72ec & 3) * -8 + 0x20) + 0x14) = uVar2;
      if (((cStack_1e == *(char *)(uVar3 + 0xbe)) && (cStack_1d == *(char *)(uVar3 + 0xbf))) &&
         (asStack_1a[0] == *(short *)(uVar3 + 0xbc))) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
      *(undefined4 *)
       ((*(uint *)(uRam020c72ec & 0xfffffffc) >> (uRam020c72ec & 3) * 8 |
        *(uint *)(uRam020c72ec & 0xfffffffc) << (uRam020c72ec & 3) * -8 + 0x20) + 0x10) = uVar4;
      return;
    }
  }
  uVar4 = 1;
  goto LAB_020c7268;
}

