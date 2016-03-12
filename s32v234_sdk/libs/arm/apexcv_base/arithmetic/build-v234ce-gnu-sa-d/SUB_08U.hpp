#ifndef _ACF_PROCESS_APU_SUB_08U
#define _ACF_PROCESS_APU_SUB_08U

#include <acf_process_apu.h>
#include <SUB_08U_APU_LOAD.h> //APU load associated with this process
#include <stdint.h>


//SCENARIO LIST*************************************************
static acf_scenario_buffer_data gScenarioBufferData0_SUB_08U[] = {{16, 4, 2, 0, 0x0}, {16, 4, 2, 0, 0x0}, {16, 4, 2, 0, 0x0}};

static acf_scenario_kernel_data gScenarioKernelData0_SUB_08U[] = {{0}};

static acf_scenario gScenarioArray_SUB_08U[] = {
{0, 0, 512, 0, 0, gScenarioBufferData0_SUB_08U, 30, gScenarioKernelData0_SUB_08U, 2}
};

static acf_scenario_list gScenarioList_SUB_08U = {
1, //number of scenarios
gScenarioArray_SUB_08U};
//**************************************************************

class SUB_08U : public ACF_Process_APU
{
public:
   SUB_08U(int32_t apex_id = 0) : ACF_Process_APU(apex_id)
   {} 

   int32_t Initialize()
   {
      int32_t lRetVal = 0;

      if (!Initialized()) //initialization steps that only need to occur once
      {
         SetProcessIdentifier("SUB_08U");
         SetApuLoadInfo(SUB_08U_LOAD_SEGMENTS,
                        SUB_08U_LOAD_PMEM, SUB_08U_LOAD_PMEM_SIZE,
                        SUB_08U_LOAD_DMEM, SUB_08U_LOAD_DMEM_SIZE,
                        0, 0); //assuming _LOAD_CMEM does not exist

         //***NOTE: the order in which the following ports are added is meaningful; do not change!

         AddPort("INPUT_0", ICP_DATATYPE_08U, 1, 1, 16, 4, 0, 0, 0, 0, 0, 0, 0, 0x0);
         AddPort("INPUT_1", ICP_DATATYPE_08U, 1, 1, 16, 4, 0, 0, 0, 0, 0, 0, 2, 0x0);
         AddPort("OUTPUT_0", ICP_DATATYPE_16S, 1, 1, 16, 4, 1, 0, 0, 0, 0, 0, 1);

         CfgScenarios(&gScenarioList_SUB_08U);

         FlagAsInitialized();
      }

      lRetVal = SelectApuConfiguration(mApuCfg, mApexId); //by default mApuCfg = ACF_APU_CFG__APEX0_DEFAULT and mApexId = 0

      return lRetVal;
   }
};

#endif //_ACF_PROCESS_APU_SUB_08U
