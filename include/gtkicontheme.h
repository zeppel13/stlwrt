/* GtkIconTheme - a loader for icon themes
 * gtk-icon-loader.h Copyright (C) 2002, 2003 Red Hat, Inc.
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

#ifndef __GTK_ICON_THEME_H__
#define __GTK_ICON_THEME_H__

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk.h>

G_BEGIN_DECLS

#define GTK_TYPE_ICON_INFO              (gtk_icon_info_get_type ())

#define GTK_TYPE_ICON_THEME             (gtk_icon_theme_get_type ())
#define GTK_ICON_THEME(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_ICON_THEME, GtkIconTheme))
#define GTK_ICON_THEME_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_ICON_THEME, GtkIconThemeClass))
#define GTK_IS_ICON_THEME(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_ICON_THEME))
#define GTK_IS_ICON_THEME_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_ICON_THEME))
#define GTK_ICON_THEME_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_ICON_THEME, GtkIconThemeClass))

typedef struct _GtkIconInfo         GtkIconInfo;
typedef struct _GtkIconThemeClass   GtkIconThemeClass;
typedef struct _GtkIconThemePrivate GtkIconThemePrivate;


struct _GtkIconThemePrivate
{
  guint custom_theme        : 1;
  guint is_screen_singleton : 1;
  guint pixbuf_supports_svg : 1;
  guint themes_valid        : 1;
  guint check_reload        : 1;
  guint loading_themes      : 1;
  
  char *current_theme;
  char *fallback_theme;
  char **search_path;
  int search_path_len;

  /* A list of all the themes needed to look up icons.
   * In search order, without duplicates
   */
  GList *themes;
  GHashTable *unthemed_icons;
  
  /* Note: The keys of this hashtable are owned by the
   * themedir and unthemed hashtables.
   */
  GHashTable *all_icons;

  /* GdkScreen for the icon theme (may be NULL)
   */
  GdkScreen *screen;
  
  /* time when we last stat:ed for theme changes */
  long last_stat_time;
  GList *dir_mtimes;

  gulong reset_styles_idle;
};

STLWRT_DECLARE_FTYPE_FPARENT(GtkIconTheme, gtk_icon_theme, GObject,
  GtkIconThemePrivate * (priv);
)

struct _GtkIconThemeClass
{
  GObjectClass parent_class;

  void (* changed)  (GtkIconTheme *icon_theme);
};

/**
 * GtkIconLookupFlags:
 * @GTK_ICON_LOOKUP_NO_SVG: Never return SVG icons, even if gdk-pixbuf
 *   supports them. Cannot be used together with %GTK_ICON_LOOKUP_FORCE_SVG.
 * @GTK_ICON_LOOKUP_FORCE_SVG: Return SVG icons, even if gdk-pixbuf
 *   doesn't support them.
 *   Cannot be used together with %GTK_ICON_LOOKUP_NO_SVG.
 * @GTK_ICON_LOOKUP_USE_BUILTIN: When passed to
 *   SF(gtk_icon_theme_lookup_icon)() includes builtin icons
 *   as well as files. For a builtin icon, SF(gtk_icon_info_get_filename)()
 *   returns %NULL and you need to call SF(gtk_icon_info_get_builtin_pixbuf)().
 * @GTK_ICON_LOOKUP_GENERIC_FALLBACK: Try to shorten icon name at '-'
 *   characters before looking at inherited themes. For more general
 *   fallback, see SF(gtk_icon_theme_choose_icon)(). Since 2.12.
 * @GTK_ICON_LOOKUP_FORCE_SIZE: Always return the icon scaled to the
 *   requested size. Since 2.14.
 * 
 * Used to specify options for SF(gtk_icon_theme_lookup_icon)()
 **/
typedef enum
{
  GTK_ICON_LOOKUP_NO_SVG           = 1 << 0,
  GTK_ICON_LOOKUP_FORCE_SVG        = 1 << 1,
  GTK_ICON_LOOKUP_USE_BUILTIN      = 1 << 2,
  GTK_ICON_LOOKUP_GENERIC_FALLBACK = 1 << 3,
  GTK_ICON_LOOKUP_FORCE_SIZE       = 1 << 4
} GtkIconLookupFlags;

#define GTK_ICON_THEME_ERROR SF(gtk_icon_theme_error_quark) ()

/**
 * GtkIconThemeError:
 * @GTK_ICON_THEME_NOT_FOUND: The icon specified does not exist in the theme
 * @GTK_ICON_THEME_FAILED: An unspecified error occurred.
 * 
 * Error codes for GtkIconTheme operations.
 **/
typedef enum {
  GTK_ICON_THEME_NOT_FOUND,
  GTK_ICON_THEME_FAILED
} GtkIconThemeError;

GQuark SF(gtk_icon_theme_error_quark) (void);

#ifdef G_OS_WIN32
/* Reserve old name for DLL ABI backward compatibility */
#define gtk_icon_theme_set_search_path gtk_icon_theme_set_search_path_utf8
#define gtk_icon_theme_get_search_path gtk_icon_theme_get_search_path_utf8
#define gtk_icon_theme_append_search_path gtk_icon_theme_append_search_path_utf8
#define gtk_icon_theme_prepend_search_path gtk_icon_theme_prepend_search_path_utf8
#define gtk_icon_info_get_filename gtk_icon_info_get_filename_utf8
#endif

GtkIconTheme *SF(gtk_icon_theme_new)                   (void);
GtkIconTheme *SF(gtk_icon_theme_get_default)           (void);
GtkIconTheme *SF(gtk_icon_theme_get_for_screen)        (GdkScreen                   *screen);
void          SF(gtk_icon_theme_set_screen)            (GtkIconTheme                *icon_theme,
						    GdkScreen                   *screen);

void          SF(gtk_icon_theme_set_search_path)       (GtkIconTheme                *icon_theme,
						    const gchar                 *path[],
						    gint                         n_elements);
void          SF(gtk_icon_theme_get_search_path)       (GtkIconTheme                *icon_theme,
						    gchar                      **path[],
						    gint                        *n_elements);
void          SF(gtk_icon_theme_append_search_path)    (GtkIconTheme                *icon_theme,
						    const gchar                 *path);
void          SF(gtk_icon_theme_prepend_search_path)   (GtkIconTheme                *icon_theme,
						    const gchar                 *path);

void          SF(gtk_icon_theme_set_custom_theme)      (GtkIconTheme                *icon_theme,
						    const gchar                 *theme_name);

gboolean      SF(gtk_icon_theme_has_icon)              (GtkIconTheme                *icon_theme,
						    const gchar                 *icon_name);
gint         *SF(gtk_icon_theme_get_icon_sizes)        (GtkIconTheme                *icon_theme,
						    const gchar                 *icon_name);
GtkIconInfo * SF(gtk_icon_theme_lookup_icon)           (GtkIconTheme                *icon_theme,
						    const gchar                 *icon_name,
						    gint                         size,
						    GtkIconLookupFlags           flags);
GtkIconInfo * SF(gtk_icon_theme_choose_icon)           (GtkIconTheme                *icon_theme,
						    const gchar                 *icon_names[],
						    gint                         size,
						    GtkIconLookupFlags           flags);
GdkPixbuf *   SF(gtk_icon_theme_load_icon)             (GtkIconTheme                *icon_theme,
						    const gchar                 *icon_name,
						    gint                         size,
						    GtkIconLookupFlags           flags,
						    GError                     **error);

GtkIconInfo * SF(gtk_icon_theme_lookup_by_gicon)       (GtkIconTheme                *icon_theme,
                                                    GIcon                       *icon,
                                                    gint                         size,
                                                    GtkIconLookupFlags           flags);

GList *       SF(gtk_icon_theme_list_icons)            (GtkIconTheme                *icon_theme,
						    const gchar                 *context);
GList *       SF(gtk_icon_theme_list_contexts)         (GtkIconTheme                *icon_theme);
char *        SF(gtk_icon_theme_get_example_icon_name) (GtkIconTheme                *icon_theme);

gboolean      SF(gtk_icon_theme_rescan_if_needed)      (GtkIconTheme                *icon_theme);

void          SF(gtk_icon_theme_add_builtin_icon)      (const gchar *icon_name,
					            gint         size,
					            GdkPixbuf   *pixbuf);

STLWRT_DECLARE_GET_FTYPE_FUNCTIONS(gtk_icon_info)
GtkIconInfo *         SF(gtk_icon_info_copy)               (GtkIconInfo  *icon_info);
void                  SF(gtk_icon_info_free)               (GtkIconInfo  *icon_info);

GtkIconInfo *         SF(gtk_icon_info_new_for_pixbuf)     (GtkIconTheme  *icon_theme,
                                                        GdkPixbuf     *pixbuf);

gint                  SF(gtk_icon_info_get_base_size)      (GtkIconInfo   *icon_info);
const gchar *         SF(gtk_icon_info_get_filename)       (GtkIconInfo   *icon_info);
GdkPixbuf *           SF(gtk_icon_info_get_builtin_pixbuf) (GtkIconInfo   *icon_info);
GdkPixbuf *           SF(gtk_icon_info_load_icon)          (GtkIconInfo   *icon_info,
							GError       **error);
void                  SF(gtk_icon_info_set_raw_coordinates) (GtkIconInfo  *icon_info,
							 gboolean      raw_coordinates);

gboolean              SF(gtk_icon_info_get_embedded_rect) (GtkIconInfo    *icon_info,
						       GdkRectangle   *rectangle);
gboolean              SF(gtk_icon_info_get_attach_points) (GtkIconInfo    *icon_info,
						       GdkPoint      **points,
						       gint           *n_points);
const gchar *         SF(gtk_icon_info_get_display_name)  (GtkIconInfo    *icon_info);

/* Non-public methods */
void SF(_gtk_icon_theme_check_reload)                     (GdkDisplay *display);
void SF(_gtk_icon_theme_ensure_builtin_cache)             (void);

G_END_DECLS

#endif /* __GTK_ICON_THEME_H__ */
