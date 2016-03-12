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
*  @file and_16u_proc_desc.hpp
*  @brief Process description for bitwise and (unsigned 16 bit)
***********************************************************************************/
#ifndef AND_16U_APU_PROCESS_DESC_HPP
#define AND_16U_APU_PROCESS_DESC_HPP

#include <acf_process_desc_apu.hpp>
//#include "and_16u_graph.hpp"
#include "arithm_chunk_size_definitions.h"
#include<acf_graph.hpp>
#include "graph_templates.h"
#include "arithmetic_kernels.h"

GRAPH_CLASS_DEF_2In_1Out(AND_16u_K);


#define AND_16U_PI		AND_16U
#define AND_16U_PIN	XSTR(AND_16U_PI)

class and_16u_apu_process_desc : public ACF_Process_Desc_APU
{
public:

	void Create()
	{
		Initialize(mGraph, AND_16U_PIN);
		SetInputChunkSize(GR_IN_0, ARITHM_CHUNK_WIDTH, ARITHM_CHUNK_HEIGHT);
		SetInputChunkSize(GR_IN_1, ARITHM_CHUNK_WIDTH, ARITHM_CHUNK_HEIGHT);
	}
	graphClassName(AND_16u_K) mGraph;
};


#ifdef APEX2_EMULATE
REGISTER_PROCESS_TYPE(AND_16U_PI, and_16u_apu_process_desc)
#endif

#endif
