/*
 * This file is part of the Sofia-SIP package
 *
 * Copyright (C) 2005 Nokia Corporation.
 *
 * Contact: Pekka Pessi <pekka.pessi@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

/**@SU_TAG
 * 
 * @CFILE su_tag.c  
 *
 * Special tags.
 * 
 * @author Pekka Pessi <Pekka.Pessi@nokia.com>
 *
 * @date Created: Tue Feb 20 20:03:38 2001 ppessi
 */

#include "config.h"

#include <assert.h>

#include "sofia-sip/su_config.h"
#include "sofia-sip/su_tag_class.h"

extern tag_class_t null_tag_class[1];
extern tag_class_t skip_tag_class[1];
extern tag_class_t next_tag_class[1];
extern tag_class_t any_tag_class[1];

