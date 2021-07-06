# General API

## Introduction

This documentation describes general supporting functions for input or output modules.

## helper functions

### path helpers (MetaModel.h)

Path helpers deliver strings in ImdOutput TID format.

```c++
string get_path(MMObject *o)
```
Delivers the full path string of the MMObject `o` (ie. `modelname.topicname.classname.attrname`).
   
```c++
string get_parent_path(MetaElement *e)
```
Delivers the full path string of the `o` parent object (ie. `modelname.topicname`).

## class `metamodel::MMObject` (MetaModel.h)

```c++
string getClass()
```
Delivers the classname of the MMObject.

```c++
string getBaseClass()
```
Delivers the baseclassname of the MMObject.

```c++
bool isAbstract()
```
Is `true` if the corresponding class / structure in the interlis metamodel is abstract.

```c++
bool isSubClassOf(string classname);
```
Delivers `true` if the MMObject is an extension of class / structure with name `classname`.

```c++
MMObject* clone();
```
Clones the MMObject. The delivered object is not a deepclone, ie. attribute values of the cloned
object may point to other objects.
