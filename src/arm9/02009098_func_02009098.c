/* Decompiled C draft; module arm9; ROM address 02009098. No matching claim. */
#include "types.h"
#include "deps/02009098_func_02009098.h"

uint func_02009098(int param_1,code *param_2)

{
  int *piVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = 0;
  puVar4 = (ushort *)*piRam020091b0;
  puVar5 = puVar4 + 8;
  puVar2 = puVar4;
  while ((((((uVar7 = 1 << (uVar3 & 0xff), (*puVar4 & uVar7) == 0 ||
             (*(int *)((int)puVar5 + iRam020091b8) != *(int *)*piRam020091b4)) ||
            (*(char *)((int)puVar5 + iRam020091bc) != *(char *)(param_1 + 4))) ||
           ((*(char *)((int)puVar5 + iRam020091c0) != *(char *)(param_1 + 5) ||
            (*(char *)((int)puVar5 + iRam020091c4) != *(char *)(param_1 + 6))))) ||
          ((*(char *)((int)puVar5 + iRam020091c8) != *(char *)(param_1 + 7) ||
           ((*(char *)((int)puVar5 + iRam020091cc) != *(char *)(param_1 + 8) ||
            (*(char *)((int)puVar5 + iRam020091d0) != *(char *)(param_1 + 9))))))) ||
         (((uint)*(byte *)((int *)*piRam020091b4 + 1) << 0x18) >> 0x1a !=
          (uint)*(byte *)((int)puVar2 + iRam020091c0)))) {
    puVar5 = (ushort *)((int)puVar5 + iRam020091d4);
    puVar2 = (ushort *)((int)puVar2 + iRam020091d4);
    uVar3 = uVar3 + 1;
    if (0xf < (int)uVar3) {
      uVar3 = 0;
      do {
        uVar7 = 1 << (uVar3 & 0xff);
        if ((*puVar4 & uVar7) == 0) {
          iVar6 = iRam020091d4 * uVar3;
          CopyMemory16(param_1,(int)puVar4 + iVar6 + iRam020091d8,0xc0);
          piVar1 = piRam020091b0;
          *(undefined1 *)(*piRam020091b0 + iVar6 + iRam020091dc) =
               *(undefined1 *)(*piRam020091b4 + 5);
          *(ushort *)*piVar1 = *(ushort *)*piVar1 | (ushort)uVar7;
          func_02008a4c(uVar3);
          return uVar3;
        }
        uVar3 = uVar3 + 1;
      } while ((int)uVar3 < 0x10);
      if (param_2 != (code *)0x0) {
        (*param_2)(4,0,0);
      }
      return 0xffffffff;
    }
  }
  if ((puVar4[2] & uVar7) == 0) {
    func_02008a4c(uVar3);
  }
  return uVar3;
}

