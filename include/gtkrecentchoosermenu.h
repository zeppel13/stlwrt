/* STLWRT - A fork of GTK+ 2 supporting future applications as well
 * gtkrecentchoosermenu.h - Recently used items menu widget
 * Copyright (C) 2006, Emmanuele Bassi
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

#ifndef __GTK_RECENT_CHOOSER_MENU_H__
#define __GTK_RECENT_CHOOSER_MENU_H__

#include <stlwrt.h>
#include <stlwrt-typedefs.h>


#include <gtkmenu.h>

#include <gtkrecentchooser.h>

G_BEGIN_DECLS

#define GTK_TYPE_RECENT_CHOOSER_MENU		(gtk_recent_chooser_menu_get_type ())
#define GTK_RECENT_CHOOSER_MENU(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_RECENT_CHOOSER_MENU, GtkRecentChooserMenu))
#define GTK_IS_RECENT_CHOOSER_MENU(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_RECENT_CHOOSER_MENU))
#define GTK_RECENT_CHOOSER_MENU_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_RECENT_CHOOSER_MENU, GtkRecentChooserMenuClass))
#define GTK_IS_RECENT_CHOOSER_MENU_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_RECENT_CHOOSER_MENU))
#define GTK_RECENT_CHOOSER_MENU_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_RECENT_CHOOSER_MENU, GtkRecentChooserMenuClass))

typedef struct _GtkRecentChooserMenuClass	GtkRecentChooserMenuClass;
typedef struct _GtkRecentChooserMenuPrivate	GtkRecentChooserMenuPrivate;

struct _GtkRecentChooserMenuPrivate
{
  /* the recent manager object */
  GtkRecentManager *manager;
  
  /* size of the icons of the menu items */  
  gint icon_size;

  /* max size of the menu item label */
  gint label_width;

  gint first_recent_item_pos;
  GtkWidget *placeholder;

  /* RecentChooser properties */
  gint limit;  
  guint show_private : 1;
  guint show_not_found : 1;
  guint show_tips : 1;
  guint show_icons : 1;
  guint local_only : 1;
  
  guint show_numbers : 1;
  
  GtkRecentSortType sort_type;
  GtkRecentSortFunc sort_func;
  gpointer sort_data;
  GDestroyNotify sort_data_destroy;
  
  GSList *filters;
  GtkRecentFilter *current_filter;
 
  guint local_manager : 1;
  gulong manager_changed_id;

  gulong populate_id;
};

STLWRT_DECLARE_VTYPE_VPARENT(GtkRecentChooserMenu, gtk_recent_chooser_menu, GtkMenu,
  GtkRecentChooserMenuPrivate * (priv);
)

struct _GtkRecentChooserMenuClass
{
  GtkMenuClass parent_class;

  /* padding for future expansion */
  void (* gtk_recent1) (void);
  void (* gtk_recent2) (void);
  void (* gtk_recent3) (void);
  void (* gtk_recent4) (void);
};


GtkWidget *SF(gtk_recent_chooser_menu_new)              (void);
GtkWidget *SF(gtk_recent_chooser_menu_new_for_manager)  (GtkRecentManager     *manager);

gboolean   SF(gtk_recent_chooser_menu_get_show_numbers) (GtkRecentChooserMenu *menu);
void       SF(gtk_recent_chooser_menu_set_show_numbers) (GtkRecentChooserMenu *menu,
						     gboolean              show_numbers);

G_END_DECLS

#endif /* ! __GTK_RECENT_CHOOSER_MENU_H__ */
