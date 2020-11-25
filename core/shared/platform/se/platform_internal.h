/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * Copyright (C) 2020 TU Bergakademie Freiberg Karl Fessel
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <inttypes.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef BH_PLATFORM_RIOT
#define BH_PLATFORM_RIOT
#endif

#define BH_APPLET_PRESERVED_STACK_SIZE (2 * BH_KB)

/* Default thread priority */
#define BH_THREAD_DEFAULT_PRIORITY 7

typedef int korp_thread;
typedef int korp_tid;
typedef int korp_mutex;
typedef int mutex_t;

#define WA_MALLOC os_malloc
#define WA_FREE os_free

#define BH_MALLOC os_malloc
#define BH_FREE os_free


// typedef sema_t korp_sem;

struct os_thread_wait_node;
typedef struct os_thread_wait_node *os_thread_wait_list;
typedef struct korp_cond {
     mutex_t wait_list_lock;
     os_thread_wait_list thread_wait_list;
} korp_cond;

#define os_printf  printf
#define os_vprintf vprintf

#if WA_MATH
/* math functions which are not provided by os*/
double sqrt(double x);
double floor(double x);
double ceil(double x);
double fmin(double x, double y);
double fmax(double x, double y);
double rint(double x);
double fabs(double x);
double trunc(double x);
float floorf(float x);
float ceilf(float x);
float fminf(float x, float y);
float fmaxf(float x, float y);
float rintf(float x);
float truncf(float x);
int signbit(double x);
int isnan(double x);
#endif

#endif /* end of _BH_PLATFORM_H */

