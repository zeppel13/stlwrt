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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTK_EVENT_BOX_H__
#define __GTK_EVENT_BOX_H__

#include <stlwrt.h>
#include <stlwrt-typedefs.h>


#include <gtkbin.h>


G_BEGIN_DECLS

#define GTK_TYPE_EVENT_BOX              (gtk_event_box_get_type ())
#define GTK_EVENT_BOX(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_EVENT_BOX, GtkEventBox))
#define GTK_EVENT_BOX_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_EVENT_BOX, GtkEventBoxClass))
#define GTK_IS_EVENT_BOX(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_EVENT_BOX))
#define GTK_IS_EVENT_BOX_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_EVENT_BOX))
#define GTK_EVENT_BOX_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_EVENT_BOX, GtkEventBoxClass))

typedef struct _GtkEventBoxClass  GtkEventBoxClass;

STLWRT_DECLARE_FTYPE_VPARENT(GtkEventBox, gtk_event_box, GtkBin)

struct _GtkEventBoxClass
{
  GtkBinClass parent_class;
};


GtkWidget* SF(gtk_event_box_new)                (void);
gboolean   SF(gtk_event_box_get_visible_window) (GtkEventBox *event_box);
void       SF(gtk_event_box_set_visible_window) (GtkEventBox *event_box,
					     gboolean     visible_window);
gboolean   SF(gtk_event_box_get_above_child)    (GtkEventBox *event_box);
void       SF(gtk_event_box_set_above_child)    (GtkEventBox *event_box,
					     gboolean     above_child);

G_END_DECLS

#endif /* __GTK_EVENT_BOX_H__ */
