/* This file was automatically generated by the MULTI Project Manager  */
/* To configure mountpoints, right-click on the file then select       */
/*   Modify Project -> Add INTEGRITY File System Mount Point           */


#include <stdio.h>
#include <sys/mnttab.h>



vfs_MountEntry vfs_MountTable[] = {
	{
                "<mr>staticdisk",
                "/",
                MOUNT_CD9660,
                "ro",
                0,
                0
        },
	{NULL, NULL, NULL, NULL, 0, 0} /* Must end with NULL/0 entry */
};
