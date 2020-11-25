/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * Copyright (C) 2020 TU Bergakademie Freiberg Karl Fessel
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "platform_api_vmcore.h"

uint64
os_time_get_boot_microsecond()
{
    return 0;
}


uint64 bh_get_tick_ms()
{
    return os_time_get_boot_microsecond() / 1000;
}