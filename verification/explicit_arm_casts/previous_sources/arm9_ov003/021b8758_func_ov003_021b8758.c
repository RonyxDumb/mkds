/* Decompiled C draft; module arm9_ov003; ROM address 021b8758. No matching claim. */
#include "types.h"
#include "deps/021b8758_func_ov003_021b8758.h"

int func_ov003_021b8758(int param_1,char *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int local_1c;
  
  uVar3 = 0;
  if (param_3 < 1) {
    return -2;
  }
  pcVar4 = (char *)(DAT_021b8864 + param_1);
  while (*param_2 != *pcVar4) {
    iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 2));
    param_2 = param_2 + iVar1 + 4;
    param_3 = param_3 - (iVar1 + 4);
    if (param_3 < 1) {
      return -4;
    }
  }
  pcVar4 = param_2 + 4;
  iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 2));
  param_4 = param_4 + DAT_021b8868 * param_1;
  local_1c = -3;
  while( true ) {
    switch(*pcVar4) {
    default:
      iVar2 = local_1c;
      break;
    case '\x03':
      iVar2 = func_ov003_021b8990(pcVar4,param_4 + 8);
      uVar3 = uVar3 | 1;
      break;
    case '\x04':
      iVar2 = func_ov003_021b8990(pcVar4,param_4 + DAT_021b886c);
      uVar3 = uVar3 | 2;
      break;
    case '\x05':
      iVar2 = func_ov003_021b88c0(pcVar4,param_4 + DAT_021b8870);
      uVar3 = uVar3 | 4;
      break;
    case '\x06':
      iVar2 = func_ov003_021b88c0(pcVar4,param_4 + DAT_021b8874);
      uVar3 = uVar3 | 8;
      break;
    case '\n':
      iVar2 = func_ov003_021b887c(pcVar4,param_5 + (param_1 + 3) * 0x80);
    }
    if (iVar2 != 0) break;
    iVar2 = func_ov003_021b7c44(*(undefined2 *)(pcVar4 + 2));
    pcVar4 = pcVar4 + iVar2 + 4;
    iVar1 = iVar1 - (iVar2 + 4);
    if (iVar1 < 1) {
      *(uint *)(DAT_021b8878 + 0xc) = *(uint *)(DAT_021b8878 + 0xc) | uVar3;
      return 0;
    }
  }
  return iVar2;
}

