/**
 * @file
 *
 * @ingroup ClassicPartImpl
 *
 * @brief Classic Partition Manager Data Structures
 */

/* COPYRIGHT (c) 1989-2008.
 * On-Line Applications Research Corporation (OAR).
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#ifndef _RTEMS_RTEMS_PARTDATA_H
#define _RTEMS_RTEMS_PARTDATA_H

#include <rtems/rtems/part.h>
#include <rtems/score/isrlock.h>
#include <rtems/score/objectdata.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup ClassicPartImpl
 *
 * @{
 */

/**
 *  The following defines the control block used to manage each partition.
 */
typedef struct {
  /** This field is the object management portion of a Partition instance. */
  Objects_Control     Object;
  /** This field is the lock of the Partition. */
  ISR_LOCK_MEMBER(    Lock )
  /** This field is the physical starting address of the Partition. */
  void               *starting_address;
  /** This field is the size of the Partition in bytes. */
  uintptr_t           length;
  /** This field is the size of each buffer in bytes */
  size_t              buffer_size;
  /** This field is the attribute set provided at create time. */
  rtems_attribute     attribute_set;
  /** This field is the of allocated buffers. */
  uintptr_t           number_of_used_blocks;
  /** This field is the chain used to manage unallocated buffers. */
  Chain_Control       Memory;
}   Partition_Control;

/** @} */

#ifdef __cplusplus
}
#endif

#endif
/* end of include file */
