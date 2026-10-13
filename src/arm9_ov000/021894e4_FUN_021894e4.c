/* Decompiled C draft; module arm9_ov000; ROM address 021894e4. No matching claim. */
#include "types.h"
#include "deps/021894e4_FUN_021894e4.h"

char FUN_021894e4(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  
  cVar2 = '\0';
  uVar4 = 0;
  if (0 < param_1) {
    do {
      if (8 < uVar4) {
        return cVar2;
      }
      if ((*param_2 == '\0') && (*(ushort *)(param_4 + 0x36) != (ushort)(byte)param_2[3])) {
        uVar3 = 0;
        do {
          cVar1 = *(char *)(param_4 + uVar3 + 0xc);
          if (cVar1 == '\0') break;
          *(char *)(param_3 + uVar3 + 4) = cVar1;
          uVar3 = uVar3 + 1 & 0xff;
        } while (uVar3 < 0x20);
        *(char *)(param_3 + 3) = (char)uVar3;
        *(char *)(param_3 + 2) = (char)*(undefined2 *)(param_4 + 0x36) + -1;
        param_3 = param_3 + 0x24;
        cVar2 = cVar2 + '\x01';
      }
      param_2 = param_2 + 4;
      param_4 = param_4 + 0xc0;
      uVar4 = uVar4 + 1 & 0xff;
    } while ((int)uVar4 < param_1);
  }
  return cVar2;
}

