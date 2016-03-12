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
*  @file ht_sobel_x_3x3_08s_graph.hpp
*  @brief ACF graph for hand-tuned sobel x 3x3 filter
***********************************************************************************/
 
#ifndef HT_SOBEL_X_3X3_08S_GRAPH_HPP
#define HT_SOBEL_X_3X3_08S_GRAPH_HPP

#include <acf_graph.hpp>
#include "filter_kernels.h"
#include "graph_templates.h"

class ht_sobel_x_3x3_08s_graph : public ACF_Graph
{
public:
	ht_sobel_x_3x3_08s_graph() : ACF_Graph() {
#ifdef APEX2_EMULATE
		XREGISTER_ACF_KERNEL(HT_SOBEL_X_3X3_08S_K);
#endif

	}
   void Create()
   {
      //set identifier for graph
      SetIdentifier("ht_sobel_x_3x3_08s_graph");
      
      //add kernels
      AddKernel("_ht_sobel_x_3x3_08s", HT_SOBEL_X_3X3_08S_KN);

      //add graph ports
     AddInputPort(GR_IN_0);
      AddOutputPort("BUFFER_0");
      AddOutputPort(GR_OUT_0);

      //specify connections
      Connect(GraphPort(GR_IN_0),   KernelPort("_ht_sobel_x_3x3_08s", INPUT_0));
      Connect(KernelPort("_ht_sobel_x_3x3_08s", "BUFFER_0"), GraphPort("BUFFER_0"));
      Connect(KernelPort("_ht_sobel_x_3x3_08s", OUTPUT_0), GraphPort(GR_OUT_0));
   }
};
#endif
