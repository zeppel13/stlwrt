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



/**
 * SECTION:gtkbin
 * @Short_description: A container with just one child
 * @Title: GtkBin
 *
 * The #GtkBin widget is a container with just one child.
 * It is not very useful itself, but it is useful for deriving subclasses,
 * since it provides common code needed for handling a single child widget.
 *
 * Many GTK+ widgets are subclasses of #GtkBin, including #GtkWindow,
 * #GtkButton, #GtkFrame, #GtkHandleBox or #GtkScrolledWindow.
 */

#include "config.h"

#include <stlwrt.h>
#include <gtkbin.h>
#include <gtkintl.h>


static void gtk_bin_add         (GtkContainer   *container,
			         GtkWidget      *widget);
static void gtk_bin_remove      (GtkContainer   *container,
			         GtkWidget      *widget);
static void gtk_bin_forall      (GtkContainer   *container,
				 gboolean	include_internals,
				 GtkCallback     callback,
				 gpointer        callback_data);
static GType gtk_bin_child_type (GtkContainer   *container);


STLWRT_DEFINE_FTYPE_VPARENT (GtkBin, gtk_bin, GTK_TYPE_CONTAINER, G_TYPE_FLAG_ABSTRACT, ;)

static void
gtk_bin_class_init (GtkBinClass *class)
{
  GtkContainerClass *container_class;

  container_class = (GtkContainerClass*) class;

  container_class->add = gtk_bin_add;
  container_class->remove = gtk_bin_remove;
  container_class->forall = gtk_bin_forall;
  container_class->child_type = gtk_bin_child_type;
}

static void
gtk_bin_init (GtkBin *bin)
{
  GtkBinProps *bin_props = gtk_bin_get_props (bin);

  __gtk_widget_set_has_window (GTK_WIDGET (bin), FALSE);

  bin_props->child = NULL;
}


static GType
gtk_bin_child_type (GtkContainer *container)
{
  GtkBinProps *bin_props = gtk_bin_get_props (GTK_BIN (container));

  if (!bin_props->child)
    return GTK_TYPE_WIDGET;
  else
    return G_TYPE_NONE;
}

static void
gtk_bin_add (GtkContainer *container,
	     GtkWidget    *child)
{
  GtkBin *bin = GTK_BIN (container);
  GtkBinProps *bin_props = gtk_bin_get_props (bin);

  if (bin_props->child != NULL)
    {
      g_warning ("Attempting to add a widget with type %s to a %s, "
                 "but as a GtkBin subclass a %s can only contain one widget at a time; "
                 "it already contains a widget of type %s",
                 g_type_name (G_OBJECT_TYPE (child)),
                 g_type_name (G_OBJECT_TYPE (bin)),
                 g_type_name (G_OBJECT_TYPE (bin)),
                 g_type_name (G_OBJECT_TYPE (bin_props->child)));
      return;
    }

  __gtk_widget_set_parent (child, GTK_WIDGET (bin));
  bin_props->child = child;
}

static void
gtk_bin_remove (GtkContainer *container,
		GtkWidget    *child)
{
  GtkBin *bin = GTK_BIN (container);
  GtkBinProps *bin_props = gtk_bin_get_props (bin);
  gboolean widget_was_visible;

  g_return_if_fail (bin_props->child == child);

  widget_was_visible = __gtk_widget_get_visible (child);
  
  __gtk_widget_unparent (child);
  bin_props->child = NULL;
  
  /* queue resize regardless of __gtk_widget_get_visible (container),
   * since that's what is needed by toplevels, which derive from GtkBin.
   */
  if (widget_was_visible)
    __gtk_widget_queue_resize (GTK_WIDGET (container));
}

static void
gtk_bin_forall (GtkContainer *container,
		gboolean      include_internals,
		GtkCallback   callback,
		gpointer      callback_data)
{
  GtkBin *bin = GTK_BIN (container);
  GtkBinProps *bin_props = gtk_bin_get_props (bin);

  if (bin_props->child)
    (* callback) (bin_props->child, callback_data);
}

/**
 * __gtk_bin_get_child:
 * @bin: a #GtkBin
 * 
 * Gets the child of the #GtkBin, or %NULL if the bin contains
 * no child widget. The returned widget does not have a reference
 * added, so you do not need to unref it.
 *
 * Return value: (transfer none): pointer to child of the #GtkBin
 **/
GtkWidget*
__gtk_bin_get_child (GtkBin *bin)
{
  GtkBinProps *bin_props = gtk_bin_get_props (bin);

  g_return_val_if_fail (GTK_IS_BIN (bin), NULL);

  return bin_props->child;
}
