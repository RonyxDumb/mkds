/* Decompiled C draft; module arm9; ROM address 02052288. No matching claim. */
#include "types.h"
#include "deps/02052288_func_02052288.h"

void func_02052288(int param_1,char *param_2,undefined4 param_3)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  iVar8 = 0;
  uVar12 = *(uint *)(uRam020525a4 & 0xfffffffc) >> (uRam020525a4 & 3) * 8 |
           *(uint *)(uRam020525a4 & 0xfffffffc) << (uRam020525a4 & 3) * -8 + 0x20;
  iVar9 = uVar12 + 0xac;
  bVar7 = 0;
  bVar5 = 0;
  iVar10 = 0;
  iVar6 = iVar9;
  do {
    if ((((((int)((uint)*(byte *)(iVar6 + 0xdc) << 0x1f) < 0) &&
          (*param_2 == *(char *)(iVar6 + 0xc0))) && (param_2[1] == *(char *)(iVar6 + 0xc1))) &&
        ((param_2[2] == *(char *)(iVar6 + 0xc2) && (param_2[3] == *(char *)(iVar6 + 0xc3))))) &&
       ((param_2[4] == *(char *)(iVar6 + 0xc4) && (param_2[5] == *(char *)(iVar6 + 0xc5))))) {
      bVar5 = 1;
      iVar8 = iVar6;
      break;
    }
    iVar10 = iVar10 + 1;
    iVar6 = iVar6 + 0xe0;
  } while (iVar10 < 4);
  iVar6 = iVar8;
  if (iVar8 == 0) {
    iVar11 = 0;
    iVar10 = iVar9;
    do {
      iVar6 = iVar10;
      if (-1 < (int)((uint)*(byte *)(iVar6 + 0xdc) << 0x1f)) break;
      iVar11 = iVar11 + 1;
      iVar10 = iVar6 + 0xe0;
      iVar6 = iVar8;
    } while (iVar11 < 4);
  }
  if (iVar6 == 0) {
    iVar8 = 0;
    do {
      bVar3 = *(byte *)(iVar9 + 0xdb);
      if ((bVar3 < 5) && (bVar7 < bVar3)) {
        iVar6 = iVar9;
        bVar7 = bVar3;
      }
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0xe0;
    } while (iVar8 < 4);
  }
  if (iVar6 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x4b) & 2) == 0) {
    if (*(char *)(param_1 + 0x4a) == '\x1c') {
      func_020525a8(iVar6,param_1,param_2,param_3);
    }
  }
  else {
    uVar12 = uVar12 + 0x1d00;
    uVar2 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    if ((uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20) != 2) {
      if (*(char *)(param_1 + 0x57) == '\x05') {
        Mem_CpuCopy8((ushort *)(uintptr_t)(param_1),(uint *)(uintptr_t)(iVar6),0xc0);
        cVar4 = param_2[1];
        *(char *)(iVar6 + 0xc0) = *param_2;
        *(char *)(iVar6 + 0xc1) = cVar4;
        cVar4 = param_2[3];
        *(char *)(iVar6 + 0xc2) = param_2[2];
        *(char *)(iVar6 + 0xc3) = cVar4;
        cVar4 = param_2[5];
        *(char *)(iVar6 + 0xc4) = param_2[4];
        *(char *)(iVar6 + 0xc5) = cVar4;
        *(byte *)(iVar6 + 0xdc) = *(byte *)(iVar6 + 0xdc) & 0xfe | 1;
        *(undefined1 *)(iVar6 + 0xdb) = 0;
        if (-1 < (int)((uint)bVar5 * -0x1000000) >> 0x18) {
          *(char *)(iVar6 + 0xda) = (char)((uint)bVar5 * -0x1000000 >> 0x18);
        }
        *(byte *)(iVar6 + 0xdc) = *(byte *)(iVar6 + 0xdc) & 0xe1;
        *(byte *)(iVar6 + 0xdc) = *(byte *)(iVar6 + 0xdc) | 0x20;
        *(byte *)(iVar6 + 0xdc) = *(byte *)(iVar6 + 0xdc) & 0xbf;
        Mem_CpuCopy8((ushort *)(uintptr_t)(param_1 + 0x96),(uint *)(uintptr_t)(iVar6 + 0xc6),0x14);
        *(undefined1 *)
         ((*(uint *)(uRam020525a4 & 0xfffffffc) >> (uRam020525a4 & 3) * 8 |
          *(uint *)(uRam020525a4 & 0xfffffffc) << (uRam020525a4 & 3) * -8 + 0x20) + 0x438) = 0;
      }
      else if (*(char *)(param_1 + 0x57) == '\t') {
        if ((int)((uint)*(byte *)(iVar6 + 0xdc) << 0x1f) < 0) {
          *(char *)(iVar6 + 0xda) = *(char *)(param_1 + 0x5a) + -1;
        }
      }
      else if ((int)((uint)*(byte *)(iVar6 + 0xdc) << 0x1f) < 0) {
        *(undefined1 *)(iVar6 + 0xdb) = 0;
      }
      else {
        cVar4 = param_2[1];
        uVar12 = *(uint *)(uRam020525a4 & 0xfffffffc) >> (uRam020525a4 & 3) * 8 |
                 *(uint *)(uRam020525a4 & 0xfffffffc) << (uRam020525a4 & 3) * -8 + 0x20;
        *(char *)(uVar12 + 0x42c) = *param_2;
        *(char *)(uVar12 + 0x42d) = cVar4;
        cVar4 = param_2[3];
        *(char *)(uVar12 + 0x42e) = param_2[2];
        *(char *)(uVar12 + 0x42f) = cVar4;
        cVar4 = param_2[5];
        *(char *)(uVar12 + 0x430) = param_2[4];
        *(char *)(uVar12 + 0x431) = cVar4;
        *(undefined1 *)(uVar12 + 0x438) = 0xf;
      }
    }
  }
  iVar8 = 0;
  uVar12 = *(uint *)(uRam020525a4 & 0xfffffffc) >> (uRam020525a4 & 3) * 8 |
           *(uint *)(uRam020525a4 & 0xfffffffc) << (uRam020525a4 & 3) * -8 + 0x20;
  iVar6 = uVar12 + 0xac;
  *(undefined2 *)(uVar12 + 0x434) = 0;
  do {
    pbVar1 = (byte *)(iVar6 + 0xdc);
    iVar8 = iVar8 + 1;
    iVar6 = iVar6 + 0xe0;
    if ((int)((uint)*pbVar1 << 0x1f) < 0) {
      *(short *)(uVar12 + 0x434) = *(short *)(uVar12 + 0x434) + 1;
    }
  } while (iVar8 < 4);
  return;
}

