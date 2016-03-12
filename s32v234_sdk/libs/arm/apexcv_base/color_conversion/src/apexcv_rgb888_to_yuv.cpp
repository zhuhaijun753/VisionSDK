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
 ******************************************************************************/
/*!*********************************************************************************
*  \file apexcv_rgb888_to_yuv.cpp
*  \brief Host-ACF interface for rgb888 to yuv 
***********************************************************************************/
#include "graph_templates.h"
#include <apexcv_rgb888_to_yuv.h>

int apexcv_rgb888_to_yuv::Initialize( DataDescriptor& lInput0,
                                      DataDescriptor& lOutput0 ) {
	int lRetVal = 0;
	
   	lRetVal |= mProcess.Initialize();
	lRetVal |= mProcess.ConnectIO("INPUT_0", lInput0);
	lRetVal |= mProcess.ConnectIO("OUTPUT_0", lOutput0);

	return lRetVal;
}
		  
int apexcv_rgb888_to_yuv::Release() {
   return 0;
}
  

int apexcv_rgb888_to_yuv::Process() {
   int lRetVal = 0;
   
   lRetVal |= mProcess.Start();
   lRetVal |= mProcess.Wait();
   
   return lRetVal;
}
