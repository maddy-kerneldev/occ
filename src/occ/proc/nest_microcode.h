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

typedef struct __attribute__ ((packed))
{
	//Microcde magic -- ASCII "OP_NEST"
	uint64_t	magic;

	//Microcode Version
	uint32_t	ver;

	//Nest Units supported by the microcode
	//Each bit represents a unit or function of a unit.
	//This microcode supports only two functions of MC (read and write BW)
	// unit_map = 0x3
	// (PowerPC MSB, bit 63 - MCS_READ, bit 62 - MCS_WRITE)
	uint32_t	unit_map;

	//Periodic ticks by the nest thread
	uint64_t	heartbeat;

	//Counter data
	//MCS Read  -- Group 1
	uint64_t	mcs0_read; //Event 0
	uint64_t	mcs1_read; //Event 1
	uint64_t	mcs2_read; //Event 2
	uint64_t	mcs3_read; //Event 3

	//MCS Write --  Group 2
	uint64_t	mcs0_write; //Event 4
	uint64_t	mcs1_write; //Event 5
	uint64_t	mcs2_write; //Event 6
	uint64_t	mcs3_write; //Event 7

	uint64_t	pb_cyc;
	//future use
	char		pad[32];
} sapphire_nest_data_t __attribute__ ((aligned (128)));

#define PMULET_COUNTER_2_MASK	0xFFFF0000
#define PMULET_COUNTER_3_MASK	0xFFFF
#define NEST_MICROCODE_MAGIC	0x4F505F4E455354 //ASCII "OP_NEST"
#define NEST_MICROCODE_VERSION	0x1
#define NEST_MICROCODE_UNIT_MAP	0x3

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
