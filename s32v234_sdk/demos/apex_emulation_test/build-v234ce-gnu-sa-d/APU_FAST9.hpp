#ifndef _ACF_PROCESS_APU_APU_FAST9
#define _ACF_PROCESS_APU_APU_FAST9

#include <acf_process_apu.h>
#include <APU_FAST9_APU_LOAD.h> //APU load associated with this process
#include <stdint.h>


//SCENARIO LIST*************************************************
static acf_scenario_buffer_data gScenarioBufferData0_APU_FAST9[] = {{8, 8, 9, 0, 0x2211}, {8, 8, 4, 1, 0x4433}, {8, 8, 4, 2, 0x2211}, {8, 8, 4, 3, 0x2222}, {8, 8, 4, 4, 0x2222}, {8, 8, 4, 5, 0x2222}, {8, 8, 1, 6, 0x0}, {8, 8, 1, 6, 0x0}, {8, 8, 2, 6, 0x0}, {1, 1, 1, 0, 0x0}};

static acf_scenario_kernel_data gScenarioKernelData0_APU_FAST9[] = {{1}, {2}, {3}, {4}, {5}, {6}, {6}, {6}};

static acf_scenario gScenarioArray_APU_FAST9[] = {
{0, 0, 3520, 8, 6, gScenarioBufferData0_APU_FAST9, 100, gScenarioKernelData0_APU_FAST9, 16}
};

static acf_scenario_list gScenarioList_APU_FAST9 = {
1, //number of scenarios
gScenarioArray_APU_FAST9};
//**************************************************************

class APU_FAST9 : public ACF_Process_APU
{
public:
   APU_FAST9(int32_t apex_id = 0) : ACF_Process_APU(apex_id)
   {} 

   int32_t Initialize()
   {
      int32_t lRetVal = 0;

      if (!Initialized()) //initialization steps that only need to occur once
      {
         SetProcessIdentifier("APU_FAST9");
         SetApuLoadInfo(APU_FAST9_LOAD_SEGMENTS,
                        APU_FAST9_LOAD_PMEM, APU_FAST9_LOAD_PMEM_SIZE,
                        APU_FAST9_LOAD_DMEM, APU_FAST9_LOAD_DMEM_SIZE,
                        0, 0); //assuming _LOAD_CMEM does not exist
         FlagSpatialDep();

         //***NOTE: the order in which the following ports are added is meaningful; do not change!

         AddPort("INPUT_0", ICP_DATATYPE_08U, 1, 1, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0xb0b0b0b);
         AddPort("INPUT_1", ICP_DATATYPE_08U, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 9);
         AddPort("OUTPUT_0", ICP_DATATYPE_08U, 1, 1, 8, 8, 1, 0, 0, 0, 0, 0, 8);

         CfgScenarios(&gScenarioList_APU_FAST9);

         FlagAsInitialized();
      }

      lRetVal = SelectApuConfiguration(mApuCfg, mApexId); //by default mApuCfg = ACF_APU_CFG__APEX0_DEFAULT and mApexId = 0

      return lRetVal;
   }
};

#endif //_ACF_PROCESS_APU_APU_FAST9
