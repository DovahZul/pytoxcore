/**
 * pytoxcore
 *
 * Copyright (C) 2015 Anton Batenev <antonbatenev@yandex.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
//----------------------------------------------------------------------------------------------
#ifndef _pytoxcore_h_
#define _pytoxcore_h_
//----------------------------------------------------------------------------------------------
#define PY_SSIZE_T_CLEAN
//----------------------------------------------------------------------------------------------
#include <Python.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <tox/tox.h>
#include <tox/toxav.h>
//----------------------------------------------------------------------------------------------
#if PY_MAJOR_VERSION < 3
    #define BUF_TC "s"
#else
    #define BUF_TC "y"
#endif
//----------------------------------------------------------------------------------------------
#if PY_MAJOR_VERSION < 3
    #define PYSTRING_FromString        PyString_FromString
    #define PYSTRING_FromStringAndSize PyString_FromStringAndSize
    #define PYSTRING_Check             PyString_Check
    #define PYBYTES_FromStringAndSize  PyString_FromStringAndSize
#else
    #define PYSTRING_FromString        PyUnicode_FromString
    #define PYSTRING_FromStringAndSize PyUnicode_FromStringAndSize
    #define PYSTRING_Check             PyUnicode_Check
    #define PYBYTES_FromStringAndSize  PyBytes_FromStringAndSize
#endif
//----------------------------------------------------------------------------------------------
typedef struct {
    PyObject_HEAD
    Tox* tox;
} ToxCore;
//----------------------------------------------------------------------------------------------
typedef struct {
    PyObject_HEAD
    ToxAV*   av;
    ToxCore* core;
} ToxCoreAV;
//----------------------------------------------------------------------------------------------
void bytes_to_hex_string(const uint8_t* digest, int length, uint8_t* hex_digest);
void hex_string_to_bytes(uint8_t* hexstr, int length, uint8_t* bytes);
void PyStringUnicode_AsStringAndSize(PyObject* object, char** str, Py_ssize_t* len);
//----------------------------------------------------------------------------------------------
#endif   // _pytoxcore_h_
//----------------------------------------------------------------------------------------------
