/******************************************************************************
 *  (C) Copyright CogniVue Corporation. 2013 All right reserved.
 * 
 *  Confidential Information
 *
 *  All parts of the CogniVue Program Source are protected by copyright law
 *  and all rights are reserved.
 *  This documentation may not, in whole or in part, be copied, photocopied,
 *  reproduced, translated, or reduced to any electronic medium or machine
 *  readable form without prior consent, in writing, from CogniVue.
 *
 ******************************************************************************/
  
/*!*********************************************************************************
*  @file magnitude_16s_proc_desc.hpp
*  @brief Process description for magnitude (signed 16 bit)
***********************************************************************************/
#ifndef MAGNITUDE_16S_APU_PROCESS_DESC_HPP
#define MAGNITUDE_16S_APU_PROCESS_DESC_HPP

#include <acf_process_desc_apu.hpp>
//#include "magnitude_16s_graph.hpp"
#include "arithm_chunk_size_definitions.h"
#include<acf_graph.hpp>
#include "graph_templates.h"
#include "arithmetic_kernels.h"

GRAPH_CLASS_DEF_2In_1Out(MAGNITUDE_16s_K)

#define MAG_16S_PI	MAGNITUDE_16S
#define MAG_16S_PIN	XSTR(MAG_16S_PI)

class magnitude_16s_apu_process_desc : public ACF_Process_Desc_APU
{
public:
	void Create()
	{
		Initialize(mGraph, MAG_16S_PIN);
		SetInputChunkSize(GR_IN_0, ARITHM_CHUNK_WIDTH, ARITHM_CHUNK_HEIGHT);
		SetInputChunkSize(GR_IN_1, ARITHM_CHUNK_WIDTH, ARITHM_CHUNK_HEIGHT);
	}

	//magnitude_16s_graph mGraph;
	graphClassName(MAGNITUDE_16s_K) mGraph;
};


#ifdef APEX2_EMULATE
REGISTER_PROCESS_TYPE(MAG_16S_PI, magnitude_16s_apu_process_desc)
#endif

#endif
