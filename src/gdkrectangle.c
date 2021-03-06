/* STLWRT - A fork of GTK+ 2 supporting future applications as well
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */



#include "config.h"

#include <stlwrt.h>
#include <gdk.h>


/**
 * __gdk_rectangle_union:
 * @src1: a #GdkRectangle
 * @src2: a #GdkRectangle
 * @dest: (out): return location for the union of @src1 and @src2
 *
 * Calculates the union of two rectangles.
 * The union of rectangles @src1 and @src2 is the smallest rectangle which
 * includes both @src1 and @src2 within it.
 * It is allowed for @dest to be the same as either @src1 or @src2.
 */
void
__gdk_rectangle_union (const GdkRectangle *src1,
		     const GdkRectangle *src2,
		     GdkRectangle       *dest)
{
  gint dest_x, dest_y;
  
  g_return_if_fail (src1 != NULL);
  g_return_if_fail (src2 != NULL);
  g_return_if_fail (dest != NULL);

  dest_x = MIN (src1->x, src2->x);
  dest_y = MIN (src1->y, src2->y);
  dest->width = MAX (src1->x + src1->width, src2->x + src2->width) - dest_x;
  dest->height = MAX (src1->y + src1->height, src2->y + src2->height) - dest_y;
  dest->x = dest_x;
  dest->y = dest_y;
}

/**
 * __gdk_rectangle_intersect:
 * @src1: a #GdkRectangle
 * @src2: a #GdkRectangle
 * @dest: (out caller-allocates) (allow-none): return location for the
 * intersection of @src1 and @src2, or %NULL
 *
 * Calculates the intersection of two rectangles. It is allowed for
 * @dest to be the same as either @src1 or @src2. If the rectangles 
 * do not intersect, @dest's width and height is set to 0 and its x 
 * and y values are undefined. If you are only interested in whether
 * the rectangles intersect, but not in the intersecting area itself,
 * pass %NULL for @dest.
 *
 * Returns: %TRUE if the rectangles intersect.
 */
gboolean
__gdk_rectangle_intersect (const GdkRectangle *src1,
			 const GdkRectangle *src2,
			 GdkRectangle       *dest)
{
  gint dest_x, dest_y;
  gint dest_x2, dest_y2;
  gint return_val;

  g_return_val_if_fail (src1 != NULL, FALSE);
  g_return_val_if_fail (src2 != NULL, FALSE);

  return_val = FALSE;

  dest_x = MAX (src1->x, src2->x);
  dest_y = MAX (src1->y, src2->y);
  dest_x2 = MIN (src1->x + src1->width, src2->x + src2->width);
  dest_y2 = MIN (src1->y + src1->height, src2->y + src2->height);

  if (dest_x2 > dest_x && dest_y2 > dest_y)
    {
      if (dest)
        {
          dest->x = dest_x;
          dest->y = dest_y;
          dest->width = dest_x2 - dest_x;
          dest->height = dest_y2 - dest_y;
        }
      return_val = TRUE;
    }
  else if (dest)
    {
      dest->width = 0;
      dest->height = 0;
    }

  return return_val;
}

static GdkRectangle *
gdk_rectangle_copy (const GdkRectangle *rectangle)
{
  GdkRectangle *result = g_new (GdkRectangle, 1);
  *result = *rectangle;

  return result;
}

STLWRT_DEFINE_BOXED_TYPE (GdkRectangle, gdk_rectangle, gdk_rectangle_copy, g_free, ;)
