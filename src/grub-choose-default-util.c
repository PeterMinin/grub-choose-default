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

#include "grub-choose-default-util.h"

/**
 * grub_choose_default_error:
 * #parent  : a parent window, or NULL
 * #error   : an error to display
 *
 * Displays the message of #error. A modal dialog is used if the optional
 * parameter #parent is non-%NULL.
 **/
void
grub_choose_default_error (GtkWidget *parent, GError *error)
{
  grub_choose_default_error_message (parent, error->message);
}

/**
 * grub_choose_default_error:
 * #parent  : a parent window, or NULL
 * #message : an error message to display
 *
 * Displays the message of #error. A modal dialog is used if the optional
 * parameter #parent is non-%NULL.
 **/
void
grub_choose_default_error_message (GtkWidget *parent, gchar * message)
{
  GtkWidget *dialog;

  dialog = gtk_message_dialog_new (GTK_WINDOW (parent),
                                   (parent != NULL) ? GTK_DIALOG_MODAL : 0,
                                   GTK_MESSAGE_ERROR,
                                   GTK_BUTTONS_CLOSE,
                                   "%s", message);

  g_warning ("%s", message);

  gtk_dialog_run (GTK_DIALOG (dialog));

  gtk_widget_destroy (dialog);
}

