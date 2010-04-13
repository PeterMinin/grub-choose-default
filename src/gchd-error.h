#ifndef _HAVE_GCHD_ERROR
#define _HAVE_GCHD_ERROR

#include <glib.h>

G_BEGIN_DECLS

typedef enum
{
  GCHD_ERROR_NONE,
  GCHD_ERROR_CFG_NOT_FOUND,
  GCHD_ERROR_CFG_NOT_READABLE,
  GCHD_ERROR_NO_REBOOT_SCRIPT,
  GCHD_ERROR_FAILED_SETTING_ENTRY,
  GCHD_ERROR_FAILED_WRITING_ENV,
} GchdError;

#define GCHD_ERROR gchd_error_quark ()

GQuark gchd_error_quark (void);

G_END_DECLS

#endif /* _HAVE_GCHD_ERROR */
