/**
 * @file RTE_Memory.h
 * @author Leon Shan (813475603@qq.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __RET_MEMORY_H
#define __RET_MEMORY_H
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
/**
 * @brief Some define for control.
 * 
 */
#define MEMORY_UST_TEST             1           /* define for if enable test main */
#define MEMORY_USE_MUTEX            0           /* define for if use the mutex */
#define MEMORY_USE_64BIT            1
#define MEMORY_USE_USER_LOG         1
#define MEMORY_USE_USER_ASSERT      1

#if MEMORY_USE_USER_LOG == 0
#define memory_printf               printf
#endif

#if MEMORY_USE_USER_ASSERT == 0
static inline void memory_assert() {
    
}
#endif
/**
 * @brief This enum defines how many bank the RTE_Memory will handle.
 * 
 */
typedef enum __mem_bank_t {
    BANK_INVALID  = -1,
    BANK_0        = 0,
    BANK_CNT,
}mem_bank_t;
/**
 * @brief This struct defines the memory handle.
 * 
 */
typedef void* mem_t;
typedef void* pool_t;
typedef struct __mem_handle__t {
    mem_t       mem;
    pool_t      pool;
#if MEMORY_USE_MUTEX == 1
    void*       mutex;
#endif
}mem_handle_t;
#endif