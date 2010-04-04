/*
 * Copyright (c) 2009     David Mohr <david@mcbf.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <glib.h>

#include "gchd.h"
#include "gchd-menu.h"
#ifdef __WIN32
#  include "gchd-windows.h"
#else
#  include "gchd-unix.h"
#endif

Gchd *
gchd_new (void)
{
  Gchd *gchd;
  
  gchd = g_new0 (Gchd, 1);

#ifdef __WIN32
  gcd_windows_init (gchd);
#else
  gcd_unix_init (gchd);
#endif

  return gchd;
}

void
gchd_free (Gchd *gchd)
{
  g_free (gchd->menu.loc);
  g_list_foreach (gchd->menu.entries, (GFunc) g_free, NULL);
  g_list_free (gchd->menu.entries);

  g_free (gchd);
}

gint
gchd_get_menu_entries (Gchd *gchd, GList **entries, GError **error)
{
  gboolean r;

  g_assert (entries != NULL);

  r = gchd_get_menu (&(gchd->menu), error);

  if (r)
  {
    /* maybe we should copy this? */
    *entries = gchd->menu.entries;

    return gchd->menu.n_entries;
  }
  else
  {
    return -1;
  }
}

gchar *
gchd_get_default_entry (Gchd * gchd, GError **error)
{
  g_assert (gchd->get_default_entry != NULL);
  g_assert (!error || !*error);

  return gchd->get_default_entry (gchd, error);
}

gboolean
gchd_set_default_entry (Gchd * gchd, gchar * entry, GError **error)
{
  g_assert (gchd->set_default_entry != NULL);
  g_assert (!error || !*error);

  return gchd->set_default_entry (gchd, entry, error);
}
