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
*  @file sobel_y_3x3_08u_graph.hpp
*  @brief ACF graph for sobel y 3x3 (unsigned 8 bit)
***********************************************************************************/
 
#ifndef SOBEL_Y_3X3_08U_GRAPH_HPP
#define SOBEL_Y_3X3_08U_GRAPH_HPP

#include <acf_graph.hpp>
#include "filter_kernels.h"
#include "graph_templates.h"

class sobel_y_3x3_08u_graph : public ACF_Graph
{
public:
	sobel_y_3x3_08u_graph() : ACF_Graph() {
#ifdef APEX2_EMULATE
		XREGISTER_ACF_KERNEL(SOBEL_Y_3X3_08U_K);
#endif

	}
   void Create()
   {
      //set identifier for graph
      SetIdentifier("sobel_y_3x3_08u_graph");
      
      //add kernels
      AddKernel("_sobel_y_3x3_08u", SOBEL_Y_3X3_08U_KN);

      //add graph ports
      AddInputPort(GR_IN_0);

      AddOutputPort(GR_OUT_0);

      //specify connections
      Connect(GraphPort(GR_IN_0),   KernelPort("_sobel_y_3x3_08u", INPUT_0));
      Connect(KernelPort("_sobel_y_3x3_08u", OUTPUT_0), GraphPort(GR_OUT_0));
   }
};

#endif
