/* -*- mode: C; c-file-style: "gnu" -*- */
/* dbus-object-tree.h  DBusObjectTree (internals of DBusConnection)
 *
 * Copyright (C) 2003  Red Hat Inc.
 *
 * Licensed under the Academic Free License version 1.2
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifndef DBUS_OBJECT_TREE_H
#define DBUS_OBJECT_TREE_H

#include <dbus/dbus-connection.h>

DBUS_BEGIN_DECLS;

typedef struct DBusObjectTree DBusObjectTree;

DBusObjectTree* _dbus_object_tree_new   (DBusConnection *connection);
void            _dbus_object_tree_ref   (DBusObjectTree *tree);
void            _dbus_object_tree_unref (DBusObjectTree *tree);

dbus_bool_t       _dbus_object_tree_register              (DBusObjectTree              *tree,
                                                           dbus_bool_t                  fallback,
                                                           const char                 **path,
                                                           const DBusObjectPathVTable  *vtable,
                                                           void                        *user_data);
void              _dbus_object_tree_unregister_and_unlock (DBusObjectTree              *tree,
                                                           const char                 **path);
DBusHandlerResult _dbus_object_tree_dispatch_and_unlock   (DBusObjectTree              *tree,
                                                           DBusMessage                 *message);
void              _dbus_object_tree_free_all_unlocked     (DBusObjectTree              *tree);

dbus_bool_t _dbus_object_tree_list_registered_and_unlock (DBusObjectTree *tree,
                                                          const char    **parent_path,
                                                          char         ***child_entries);
DBUS_END_DECLS;

#endif /* DBUS_OBJECT_TREE_H */