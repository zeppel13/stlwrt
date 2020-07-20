
/* STLWRT - A fork of GTK+ 2 supporting future applications as well
 *
 * Copyright (C) 2007 John Stowers, Neil Jagdish Patel.
 * Copyright (C) 2009 Bastien Nocera, David Zeuthen
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
 * Boston, MA  02111-1307, USA.
 *
 * Code adapted from egg-spinner
 * by Christian Hergert <christian.hergert@gmail.com>
 */

#ifndef __GTK_SPINNER_H__
#define __GTK_SPINNER_H__

#include <gtkdrawingarea.h>

G_BEGIN_DECLS

#define GTK_TYPE_SPINNER           (gtk_spinner_get_type ())
#define GTK_SPINNER(obj)           (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_SPINNER, GtkSpinner))
#define GTK_SPINNER_CLASS(obj)     (G_TYPE_CHECK_CLASS_CAST ((obj), GTK_SPINNER,  GtkSpinnerClass))
#define GTK_IS_SPINNER(obj)        (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_SPINNER))
#define GTK_IS_SPINNER_CLASS(obj)  (G_TYPE_CHECK_CLASS_TYPE ((obj), GTK_TYPE_SPINNER))
#define GTK_SPINNER_GET_CLASS      (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_SPINNER, GtkSpinnerClass))

typedef struct _GtkSpinner      GtkSpinnerFat;
typedef struct _GtkSpinner      GtkSpinnerThin;
typedef struct _GtkSpinnerClass GtkSpinnerClassFat;
typedef struct _GtkSpinnerClass GtkSpinnerClassThin;
typedef struct _GtkSpinnerPrivate  GtkSpinnerPrivate;

struct _GtkSpinner
{
  GtkDrawingArea parent;
  GtkSpinnerPrivate *priv;
};

struct _GtkSpinnerClass
{
  GtkDrawingAreaClass parent_class;
};

GType      _T2_gtk_spinner_get_type  (void) G_GNUC_CONST;
GType      _3T_gtk_spinner_get_type  (void) G_GNUC_CONST;
/* Supplied in the STLWRT public libraries */
GType      gtk_spinner_get_type  (void) G_GNUC_CONST;
GtkWidget *__gtk_spinner_new (void);
void       __gtk_spinner_start      (GtkSpinner *spinner);
void       __gtk_spinner_stop       (GtkSpinner *spinner);

G_END_DECLS

#endif /* __GTK_SPINNER_H__ */
