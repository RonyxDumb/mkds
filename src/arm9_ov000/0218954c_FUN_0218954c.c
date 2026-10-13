/* Decompiled C draft; module arm9_ov000; ROM address 0218954c. No matching claim. */
#include "types.h"
#include "deps/0218954c_FUN_0218954c.h"

char FUN_0218954c(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  
  cVar4 = '\0';
  iVar2 = param_1 + DAT_02189608;
  iVar5 = 0;
  iVar3 = param_1;
  do {
    if ((((*(byte *)(param_1 + DAT_0218960c) & 0xf) == 0) ||
        ((*(byte *)(param_1 + DAT_0218960c) & 0xf) == iVar5 + 1U)) &&
       (*(char *)(iVar3 + 0xe7) != -1)) {
      uVar6 = 0;
      do {
        cVar1 = *(char *)(iVar3 + uVar6 + 0x40);
        if (cVar1 == '\0') break;
        *(char *)(iVar2 + uVar6 + 4) = cVar1;
        uVar6 = uVar6 + 1 & 0xff;
      } while (uVar6 < 0x20);
      if (uVar6 != 0) {
        *(char *)(iVar2 + 3) = (char)uVar6;
        *(char *)(iVar2 + 1) = (char)iVar5;
        cVar4 = cVar4 + '\x01';
        iVar2 = iVar2 + 0x24;
      }
      if (*(char *)(iVar3 + 0xe7) == '\x01') {
        uVar6 = 0;
        do {
          cVar1 = *(char *)(iVar3 + uVar6 + 0x60);
          if (cVar1 == '\0') break;
          *(char *)(iVar2 + uVar6 + 4) = cVar1;
          uVar6 = uVar6 + 1 & 0xff;
        } while (uVar6 < 0x20);
        if (uVar6 != 0) {
          *(char *)(iVar2 + 3) = (char)uVar6;
          *(char *)(iVar2 + 1) = (char)iVar5 + '\x03';
          cVar4 = cVar4 + '\x01';
          iVar2 = iVar2 + 0x24;
        }
      }
    }
    iVar3 = iVar3 + DAT_02189610;
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      return cVar4;
    }
  } while( true );
}

