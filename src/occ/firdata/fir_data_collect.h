/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ/firdata/fir_data_collect.h $                          */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */


#ifndef _FIR_DATA_COLLECT_H
#define _FIR_DATA_COLLECT_H

#include <common_types.h>

/* This size has to agree with the size _FIR_PARMS_SECTION_SIZE defined in the */
/* OCC linker command file. */
#define FIR_PARMS_SECTION_SIZE          0x1000
// This size has to agree with the size _FIR_HEAP_SECTION_SIZE defined in the
// OCC linker command file.
#define FIR_HEAP_SECTION_SIZE           0x3000

enum fir_master
{
    FIR_OCC_NOT_FIR_MASTER              = 0x00000000,
    FIR_OCC_IS_FIR_MASTER               = 0x00000001
};

extern uint8_t G_fir_data_parms[FIR_PARMS_SECTION_SIZE];
extern uint8_t G_fir_heap[FIR_HEAP_SECTION_SIZE];
extern uint32_t G_fir_master;

#define OCC_SET_FIR_MASTER(_fm_t) G_fir_master = _fm_t
#define OCC_IS_FIR_MASTER()       (G_fir_master == FIR_OCC_IS_FIR_MASTER) ? TRUE : FALSE
#define TPC_GP0_BIT18_PNOR_OWNER_MASK   0x00002000

void fir_data_collect(void);
bool pnor_access_allowed(void);

#endif /* _FIR_DATA_COLLECT_H */
