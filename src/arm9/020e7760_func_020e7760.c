/* Decompiled C draft; module arm9; ROM address 020e7760. No matching claim. */
#include "types.h"
#include "deps/020e7760_func_020e7760.h"

void func_020e7760(void)

{
  char cVar1;
  short *psVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  
  psVar2 = psRam020e793c;
  iVar6 = *(int *)(*piRam020e7934 + 0xc);
  if (iVar6 != 6) {
    if (iVar6 == 3) {
      *piRam020e7938 = 0;
      return;
    }
    cVar1 = *(char *)(*piRam020e7934 + 0x62);
    if (cVar1 < '\0') {
      *piRam020e7938 = 0;
      return;
    }
    *psRam020e793c = (short)cVar1;
    iVar6 = GetDriverEntry(*psVar2);
    *piRam020e7938 = iVar6;
    *piRam020e7944 = *(int *)(iVar6 + iRam020e7940) + 0x40;
    puVar3 = puRam020e7948;
    *puRam020e7948 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar4 = puRam020e794c;
    uVar7 = puVar3[1];
    *puRam020e794c = *puVar3;
    puVar4[1] = uVar7;
    puVar4[2] = puVar3[2];
    puVar3 = puRam020e7950;
    uVar7 = puVar4[1];
    *puRam020e7950 = *puVar4;
    puVar3[1] = uVar7;
    puVar3[2] = puVar4[2];
    puVar4 = puRam020e7954;
    uVar7 = puVar3[1];
    *puRam020e7954 = *puVar3;
    puVar4[1] = uVar7;
    puVar4[2] = puVar3[2];
    puVar3 = puRam020e7958;
    uVar7 = puVar4[1];
    *puRam020e7958 = *puVar4;
    puVar3[1] = uVar7;
    puVar3[2] = puVar4[2];
    puVar4 = puRam020e795c;
    uVar7 = puVar3[1];
    *puRam020e795c = *puVar3;
    puVar4[1] = uVar7;
    puVar4[2] = puVar3[2];
    puVar3 = puRam020e7960;
    *puRam020e7960 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3 = puRam020e7964;
    *puRam020e7964 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    *puRam020e7968 = 0;
    *puRam020e796c = 0;
    *puRam020e7970 = 0;
    *puRam020e7974 = 0;
    *puRam020e7978 = 0;
    puVar3 = puRam020e797c;
    uVar7 = puVar4[1];
    *puRam020e797c = *puVar4;
    puVar3[1] = uVar7;
    puVar3[2] = puVar4[2];
    *puRam020e7980 = 1;
    *puRam020e7984 = 1;
    *puRam020e7988 = 0;
    *puRam020e7990 = (uint)(*(char *)(*(int *)(*piRam020e798c + 0x18) + 4) == '\0');
    *puRam020e7994 = 4;
    *puRam020e7998 = 1;
    uVar5 = GetCurrentLapCount();
    *puRam020e799c = uVar5;
    func_020ea37c();
    puVar3 = puRam020e79a0;
    iVar6 = 0;
    *puRam020e79a0 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    piVar11 = piRam020e79a4;
    do {
      piVar10 = puVar3 + (iVar6 + 1) * 3;
      iVar8 = piVar11[1];
      *piVar10 = *piVar11;
      piVar10[1] = iVar8;
      piVar10[2] = piVar11[2];
      if (*puRam020e7990 != 0) {
        *piVar10 = -*piVar10;
        piVar10[1] = -piVar10[1];
        piVar10[2] = -piVar10[2];
      }
      piVar11 = piVar11 + 3;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 7);
    iVar6 = *piRam020e7934;
    if (*(int *)(iVar6 + 8) == 2) {
      *puRam020e79a8 = 0;
    }
    else if (*(int *)(iVar6 + 8) == 4) {
      uVar7 = 0;
      uVar9 = *(byte *)(iVar6 + 0x2f) + 0xfe & 0xff;
      if ((uVar9 < 9) && ((1 << uVar9 & uRam020e79ac) != 0)) {
        uVar7 = 1;
      }
      *puRam020e79a8 = uVar7;
    }
    else {
      *puRam020e79a8 = 1;
    }
    if (*(int *)(iVar6 + 0x10) == 0) {
      *puRam020e79b0 = 0x50;
    }
    else if (*(int *)(iVar6 + 0x10) == 1) {
      *puRam020e79b0 = 0x3c;
    }
    else {
      *puRam020e79b0 = 0x2d;
    }
    puVar3 = puRam020e79b8;
    *puRam020e79b8 = uRam020e79b4;
    puVar3[1] = puRam020e795c;
    puVar3[2] = 1;
    StateDualHandler_Create((undefined4 *)(uintptr_t)(uRam020e79bc),uRam020e79c0,7,0);
    StateDualHandler_SetState(uRam020e79bc,0);
  }
  return;
}

