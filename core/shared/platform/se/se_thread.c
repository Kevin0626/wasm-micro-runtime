/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * Copyright (C) 2020 TU Bergakademie Freiberg Karl Fessel
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "platform_api_vmcore.h"
#include "platform_api_extension.h"


#define bh_assert(v) do {                                   \
     if (!(v)) {                                            \
       printf("\nASSERTION FAILED: %s, at %s, line %d\n",   \
              #v, __FILE__, __LINE__);                      \
      while (1);                                           \
     }                                                      \
  } while (0)

struct os_thread_data;
typedef struct os_thread_wait_node {
    void * ret;
    os_thread_wait_list next;
} os_thread_wait_node;

// all information for thread to cleanup it self
typedef struct os_thread_data {
    /* Next thread data */
    struct os_thread_data *next;
    /* thread handle */
    int tid;
    /* Thread start routine */
    thread_start_routine_t start_routine;
    /* Thread start routine argument */
    void *arg;
    /* thread local root */
    void *tlr;
    /* Lock for waiting list */
    mutex_t wait_list_lock;
    /* Waiting list of other threads who are joining this thread */
    os_thread_wait_list thread_wait_list;
    /* Thread stack size */
    unsigned stack_size;
    /* Thread stack */
    char stack[1];
} os_thread_data;

typedef struct os_thread_obj {
    korp_tid thread;
    /* Whether the thread is terminated and this thread object is to
     be freed in the future. */
    bool to_be_freed;
    struct os_thread_obj *next;
} os_thread_obj;

static bool is_thread_sys_inited = false;

/* Lock for thread data list */
static mutex_t thread_data_lock;

/* Thread data list */
static os_thread_data *thread_data_list = NULL;

int
os_thread_sys_init()
{
        return BHT_OK;

}

void
os_thread_sys_destroy()
{
    if (is_thread_sys_inited) {
        is_thread_sys_inited = false;
    }
}

int
os_thread_create(korp_tid *p_tid, thread_start_routine_t start,
                 void *arg, unsigned int stack_size)
{
    return 0;
}

int
os_thread_create_with_prio(korp_tid *p_tid, thread_start_routine_t start,
                           void *arg, unsigned int stack_size, int prio)
{
    
    return BHT_OK;
}

korp_tid
os_self_thread()
{
    return (korp_tid) 0;
}

int
os_thread_join (korp_tid thread, void **value_ptr)
{
    // will test if thread is still working,
    // wait if it is
//     (void) value_ptr;
    

    return BHT_OK;
}



// int vm_mutex_trylock(korp_mutex *mutex)
// {
//     return mutex_trylock(mutex);
// }

int
os_mutex_init(korp_mutex *mutex)
{
  
    return BHT_OK;
}

int
os_mutex_destroy(korp_mutex *mutex)
{
    (void) mutex;
    return BHT_OK;
}

int
os_mutex_lock(korp_mutex *mutex)
{
    return 0; //Riot mutexes do not return until success
}

int
os_mutex_unlock(korp_mutex *mutex)
{
    return 0; //Riot mutexes do not return until success

}

int
os_cond_init(korp_cond *cond)
{
   
    return BHT_OK;
}

int
os_cond_destroy(korp_cond *cond)
{
    (void) cond;
    return BHT_OK;
}



int
os_cond_wait(korp_cond *cond, korp_mutex *mutex)
{
    return BHT_OK;
}

int
os_cond_reltimedwait(korp_cond *cond, korp_mutex *mutex, int useconds)
{
    return BHT_OK;
}

int
os_cond_signal(korp_cond *cond)
{
    /* Signal the head wait node of wait list */

    return BHT_OK;
}

uint8 *os_thread_get_stack_boundary()
{
#if defined(DEVELHELP) || defined(SCHED_TEST_STACK) \
    || defined(MODULE_MPU_STACK_GUARD)
    return (uint8*)thread_get_active()->stack_start;
#else
    return NULL;
#endif
}
