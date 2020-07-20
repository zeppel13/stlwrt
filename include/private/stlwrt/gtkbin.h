
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
 

#ifndef __GTK_BIN_H__
#define __GTK_BIN_H__


#include <gtkcontainer.h>


G_BEGIN_DECLS

#define GTK_TYPE_BIN                  (gtk_bin_get_type ())
#define GTK_BIN(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_BIN, GtkBin))
#define GTK_BIN_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_BIN, GtkBinClass))
#define GTK_IS_BIN(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_BIN))
#define GTK_IS_BIN_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_BIN))
#define GTK_BIN_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_BIN, GtkBinClass))


typedef struct _GtkBin       GtkBinFat;
typedef struct _GtkBin       GtkBinThin;
typedef struct _GtkBinClass  GtkBinClassFat;
typedef struct _GtkBinClass  GtkBinClassThin;

struct _GtkBin
{
  GtkContainer container;

  GtkWidget * (child);
};

struct _GtkBinClass
{
  GtkContainerClass parent_class;
};


GType      _T2_gtk_bin_get_type  (void) G_GNUC_CONST;
GType      _3T_gtk_bin_get_type  (void) G_GNUC_CONST;
/* Supplied in the STLWRT public libraries */
GType      gtk_bin_get_type  (void) G_GNUC_CONST;

GtkWidget *__gtk_bin_get_child (GtkBin *bin);

G_END_DECLS

#endif /* __GTK_BIN_H__ */
