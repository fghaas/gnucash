/********************************************************************\
 * FileIO.h -- read from and writing to a datafile for gnucash      *
 *             (X-Accountant)                                       *
 * Copyright (C) 1997 Robin D. Clark                                *
 * Copyright (C) 1998 Linas Vepstas                                 *
 *                                                                  *
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, write to the Free Software      *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.        *
 *                                                                  *
 *   Author: Rob Clark                                              *
 * Internet: rclark@cs.hmc.edu                                      *
 *  Address: 609 8th Street                                         *
 *           Huntington Beach, CA 92648-4632                        *
\********************************************************************/

#ifndef __XACC_FILEIO_H__
#define __XACC_FILEIO_H__

#include "Group.h"

#define ERR_FILEIO_NO_ERROR          0
#define ERR_FILEIO_FILE_BAD_READ     1 
#define ERR_FILEIO_FILE_EMPTY        2 
#define ERR_FILEIO_FILE_NOT_FOUND    3
#define ERR_FILEIO_FILE_TOO_NEW      4
#define ERR_FILEIO_FILE_TOO_OLD      5

/** PROTOTYPES ******************************************************/
int           xaccGetFileIOError (void);

AccountGroup *xaccReadQIFAccountGroup (char *datafile);
int           xaccGetQIFIOError (void);

#endif /* __XACC_FILEIO_H__ */
