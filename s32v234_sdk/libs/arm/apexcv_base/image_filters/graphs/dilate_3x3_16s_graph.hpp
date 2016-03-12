/******************************************************************************
 *  (C) Copyright CogniVue Corporation. 2014 All right reserved.
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
*  @file dilate_3x3_16s_graph.hpp
*  @brief ACF graph for dilate 3x3 (signed 16 bit)
***********************************************************************************/
#ifndef DILATE_3X3_16S_GRAPH_HPP
#define DILATE_3X3_16S_GRAPH_HPP

#include <acf_graph.hpp>
#include "filter_kernels.h"
#include "graph_templates.h"

class dilate_3x3_16s_graph : public ACF_Graph
{
public:
	dilate_3x3_16s_graph() : ACF_Graph() {
#ifdef APEX2_EMULATE
		XREGISTER_ACF_KERNEL(DILATE_3X3_16S_K);
#endif

	}
   void Create()
   {
      //set identifier for graph
      SetIdentifier("dilate_3x3_16s_graph");
      
      //add kernels
      AddKernel("_dilate_3x3_16s", DILATE_3X3_16S_KN);

      //add graph ports
      AddInputPort(GR_IN_0);

      AddOutputPort(GR_OUT_0);

      //specify connections
      Connect(GraphPort(GR_IN_0),   KernelPort("_dilate_3x3_16s", INPUT_0));
      Connect(KernelPort("_dilate_3x3_16s", OUTPUT_0), GraphPort(GR_OUT_0));
   }
};
#endif

