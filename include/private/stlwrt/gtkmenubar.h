
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

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/.
 */

#ifndef __GTK_MENU_BAR_H__
#define __GTK_MENU_BAR_H__


#if defined(GTK_DISABLE_SINGLE_INCLUDES) && !defined (__GTK_H_INSIDE__) && !defined (STLWRT_COMPILATION)
#error "Only <gtk.h> can be included directly."
#endif

#include <gtkmenushell.h>


G_BEGIN_DECLS


#define	GTK_TYPE_MENU_BAR               (__gtk_menu_bar_get_type ())
#define GTK_MENU_BAR(obj)               (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_MENU_BAR, GtkMenuBar))
#define GTK_MENU_BAR_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_MENU_BAR, GtkMenuBarClass))
#define GTK_IS_MENU_BAR(obj)            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_MENU_BAR))
#define GTK_IS_MENU_BAR_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_MENU_BAR))
#define GTK_MENU_BAR_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_MENU_BAR, GtkMenuBarClass))

typedef struct _GtkMenuBar       GtkMenuBarFat;
typedef struct _GtkMenuBar       GtkMenuBarSkinny;
typedef struct _GtkMenuBarClass  GtkMenuBarClassFat;
typedef struct _GtkMenuBarClass  GtkMenuBarClassSkinny;

struct _GtkMenuBar
{
  GtkMenuShell menu_shell;
};

struct _GtkMenuBarClass
{
  GtkMenuShellClass parent_class;

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};


GType      __gtk_menu_bar_get_type        (void) G_GNUC_CONST;
GtkWidget* __gtk_menu_bar_new             (void);

GtkPackDirection __gtk_menu_bar_get_pack_direction (GtkMenuBar       *menubar);
void             __gtk_menu_bar_set_pack_direction (GtkMenuBar       *menubar,
						  GtkPackDirection  pack_dir);
GtkPackDirection __gtk_menu_bar_get_child_pack_direction (GtkMenuBar       *menubar);
void             __gtk_menu_bar_set_child_pack_direction (GtkMenuBar       *menubar,
							GtkPackDirection  child_pack_dir);

#ifndef GTK_DISABLE_DEPRECATED
#define __gtk_menu_bar_append(menu,child)	    __gtk_menu_shell_append  ((GtkMenuShell *)(menu),(child))
#define __gtk_menu_bar_prepend(menu,child)    __gtk_menu_shell_prepend ((GtkMenuShell *)(menu),(child))
#define __gtk_menu_bar_insert(menu,child,pos) __gtk_menu_shell_insert ((GtkMenuShell *)(menu),(child),(pos))
#endif /* GTK_DISABLE_DEPRECATED */

/* Private functions */
void ___gtk_menu_bar_cycle_focus (GtkMenuBar       *menubar,
				GtkDirectionType  dir);


G_END_DECLS


#endif /* __GTK_MENU_BAR_H__ */
