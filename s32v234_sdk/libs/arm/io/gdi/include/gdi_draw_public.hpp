/******************************************************************************
 *  (C) Copyright CogniVue Corporation. 2010 All right reserved.
 *  
 *  Confidential Information
 *
 *  All parts of the CogniVue Program Source are protected by copyright law
 *  and all rights are reserved.
 *  This documentation may not, in whole or in part, be copied, photocopied,
 *  reproduced, translated, or reduced to any electronic medium or machine
 *  readable form without prior consent, in writing, from CogniVue.
 ******************************************************************************/

/* Information for doxygen */
/**
 *  \file   gdi_draw_public.hpp
 *  \brief  function declarations for the GDI Draw component
 *
 */

#ifndef GDI_DRAW_PUBLIC_HPP
#define GDI_DRAW_PUBLIC_HPP


/***************************************************************************/
/* Include files. */
//#include "GlobalBuildOptions.h"
#include "gdi_types_public.hpp"
#include "Oal.h"
#include "GlobalErrors.h"
#include "GlobalTypes.h"
#include "ICP_Image.hpp"
#include <stdint.h>

//**************************************************************************/
// Literals & definitions
const uint32_t gcGdiDrawBoxTextArraySize     = 36;

/**
 *  \file gdi_draw_public.hpp
 *  \addtogroup Display GDI: Graphical Device Interface
 *  @{
 *  \brief Drawing utility classes
 *  \details
 *   This component contains a set of utility classes that let you draw on a canvas;
 *   the canvas being a raster pixel buffer.
 *
 * Mandatory operation sequence:
 * <ol><li>Constructor to create a GdiDraw_XXX object.
 * </li><li>Populate all object member variables with values.
 * </li><li>Draw to draw the visual representation of the object in the buffer.
 * </li></ol>
*/


/**
 * \brief This class holds the data used to represent and draw a bounding box.
 *  
 */
class GdiDraw_BoxText
{
public:
   GdiDraw_BoxText();
   virtual ~GdiDraw_BoxText();

public:
   uint32_t       mBoxWidthInPixels;                     ///< Dimension of the box
   uint32_t       mBoxHeightInPixels;                    ///< Dimension of the box
   uint32_t       mOutlineWidthInPixels;                 ///< Line width
   uint32_t       mOutlineColor;                         ///< Line color
   char           mText[gcGdiDrawBoxTextArraySize];      ///< Text to be drawn on specified edge
   uint32_t       mTextColor;                            ///< Text Color
   LIB_BOX_EDGE   mTextEdge;                             ///< Edge of the box along which the text shall be drawn
   LIB_TEXT_ALIGN mTextAligment;                         ///< Alignment of the text

public:
   /***************************************************************************/
   /**
    * \details
    * This function draws the visual representation of the object into the provided buffer.
    *
    * Currently only 16 bit pixel formats are supported.
    *
    * \param  cCanvasWidthInPixels       - [in] Width in pixels of the image in cpBuffer
    * \param  cCanvasHeightInPixels      - [in] Height in pixels of the image in cpBuffer
    * \param  cHorizontalOffsetInPixels  - [in] Horizontal offset of the box relative to the upper left corner of the canvas
    * \param  cVerticalOffsetInPixels    - [in] Vertical offset of the box relative to the upper left corner of the canvas
    * \param  cGdiImageFormat            - [in] Format of the pixels in cpBuffer
    * \param  cpBuffer                   - [in] Buffer into which the visual representation of the object shall be drawn.
    *               
    *
    * \return 
    *    - #LIB_SUCCESS
    *    - #LIB_FAILURE
    **************************************************************************/
   LIB_RESULT Draw(uint32_t const cCanvasWidthInPixels,
                   uint32_t const cCanvasHeightInPixels,
                   uint32_t const cHorizontalOffsetInPixels,
                   uint32_t const cVerticalOffsetInPixels,
                   GDI_IMAGE_FORMAT const cGdiImageFormat,
                   void* const cpBuffer);
};


class GdiDraw_Icon
{
public:
	GdiDraw_Icon(ICP_Image *iconImg);
   virtual ~GdiDraw_Icon();

public:
   ICP_Image      mIconImg;

public:
   /***************************************************************************/
   /**
    * \details
    * This function draws the visual representation of the object into the provided buffer.
    *
    * Currently only 16 bit pixel formats are supported.
    *
    * \param  cHorizontalOffsetInPixels  - [in] Horizontal offset of the box relative to the upper left corner of the canvas
    * \param  cVerticalOffsetInPixels    - [in] Vertical offset of the box relative to the upper left corner of the canvas
    * \param  destImage                   - [in] Buffer into which the visual representation of the object shall be drawn.
    *
    *
    * \return
    *    - #LIB_SUCCESS
    *    - #LIB_FAILURE
    **************************************************************************/
   LIB_RESULT Draw(uint32_t const cHorizontalOffsetInPixels,
                   uint32_t const cVerticalOffsetInPixels,
                   ICP_Image *destImage);
};


class GdiDraw_Line
{
public:
   GdiDraw_Line();
   virtual ~GdiDraw_Line();

public:
   uint32_t mX1;
   uint32_t mY1;
   uint32_t mX2;
   uint32_t mY2;
   uint32_t mColor;

public:
   /***************************************************************************/
   /**
    * \details
    * This function draws the visual representation of the object into the provided buffer.
    *
    * Currently only 8, 16 and 36 bit pixel single plane formats are supported.
    *
    * \param  cpDestImage - [in] Buffer into which the visual representation of the object shall be drawn.
    *
    *
    * \return
    *    - #LIB_SUCCESS
    *    - #LIB_FAILURE
    **************************************************************************/
   LIB_RESULT Draw(ICP_Image* const cpDestImage);
};

/**
 * @}
*/

#endif // #ifndef GDI_DRAW_PUBLIC_HPP

