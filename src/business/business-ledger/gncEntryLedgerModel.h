/*
 * gncEntryLedgerModel.h -- Model of GncEntry Manipulation Widget
 * Copyright (C) 2001, 2002 Derek Atkins
 * Author: Derek Atkins <warlord@MIT.EDU>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, contact:
 *
 * Free Software Foundation           Voice:  +1-617-542-5942
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652
 * Boston, MA  02111-1307,  USA       gnu@gnu.org
 */

#ifndef GNC_ENTRY_LEDGER_MODEL_H
#define GNC_ENTRY_LEDGER_MODEL_H

#include "gncEntryLedger.h"

TableModel * gnc_entry_ledger_model_new (GncEntryLedgerType type);

#endif /* GNC_ENTRY_LEDGER_MODEL_H */
