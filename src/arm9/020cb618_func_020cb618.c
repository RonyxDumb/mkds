/* Decompiled C draft; module arm9; ROM address 020cb618. No matching claim. */
#include "types.h"
#include "deps/020cb618_func_020cb618.h"

void func_020cb618(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_020cb6bc + 8);
  if (*(int *)(*DAT_020cb6bc + 0xc) != iVar1) {
    switch(iVar1) {
    case 4:
      func_0x021a1838();
      break;
    case 5:
    case 8:
    case 0xf:
    case 0x15:
      func_020260e4();
      break;
    case 6:
    case 9:
    case 0x16:
      func_0202808c();
      break;
    case 7:
    case 0xb:
    case 0x17:
      func_02117db0();
      break;
    case 10:
    case 0x10:
      func_0211b23c();
      break;
    case 0xc:
    case 0x18:
      func_0211e924();
      break;
    case 0xd:
    case 0x19:
      func_021196f4();
      break;
    case 0xe:
      func_0203223c();
      break;
    case 0x11:
      func_0x0219d26c();
      break;
    case 0x12:
      func_0x0219efec();
      break;
    case 0x13:
      func_0x021a0140();
      break;
    case 0x14:
      func_0x021980e0();
      break;
    case 0x1a:
      func_0x0219baf4();
    }
  }
  return;
}

