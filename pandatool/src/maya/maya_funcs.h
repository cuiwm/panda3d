// Filename: maya_funcs.h
// Created by:  drose (16Feb00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://www.panda3d.org/license.txt .
//
// To contact the maintainers of this program write to
// panda3d@yahoogroups.com .
//
////////////////////////////////////////////////////////////////////

#ifndef MAYA_FUNCS_H
#define MAYA_FUNCS_H

#include "pandatoolbase.h"
#include "luse.h"
#include "config_maya.h"

#include "pre_maya_include.h"
#include <maya/MFnAttribute.h>
#include <maya/MPlug.h>
#include <maya/MStatus.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MObject.h>
#include <maya/MString.h>
#include <maya/MVector.h>
#include "post_maya_include.h"

class MObject;

bool
get_maya_plug(MObject &node, const string &attribute_name, MPlug &plug);

bool
is_connected(MObject &node, const string &attribute_name);

template<class ValueType>
bool
get_maya_attribute(MObject &node, const string &attribute_name,
                   ValueType &value);

template<class ValueType>
bool
set_maya_attribute(MObject &node, const string &attribute_name,
                   ValueType &value);

bool
has_attribute(MObject &node, const string &attribute_name);

bool
get_bool_attribute(MObject &node, const string &attribute_name,
                   bool &value);

bool
get_angle_attribute(MObject &node, const string &attribute_name,
                    double &value);

bool
get_vec2f_attribute(MObject &node, const string &attribute_name,
                    LVecBase2f &value);

bool
get_vec3f_attribute(MObject &node, const string &attribute_name,
                    LVecBase3f &value);

bool
get_vec2d_attribute(MObject &node, const string &attribute_name,
                    LVecBase2d &value);

bool
get_vec3d_attribute(MObject &node, const string &attribute_name,
                    LVecBase3d &value);

bool
get_mat4d_attribute(MObject &node, const string &attribute_name,
                    LMatrix4d &value);

bool
get_enum_attribute(MObject &node, const string &attribute_name,
                   string &value);

bool
get_string_attribute(MObject &node, const string &attribute_name,
                     string &value);

bool
set_string_attribute(MObject &node, const string &attribute_name,
                     const string &value);

void
describe_maya_attribute(MObject &node, const string &attribute_name);

string
string_mfndata_type(MFnData::Type type);

void
list_maya_attributes(MObject &node);

// Also, we must define some output functions for Maya objects, since
// we can't use those built into Maya (which forward-defines the
// ostream type incorrectly).
INLINE ostream &operator << (ostream &out, const MString &str);
INLINE ostream &operator << (ostream &out, const MVector &vec);

#include "maya_funcs.I"
#include "maya_funcs.T"

#endif
