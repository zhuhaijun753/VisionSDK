//////////////////////////////////////////////////////////////////////////////////
//  (C) Copyright CogniVue Corporation. 2014 All rights reserved.
//
//  Confidential Information
//
//  All parts of the CogniVue software and documentation are confidential and
//  proprietary to CogniVue Corp.
//  This file may not, in whole or in part, be copied, photocopied,
//  reproduced, translated, or reduced to any electronic medium or machine
//  readable form without prior consent, in writing, from CogniVue.
//////////////////////////////////////////////////////////////////////////////////


// KERNEL WRAPPER DECL (Implementation generated by Compiler)
int MemoryModel__3 (  int nxt,
                      vuint _vec_wx, vuint _vec_wy, size_t wz,
                      const _cl_runtime* rt,
                      void chess_storage(DMb)*,
                      void chess_storage(VMb)*);
// KERNEL CONTEXT SIZE DATA STRUCT (generated by Compiler)
extern int  MemoryModel__3__md[];

// SET ARGUMENT FUNCTION DECL
void MemoryModel__3__set(void chess_storage(DMb)* ctx, cl_argument* args);


// KERNEL METADATA
CL_KRNL_MD MemoryModel_md = 
{
   0,0,0,0,                   // required wg size
   2,        // number of arguments
   3,                         // kernel mode
   1,1,0,0,0,0,0,0,           // arg addr space type
   0,0,0,0,0,0,0,0,           // arg access type
   MemoryModel__3__md,
   (int32_t)(&MemoryModel__3),
   (int32_t)(&MemoryModel__3__set),

};


// KERNEL SET ARGUMENT FUNCTION
void MemoryModel__3__set(void chess_storage(DMb)* ctx, cl_argument* args) {
    char chess_storage(DMb)* p = (char chess_storage(DMb)*)ctx;
    //
    p = kernel_add_ptr_arg(p, args[0].value);

    //
    p = kernel_add_ptr_arg(p, args[1].value);

}

