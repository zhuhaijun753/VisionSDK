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
*  @file convolve_scale_3x3_08u_graph.hpp
*  @brief ACF graph for convolve with scale (unsigned 8 bit)
***********************************************************************************/
#ifndef CONVOLVE_SCALE_3X3_08U_GRAPH_HPP
#define CONVOLVE_SCALE_3X3_08U_GRAPH_HPP

#include <acf_graph.hpp>
#include "filter_kernels.h"
#include<acf_graph.hpp>
#include "graph_templates.h"

class convolve_scale_3x3_08u_graph : public ACF_Graph
{
public:
	convolve_scale_3x3_08u_graph() : ACF_Graph() {
#ifdef APEX2_EMULATE
		XREGISTER_ACF_KERNEL(CONVOLVE_SCALE_3X3_08U_K);
#endif

	}
   void Create()
   {
      //set identifier for graph
      SetIdentifier("convolve_scale_3x3_08u_graph");
      
      //add kernels
      AddKernel("_convolve_scale_3x3_08u", CONVOLVE_SCALE_3X3_08U_KN);

      //add graph ports
      AddInputPort(GR_IN_0);
	  AddInputPort(GR_F_COEFF);
	  AddInputPort(GR_F_SCALE);

      AddOutputPort(GR_OUT_0);

      //specify connections
      Connect(GraphPort(GR_IN_0),   KernelPort("_convolve_scale_3x3_08u", INPUT_0));
	  Connect(GraphPort(GR_F_COEFF),   KernelPort("_convolve_scale_3x3_08u", F_COEFF));
	  Connect(GraphPort(GR_F_SCALE),   KernelPort("_convolve_scale_3x3_08u", F_SCALE));			
      Connect(KernelPort("_convolve_scale_3x3_08u", OUTPUT_0), GraphPort(GR_OUT_0));
   }
};
#endif

