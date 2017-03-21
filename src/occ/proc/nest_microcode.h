/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/occ/proc/nest_microcode.h $                               */
/*                                                                        */
/* OpenPOWER OnChipController Project                                     */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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

#ifndef NEST_MICROCODE.H
#define NEST_MICROCODE.H

#include "pgp_async.h"

#define NEST_MCS_UP		0x320100
#define NEST_MCS_DOWN		0x320180

typedef struct __attribute__ ((packed))
{
	uint64_t	TOD;
	uint64_t	count2;
	uint64_t	period;
	uint64_t	mcs0_up;
	uint64_t	mcs1_up;
	uint64_t	mcs2_up;
	uint64_t	mcs3_up;
	uint64_t	period2;
	uint64_t	pad[8];
} sapphire_nest_data_up_t __attribute__ ((aligned (128)));

typedef struct __attribute__ ((packed))
{
	uint64_t	TOD;
	uint64_t	count2;
	uint64_t	period;
	uint64_t	mcs0_down;
	uint64_t	mcs1_down;
	uint64_t	mcs2_down;
	uint64_t	mcs3_down;
	uint64_t	period2;
	uint64_t	pad[8];
} sapphire_nest_data_down_t __attribute__ ((aligned (128)));

#define PMULET_COUNTER_2_MASK	0xFFFF0000
#define PMULET_COUNTER_3_MASK	0xFFFF

#define NEST_PMU_SCOM1		0x02010C54
#define NEST_PMU_SCOM2		0x02010C55
#define NEST_PMU_SCOM3		0x02010C56
#define NEST_PMU_SCOM4		0x02010C57

/*
 * From HOMER Map:
 * https://github.com/open-power/hostboot/blob/master-p8/src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_homer_map.h
 */
#define NEST_HOMER_OFFSET	0x320000

#endif

