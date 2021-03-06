/*****************************************************************************
*
* Freescale Confidential Proprietary
*
* Copyright (c) 2014 Freescale Semiconductor;
* All Rights Reserved
*
*****************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************/
#ifndef APU_ROTATE_GRAPH_H
#define APU_ROTATE_GRAPH_H

#include <stringify_macros.h>

#define ROTATE_PI	APU_ROTATE
#define ROTATE_GN	XSTR(ROTATE_PI)

#define ROTATE_GRAPH_IN			"INPUT_0"
#define ROTATE_GRAPH_OUT		"OUTPUT_0"
//#define ROTATE_GRAPH_OUT_OFFSETS "ROTATEGraph_Out_Filt"


#define ROT_TRANSFER_TILE_SIZE_X  8
#define ROT_TRANSFER_TILE_SIZE_Y  8

#endif
