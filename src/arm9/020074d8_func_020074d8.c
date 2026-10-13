/* Decompiled C draft; module arm9; ROM address 020074d8. No matching claim. */
#include "types.h"
#include "deps/020074d8_func_020074d8.h"

undefined4 func_020074d8(void)

{
  char cVar1;
  undefined4 uVar2;
  byte bVar3;
  uint extraout_r1;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 local_30 [2];
  undefined2 local_2e;
  char acStack_2a [22];
  
  uVar6 = 0;
  iVar7 = -1;
  Mem_CpuFill8((uint *)(void *)(acStack_2a),0,0x10);
  uVar4 = 1;
  iVar5 = *piRam020075dc;
  do {
    if (*(int *)(iVar5 + (uVar4 - 1) * 4 + iRam020075e0) == 5) {
      cVar1 = *(char *)(iVar5 + (uVar4 - 1) + iRam020075e4);
      acStack_2a[cVar1] = acStack_2a[cVar1] + '\x01';
    }
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 0x10);
  uVar4 = (uint)*pbRam020075e8;
  bVar3 = 0;
  while( true ) {
    _s32_div_f(uVar4 + 1,0x10);
    uVar4 = extraout_r1 & 0xff;
    if ((*(char *)(iVar5 + iRam020075ec * uVar4 + iRam020075f0) != '\0') &&
       (acStack_2a[uVar4] != '\0')) break;
    bVar3 = bVar3 + 1;
    if (0xf < bVar3) {
LAB_02007556:
      if (iVar7 == -1) {
        return 0x15;
      }
      *pbRam020075e8 = (byte)iVar7;
      uVar4 = 1;
      do {
        if ((*(int *)(iVar5 + (uVar4 - 1) * 4 + iRam020075e0) == 5) &&
           (iVar7 == *(char *)(iVar5 + (uVar4 - 1) + iRam020075e4))) {
          uVar6 = uVar6 | 1 << (uVar4 & 0xff) & 0xffffU;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < 0x10);
      local_30[0] = 3;
      local_2e = (undefined2)iVar7;
      iVar5 = func_0200c3a4(local_30,(undefined1 *)(uintptr_t)(iVar5));
      if (iVar5 != 0) {
        Mem_CpuCopy8((ushort *)(uintptr_t)(*piRam020075dc + iRam020075f4 + iRam020075ec * iVar7),(uint *)(uintptr_t)(iVar5),0xe4);
      }
      uVar2 = func_02008908(0xea,uVar6,*piRam020075dc);
      return uVar2;
    }
  }
  iVar7 = (int)(char)extraout_r1;
  goto LAB_02007556;
}

