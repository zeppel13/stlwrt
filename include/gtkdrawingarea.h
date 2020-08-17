
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

#ifndef __GTK_DRAWING_AREA_H__
#define __GTK_DRAWING_AREA_H__

#include <gtkwidget.h>


G_BEGIN_DECLS

#define GTK_TYPE_DRAWING_AREA            (gtk_drawing_area_get_type ())
#define GTK_DRAWING_AREA(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_DRAWING_AREA, GtkDrawingArea))
#define GTK_DRAWING_AREA_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_DRAWING_AREA, GtkDrawingAreaClass))
#define GTK_IS_DRAWING_AREA(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_DRAWING_AREA))
#define GTK_IS_DRAWING_AREA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_DRAWING_AREA))
#define GTK_DRAWING_AREA_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_DRAWING_AREA, GtkDrawingAreaClass))


typedef struct _GtkDrawingArea       GtkDrawingAreaFat;
typedef struct _GtkDrawingArea       GtkDrawingAreaThin;

typedef struct _GtkDrawingAreaClass  GtkDrawingAreaClass;

/********************************************************************/
struct _GtkDrawingAreaProps
{


  gpointer  (draw_data);
};

struct _GtkDrawingAreaFat
{
  GtkWidgetFat   widget;

  struct _GtkDrawingAreaProps instance_properties;
};

struct _GtkDrawingAreaThin
{
  GtkWidgetThin  widget;

  gpointer reserved;
};


#ifdef STLWRT_COMPILATION
typedef union
{
  struct _GtkDrawingAreaFat   fat_instance;
  struct _GtkDrawingAreaThin  thin_instance;
}   GtkDrawingArea;
#elif STLWRT_GTK_VERSION <= 2
typedef struct _GtkDrawingAreaFat GtkDrawingArea;
#elif STLWRT_GTK_VERSION >= 3
typedef struct _GtkDrawingAreaThin GtkDrawingArea;
#endif
/********************************************************************/



struct _GtkDrawingAreaClass
{
  GtkWidgetClass parent_class;

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};


GType      _T2_gtk_drawing_area_get_type   (void) G_GNUC_CONST;
GType      _3T_gtk_drawing_area_get_type   (void) G_GNUC_CONST;
/* Supplied in the STLWRT public libraries */
GType      gtk_drawing_area_get_type   (void) G_GNUC_CONST;
GtkWidget* __gtk_drawing_area_new        (void);

#ifndef GTK_DISABLE_DEPRECATED
void       __gtk_drawing_area_size       (GtkDrawingArea      *darea,
					gint                 width,
					gint                 height);
#endif /* GTK_DISABLE_DEPRECATED */


G_END_DECLS

#endif /* __GTK_DRAWING_AREA_H__ */