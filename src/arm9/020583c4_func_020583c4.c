/* Decompiled C draft; module arm9; ROM address 020583c4. No matching claim. */
#include "types.h"
#include "deps/020583c4_func_020583c4.h"

void func_020583c4(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar5;
  short *psVar6;
  int iVar7;
  uint uVar8;
  undefined2 local_1c [2];
  undefined4 local_18 [2];
  
  piVar5 = (int *)*piRam020584bc;
  if (piVar5 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar5;
  }
  if (iVar3 == 1) {
    bVar2 = true;
    if ((*(byte *)((int)piVar5 + iRam020584c0) & 1) != 0) {
      iVar3 = *piRam020584bc;
      uVar8 = (uint)*(byte *)(iVar3 + iRam020584c4);
      if (((*(byte *)(iVar3 + 0x87) | 1) & 1 << uVar8) != 0) {
        cVar1 = *(char *)(iVar3 + iRam020584c8);
        iVar3 = func_0205867c(iVar3 + iRam020584cc + iRam020584d0 * uVar8,cVar1,uRam020584d4,
                              local_18,local_1c);
        if (iVar3 != 0) {
          func_020586ac(cVar1,local_18[0],local_1c[0],uVar8,*(undefined1 *)(*piRam020584bc + 0x87));
          *(char *)(*piRam020584bc + iRam020584c8) = cVar1 + '\x01';
          bVar2 = false;
        }
      }
      iVar3 = iRam020584c4;
      piVar5 = piRam020584bc;
      if (bVar2) {
        *(char *)(*piRam020584bc + iRam020584c4) = *(char *)(*piRam020584bc + iRam020584c4) + '\x01'
        ;
        *(undefined1 *)(*piVar5 + iRam020584c8) = 0;
        pbVar4 = (byte *)(*piVar5 + iVar3);
        if (7 < *pbVar4) {
          *pbVar4 = 0;
        }
      }
    }
    iVar3 = iRam020584e4;
    uVar8 = uRam020584e0;
    if ((*(ushort *)(*piRam020584bc + iRam020584d8) & 0x40) != 0) {
      uVar8 = uRam020584dc;
    }
    psVar6 = (short *)(*piRam020584bc + iRam020584e4);
    *psVar6 = *psVar6 + 1;
    piVar5 = piRam020584bc;
    iVar7 = *piRam020584bc;
    if (uVar8 < *(ushort *)(iVar7 + iVar3)) {
      *(undefined1 *)(iVar7 + iRam020584e8) = *(undefined1 *)(iVar7 + 0x87);
      iVar3 = *piVar5 + iRam020584ec;
      *(undefined2 *)(iVar3 + 0x10) = 10;
      *(undefined2 *)(iVar3 + 0x12) = 1;
    }
  }
  return;
}

