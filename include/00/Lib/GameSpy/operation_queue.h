#pragma once

#include "types.h"


#include "00/Lib/GameSpy/buddy_messages.h"

#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/error_set.h"

u32 GpiIsValidDate(int day, int month, int year);
s32 GpiProcessOperation(GpConnection *connection, GpiOperation *operation, const char *input);
BOOL gpiOperationsAreBlocking(GpConnection *object);
BOOL GpiFindOperation(GpConnection *object, GpiOperation **output, u32 key);
void GpiRemoveOperation(GpConnection *connection, GpiOperation *operation);
void GpiDeleteOperation(GpConnection *connection, GpiOperation *operation);
s32 GpiQueueOperationCallback(GpConnection *connection, GpiOperation *operation);
