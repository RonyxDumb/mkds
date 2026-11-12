#include "00/Lib/DWC/code_02189440.h"

s32 GetProgramaError(u32 error) {
    switch (error) {
        case 1:
            return -9;
        case 0:
            return -10;
        case 2:
            return -8;
        case 3:
            return -7;
    }
    return 0;
}
