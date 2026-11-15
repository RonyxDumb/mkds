#pragma once

#include "types.h"


#include "00/Lib/GameSpy/code_0218f960.h"

#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/Lib/GameSpy/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02192d64.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/GameSpy/code_021965a0.h"

u32 GpiIsValidDate(int day, int month, int year);
s32 GpiProcessOperation(GpConnection *connection, GpiOperation *operation, const char *input);
BOOL gpiOperationsAreBlocking(GpConnection *object);
BOOL GpiFindOperation(GpConnection *object, GpiOperation **output, u32 key);
void GpiRemoveOperation(GpConnection *connection, GpiOperation *operation);
void GpiDeleteOperation(GpConnection *connection, GpiOperation *operation);
s32 GpiQueueOperationCallback(GpConnection *connection, GpiOperation *operation);
