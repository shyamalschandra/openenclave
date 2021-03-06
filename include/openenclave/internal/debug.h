// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#ifndef _OE_DEBUG_H
#define _OE_DEBUG_H

#include "sgxtypes.h"

OE_EXTERNC_BEGIN

typedef struct _oe_enclave oe_enclave_t;

void _oe_notify_gdb_enclave_creation(
    const oe_enclave_t* enclave,
    const char* enclave_path,
    uint32_t enclave_path_length);

void _oe_notify_gdb_enclave_termination(
    const oe_enclave_t* enclave,
    const char* enclave_path,
    uint32_t enclave_path_length);

OE_EXTERNC_END

#endif /* _OE_DEBUG_H */
