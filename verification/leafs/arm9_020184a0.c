/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define IsValidArchiveBinary ArcEntry_ValidateNarcHeader
#include <string.h>

#include <nnsys/misc.h>
#include <nnsys/fnd/archive.h>

#include "archive_block.h"

#pragma thumb off
BOOL IsValidArchiveBinary (NNSiFndArchiveHeader * arcBinary)
{
    NNS_NULL_ASSERT(arcBinary);

    if (arcBinary->signature != 'CRAN') return FALSE;
    if (arcBinary->byteOrder != 0xfffe) return FALSE;
    if (arcBinary->version   != 0x0100) return FALSE;

    return TRUE;
}
